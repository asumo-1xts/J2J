// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define LED_LAYER_2 D2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC, KC_1,   KC_2,   KC_3,       KC_4,       KC_5,
        KC_TAB, KC_Q,   KC_W,   KC_E,       KC_R,       KC_T,
        KC_LCTL,KC_A,   KC_S,   KC_D,       KC_F,       KC_G,
        KC_LSFT,KC_Z,   KC_X,   KC_C,       KC_V,       KC_6,
        MO(1),  KC_LALT,KC_LWIN,KC_LNG1,    KC_SPACE,
        KC_7,   KC_8,   KC_9,   KC_0,       KC_MINUS,   KC_EQUAL,       KC_GRAVE,
        KC_Y,   KC_U,   KC_I,   KC_O,       KC_P,       KC_LBRC,        KC_RBRC,
        KC_H,   KC_J,   KC_K,   KC_L,       KC_SCLN,    KC_QUOTE,       KC_BSLS,
        KC_B,   KC_N,   KC_M,   KC_COMM,    KC_DOT,     KC_SLASH,       KC_RIGHT_SHIFT,
        KC_SPC, KC_LNG2,KC_LGUI,MO(1),      KC_LEFT,    KC_DOWN,        KC_UP,
        KC_BSPC,KC_ENT, KC_HOME,KC_END,     KC_RIGHT,   KC_PSCR,        KC_NO
    ),
    [1] = LAYOUT(
        KC_TRNS,KC_F1,  KC_F2,  KC_F3,      KC_F4,      KC_F5,
        KC_TRNS,KC_TRNS,KC_UP,  KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_DEL, KC_LEFT,KC_DOWN,KC_RIGHT,   KC_TRNS,    KC_TRNS,
        KC_ENT, KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,    KC_F6,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,
        KC_F7,  KC_F8,  KC_F9,  KC_F10,     KC_F11,     KC_F12,         KC_TRNS,
        KC_TRNS,KC_TRNS,KC_UP,  KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,    C(S(KC_SLASH)), KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
        KC_DEL, KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS
    ),
    [2] = LAYOUT(
        MI_AOFF,MI_CH1, MI_CH2, MI_CH3,     MI_CH4,     MI_CH5,
        KC_NO,  MI_OC0, MI_OCTU,KC_NO,      KC_NO,      KC_NO,
        KC_NO,  MI_MODD,MI_OCTD,MI_MODU,    KC_NO,      KC_NO,
        MI_SUST,MI_BNDD,MI_BNDU,KC_NO,      KC_NO,      MI_CH6,
        KC_NO,  KC_NO,  KC_NO,  MI_OFF,     KC_NO,
        MI_CH7, MI_CH8, MI_CH9, MI_CH10,    MI_CHND,    MI_CHNU,        KC_NO,
        KC_NO,  MI_Cs,  MI_Ds,  KC_NO,      MI_Fs,      MI_Gs,          MI_As,
        MI_C,   MI_D,   MI_E,   MI_F,       MI_G,       MI_A,           MI_B,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,      KC_NO,          KC_NO,
        KC_NO,  MI_ON,  KC_NO,  KC_NO,      KC_NO,      KC_NO,          KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,      KC_NO,          KC_NO
    )
};

void keyboard_post_init_user(void) {
    wait_ms(50);    // 電圧とスキャンの安定を待つ
    setPinOutput(LED_LAYER_2);
    matrix_scan();

    // 8行2列のMキーが押されているかを確認
    if (matrix_get_row(8) & (1 << 2)) {
        set_single_default_layer(2);    // レイヤー2をデフォルトに設定
    }
}

// デフォルトレイヤーが変わったときに呼ばれる関数
layer_state_t default_layer_state_set_user(layer_state_t state) {
    // デフォルトレイヤーが2なら点灯、それ以外なら消灯
    if (get_highest_layer(state) == 2) {
        writePinHigh(LED_LAYER_2);
    } else {
        writePinLow(LED_LAYER_2);
    }
    return state;
}

// Magic機能を使わないので、容量を削減するため上書きする
uint16_t keycode_config(uint16_t keycode) {return keycode;}
uint8_t mod_config(uint8_t mod) {return mod;}