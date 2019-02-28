/* Copyright 2017 Wunder
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

/* BUILD STEPS
 *
 * $ make xd75:yeoh
 * open QMK Toolbox.app
 * microcontroller: atmega32u4
 * FN+ALT to put it in reset mode
 * Hit flash in QMK Toolbox
 */

#include "xd75.h"

// Layer shorthand
#define _QW 0
#define _FN 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | CAP LK | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | RGUI   | RCTRL  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

/* YEOH
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | `      | 1      | 2      | 3      | 4      | 5      | VOL-   | MUTE   | VOL+   | 8      | 9      | 0      | -      | =      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | 6      |        | 7      | Y      | U      | I      | O      | P      | \      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | ESC/CTR| A      | S      | D      | F      | G      | [      | DEL    | ]      | H      | J      | K      | L      | ;      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | PREV   | PLAY   | NEXT   | N      | M      | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LALT   |  MEH   |        | FN     | LGUI   | ENTER  |        |        |        | SPACE  | RGUI   | FN     |        | CTRL   | ALT    |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 // [_QW] = { /* QWERTY */
 //  { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_MINS, KC_GRV,  KC_EQL,  KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC },
 //  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_QUOT },
 //  { KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_HOME, KC_DEL,  KC_PGUP, KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_ENT  },
 //  { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_END,  KC_UP,   KC_PGDN, KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT },
 //  { KC_LCTL, KC_LGUI, KC_LALT, MO(_FN), KC_SPC, KC_SPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC, KC_SPC, MO(_FN), KC_RALT, KC_RGUI, KC_RCTL },
 // },

 [_QW] = { /* QWERTY */
  { KC_GRV,           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_VOLD, KC_MUTE,  KC_VOLU, KC_8,    KC_9,   KC_0,     KC_MINS, KC_EQL,  KC_BSPC },
  { KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_6,    KC_NO,    KC_7,    KC_Y,    KC_U,   KC_I,     KC_O,    KC_P,    KC_BSLS },
  { CTL_T(KC_ESCAPE), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_LBRC, KC_DEL,   KC_RBRC, KC_H,    KC_J,   KC_K,     KC_L,    KC_SCLN, KC_QUOT  },
  { KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_MPRV, KC_MPLY,  KC_MNXT, KC_N,    KC_M,   KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT },
  { KC_LALT,          KC_MEH,  KC_NO,   MO(_FN), KC_LGUI, KC_ENT, KC_NO,   KC_NO,    KC_NO,   KC_SPC,  KC_RGUI, MO(_FN), KC_NO,   KC_RCTL, KC_RALT },
 },

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   |        |        | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PR SCR |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   |        |        | P4     | P5     | P6     | +      |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   |        |        |        | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | RESET  |        |        | FN     |        |        | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |RGB_on/f|RGB MODE|        |        |        |        |        | VOL+   |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |RGB_UP  |RGB_DOWN|        |        |        |        |        | VOL-   |        |        | SF+C+[ | SF+C+] |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        | CMD+[  | CMD+]  |        |        | MUTE   |        |  LEFT  | DOWN   |  UP    |  RIGHT |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SHIFT  | CMD+Z  | CMD+X  | CMD+C  | CMD+V  |        |        |        |        | CMD+LT | ALT+LF | ALT+RT | CMD+RT | CMD+/  |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | RESET  |        |        | FN     |        | ENTER  | PREV   | PLAY   | NEXT   | SPACE  |        |  FN    |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

//  [_FN] = { /* FUNCTION */
//   { KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,  KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 },
//   { KC_MSEL, KC_CALC, KC_TRNS, KC_MAIL, KC_SPC, KC_SPC, KC_P7,   KC_P8,   KC_P9,   KC_MINS, KC_SPC,  KC_SPC,  KC_TRNS, KC_TRNS, KC_TRNS },
//   { KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_SPC, KC_SPC, KC_P6,   KC_P5,   KC_P4,   KC_PLUS, KC_SPC,  KC_TRNS, KC_SPC,  KC_SPC,  KC_SPC },
//   { KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  KC_SPC, KC_SPC, KC_P3,   KC_P2,   KC_P1,   KC_TRNS, KC_SPC,  KC_SPC,  KC_SPC,  KC_TRNS, KC_TRNS },
//   { RESET,   KC_TRNS, KC_TRNS, MO(_FN), KC_SPC, KC_SPC, KC_KP_0, KC_TRNS, KC_PDOT, KC_PENT, KC_TRNS, MO(_FN), KC_TRNS, KC_TRNS, KC_TRNS },
//  }
// };

 [_FN] = { /* FUNCTION */
  { RGB_TOG, RGB_MOD, KC_NO,   KC_NO,             KC_NO,              KC_NO,  KC_NO,   KC_VOLU,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO },
  { RGB_VAI, RGB_VAD, KC_NO,   KC_NO,             KC_NO,              KC_NO,  KC_NO,   KC_VOLD,   KC_NO,   KC_NO,     LGUI(LSFT(KC_LBRACKET)), LGUI(LSFT(KC_RBRACKET)), KC_NO,  KC_NO,  KC_NO },
  { KC_NO,   KC_NO,   KC_NO,   LGUI(KC_LBRACKET), LGUI(KC_RBRACKET),  KC_NO,  KC_NO,   KC_MUTE,   KC_NO,   KC_LEFT,   KC_DOWN,   KC_UP,   KC_RGHT,  KC_NO,  KC_NO },
  { KC_LSFT, LGUI(KC_Z),   LGUI(KC_X),   LGUI(KC_C), LGUI(KC_V),  KC_NO,  KC_NO,   KC_NO,     KC_NO,   LGUI(KC_LEFT), LALT(KC_LEFT), LALT(KC_RIGHT), LGUI(KC_RIGHT), LGUI(KC_SLASH),  KC_NO },
  { RESET,   KC_NO,   KC_NO,   MO(_FN),           KC_NO,              KC_ENT,  KC_MPRV, KC_MPLY,   KC_MNXT, KC_SPC,     KC_NO,   MO(_FN),   KC_NO,  KC_NO,  KC_NO },
 }
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
