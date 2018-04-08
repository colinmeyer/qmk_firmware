#include "s65_x.h"

#define BASELAYER 0
#define FUNCTIONLAYER 1
#define LIGHTSLAYER 2
#define MOUSELAYER 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: Main layer, swapped alt and GUI for Mac
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * │ ESC │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │▒▒▒▒▒│BKSPC│GRAVE│
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │ TAB │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │  \  │█████│END  │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │CAPSL│  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │▒▒▒▒▒│ENTER│█████│PG_UP│
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │LSHFT│▒▒▒▒▒│  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │▒▒▒▒▒│RSHFT│ UP  │PG_DN│
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │LCTRL│L_GUI│LARROWLAYERT│█████│█████│█████│ SPC │█████│█████│█████│RARROWLAYERT│ FN0 │ APP │LEFT │DOWN │RIGHT│
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */

  /* 0: ANSI qwerty */
  [BASELAYER] = ANSI_KEYMAP(
        KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_GRAVE, \
        KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, \
        F(1),    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,       KC_ENT,     KC_PGUP, \
        KC_LSFT,       KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,    KC_RSFT, KC_UP, KC_PGDN, \
        KC_LCTL, KC_LGUI, KC_LALT,            KC_SPC,            KC_RALT, MO(FUNCTIONLAYER), KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT),


  /* 1: Fn layer
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * │GRAVE│ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │▒▒▒▒▒│▒▒▒▒▒│     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │osxsl│     │ Up  │     │     │     │     │     │PGUP │PGDWN│PRTSC│SCLCK│PAUSE│     │▒▒▒▒▒│     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │sleep│Left │Down │Right│     │     │Left │Down │ Up  │Right│     │     │▒▒▒▒▒│     │▒▒▒▒▒│     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │▒▒▒▒▒│LIGHT│     │     │     │     │     │MOUSE│     │Home │End  │▒▒▒▒▒│     │Vol+ │     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │debug│     │     │█████│█████│█████│     │█████│█████│█████│     │     │     │Mute │Vol- │Play │
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */

  [FUNCTIONLAYER] = ANSI_KEYMAP(
      KC_GRAVE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, \
      LCTL(LSFT(KC_PWR)), KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, KC_TRNS, \
      KC_SLEP, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
      KC_TRNS,    F(2), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     F(3), KC_HOME, KC_END, KC_TRNS, KC_TRNS, KC_VOLU, KC_TRNS, \
      DEBUG, KC_TRNS, KC_TRNS,               KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_MPLY),

  /* 2: Locking layer for controlling the underglow
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * │     │     │     │     │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│▒▒▒▒▒│     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │BL On│BLOff│BLINC│BLDEC│BL BR│     │     │     │     │     │     │     │     │▒▒▒▒▒│     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │ On  │Mode │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│     │▒▒▒▒▒│     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │▒▒▒▒▒│     │Hue+ │Hue- │Sat+ │Sat- │Val+ │Val- │     │     │     │▒▒▒▒▒│     │▒▒▒▒▒│     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │     │     │█████│█████│█████│     │█████│█████│█████│     │     │     │     │     │     │
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */

  [LIGHTSLAYER] = ANSI_KEYMAP(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  \
      KC_TRNS, BL_ON, BL_OFF, BL_INC, BL_DEC, BL_BRTG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
      KC_TRNS, RGB_TOG, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
      KC_TRNS, KC_TRNS, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
      KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /* 3: Locking layer for mousekeys
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * │     │  lc │ mc  │ rc  │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│▒▒▒▒▒│     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │     │  ^  │     │ W^  │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │ <-  │  v  │ ->  │ Wv  │     │     │     │     │     │     │     │▒▒▒▒▒│     │▒▒▒▒▒│     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │▒▒▒▒▒│acc 0│acc 1│acc 2│     │     │     │     │     │     │     │▒▒▒▒▒│     │▒▒▒▒▒│     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │     │     │█████│█████│█████│     │█████│█████│█████│     │     │     │     │     │     │
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */

  [MOUSELAYER] = ANSI_KEYMAP(
      KC_TRNS, KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  \
      KC_TRNS, KC_TRNS, KC_MS_UP, KC_TRNS, KC_MS_WH_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
      KC_TRNS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
      KC_TRNS, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_UP, KC_TRNS, \
      KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT),
};


const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(FUNCTIONLAYER),       // Momentary Fn overlay
  [1] = ACTION_LAYER_TAP_KEY(FUNCTIONLAYER, KC_CAPS),// Tap to toggle caps lock and hold to activate function layer
  [2] = ACTION_LAYER_TOGGLE(LIGHTSLAYER),          // Toggle Underglow Layer overlay
  [3] = ACTION_LAYER_TOGGLE(MOUSELAYER),
};



  /* 3: Locking layer for mousekeys
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * │     │     │     │     │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│▒▒▒▒▒│     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │     │     │     │     │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │     │     │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│     │▒▒▒▒▒│     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │▒▒▒▒▒│     │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│     │▒▒▒▒▒│     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │     │     │█████│█████│█████│     │█████│█████│█████│     │     │     │     │     │     │
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
/*
  [LIGHTSLAYER] = ANSI_KEYMAP(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  \
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
      KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};
*/

