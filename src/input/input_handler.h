// SPDX-FileCopyrightText: Copyright 2024 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "array"
#include "common/logging/log.h"
#include "common/types.h"
#include "core/libraries/pad/pad.h"
#include "fmt/format.h"
#include "input/controller.h"
#include "map"
#include "string"
#include "unordered_set"

#include "SDL3/SDL_events.h"
#include "SDL3/SDL_timer.h"

// +1 and +2 is taken
#define SDL_MOUSE_WHEEL_UP SDL_EVENT_MOUSE_WHEEL + 3
#define SDL_MOUSE_WHEEL_DOWN SDL_EVENT_MOUSE_WHEEL + 4
#define SDL_MOUSE_WHEEL_LEFT SDL_EVENT_MOUSE_WHEEL + 5
#define SDL_MOUSE_WHEEL_RIGHT SDL_EVENT_MOUSE_WHEEL + 7

// idk who already used what where so I just chose a big number
#define SDL_EVENT_MOUSE_WHEEL_OFF SDL_EVENT_USER + 10

#define LEFTJOYSTICK_HALFMODE 0x00010000
#define RIGHTJOYSTICK_HALFMODE 0x00020000

#define KEY_TOGGLE 0x00200000

namespace Input {
using Input::Axis;
using Libraries::Pad::OrbisPadButtonDataOffset;

struct AxisMapping {
    Axis axis;
    int value; // Value to set for key press (+127 or -127 for movement)
};

// i strongly suggest you collapse these maps
const std::map<std::string, u32> string_to_cbutton_map = {
    {"triangle", OrbisPadButtonDataOffset::ORBIS_PAD_BUTTON_TRIANGLE},
    {"circle", OrbisPadButtonDataOffset::ORBIS_PAD_BUTTON_CIRCLE},
    {"cross", OrbisPadButtonDataOffset::ORBIS_PAD_BUTTON_CROSS},
    {"square", OrbisPadButtonDataOffset::ORBIS_PAD_BUTTON_SQUARE},
    {"l1", OrbisPadButtonDataOffset::ORBIS_PAD_BUTTON_L1},
    {"r1", OrbisPadButtonDataOffset::ORBIS_PAD_BUTTON_R1},
    {"l3", OrbisPadButtonDataOffset::ORBIS_PAD_BUTTON_L3},
    {"r3", OrbisPadButtonDataOffset::ORBIS_PAD_BUTTON_R3},
    {"options", OrbisPadButtonDataOffset::ORBIS_PAD_BUTTON_OPTIONS},
    {"touchpad", OrbisPadButtonDataOffset::ORBIS_PAD_BUTTON_TOUCH_PAD},
    {"up", OrbisPadButtonDataOffset::ORBIS_PAD_BUTTON_UP},
    {"down", OrbisPadButtonDataOffset::ORBIS_PAD_BUTTON_DOWN},
    {"left", OrbisPadButtonDataOffset::ORBIS_PAD_BUTTON_LEFT},
    {"right", OrbisPadButtonDataOffset::ORBIS_PAD_BUTTON_RIGHT},
    {"leftjoystick_halfmode", LEFTJOYSTICK_HALFMODE},
    {"rightjoystick_halfmode", RIGHTJOYSTICK_HALFMODE},
};
const std::map<std::string, AxisMapping> string_to_axis_map = {
    {"axis_left_x_plus", {Input::Axis::LeftX, 127}},
    {"axis_left_x_minus", {Input::Axis::LeftX, -127}},
    {"axis_left_y_plus", {Input::Axis::LeftY, 127}},
    {"axis_left_y_minus", {Input::Axis::LeftY, -127}},
    {"axis_right_x_plus", {Input::Axis::RightX, 127}},
    {"axis_right_x_minus", {Input::Axis::RightX, -127}},
    {"axis_right_y_plus", {Input::Axis::RightY, 127}},
    {"axis_right_y_minus", {Input::Axis::RightY, -127}},
    {"l2", {Axis::TriggerLeft, 127}},
    {"r2", {Axis::TriggerRight, 127}},
};
const std::map<std::string, u32> string_to_keyboard_key_map = {
    {"a", SDLK_A},
    {"b", SDLK_B},
    {"c", SDLK_C},
    {"d", SDLK_D},
    {"e", SDLK_E},
    {"f", SDLK_F},
    {"g", SDLK_G},
    {"h", SDLK_H},
    {"i", SDLK_I},
    {"j", SDLK_J},
    {"k", SDLK_K},
    {"l", SDLK_L},
    {"m", SDLK_M},
    {"n", SDLK_N},
    {"o", SDLK_O},
    {"p", SDLK_P},
    {"q", SDLK_Q},
    {"r", SDLK_R},
    {"s", SDLK_S},
    {"t", SDLK_T},
    {"u", SDLK_U},
    {"v", SDLK_V},
    {"w", SDLK_W},
    {"x", SDLK_X},
    {"y", SDLK_Y},
    {"z", SDLK_Z},
    {"0", SDLK_0},
    {"1", SDLK_1},
    {"2", SDLK_2},
    {"3", SDLK_3},
    {"4", SDLK_4},
    {"5", SDLK_5},
    {"6", SDLK_6},
    {"7", SDLK_7},
    {"8", SDLK_8},
    {"9", SDLK_9},
    {"kp0", SDLK_KP_0},
    {"kp1", SDLK_KP_1},
    {"kp2", SDLK_KP_2},
    {"kp3", SDLK_KP_3},
    {"kp4", SDLK_KP_4},
    {"kp5", SDLK_KP_5},
    {"kp6", SDLK_KP_6},
    {"kp7", SDLK_KP_7},
    {"kp8", SDLK_KP_8},
    {"kp9", SDLK_KP_9},
    {"comma", SDLK_COMMA},
    {"period", SDLK_PERIOD},
    {"question", SDLK_QUESTION},
    {"semicolon", SDLK_SEMICOLON},
    {"minus", SDLK_MINUS},
    {"underscore", SDLK_UNDERSCORE},
    {"lparenthesis", SDLK_LEFTPAREN},
    {"rparenthesis", SDLK_RIGHTPAREN},
    {"lbracket", SDLK_LEFTBRACKET},
    {"rbracket", SDLK_RIGHTBRACKET},
    {"lbrace", SDLK_LEFTBRACE},
    {"rbrace", SDLK_RIGHTBRACE},
    {"backslash", SDLK_BACKSLASH},
    {"dash", SDLK_SLASH},
    {"enter", SDLK_RETURN},
    {"space", SDLK_SPACE},
    {"tab", SDLK_TAB},
    {"backspace", SDLK_BACKSPACE},
    {"escape", SDLK_ESCAPE},
    {"left", SDLK_LEFT},
    {"right", SDLK_RIGHT},
    {"up", SDLK_UP},
    {"down", SDLK_DOWN},
    {"lctrl", SDLK_LCTRL},
    {"rctrl", SDLK_RCTRL},
    {"lshift", SDLK_LSHIFT},
    {"rshift", SDLK_RSHIFT},
    {"lalt", SDLK_LALT},
    {"ralt", SDLK_RALT},
    {"lmeta", SDLK_LGUI},
    {"rmeta", SDLK_RGUI},
    {"lwin", SDLK_LGUI},
    {"rwin", SDLK_RGUI},
    {"home", SDLK_HOME},
    {"end", SDLK_END},
    {"pgup", SDLK_PAGEUP},
    {"pgdown", SDLK_PAGEDOWN},
    {"leftbutton", SDL_BUTTON_LEFT},
    {"rightbutton", SDL_BUTTON_RIGHT},
    {"middlebutton", SDL_BUTTON_MIDDLE},
    {"sidebuttonback", SDL_BUTTON_X1},
    {"sidebuttonforward", SDL_BUTTON_X2},
    {"mousewheelup", SDL_MOUSE_WHEEL_UP},
    {"mousewheeldown", SDL_MOUSE_WHEEL_DOWN},
    {"mousewheelleft", SDL_MOUSE_WHEEL_LEFT},
    {"mousewheelright", SDL_MOUSE_WHEEL_RIGHT},
    {"kpperiod", SDLK_KP_PERIOD},
    {"kpcomma", SDLK_KP_COMMA},
    {"kpdivide", SDLK_KP_DIVIDE},
    {"kpmultiply", SDLK_KP_MULTIPLY},
    {"kpminus", SDLK_KP_MINUS},
    {"kpplus", SDLK_KP_PLUS},
    {"kpenter", SDLK_KP_ENTER},
    {"kpequals", SDLK_KP_EQUALS},
    {"capslock", SDLK_CAPSLOCK},
};

// literally the only flag that needs external access
void toggleMouseEnabled();

// i wrapped it in a function so I can collapse it
std::string_view getDefaultKeyboardConfig();

void parseInputConfig(const std::string game_id);

class InputBinding {
public:
    u32 key1, key2, key3;
    InputBinding(u32 k1 = SDLK_UNKNOWN, u32 k2 = SDLK_UNKNOWN, u32 k3 = SDLK_UNKNOWN) {
        // we format the keys so comparing them will be very fast, because we will only have to
        // compare 3 sorted elements, where the only possible duplicate item is 0

        // duplicate entries get changed to one original, one null
        if (k1 == k2 && k1 != SDLK_UNKNOWN) {
            k2 = 0;
        }
        if (k1 == k3 && k1 != SDLK_UNKNOWN) {
            k3 = 0;
        }
        if (k3 == k2 && k2 != SDLK_UNKNOWN) {
            k2 = 0;
        }
        // this sorts them
        if (k1 <= k2 && k1 <= k3) {
            key1 = k1;
            if (k2 <= k3) {
                key2 = k2;
                key3 = k3;
            } else {
                key2 = k3;
                key3 = k2;
            }
        } else if (k2 <= k1 && k2 <= k3) {
            key1 = k2;
            if (k1 <= k3) {
                key2 = k1;
                key3 = k3;
            } else {
                key2 = k3;
                key3 = k1;
            }
        } else {
            key1 = k3;
            if (k1 <= k2) {
                key2 = k1;
                key3 = k2;
            } else {
                key2 = k2;
                key3 = k1;
            }
        }
    }
    // copy ctor
    InputBinding(const InputBinding& o) : key1(o.key1), key2(o.key2), key3(o.key3) {}

