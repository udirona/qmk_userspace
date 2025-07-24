// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
//

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
#include "rgblight.h"

#define CG_LEFT C(G(KC_LEFT))
#define CG_RIGHT C(G(KC_RIGHT))
#define DESKTOP G(KC_D)
#define LOCKWIN G(KC_L)
#define EN_MUTE LT(l_sys, KC_AUDIO_MUTE)

enum layers {
    l_base,
    l_number,
    l_symbol,
    l_navi,
    l_macro,
    l_sys
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[l_base] = LAYOUT_ortho_3x4(
 //---------|---------|---------|---------|
    BASE_1_1, BASE_1_2, BASE_1_3, BASE_1_4,
 //---------|---------|---------|---------|
    BASE_2_1, BASE_2_2, BASE_2_3, BASE_2_4,
 //---------|---------|---------|---------|
    EN_MUTE,        IT,       OT,  XXXXXXX
    ),

[l_number] = LAYOUT_ortho_3x4(
 //---------|---------|---------|---------|
        KC_1,     KC_2,     KC_3,     KC_4,
 //---------|---------|---------|---------|
        KC_5,     KC_6,     KC_7,     KC_8,
 //---------|---------|---------|---------|
     KC_TRNS,  KC_TRNS,  KC_TRNS,  XXXXXXX
    ),

[l_symbol] = LAYOUT_ortho_3x4(
 //---------|---------|---------|---------|
     KC_EXLM,    KC_AT,  KC_HASH,  KC_PERC,
 //---------|---------|---------|---------|
     KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,
 //---------|---------|---------|---------|
     KC_TRNS,  KC_TRNS,  KC_TRNS,  XXXXXXX
    ),

[l_navi] = LAYOUT_ortho_3x4(
 //---------|---------|---------|---------|
       KC_NO,  KC_HOME,    KC_UP,   KC_END,
 //---------|---------|---------|---------|
       KC_NO,  KC_LEFT,  KC_DOWN, KC_RIGHT,
 //---------|---------|---------|---------|
       KC_NO,    KC_NO,   KC_DEL,  XXXXXXX
    ),

[l_macro] = LAYOUT_ortho_3x4(
 //---------|---------|---------|---------|
     LOCKWIN,    KC_NO,    KC_NO,    KC_NO,
 //---------|---------|---------|---------|
       KC_NO,  CG_LEFT,  DESKTOP, CG_RIGHT,
 //---------|---------|---------|---------|
       KC_NO,    KC_NO,    KC_NO,  XXXXXXX
    ),

[l_sys] = LAYOUT_ortho_3x4(
 //---------|---------|---------|---------|
     QK_BOOT,    KC_NO,    KC_NO,    KC_NO,
 //---------|---------|---------|---------|
       KC_NO,    KC_NO,    KC_NO,    KC_NO,
 //---------|---------|---------|---------|
       KC_NO,    KC_NO,    KC_NO,  XXXXXXX
    )
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [l_base]   = { ENCODER_CCW_CW(KC_DOWN, KC_UP) },
    [l_number] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [l_symbol] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [l_navi]   = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [l_macro]  = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [l_sys]    = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) }
};
#endif

// ws2812_setleds(rgb_led_t *ledarray, uint16_t number_of_leds)
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case l_base:
        rgblight_setrgb (0x00,  0x00, 0xFF);
        break;
    case l_number:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    case l_symbol:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    case l_navi:
        rgblight_setrgb (0x7A,  0x00, 0xFF);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    }
  return state;
}

