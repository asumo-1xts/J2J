#include QMK_KEYBOARD_H

#define TTTT KC_TRNS

// HSV_CORAL
const uint8_t HUE = 11;
const uint8_t SAT = 176;
const uint8_t VAL = 127;

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
        TTTT,   TTTT,   TTTT,   UG_VALU,TTTT,   TTTT,   TTTT,           TTTT,
                KC_ENT, TTTT,   TTTT,   TTTT,   TTTT,   TTTT,
        TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   KC_CAPS,        TTTT,   TTTT,
                TTTT,   TTTT,   TTTT,   TTTT,   TTTT,
                TTTT,   TTTT,   TTTT,   TTTT,   TTTT,           TTTT,   TTTT
    )
};

void yawn(uint8_t hue, uint8_t sat, uint8_t val) {
   	for (int16_t i = 0; i <= RGBLIGHT_LIMIT_VAL; i += RGBLIGHT_VAL_STEP) {
		rgblight_sethsv_noeeprom(hue, sat, i);
		wait_ms(30);
	}
	for (int16_t i = RGBLIGHT_LIMIT_VAL; i >= 0; i -= RGBLIGHT_VAL_STEP) {
		rgblight_sethsv_noeeprom(hue, sat, i);
		wait_ms(30);
	}

	rgblight_sethsv_noeeprom(hue, sat, 0); // いったん消灯
	wait_ms(60);
	rgblight_sethsv_noeeprom(hue, sat, val); // 最終的な明るさ
}

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
	yawn(HUE, SAT, VAL);
}

// Magic機能を使わないので、容量を削減するため上書きする
uint16_t keycode_config(uint16_t keycode) {return keycode;}
uint8_t mod_config(uint8_t mod) {return mod;}

static uint32_t key_timer;           // timer for last keyboard activity, use 32bit value and function to make longer idle time possible
static void refresh_rgb(void);       // refreshes the activity timer and RGB, invoke whenever any activity happens
static void check_rgb_timeout(void); // checks if enough time has passed for RGB to timeout
bool is_rgb_timeout = false;         // store if RGB has timed out or not in a boolean

void refresh_rgb(void) {
    key_timer = timer_read32(); // store time of last refresh
    if (is_rgb_timeout)
    {
        is_rgb_timeout = false;
        rgblight_wakeup();
    }
}
void check_rgb_timeout(void) {
    if (!is_rgb_timeout && timer_elapsed32(key_timer) > RGBLIGHT_TIMEOUT) // check if RGB has already timeout and if enough time has passed
    {
        rgblight_suspend();
        is_rgb_timeout = true;
    }
}
/* Then, call the above functions from QMK's built in post processing functions like so */
/* Runs at the end of each scan loop, check if RGB timeout has occurred or not */
void housekeeping_task_user(void) {
#ifdef RGBLIGHT_TIMEOUT
    check_rgb_timeout();
#endif
}
/* Runs after each key press, check if activity occurred */
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef RGBLIGHT_TIMEOUT
    if (record->event.pressed)
        refresh_rgb();
#endif
}
/* Runs after each encoder tick, check if activity occurred */
void post_encoder_update_user(uint8_t index, bool clockwise) {
#ifdef RGBLIGHT_TIMEOUT
    refresh_rgb();
#endif
}