    inline bool operator==(const InputBinding& o) {
        // 0 = SDLK_UNKNOWN aka unused slot
        return (key3 == o.key3 || key3 == 0 || o.key3 == 0) &&
               (key2 == o.key2 || key2 == 0 || o.key2 == 0) &&
               (key1 == o.key1 || key1 == 0 || o.key1 == 0);
        // it is already very fast,
        // but reverse order makes it check the actual keys first instead of possible 0-s,
        // potenially skipping the later expressions of the three-way AND
    }
    inline int keyCount() const {
        return (key1 ? 1 : 0) + (key2 ? 1 : 0) + (key3 ? 1 : 0);
    }
    // Sorts by the amount of non zero keys - left side is 'bigger' here
    bool operator<(const InputBinding& other) const {
        return keyCount() > other.keyCount();
    }
    inline bool isEmpty() {
        return key1 == 0 && key2 == 0 && key3 == 0;
    }
    std::string toString() const {
        return fmt::format("({}, {}, {})", key1, key2, key3);
    }

    // returns a u32 based on the event type (keyboard, mouse buttons, or wheel)
    static u32 getInputIDFromEvent(const SDL_Event& e);
};
class ControllerOutput {
    static GameController* controller;

public:
    static void setControllerOutputController(GameController* c);

