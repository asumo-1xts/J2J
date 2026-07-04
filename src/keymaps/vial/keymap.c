#include QMK_KEYBOARD_H
#include "keymap.h"

/**
 * ==============================
 * 内部変数・内部関数の定義
 * ==============================
 */

void yawn(void) {
  uint8_t hue = rgblight_get_hue();
  uint8_t sat = rgblight_get_sat();
  uint8_t val = rgblight_get_val();

  for (int16_t i = 0; i <= RGBLIGHT_LIMIT_VAL; i += RGBLIGHT_VAL_STEP) {
    rgblight_sethsv_noeeprom(hue, sat, i);
    wait_ms(30);
  }
  for (int16_t i = RGBLIGHT_LIMIT_VAL; i >= 0; i -= RGBLIGHT_VAL_STEP) {
    rgblight_sethsv_noeeprom(hue, sat, i);
    wait_ms(30);
  }

  rgblight_sethsv_noeeprom(hue, sat, 0);    // いったん消灯
  wait_ms(60);
  rgblight_sethsv_noeeprom(hue, sat, val);  // 点灯
}

/**
 * ==============================
 * QMKで用意されているAPI
 * ==============================
 */

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom();
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
  rgblight_sethsv_noeeprom(HSV_TURQUOISE);
  yawn();
}

// ===============================

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case _MI:
      rgblight_sethsv_noeeprom(HSV_RED);
      break;
    default:
      rgblight_sethsv_noeeprom(HSV_TURQUOISE);
      break;
  }
  return state;
}

/**
 * ==============================
 * ファームウェア容量削減
 * ==============================
 */

// Magic機能は使わないので上書き
uint16_t keycode_config(uint16_t keycode) { return keycode; }
uint8_t mod_config(uint8_t mod) { return mod; }
