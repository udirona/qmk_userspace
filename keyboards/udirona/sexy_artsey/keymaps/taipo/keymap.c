
#include QMK_KEYBOARD_H

#include "custom_keycodes.h"
#include "taipo.h"

enum layers {
    _TAIPO,
    _SYS
};

//[_TAIPO] = LAYOUT_ortho_3x4(
//       TP_TLP,        TP_TLR,    TP_TLM,       TP_TLI,          TP_TRI,     TP_TRM,     TP_TRR,     TP_TRP,
//       TP_BLP,        TP_BLR,    TP_BLM,       TP_BLI,          TP_BRI,     TP_BRM,     TP_BRR,     TP_BRP,
//                                 TP_LIT,       TP_LOT,          TP_ROT,     TP_RIT
//    ),
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_TAIPO] = LAYOUT_ortho_3x4(
      TP_TLP,        TP_TLR,    TP_TLM,       TP_TLI,
      TP_BLP,        TP_BLR,    TP_BLM,       TP_BLI,
      KC_AUDIO_MUTE, TP_LIT,  TP_LOT,     KC_NO
),

[_SYS] = LAYOUT_ortho_3x4(
      TP_TLP,        TP_TLR,    TP_TLM,       TP_TLI,
      TP_BLP,        TP_BLR,    TP_BLM,       TP_BLI,
      KC_AUDIO_MUTE, TP_LIT,  TP_LOT,     KC_NO
),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_TAIPO] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_SYS] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (IS_LAYER_ON(_TAIPO)) {
        return taipo_process_record_user(keycode, record);
    } else {
        return true;
    }
};

void matrix_scan_user(void) {
        taipo_matrix_scan_user();
};

#endif  
