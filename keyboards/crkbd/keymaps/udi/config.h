/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

//#define CHORDAL_HOLD
//#define PERMISSIVE_HOLD
#define TAPPING_TERM 200

// Trigger hold after double tap => key repeat instead of LT/MT
//QUICK_TAP_TERM must be < TAPPING_TERM
#define QUICK_TAP_TERM 120

// disable Holds on fast typping
//#define FLOW_TAP_TERM 150

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD



#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_ALPHAS_MODS
#define RGB_MATRIX_DEFAULT_HUE 201
#define RGB_MATRIX_DEFAULT_SAT 10
#define RGB_MATRIX_DEFAULT_SPD 128



#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// this nearly max out ram
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_USB_TIMEOUT 500
// // #define USB_SUSPEND_WAKEUP_DELAY 5000
