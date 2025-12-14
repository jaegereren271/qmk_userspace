// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Thumb Keys
#define L_THUMB LT(_RAISE, KC_ENTER)
#define R_THUMB LT(_LOWER, KC_SPACE)

#define G_RAISE LT(_RAISE, KC_LGUI)
#define G_LOWER LT(_LOWER, KC_RGUI)

// Rotary
#define L_ROT KC_MPLY
#define R_ROT KC_MUTE

// Custom Mod Keys
#define KC_PRVWD C(KC_LEFT)
#define KC_NXTWD C(KC_RIGHT)
#define KC_DLINE C(KC_BSPC)
#define KC_TERM  RGUI(KC_ENTER)

// Layer Keys
#define KC_QWRTY DF(_QWRTY)
#define KC_CLMK  DF(_CLMK)
#define KC_GAME  DF(_GAME)
#define KC_MEDIA TG(_MEDIA)

// International Keys Alias
#define KC_KANA KC_INT2
#define KC_HENK KC_INT4

enum coral_layers {
    _QWRTY,
    _CLMK,
    _GAME,
    _MEDIA,
    _LOWER,
    _RAISE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWRTY] = LAYOUT(
        QK_GESC,  KC_1, KC_2,    KC_3,    KC_4,    KC_5,            /**/        KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_QUOT,
        KC_TAB,   KC_Q, KC_W,    KC_E,    KC_R,    KC_T,            /**/        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_MINS,
        KC_LCTL,  KC_A, KC_S,    KC_D,    KC_F,    KC_G,            /**/        KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_BSPC,
        KC_LSFT,  KC_Z, KC_X,    KC_C,    KC_V,    KC_B,    L_ROT,  /**/ R_ROT, KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                        KC_LGUI, KC_LALT, KC_LCTL, L_THUMB,         /**/        R_THUMB, KC_RCTL, KC_RALT, KC_RGUI
    ),
    [_CLMK] = LAYOUT(
        QK_GESC,  KC_1, KC_2,    KC_3,    KC_4,    KC_5,           /**/        KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_QUOT,
        KC_TAB,   KC_Q, KC_W,    KC_F,    KC_P,    KC_G,           /**/        KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN, KC_MINS,
        KC_LCTL,  KC_A, KC_R,    KC_S,    KC_T,    KC_D,           /**/        KC_H,    KC_N,    KC_E,    KC_I,   KC_O,    KC_BSPC,
        KC_LSFT,  KC_Z, KC_X,    KC_C,    KC_V,    KC_B,    L_ROT, /**/ R_ROT, KC_K,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                        KC_LGUI, KC_LALT, KC_LCTL, L_THUMB,        /**/        R_THUMB, KC_RCTL, KC_RALT, KC_RGUI
    ),
    [_GAME] = LAYOUT(
        QK_GESC,  KC_1, KC_2,    KC_3,    KC_4,     KC_5,            /**/        KC_6,     KC_7,     KC_8,    KC_9,   KC_0,    KC_QUOT,
        KC_TAB,   KC_Q, KC_W,    KC_E,    KC_R,     KC_T,            /**/        KC_Y,     KC_U,     KC_I,    KC_O,   KC_P,    KC_MINS,
        KC_LCTL,  KC_A, KC_S,    KC_D,    KC_F,     KC_G,            /**/        KC_H,     KC_J,     KC_K,    KC_L,   KC_SCLN, KC_BSPC,
        KC_LSFT,  KC_Z, KC_X,    KC_C,    KC_V,     KC_B,    L_ROT,  /**/ R_ROT, KC_N,     KC_M,     KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                        G_RAISE, KC_LCTL, KC_SPACE, KC_LALT,         /**/        KC_RALT,  KC_ENTER, KC_RCTL, G_LOWER
    ),
    [_MEDIA] = LAYOUT(
        _______, _______, _______, _______,  _______, _______,          /**/          _______, _______, _______, _______, _______, _______,
        _______, KC_MPLY, KC_UP,   _______,  _______, _______,          /**/          _______, _______, _______, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,          /**/          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,  _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, _______,
                          _______, _______,  _______, _______,          /**/          _______, _______, _______, _______ 
    ),
    [_LOWER] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            /**/          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             /**/          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,          /**/          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
        _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______, /**/ _______, KC_LBRC, KC_RBRC, KC_QUOT, KC_DQUO, KC_BSLS, _______,
                          _______, _______, _______, _______,          /**/          _______, _______, _______, QK_BOOT
    ),
    [_RAISE] = LAYOUT(
        _______, KC_QWRTY, KC_CLMK, KC_GAME,  KC_MEDIA, _______,          /**/          _______, _______,  _______, _______,  _______,  _______,
        _______, MS_BTN1,  MS_UP,   MS_BTN2,  KC_INS,   MS_WHLU,          /**/          KC_PGUP, KC_PRVWD, KC_UP,   KC_NXTWD, KC_DLINE, KC_BSPC,
        _______, MS_LEFT,  MS_DOWN, MS_RGHT,  KC_PSCR,  MS_WHLD,          /**/          KC_PGDN, KC_LEFT,  KC_DOWN, KC_RGHT,  KC_DEL,   KC_TERM,
        _______, KC_UNDO,  KC_CUT,  KC_COPY,  KC_PASTE, KC_KANA, _______, /**/ _______, KC_HENK, KC_HOME,  XXXXXXX, KC_END,   XXXXXXX,  _______,
                           _______, _______,   _______, _______,          /**/          _______, _______,  _______, _______
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWRTY] = { ENCODER_CCW_CW(KC_BRID, KC_BRIU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_CLMK] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_GAME] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_MEDIA] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_LOWER] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_RAISE] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};
#endif

void keyboard_post_init_user(void) {
  debug_enable=true;
}
