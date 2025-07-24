/* Copyright 2025 udirona
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the impliesd warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define CG_LEFT C(G(KC_LEFT))
#define CG_RIGHT C(G(KC_RIGHT))
#define DESKTOP G(KC_D)
#define LOCKWIN G(KC_L)

#define LT_LOW_D LT(LOWER, KC_DOT)
#define RC_ENT RCTL_T(KC_ENT)
#define CC_A LCTL_T(KC_A)
#define LT_LOW_Z LT(LOWER, KC_Z)

//home row mod colmak
#define CC_O LCTL_T(KC_O)

//home row mods default
#define CC_F LSFT_T(KC_F)
#define CC_J RSFT_T(KC_J)
//home row mods colmak
#define CC_T LSFT_T(KC_T)
#define CC_N RSFT_T(KC_N)

#define CA_F1 C(A(KC_F1))
#define CA_F2 C(A(KC_F2))
#define CA_F3 C(A(KC_F3))
#define C__F1 C(KC_F1)
#define C__F2 C(KC_F2)
#define C__F3 C(KC_F3)
#define C__F9 C(KC_F9)
#define C__F12 C(KC_F12)
#define CG_L C(G(KC_LEFT))
#define CG_R C(G(KC_RGHT))

const uint16_t PROGMEM cm_tab[]  = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cm_esc[]  = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cm_bspc[] = {KC_O, KC_P, COMBO_END};

combo_t key_combos[] = {
//    COMBO(cm_bspc, KC_BSPC),
//    COMBO(cm_esc,  KC_ESC),
//    COMBO(cm_tab,  KC_TAB),
};

enum layers {
    BASE,
    COLMAK,
    LOWER,
    SYMBL,
    MACRO
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_long_space(
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,
  //|---------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         CC_A,     KC_S,    KC_D,    CC_F,    KC_G,    KC_H,    CC_J,    KC_K,    KC_L,  RC_ENT,
  //|-------------+--------+--------+--------+--------+--------+--------+--------+-------------|
          LT_LOW_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,     LT_LOW_D,
  //|---------+---------+---------+------------------------------+---------+---------+---------|
     MO(SYMBL),  KC_LGUI,   KC_LALT,        LSFT_T(KC_SPC),         KC_RALT, MO(MACRO),MO(SYMBL)
    ),

    [COLMAK] = LAYOUT_long_space(
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
         KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,   KC_ENT,
  //|---------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
          CC_A,    KC_R,    KC_S,    CC_T,    KC_G,    KC_M,    CC_N,    KC_E,    KC_I,    CC_O,
  //|-------------+--------+--------+--------+--------+--------+--------+--------+-------------|
          LT_LOW_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H, KC_COMM,     LT_LOW_D,
  //|---------+---------+---------+------------------------------+---------+---------+---------|
     MO(SYMBL),  KC_LGUI,  KC_LALT,        LSFT_T(KC_SPC),          KC_RALT, MO(MACRO),MO(SYMBL)
    ),

    [LOWER] = LAYOUT_long_space(
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
         KC_1,    KC_2,     KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,
  //|---------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        KC_TAB, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_DEL,
  //|-------------+--------+--------+--------+--------+--------+--------+--------+-------------|
            KC_ESC, _______,  _______, _______, _______, _______, _______, _______,     _______,
  //|---------+---------+---------+------------------------------+---------+---------+---------|
       _______,  _______,  _______,         KC_BSPC,                _______,  _______,   _______
    ),

    [SYMBL] = LAYOUT_long_space(
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
      S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9),  S(KC_0),
  //|---------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      KC_GRAVE, KC_TILD, KC_SCLN, KC_QUOT, KC_DQUO, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_COLN,
  //|-------------+--------+--------+--------+--------+--------+--------+--------+-------------|
           KC_LCBR, KC_RCBR, KC_QUES, KC_BSLS, XXXXXXX, KC_UNDS, KC_PLUS, KC_SLSH,      KC_PIPE,
  //|---------+---------+---------+------------------------------+---------+---------+---------|
       _______,  _______,  _______,         KC_BSPC,                _______,  _______,   _______
    ),

//CA_F1,   CA_F2,   CA_F3  C__F9,   C__F12,
    [MACRO] = LAYOUT_long_space(
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F12,
  //|---------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     DF(COLMAK),C(KC_F1),C(KC_F2),C(KC_F3),_______, _______,  KC_F10,  KC_F11,   C__F9,  C__F12,
  //|-------------+--------+--------+--------+--------+--------+--------+--------+-------------|
          DF(BASE), _______, _______, _______, _______,    CG_L,    CG_R, _______,      _______,
  //|---------+---------+---------+------------------------------+---------+---------+---------|
       QK_BOOT,  _______,  _______,        _______,                 _______,  _______,  _______
    ),
};

