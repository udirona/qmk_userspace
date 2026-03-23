// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
//

#include QMK_KEYBOARD_H
#include "rgblight.h"

enum layers {
    l0,
    l1,
    l2,
    l3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[l0] = LAYOUT_ortho_3x4(
 //---------|---------|---------|---------|
    KC_A    , KC_B    , KC_C    , KC_D    ,
 //---------|---------|---------|---------|
    KC_E    , KC_F    , KC_G    , KC_H    ,
 //---------|---------|---------|---------|
    MO(3),      KC_0,     KC_1,  XXXXXXX
    ),

[l1] = LAYOUT_ortho_3x4(
 //---------|---------|---------|---------|
        KC_1,     KC_2,     KC_3,     KC_4,
 //---------|---------|---------|---------|
        KC_5,     KC_6,     KC_7,     KC_8,
 //---------|---------|---------|---------|
     KC_TRNS,  KC_TRNS,  KC_TRNS,  XXXXXXX
    ),

[l2] = LAYOUT_ortho_3x4(
 //---------|---------|---------|---------|
     QK_BOOT,    KC_NO,    KC_NO,    KC_NO,
 //---------|---------|---------|---------|
       KC_NO,    KC_NO,    KC_NO,    KC_NO,
 //---------|---------|---------|---------|
       KC_NO,    KC_NO,    KC_NO,  XXXXXXX
    ),

[l3] = LAYOUT_ortho_3x4(
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
    [l0]   = { ENCODER_CCW_CW(KC_DOWN, KC_UP) },
    [l1] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [l2] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [l3]   = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) }
};
#endif

// ws2812_setleds(rgb_led_t *ledarray, uint16_t number_of_leds)
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case l0:
        rgblight_setrgb (0x00,  0x00, 0xFF);
        break;
    case l1:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    case l2:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    case l3:
        rgblight_setrgb (0x7A,  0x00, 0xFF);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    }
  return state;
}

