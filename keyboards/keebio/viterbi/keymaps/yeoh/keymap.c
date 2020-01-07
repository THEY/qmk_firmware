#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// TO UPDATE:
// make keebio/viterbi/rev1:yeoh:avrdude


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_ortho_5x14(
    KC_GRV          , KC_1   , KC_2   , KC_3      , KC_4   , KC_5   , KC_6   ,         KC_7   , KC_8   , KC_9   , KC_0      , KC_MINS, KC_EQL , KC_BSPC,
    KC_TAB          , KC_Q   , KC_W   , KC_E      , KC_R   , KC_T   , KC_VOLD,         KC_VOLU, KC_Y   , KC_U   , KC_I      , KC_O   , KC_P   , KC_BSLS,
    CTL_T(KC_ESCAPE), KC_A   , KC_S   , KC_D      , KC_F   , KC_G   , KC_LCBR,         KC_RCBR, KC_H   , KC_J   , KC_K      , KC_L   , KC_SCLN, KC_QUOT,
    KC_LSFT         , KC_Z   , KC_X   , KC_C      , KC_V   , KC_B   , KC_LBRC,         KC_RBRC, KC_N   , KC_M   , KC_COMM   , KC_DOT , KC_SLSH, KC_RSFT,
    KC_LALT         , KC_MEH , KC_NO  , MO(_LOWER), KC_LGUI, KC_NO  , KC_ENT ,         KC_SPC , KC_NO  , KC_RGUI, MO(_RAISE), KC_NO  , KC_NO  , KC_LCTL
  ),

  [_LOWER] = LAYOUT_ortho_5x14(
    RGB_TOG, RGB_MOD,      KC_NO,        KC_NO,             KC_NO,              KC_NO,  KC_NO,   KC_NO,   KC_NO,         KC_NO,                   KC_NO,                   KC_NO,          KC_NO,           KC_DEL,
    RGB_VAI, RGB_VAD,      KC_NO,        KC_NO,             KC_NO,              KC_NO,  KC_NO,   KC_NO,   KC_NO,         LGUI(LSFT(KC_LBRACKET)), LGUI(LSFT(KC_RBRACKET)), KC_NO,          KC_NO,           KC_NO,
    KC_NO,   KC_NO,        KC_NO,        LGUI(KC_LBRACKET), LGUI(KC_RBRACKET),  KC_NO,  KC_NO,   KC_NO,   KC_LEFT,       KC_DOWN,                 KC_UP,                   KC_RGHT,        KC_NO,           KC_NO,
    KC_LSFT, LGUI(KC_Z),   LGUI(KC_X),   LGUI(KC_C),        LGUI(KC_V),         KC_NO,  KC_NO,   KC_NO,   LGUI(KC_LEFT), LALT(KC_LEFT),           LALT(KC_RIGHT),          LGUI(KC_RIGHT), LGUI(KC_SLASH),  KC_NO,
    RESET,   KC_NO,        KC_NO,        MO(_LOWER),        KC_NO,              KC_ENT, KC_MPRV, KC_MNXT, KC_SPC,        KC_NO,                   MO(_LOWER),              KC_NO,          KC_NO,           KC_NO
  ),

  [_RAISE] = LAYOUT_ortho_5x14(
    _______, KC_TILD, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    KC_UNDS, _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_LCBR, KC_RCBR,
    KC_PLUS, _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, _______, _______,
    _______, _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,     KC_F12 , KC_NUHS, KC_NUBS, KC_MPRV, KC_MNXT, KC_MPLY, KC_MUTE,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_MNXT, MO(_RAISE), KC_NO  , KC_NO  , KC_RCTL
  ),

  [_ADJUST] = LAYOUT_ortho_5x14(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    _______, _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,     RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_DEL,  _______,
    _______, _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM,     AG_SWAP, QWERTY,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______
  )

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
