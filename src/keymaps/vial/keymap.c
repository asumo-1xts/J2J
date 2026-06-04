#include QMK_KEYBOARD_H

#define TTTT KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        MO(1),  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
        KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_PSCR,KC_NO,  KC_NO,
        KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,
        KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_GRV, KC_BSPC,KC_NO,
                KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,
        KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_ENT, KC_NO,
                KC_LCTL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_BSLS,        KC_HOME, 
                KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,
        KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,        KC_UP,  KC_END,
                MO(1),  KC_LWIN,KC_LALT,KC_LNG1,KC_SPC,
                KC_SPC, KC_LNG2,KC_RWIN,MO(1),  KC_LEFT,        KC_DOWN,KC_RGHT
    ),
    [1] = LAYOUT(
        TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,
        TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,
        TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,
        TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   KC_DEL, TTTT,
                TTTT,   TTTT,   KC_UP,  TTTT,   TTTT,   TTTT,
        TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,
                KC_DEL, KC_LEFT,KC_DOWN,KC_RGHT,TTTT,   TTTT,
        TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,           TTTT,
                KC_ENT, TTTT,   TTTT,   TTTT,   TTTT,   TTTT,
        TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   KC_CAPS,        TTTT,   TTTT,
                TTTT,   TTTT,   TTTT,   TTTT,   TTTT,
                TTTT,   TTTT,   TTTT,   TTTT,   TTTT,           TTTT,   TTTT
    )
};

// 電源投入時に走る関数
void keyboard_post_init_user(void) {
	_delay_ms(50); // 安定化を待つ
    matrix_scan();

    // 9行3列のLキーが押されているかを確認
    // もしTrueならLEDを点灯
    if (matrix_get_row(9) & (1 << 3)) {
        rgblight_enable_noeeprom();
        for (int i = 0; i < 37; i++) { // 左手側
            rgblight_sethsv_at(180, 97, 57, i); 
        }
        for (int i = 37; i < 87; i++) { // 右手側
            rgblight_sethsv_at(180, 97, 57, i); 
        }
    }
}

// Magic機能を使わないので、容量を削減するため上書きする
uint16_t keycode_config(uint16_t keycode) {return keycode;}
uint8_t mod_config(uint8_t mod) {return mod;}