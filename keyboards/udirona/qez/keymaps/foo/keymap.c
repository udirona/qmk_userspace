/* Copyright 2021 kb-elmo<mail@elmo.space>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
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


const uint16_t PROGMEM cm_tab[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM cm_esc[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cm_bspc[] = {KC_O, KC_P, COMBO_END};
combo_t key_combos[] = {
    COMBO(cm_bspc, KC_BSPC),
    COMBO(cm_esc, KC_ESC),
    COMBO(cm_tab, KC_TAB),
};

/* Fehlende Tastedf
 ;: KC_SCLN
 *  Kombis Alt Tab
 *  Features
 *  Home Row Mods
 *  Combos
 *   ESC
 *   Backspace
 *
 *  kann mann alt und layer switch wenn gehalten und kc wenn gedruckt
 */
enum layers {
    BASE,
    LOWER,
    RAISE,
    SYS
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_long_space(
        KC_Q,            KC_W,      KC_E,      KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,      KC_O,    KC_P,
        LCTL_T(KC_A),    KC_S,      KC_D,      KC_F,    KC_G,    KC_H,    KC_J,    KC_K,      KC_L,    RCTL_T(KC_ENT),
        LT(LOWER, KC_Z), KC_X,      KC_C,      KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,   LT(LOWER, KC_DOT),
        MO(RAISE),       KC_LGUI,   SC_LAPO,        LSFT_T(KC_SPC),      SC_RAPC,  MO(RAISE),   MO(SYS)
    ),

    [LOWER] = LAYOUT_long_space(
        KC_1,            KC_2,      KC_3,      KC_4,    KC_5,    KC_6,    KC_7,    KC_8,      KC_9,      KC_0,
        KC_TAB,          KC_EXLM,   KC_CIRC,   KC_HASH, KC_ASTR, KC_DLR,  KC_MINS, KC_EQL,    KC_LBRC,   KC_RBRC,
        KC_SLSH,         KC_AT,     KC_AMPR,   KC_PERC, KC_LCBR, KC_RCBR, KC_UNDS, KC_PLUS,       KC_BSLS,
        KC_TRNS,         KC_TRNS,   KC_TRNS,        KC_ESC,              KC_TRNS,  KC_TRNS,   KC_TRNS
    ),

    [RAISE] = LAYOUT_long_space(
        KC_F1,           KC_F2,     KC_F3,     KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,     KC_BSPC,
        KC_F10,          KC_HOME,   KC_PGDN,   KC_PGUP, KC_END,  KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT,   KC_F12,
        KC_TRNS,         KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_COLN,      KC_SCLN,
        KC_TRNS,         KC_TRNS,   KC_TRNS,        KC_ESC,              KC_TRNS, KC_TRNS,   KC_TRNS
    ),

    [SYS] = LAYOUT_long_space(
        QK_BOOT,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,     KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,     KC_NO,   KC_NO,   KC_NO, KC_NO, CG_LEFT, CG_RIGHT,   KC_NO, KC_NO,
        KC_NO,     KC_NO,   KC_NO,        KC_TRNS,               KC_NO, KC_NO, KC_NO
    )
};



