// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESCAPE,      KC_1,   KC_2,   KC_3,   KC_4,   KC_5,
        KC_TAB,         KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,
        KC_LEFT_CTRL,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        KC_LEFT_SHIFT,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_6,
        MO(1), KC_LEFT_ALT, KC_LEFT_GUI, KC_LANGUAGE_1, KC_SPACE
    ),
    [1] = LAYOUT(
        KC_TRNS,    KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_F5,
        KC_TRNS,    KC_TRNS,    KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,    KC_LEFT,    KC_DOWN, KC_RIGHT,KC_TRNS, KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_F6,
        KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
    )
};
