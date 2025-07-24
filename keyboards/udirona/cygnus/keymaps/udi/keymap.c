/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H


#define CC_ESC MT(MOD_LGUI,KC_ESC)
#define CC_QUOT MT(MOD_LCTL | MOD_RCTL, KC_QUOT)
#define CC_SCLN MT(MOD_LALT, KC_SCLN)
#define CC_A MT(MOD_LALT, KC_A)

#define CC_SPC LT(RAISE, KC_SPC)
#define CC_ENT LT(SYS, KC_ENT)

#define CC_BSLS MT(MOD_RCTL, KC_BSLS)

#define CG_LEFT C(G(KC_LEFT))
#define CG_RGHT C(G(KC_RGHT))
#define AG_UP A(G(KC_UP))
#define G_LEFT G(KC_LEFT)
#define G_RGHT G(KC_RGHT)
#define G_UP G(KC_UP)
#define G_DOWN G(KC_DOWN)
#define A_F4 A(KC_F4)
#define C_F4 C(KC_F4)

enum custom_keycodes {
  MOUSEJIG = SAFE_RANGE
};
bool mouse_jiggle_mode = false;

const uint16_t PROGMEM cm_esc[] = {KC_C, KC_V, COMBO_END};

combo_t key_combos[] = {
    COMBO(cm_esc, KC_ESC)
};

enum layers {
    BASE,
    LOWER,
    RAISE,
    NUMBERS,
    SYS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    CC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, CC_SCLN, CC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   MO(LOWER),  CC_ESC,     CC_ENT,   CC_SPC, KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

    [LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_PSCR, KC_HOME, KC_PGDN, KC_PGUP, KC_END,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_TILD,  KC_GRV, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_INS,  KC_APP, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_F10,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_EXLM, KC_CIRC, KC_HASH, KC_ASTR,  KC_DLR,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_COLN, CC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_AT, KC_AMPR, KC_PERC, KC_LPRN, KC_RPRN,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [NUMBERS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,    KC_7,    KC_8,    KC_9,    KC_0,                      XXXXXXX, XXXXXXX, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [SYS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX,   MS_UP, XXXXXXX, MS_WHLU,                     MOUSEJIG, XXXXXXX, XXXXXXX, XXXXXXX, C(KC_PPLS), S(C(KC_PPLS)),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    A_F4, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLD,                      CG_LEFT,   AG_UP, XXXXXXX, CG_RGHT, C(KC_PMNS), S(C(KC_PMNS)),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    C_F4, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       G_LEFT,    G_UP,  G_DOWN,  G_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MS_BTN3, MS_BTN1, MS_BTN2,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_SPACE:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MOUSEJIG:
      if (record->event.pressed) {
        if (mouse_jiggle_mode) {
            SEND_STRING(SS_DELAY(15));
            mouse_jiggle_mode = false;
        } else {
            SEND_STRING(SS_DELAY(15));
            mouse_jiggle_mode = true;
        }
      } else {
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) {
  if (mouse_jiggle_mode) {
    SEND_STRING(SS_DELAY(10));
    tap_code(KC_MS_UP);
    tap_code(KC_MS_DOWN);
    SEND_STRING(SS_DELAY(30));
    tap_code(KC_MS_LEFT);
    tap_code(KC_MS_RIGHT);
  } else {
  }
}