    u32 button;
    Axis axis;
    int axis_value;

    ControllerOutput(const u32 b, Axis a = Axis::AxisMax) {
        button = b;
        axis = a;
        axis_value = 0;
    }
    ControllerOutput(const ControllerOutput& o) : button(o.button), axis(o.axis) {}
    inline bool operator==(const ControllerOutput& o) const { // fucking consts everywhere
        return button == o.button && axis == o.axis;
    }
    inline bool operator!=(const ControllerOutput& o) const {
        return button != o.button || axis != o.axis;
    }
    std::string toString() const {
        return fmt::format("({}, {}, {})", button, (int)axis, axis_value);
    }
    inline bool isButton() const {
        return axis == Axis::AxisMax && button != 0;
    }
    inline bool isAxis() const {
        return axis != Axis::AxisMax && button == 0;
    }
    void update(bool pressed, u32 param = 0);
    // Off events are not counted
    void addUpdate(bool pressed, u32 param = 0);
};
class BindingConnection {
public:
    InputBinding binding;
    ControllerOutput* output;
    u32 parameter;
    BindingConnection(InputBinding b, ControllerOutput* out, u32 param = 0) {
        binding = b;
        parameter = param; // bruh this accidentally set to be 0 no wonder it didn't do anything

        // todo: check if out is in the allowed array
        output = out;
    }
    bool operator<(const BindingConnection& other) const {
        // a button is a higher priority than an axis, as buttons can influence axes
        // (e.g. joystick_halfmode)
        if( output->isButton() && other.output->isAxis()) {
            return true;
        }
        if (binding < other.binding) {
            return true;
        }
        return false;
        
    }
};

// Check if the 3 key input is currently active.
bool checkForInputDown(InputBinding i);

// Add/remove the input that generated the event to/from the held keys container.
void updatePressedKeys(u32 button, bool is_pressed);

void activateOutputsFromInputs();

void updateMouse(GameController* controller);

// Polls the mouse for changes, and simulates joystick movement from it.
Uint32 mousePolling(void* param, Uint32 id, Uint32 interval);

} // namespace Input