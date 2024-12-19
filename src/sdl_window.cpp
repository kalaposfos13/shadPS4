// SPDX-FileCopyrightText: Copyright 2024 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include <SDL3/SDL_hints.h>
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_properties.h"
#include "SDL3/SDL_timer.h"
#include "SDL3/SDL_video.h"

#include "common/assert.h"
#include "common/config.h"
#include "common/elf_info.h"
#include "common/version.h"
#include "core/libraries/pad/pad.h"
#include "imgui/renderer/imgui_core.h"
#include "input/controller.h"
#include "input/input_handler.h"
#include "sdl_window.h"
#include "video_core/renderdoc.h"

#ifdef __APPLE__
#include "SDL3/SDL_metal.h"
#endif

namespace Frontend {

using namespace Libraries::Pad;

static OrbisPadButtonDataOffset SDLGamepadToOrbisButton(u8 button) {
    switch (button) {
    case SDL_GAMEPAD_BUTTON_DPAD_DOWN:
        return OrbisPadButtonDataOffset::Down;
    case SDL_GAMEPAD_BUTTON_DPAD_UP:
        return OrbisPadButtonDataOffset::Up;
    case SDL_GAMEPAD_BUTTON_DPAD_LEFT:
        return OrbisPadButtonDataOffset::Left;
    case SDL_GAMEPAD_BUTTON_DPAD_RIGHT:
        return OrbisPadButtonDataOffset::Right;
    case SDL_GAMEPAD_BUTTON_SOUTH:
        return OrbisPadButtonDataOffset::Cross;
    case SDL_GAMEPAD_BUTTON_NORTH:
        return OrbisPadButtonDataOffset::Triangle;
    case SDL_GAMEPAD_BUTTON_WEST:
        return OrbisPadButtonDataOffset::Square;
    case SDL_GAMEPAD_BUTTON_EAST:
        return OrbisPadButtonDataOffset::Circle;
    case SDL_GAMEPAD_BUTTON_START:
        return OrbisPadButtonDataOffset::Options;
    case SDL_GAMEPAD_BUTTON_TOUCHPAD:
        return OrbisPadButtonDataOffset::TouchPad;
    case SDL_GAMEPAD_BUTTON_BACK:
        return OrbisPadButtonDataOffset::TouchPad;
    case SDL_GAMEPAD_BUTTON_LEFT_SHOULDER:
        return OrbisPadButtonDataOffset::L1;
    case SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER:
        return OrbisPadButtonDataOffset::R1;
    case SDL_GAMEPAD_BUTTON_LEFT_STICK:
        return OrbisPadButtonDataOffset::L3;
    case SDL_GAMEPAD_BUTTON_RIGHT_STICK:
        return OrbisPadButtonDataOffset::R3;
    default:
        return OrbisPadButtonDataOffset::None;
    }
}

static Uint32 SDLCALL PollController(void* userdata, SDL_TimerID timer_id, Uint32 interval) {
    auto* controller = reinterpret_cast<Input::GameController*>(userdata);
    return controller->Poll();
}

WindowSDL::WindowSDL(s32 width_, s32 height_, Input::GameController* controller_,
                     std::string_view window_title)
    : width{width_}, height{height_}, controller{controller_} {
    if (!SDL_SetHint(SDL_HINT_APP_NAME, "shadPS4")) {
        UNREACHABLE_MSG("Failed to set SDL window hint: {}", SDL_GetError());
    }
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        UNREACHABLE_MSG("Failed to initialize SDL video subsystem: {}", SDL_GetError());
    }
    SDL_InitSubSystem(SDL_INIT_AUDIO);

    SDL_PropertiesID props = SDL_CreateProperties();
    SDL_SetStringProperty(props, SDL_PROP_WINDOW_CREATE_TITLE_STRING,
                          std::string(window_title).c_str());
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_X_NUMBER, SDL_WINDOWPOS_CENTERED);
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_Y_NUMBER, SDL_WINDOWPOS_CENTERED);
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_WIDTH_NUMBER, width);
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_HEIGHT_NUMBER, height);
    SDL_SetNumberProperty(props, "flags", SDL_WINDOW_VULKAN);
    SDL_SetBooleanProperty(props, SDL_PROP_WINDOW_CREATE_RESIZABLE_BOOLEAN, true);
    window = SDL_CreateWindowWithProperties(props);
    SDL_DestroyProperties(props);
    if (window == nullptr) {
        UNREACHABLE_MSG("Failed to create window handle: {}", SDL_GetError());
    }

    SDL_SetWindowFullscreen(window, Config::isFullscreenMode());

    SDL_InitSubSystem(SDL_INIT_GAMEPAD);
    controller->TryOpenSDLController();

#if defined(SDL_PLATFORM_WIN32)
    window_info.type = WindowSystemType::Windows;
    window_info.render_surface = SDL_GetPointerProperty(SDL_GetWindowProperties(window),
                                                        SDL_PROP_WINDOW_WIN32_HWND_POINTER, NULL);
