/*

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

/* Udirona crkb keymap */

#include QMK_KEYBOARD_H

#define CC_THL LT(LOWER,KC_ESC)
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

//#define COMBOS

#ifdef COMBOS
const uint16_t PROGMEM cm_esc[] = {KC_C, KC_V, COMBO_END};
combo_t key_combos[] = {
    COMBO(cm_esc, KC_ESC)
};
#endif

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
                                          KC_LGUI, KC_LALT, CC_THL,     CC_ENT,   CC_SPC, KC_RALT
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
      QK_BOOT, XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX,                      RM_HUEU, RM_SATU, RM_SPDU, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX,                      RM_HUED, RM_SATD, RM_SPDD, XXXXXXX, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,    KC_7,    KC_8,    KC_9,    KC_0,                      XXXXXXX, XXXXXXX, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [SYS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX,   MS_UP, XXXXXXX, MS_WHLU,                     MOUSEJIG, DT_PRNT,   DT_UP, DT_DOWN, C(KC_PPLS), S(C(KC_PPLS)),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    A_F4, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLD,                      CG_LEFT,   AG_UP, XXXXXXX, CG_RGHT, C(KC_PMNS), S(C(KC_PMNS)),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    C_F4, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       G_LEFT,    G_UP,  G_DOWN,  G_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MS_BTN3, MS_BTN1, MS_BTN2,     KC_ENT, MO(NUMBERS), KC_RALT

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

//void keyboard_post_init_user(void) {
//    // Initialize RGB Matrix if not already
//    rgb_matrix_enable_noeeprom();
//
//    // Set mode to RGB_MATRIX_ALPHAS_MODS (mode index may vary per keyboard)
//    rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);
//
//    // Optional: set a default color
//    rgb_matrix_sethsv_noeeprom(HSV_CYAN);
//    rgb_matrix_sethsv_noeeprom(HSV_CYAN);
//}

#ifdef OLED_ENABLE

static void render_snoopy(void) {
    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,240,240,160, 96,224,224,224,192,192,192,128,128,  0,  0,  0,  0,  0,  0,128,192,224,224,224,224,240,240,240,240,224,224,224,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,224,240,240,248,248,252,252,252,252,252,252,248,248,248,248,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,134,140,  9,  9,  9,155,211,247,255,255,248,252,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,248,224,192,128,128,128,  0,  0,  0,128,224,120,124, 30, 15,  3,  3,  1, 49, 99,199, 15, 31,127,255,255,255,255,255,255,255,255,255,127, 31,255,254,252,248,240,240,224,224,224,224,224,224,192,192,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,254,255,255,255,255,222, 56,131,255,255,255,255,255,255,255,255,253,253,253,253,253,253,249,243,247,231, 31,255,127, 31,227,251, 59,203,227,243,247, 55,135,159,191,127,255,255,255,255,255,252,240,224,128,  0,  0,  0,  0,  0,  1,  3, 60,  0,  3, 31,255,255,255,255,255,253,253,252,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255, 15, 66,  4,  4,200, 80,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,192,224,240,248,248,255,255,255,255,255,127, 31,139,227,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255, 63, 31,192,255,192, 63,127,127,124,125,127,127,120,126,127,127,127,120,115,111,111,111,111,111,111,111,111,111,110,126,124,124,124,124,124,124,126,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,119,113,125,125,125,121,123,123, 59, 31,  7,  4,  4,  4,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_clear();
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

#ifdef OLED_SETTINGS
static void render_setting(void) {
    static char TEXT[20];
    oled_write_P(PSTR("RGB "), false);
    uint8_t h = rgb_matrix_get_hue();
    uint8_t s = rgb_matrix_get_sat();
    uint8_t v = rgb_matrix_get_val();
    uint8_t speed = rgb_matrix_get_speed();
    snprintf(TEXT, sizeof(TEXT), "H%d S%d V%d", h, s, v);
    oled_write_ln(TEXT, false);
    snprintf(TEXT, sizeof(TEXT), "Speed%d", speed);
    oled_write_ln(TEXT, false);
}
#endif


static void oled_render_layer_state(void) {
    oled_write_P(PSTR(""), false);
    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case NUMBERS:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
        case SYS:
            oled_write_ln_P(PSTR("System"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
            break;
    }
}

//Setup some mask which can be or'd with bytes to turn off pixels
const uint8_t single_bit_masks[8] = {127, 191, 223, 239, 247, 251, 253, 254};

static void fade_display(void) {
    //Define the reader structure
    oled_buffer_reader_t reader;
    uint8_t buff_char;
    if (random() % 30 == 0) {
        srand(timer_read());
        // Fetch a pointer for the buffer byte at index 0. The return structure
        // will have the pointer and the number of bytes remaining from this
        // index position if we want to perform a sequential read by
        // incrementing the buffer pointer
        reader = oled_read_raw(0);
        //Loop over the remaining buffer and erase pixels as we go
        for (uint16_t i = 0; i < reader.remaining_element_count; i++) {
            //Get the actual byte in the buffer by dereferencing the pointer
            buff_char = *reader.current_element;
            if (buff_char != 0) {
                oled_write_raw_byte(buff_char & single_bit_masks[rand() % 8], i);
            }
            //increment the pointer to fetch a new byte during the next loop
            reader.current_element++;
        }
    }
}

bool oled_task_user (void) {
    if (!mouse_jiggle_mode) {
        fade_display();
    }
    if (is_keyboard_master() && !mouse_jiggle_mode) {
        oled_render_layer_state();
        //render_setting();
        return false;
    }
    return false;
}

void oled_render_boot(bool bootloader) {
    oled_clear();
    for (int i = 0; i < 16; i++) {
        oled_set_cursor(0, i);
        if (bootloader) {
            oled_write_P(PSTR("Awaiting New Firmware "), false);
        } else {
            oled_write_P(PSTR("Rebooting "), false);
        }
    }
    oled_render_dirty(true);
}

bool shutdown_user(bool jump_to_bootloader) {
    oled_render_boot(jump_to_bootloader);
    return true;
}
#endif

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
                render_snoopy();
            }
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
  }
}

