/**
 * ==============================
 * RGBライトのカラー設定
 * ==============================
 */

const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {30};

/**
 * ==============================
 * キーマップの定義
 * ==============================
 */

#define _BS 0
#define _FN 1
#define _MI 2
#define TTTT KC_TRNS
#define NNNN KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BS] = LAYOUT(
        MO(_FN),KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
        KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_PSCR,NNNN,   TG(_MI),
        KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,
        KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_GRV, KC_BSPC,NNNN,
                KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,
        KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_ENT, MS_BTN1,
                KC_LCTL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_BSLS,        KC_HOME,
                KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,
        KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,        KC_UP,  KC_END,
                NNNN,   KC_LGUI,KC_LALT,KC_LNG2,KC_SPC,
                KC_SPC, KC_LNG1,KC_RGUI,MO(_FN),KC_LEFT,        KC_DOWN,KC_RGHT
    ),
    [_FN] = LAYOUT(
        TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,
        TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,
        TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,
        TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   KC_DEL, TTTT,
                TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,
        TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   MS_BTN3,MS_BTN2,
                KC_ENT, TTTT,   TTTT,   TTTT,   TTTT,   TTTT,
        TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,           MS_WHLU,
                KC_DEL, TTTT,   TTTT,   TTTT,   TTTT,   TTTT,
        TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,           MS_UP,  MS_WHLD,
                NNNN,   TTTT,   TTTT,   TTTT,   TTTT,
                TTTT,   TTTT,   TTTT,   TTTT,   MS_LEFT,        MS_DOWN,MS_RGHT
    ),
    [_MI] = LAYOUT(
        TTTT,   MI_CH1, MI_CH2, MI_CH3, MI_CH4, MI_CH5, MI_CH6,
        MI_CH7, MI_CH8, MI_CH9, MI_CH10,MI_CH11,MI_CH12,TTTT,   TTTT,   TTTT,
        TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,
        TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,
                TTTT,   TTTT,   MI_Cs,  MI_Ds,  TTTT,   MI_Fs,
        MI_Gs,  MI_As,  TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,
                TTTT,   MI_C,   MI_D,   MI_E,   MI_F,   MI_G,
        MI_A,   MI_B,   MI_C,   TTTT,   TTTT,   TTTT,   TTTT,           MI_OCTU,
                TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,
        TTTT,   TTTT,   TTTT,   TTTT,   TTTT,   TTTT,           MI_MODU,MI_OCTD,
                TTTT,   TTTT,   TTTT,   TTTT,   TTTT,
                TTTT,   TTTT,   TTTT,   TTTT,   MI_BNDD,        MI_MODD,MI_BNDU
    )
};

/**
 * ==============================
 * note: LEDの物理的な順番
 * ==============================
 */

// 2,      3,      4,      5,      6,      7,      8,                
// 80,     81,     82,     83,     84,     85,     86,     39,     40,
// 1,      0,      13,     12,     11,     10,     9,                 
// 79,     78,     77,     76,     75,     74,     73,     38,     41,
//         14,     15,     16,     17,     18,     19,                
// 66,     67,     68,     69,     70,     71,     72,     37,     42,
//         36,     24,     23,     22,     21,     20,                
// 65,     64,     63,     62,     61,     60,     59,             43,
//         35,     25,     26,     27,     28,     29,                
// 53,     54,     55,     56,     57,     58,             46,     44,
//         34,     33,     32,     31,     30,                             
//         52,     51,     50,     49,     48,             47,     45