#elif defined(SDL_PLATFORM_LINUX)
    if (SDL_strcmp(SDL_GetCurrentVideoDriver(), "x11") == 0) {
        window_info.type = WindowSystemType::X11;
        window_info.display_connection = SDL_GetPointerProperty(
            SDL_GetWindowProperties(window), SDL_PROP_WINDOW_X11_DISPLAY_POINTER, NULL);
        window_info.render_surface = (void*)SDL_GetNumberProperty(
            SDL_GetWindowProperties(window), SDL_PROP_WINDOW_X11_WINDOW_NUMBER, 0);
    } else if (SDL_strcmp(SDL_GetCurrentVideoDriver(), "wayland") == 0) {
        window_info.type = WindowSystemType::Wayland;
        window_info.display_connection = SDL_GetPointerProperty(
            SDL_GetWindowProperties(window), SDL_PROP_WINDOW_WAYLAND_DISPLAY_POINTER, NULL);
        window_info.render_surface = SDL_GetPointerProperty(
            SDL_GetWindowProperties(window), SDL_PROP_WINDOW_WAYLAND_SURFACE_POINTER, NULL);
    }
#elif defined(SDL_PLATFORM_MACOS)
    window_info.type = WindowSystemType::Metal;
    window_info.render_surface = SDL_Metal_GetLayer(SDL_Metal_CreateView(window));
#endif
    // input handler init-s
    Input::ControllerOutput::SetControllerOutputController(controller);
    Input::ParseInputConfig(std::string(Common::ElfInfo::Instance().GameSerial()));
}

WindowSDL::~WindowSDL() = default;

void WindowSDL::WaitEvent() {
    // Called on main thread
    SDL_Event event;

    if (!SDL_WaitEvent(&event)) {
        return;
    }

    if (ImGui::Core::ProcessEvent(&event)) {
        return;
    }

    switch (event.type) {
    case SDL_EVENT_WINDOW_RESIZED:
    case SDL_EVENT_WINDOW_MAXIMIZED:
    case SDL_EVENT_WINDOW_RESTORED:
        OnResize();
        break;
    case SDL_EVENT_WINDOW_MINIMIZED:
    case SDL_EVENT_WINDOW_EXPOSED:
        is_shown = event.type == SDL_EVENT_WINDOW_EXPOSED;
        OnResize();
        break;
    case SDL_EVENT_MOUSE_BUTTON_DOWN:
    case SDL_EVENT_MOUSE_BUTTON_UP:
    case SDL_EVENT_MOUSE_WHEEL:
    case SDL_EVENT_MOUSE_WHEEL_OFF:
    case SDL_EVENT_KEY_DOWN:
    case SDL_EVENT_KEY_UP:
        OnKeyboardMouseInput(&event);
        break;
    case SDL_EVENT_GAMEPAD_BUTTON_DOWN:
    case SDL_EVENT_GAMEPAD_BUTTON_UP:
    case SDL_EVENT_GAMEPAD_AXIS_MOTION:
    case SDL_EVENT_GAMEPAD_ADDED:
    case SDL_EVENT_GAMEPAD_REMOVED:
    case SDL_EVENT_GAMEPAD_TOUCHPAD_DOWN:
    case SDL_EVENT_GAMEPAD_TOUCHPAD_UP:
    case SDL_EVENT_GAMEPAD_TOUCHPAD_MOTION:
        OnGamepadEvent(&event);
        break;
    case SDL_EVENT_QUIT:
        is_open = false;
        break;
    default:
        break;
    }
}

void WindowSDL::InitTimers() {
    SDL_AddTimer(100, &PollController, controller);
    SDL_AddTimer(33, Input::MousePolling, (void*)controller);
}

void WindowSDL::RequestKeyboard() {
    if (keyboard_grab == 0) {
        SDL_StartTextInput(window);
    }
    keyboard_grab++;
}

void WindowSDL::ReleaseKeyboard() {
    ASSERT(keyboard_grab > 0);
    keyboard_grab--;
    if (keyboard_grab == 0) {
        SDL_StopTextInput(window);
    }
}

void WindowSDL::OnResize() {
    SDL_GetWindowSizeInPixels(window, &width, &height);
    ImGui::Core::OnResize();
}

Uint32 wheelOffCallback(void* og_event, Uint32 timer_id, Uint32 interval) {
    SDL_Event off_event = *(SDL_Event*)og_event;
    off_event.type = SDL_EVENT_MOUSE_WHEEL_OFF;
    SDL_PushEvent(&off_event);
    delete (SDL_Event*)og_event;
    return 0;
}

