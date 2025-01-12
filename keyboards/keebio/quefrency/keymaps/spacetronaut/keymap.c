#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1
#define _EMOJ 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  ___PASS,
  ____VSC,
  _WINTAB = LGUI(KC_TAB),
  ___LOCK,
  _LAYOUT,
  TD_WTAB,
  NEWTERM,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ___PASS:
      if (record->event.pressed) {
        // when keycode ___PASS is pressed
        SEND_STRING("Njm01243" SS_TAP(X_ENTER));
      } else {
        // when keycode ___PASS is released
      }
      break;
    break;
    case ___LOCK:
      if (record->event.pressed) {
        // when keycode ___LOCK is pressed
        SEND_STRING(SS_DOWN(X_LGUI) "l" SS_UP(X_LGUI));
    }
      else {
        //when released
    }
    break;
    case NEWTERM:
      if (record->event.pressed) {
        // when keycode NEWTERM is pressed
        SEND_STRING(SS_LCTL(SS_LSFT("t")));
    }
      else {
        //when released
    }
    break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65_with_macro(
    KC_F1,   KC_F2,   KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______,  KC_BSPC, KC_DEL, \
    KC_F3,   KC_F4,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP, \
    KC_F5,   KC_F6,   KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGDN, \
    KC_F7,   KC_F8,   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END, \
    KC_F9,   KC_F10,  KC_LCTL, KC_LALT, KC_LGUI, MO(_FN1),KC_SPC,      KC_SPC, _______,  _______, KC_RCTL, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_FN1] = LAYOUT_65_with_macro(
    KC_PWR,  _______, KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  _______, KC_HOME, \
    _______, _______, _______, _______, _______, _______, _______, NEWTERM, _______, _______, _______, _______, KC_PSCR, _______, _______, _______, _______, \
    _______, _______, CW_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, _______, \
    _______, _______, _______, _______, _______, KC_CALC, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, KC_HOME, \
    ___LOCK, ___PASS, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
  ),

};

