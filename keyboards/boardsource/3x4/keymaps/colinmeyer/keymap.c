#include QMK_KEYBOARD_H

enum layers {
    _MAIN,
    _RAISE,
    _LOWER,
};

// Readability keycodes
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT(
    RAISE  , KC_7   , KC_8   , KC_9   ,
    LOWER  , KC_4   , KC_5   , KC_6   ,
    KC_0   , KC_1   , KC_2   , KC_3   
  ),
  [_RAISE] = LAYOUT(
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, RESET
  )

};