void WindowSDL::OnKeyboardMouseInput(const SDL_Event* event) {
    using Libraries::Pad::OrbisPadButtonDataOffset;

    // get the event's id, if it's keyup or keydown
    bool input_down = event->type == SDL_EVENT_KEY_DOWN ||
                      event->type == SDL_EVENT_MOUSE_BUTTON_DOWN ||
                      event->type == SDL_EVENT_MOUSE_WHEEL;
    u32 input_id = Input::InputBinding::GetInputIDFromEvent(*event);

    // Handle window controls outside of the input maps
    if (event->type == SDL_EVENT_KEY_DOWN) {
        // Reparse kbm inputs
        if (input_id == SDLK_F8) {
            Input::ParseInputConfig(std::string(Common::ElfInfo::Instance().GameSerial()));
            return;
        }
        // Toggle mouse capture and movement input
        else if (input_id == SDLK_F7) {
            Input::ToggleMouseEnabled();
            SDL_SetWindowRelativeMouseMode(this->GetSDLWindow(),
                                           !SDL_GetWindowRelativeMouseMode(this->GetSDLWindow()));
            return;
        }
        // Toggle fullscreen
        else if (input_id == SDLK_F11) {
            SDL_WindowFlags flag = SDL_GetWindowFlags(window);
            bool is_fullscreen = flag & SDL_WINDOW_FULLSCREEN;
            SDL_SetWindowFullscreen(window, !is_fullscreen);
            return;
        }
        // Trigger rdoc capture
        else if (input_id == SDLK_F12) {
            VideoCore::TriggerCapture();
            return;
        }
    }

    // if it's a wheel event, make a timer that turns it off after a set time
    if (event->type == SDL_EVENT_MOUSE_WHEEL) {
        const SDL_Event* copy = new SDL_Event(*event);
        SDL_AddTimer(33, wheelOffCallback, (void*)copy);
    }

    // add/remove it from the list
    bool inputs_changed = Input::UpdatePressedKeys(input_id, input_down);

    // update bindings
    if (inputs_changed) {
        Input::ActivateOutputsFromInputs();
    }
}

void WindowSDL::OnGamepadEvent(const SDL_Event* event) {
    auto button = OrbisPadButtonDataOffset::None;
    Input::Axis axis = Input::Axis::AxisMax;
    switch (event->type) {
    case SDL_EVENT_GAMEPAD_ADDED:
    case SDL_EVENT_GAMEPAD_REMOVED:
        controller->TryOpenSDLController();
        break;
    case SDL_EVENT_GAMEPAD_TOUCHPAD_DOWN:
    case SDL_EVENT_GAMEPAD_TOUCHPAD_UP:
    case SDL_EVENT_GAMEPAD_TOUCHPAD_MOTION:
        controller->SetTouchpadState(event->gtouchpad.finger,
                                     event->type != SDL_EVENT_GAMEPAD_TOUCHPAD_UP,
                                     event->gtouchpad.x, event->gtouchpad.y);
        break;
    case SDL_EVENT_GAMEPAD_BUTTON_DOWN:
    case SDL_EVENT_GAMEPAD_BUTTON_UP: {
        button = SDLGamepadToOrbisButton(event->gbutton.button);
        if (button == OrbisPadButtonDataOffset::None) {
            break;
        }
        if (event->gbutton.button != SDL_GAMEPAD_BUTTON_BACK) {
            controller->CheckButton(0, button, event->type == SDL_EVENT_GAMEPAD_BUTTON_DOWN);
            break;
        }
        const auto backButtonBehavior = Config::getBackButtonBehavior();
        if (backButtonBehavior != "none") {
            float x = backButtonBehavior == "left" ? 0.25f
                                                   : (backButtonBehavior == "right" ? 0.75f : 0.5f);
            // trigger a touchpad event so that the touchpad emulation for back button works
            controller->SetTouchpadState(0, true, x, 0.5f);
            controller->CheckButton(0, button, event->type == SDL_EVENT_GAMEPAD_BUTTON_DOWN);
        }
        break;
    }
    case SDL_EVENT_GAMEPAD_AXIS_MOTION:
        axis = event->gaxis.axis == SDL_GAMEPAD_AXIS_LEFTX           ? Input::Axis::LeftX
               : event->gaxis.axis == SDL_GAMEPAD_AXIS_LEFTY         ? Input::Axis::LeftY
               : event->gaxis.axis == SDL_GAMEPAD_AXIS_RIGHTX        ? Input::Axis::RightX
               : event->gaxis.axis == SDL_GAMEPAD_AXIS_RIGHTY        ? Input::Axis::RightY
               : event->gaxis.axis == SDL_GAMEPAD_AXIS_LEFT_TRIGGER  ? Input::Axis::TriggerLeft
               : event->gaxis.axis == SDL_GAMEPAD_AXIS_RIGHT_TRIGGER ? Input::Axis::TriggerRight
                                                                     : Input::Axis::AxisMax;
        if (axis != Input::Axis::AxisMax) {
            if (event->gaxis.axis == SDL_GAMEPAD_AXIS_LEFT_TRIGGER ||
                event->gaxis.axis == SDL_GAMEPAD_AXIS_RIGHT_TRIGGER) {
                controller->Axis(0, axis, Input::GetAxis(0, 0x8000, event->gaxis.value));

            } else {
                controller->Axis(0, axis, Input::GetAxis(-0x8000, 0x8000, event->gaxis.value));
            }
        }
        break;
    }
}

} // namespace Frontend