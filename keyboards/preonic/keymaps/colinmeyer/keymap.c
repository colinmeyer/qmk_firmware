/* Copyright 2021 Colin Meyer
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
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _MOUSE,
  _NUMPAD,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BEWOO
};

enum tap_dance_keys {
    OS_OSTAB,
    ALT_ALTTAB,
    CTL_OSTIC,
    SHFT_CAPS,
    SHFT_ENTR
};

#define CTL_ESC LCTL_T(KC_ESC)
// #define LSFTCAP LSFT_T(KC_CAPS)
// #define RSFTENT RSFT_T(KC_ENT)


// qwerty home row mods
#define GUI_A   LGUI_T(KC_A)
#define ALT_S   LALT_T(KC_S)
#define SFT_D   LSFT_T(KC_D)
#define CTL_F   LCTL_T(KC_F)

#define CTL_J   RCTL_T(KC_J)
#define SFT_K   RSFT_T(KC_K)
#define ALT_L   RALT_T(KC_L)
#define GUISCLN LGUI_T(KC_SCLN)


#define LSFTCAP TD(SHFT_CAPS)
#define RSFTENT TD(SHFT_ENTR)
#define TAP_CTL TD(CTL_OSTIC)
#define TAP_GUI TD(OS_OSTAB)
#define TAP_ALT TD(ALT_ALTTAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *    0      1      2      3      4      5      6      7      8      9      10      11
 * ,-----------------------------------------------------------------------------------.
 * |RtrF14|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Ctr/Es|GUI/A |ALT/S |SFT/D |CTL/F |   G  |   H  |CTL/J |SFT/K |ALT/L |GUI/; |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Cap/sf|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Sh/Ent|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  `   | Ctrl | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_F14,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  CTL_ESC,  GUI_A,   ALT_S,   SFT_D,   CTL_F,   KC_G,    KC_H,    CTL_J,   SFT_K,   ALT_L,   GUISCLN, KC_QUOT,
  LSFTCAP,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFTENT,
  KC_GRAVE, TAP_CTL, TAP_GUI, TAP_ALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),


/* Lower
 *    0      1      2      3      4      5      6      7      8      9      10      11
 * ,-----------------------------------------------------------------------------------.
 * | Mute |      |      |      |      |      |Pause |      |      |   (  |   )  |PrntSc|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |   =  |   +  |   -  |   *  |   /  |   [  |   ]  |  |   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |  |   |  \   |      |   -  |   _  |   +  |   {  |   }  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
//    0       1        2        3        4        5        6        7        8        9        10      11
  KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, KC_PAUS, _______, _______, KC_LPRN, KC_RPRN, KC_PSCR,
  _______, _______, _______, _______, KC_EQL,  KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, KC_LBRC, KC_RBRC, KC_PIPE,
  _______, _______, _______, KC_PIPE, KC_BSLS, _______, KC_MINS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_BSLS,
  _______, _______, _______, _______, _______, _______, _______, _______,S(KC_NUBS),KC_HOME, KC_END, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 *    0      1      2      3      4      5      6      7      8      9      10      11
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |DMPLY1|DMPLY2|DMREC1|DMREC2|DMRSTP|      |      |      |      |      | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |ISO # |ISO / | Pg Up| Pg Dn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, DM_PLY1, DM_PLY2, DM_REC1, DM_REC2, DM_RSTP, _______, _______, _______, _______, _______, KC_F12,
  _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, _______, _______, _______, _______, _______, _______, KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 *    0      1      2      3      4      5      6      7      8      9      10      11
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|Numpad|Mouse |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|RGBTOG|RGBHUI|RGBSAI|RGBVAI|RGBMOD|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |RGBHUD|RGBSAD|RGBVAD|RGBRMD|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,
  _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD
)

,
/* vi style Mouse Keys
 *    0      1      2      3      4      5      6      7      8      9      10      11
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |  WH^ |      |      | B1   |  B3  |  B2  |  WH^ |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |  WH^ |  WHv |      | M<   | Mv   |  M^  |  M>  |  WHv |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | MS0  | MS1  | MS2  |      |      |      | WH<  |  WH> |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
 
[_MOUSE] = LAYOUT_preonic_grid(
//    0       1        2        3        4        5        6        7        8        9        10      11
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, 
  _______, KC_ACL0, KC_ACL1, KC_ACL2, KC_WH_U, _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, KC_WH_U,_______, 
  _______, _______, _______, KC_WH_U, KC_WH_D, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_WH_D,_______, 
  _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_R, _______, _______,_______, 
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______
),


/* NUMPAD
 *    0      1      2      3      4      5      6      7      8      9      10      11
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |  {   |   }  |      |   /  |   *  |  -   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |      |  ^   |      |      |  <   |   >  |   7  |   8  |   9  |  +   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   <  |  v   |  >   |      |  (   |   )  |   4  |   5  |   6  |  +   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  [   |   ]  |   1  |   2  |   3  |Enter |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   0  |   .  |  =   |      |
 * `-----------------------------------------------------------------------------------'
 */

[_NUMPAD] = LAYOUT_preonic_grid(
//    0       1        2        3        4        5        6        7        8        9        10      11
  _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______, KC_SLSH, KC_ASTR, KC_MINS,_______,
  KC_TAB , _______, KC_UP  , _______, _______, KC_LT  , KC_GT  , KC_7   , KC_8   , KC_9   , KC_PLUS,_______,
  _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_LPRN, KC_RPRN, KC_4   , KC_5   , KC_6   , KC_PLUS,_______,
  _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_1   , KC_2   , KC_3   , KC_ENT ,_______, 
  _______, _______, _______, _______, _______, _______, _______, _______, KC_0   , KC_DOT , KC_EQL ,_______
)


//,
/* layer template
 *    0      1      2      3      4      5      6      7      8      9      10      11
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/*
[_LAYER_NAME] = LAYOUT_preonic_grid(
//    0       1        2        3        4        5        6        7        8        9        10      11
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, 
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, 
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, 
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, 
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______
)
*/


};


/* capslock colors */
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 2, HSV_ORANGE},
    {0, 2, HSV_ORANGE},
    {8, 1, HSV_ORANGE}
);

/* numpad colors */
const rgblight_segment_t PROGMEM my_numpad_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 2, HSV_GREEN},
    {0, 2, HSV_GREEN},
    {8, 1, HSV_GREEN}
);

/* mouse colors */
const rgblight_segment_t PROGMEM my_mouse_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 2, HSV_CYAN},
    {0, 2, HSV_CYAN},
    {8, 1, HSV_CYAN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_numpad_layer,
    my_mouse_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _NUMPAD));
    rgblight_set_layer_state(2, layer_state_cmp(state, _MOUSE));
    return state;
}

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
      }
    return true;
};


enum {
    NO_TAP,
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    TRIPLE_TAP,
    TRIPLE_HOLD,
    MUMBLE_TAP
};

/* tap dance for MT functions w/ mods */
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->pressed) return SINGLE_HOLD;
        else return SINGLE_TAP;
    }

    if (state->count == 2) {
        if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }

    if (state->count == 3) {
        if (state->pressed) return TRIPLE_HOLD;
        else return TRIPLE_TAP;
    } else return MUMBLE_TAP;
}


uint8_t os_tap_state = NO_TAP;

void os_finished(qk_tap_dance_state_t *state, void *user_data) {
    os_tap_state = cur_dance(state);
    switch (os_tap_state) {
        case SINGLE_TAP:  register_code16(G(KC_TAB)); break;
        case SINGLE_HOLD: register_code16(KC_LGUI); break;
        case DOUBLE_TAP:  layer_invert(_MOUSE); break;
    }
}

void os_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (os_tap_state) {
        case SINGLE_TAP:  unregister_code16(G(KC_TAB)); break;
        case SINGLE_HOLD: unregister_code16(KC_LGUI);
    }
    os_tap_state = NO_TAP;
}


uint8_t alt_tap_state = NO_TAP;

void alt_finished(qk_tap_dance_state_t *state, void *user_data) {
    alt_tap_state = cur_dance(state);
    switch (alt_tap_state) {
        case SINGLE_TAP:  register_code16(A(KC_TAB)); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
    }
}

void alt_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (alt_tap_state) {
        case SINGLE_TAP:  unregister_code16(A(KC_TAB)); break;
        case SINGLE_HOLD: unregister_code16(KC_LALT);
    }
    alt_tap_state = NO_TAP;
}


uint8_t ctl_tap_state = NO_TAP;

void ctl_finished(qk_tap_dance_state_t *state, void *user_data) {
    ctl_tap_state = cur_dance(state);
    switch (ctl_tap_state) {
        case SINGLE_TAP:  register_code16(G(KC_GRAVE)); break;
        case SINGLE_HOLD: register_code16(KC_LCTL); break;
        case DOUBLE_TAP:  layer_invert(_NUMPAD); break;
    }
}

void ctl_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ctl_tap_state) {
        case SINGLE_TAP:  unregister_code16(G(KC_GRAVE)); break;
        case SINGLE_HOLD: unregister_code16(KC_LCTL); break;
    }
    ctl_tap_state = NO_TAP;
}


uint8_t shift_caps_tap_state = NO_TAP;

float bewoo[][2] = SONG(E__NOTE(_B5), Q__NOTE(_B3));

void shift_caps_finished(qk_tap_dance_state_t *state, void *user_data) {
    shift_caps_tap_state = cur_dance(state);
    switch (shift_caps_tap_state) {
        case SINGLE_TAP:  tap_code(KC_CAPS); break;
        case SINGLE_HOLD:
            register_code16(KC_LSHIFT);
            PLAY_SONG(bewoo);
            break;
    }
}

void shift_caps_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (shift_caps_tap_state) {
        case SINGLE_HOLD: unregister_code16(KC_LSHIFT); break;
    }
    shift_caps_tap_state = NO_TAP;
}


uint8_t shift_entr_tap_state = NO_TAP;

void shift_entr_finished(qk_tap_dance_state_t *state, void *user_data) {
    shift_entr_tap_state = cur_dance(state);
    switch (shift_entr_tap_state) {
        case SINGLE_TAP:  tap_code(KC_ENT); break;
        case SINGLE_HOLD:
            register_code16(KC_RSHIFT);
            PLAY_SONG(bewoo);
            break;
        case DOUBLE_TAP:  tap_code(KC_ENT); tap_code(KC_ENT); break;
    }
}

void shift_entr_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (shift_entr_tap_state) {
        case SINGLE_HOLD: unregister_code16(KC_RSHIFT); break;
    }
    shift_entr_tap_state = NO_TAP;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [OS_OSTAB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, os_finished, os_reset),
    [ALT_ALTTAB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_finished, alt_reset),
    [CTL_OSTIC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctl_finished, ctl_reset),
    [SHFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, shift_caps_finished, shift_caps_reset),
    [SHFT_ENTR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, shift_entr_finished, shift_entr_reset),
};



bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (IS_LAYER_ON(_ADJUST)) {
  // window switcher
  // sends gui ` / gui shift `
    if (clockwise) {
      tap_code16(G(KC_GRAVE));
    } else {
      tap_code16(G(S(KC_GRAVE)));
    }
  } else if (IS_LAYER_ON(_RAISE)) {
  // magnification
    if(get_mods() & MOD_BIT(KC_LGUI)) {
    // osx style if holding gui
      if (clockwise) {
        tap_code16(S(KC_EQL));
      } else {
        tap_code16(KC_MINS);
      }
    } else {
      if (clockwise) {
        tap_code16(C(S(KC_EQL)));
      } else {
        tap_code16(C(KC_MINS));
      }
    }
  } else if (get_mods() & (MOD_BIT(KC_LALT) | MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL)) ) {
  // app/tab switcher
    if (clockwise) {
      tap_code(KC_TAB);
    } else {
      tap_code16(S(KC_TAB));
    }
  } else  if (IS_LAYER_ON(_LOWER)) {
  // audio volume
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  } else if (get_mods() & MOD_BIT(KC_LSHIFT)) {
  // cursor up/down
    unregister_code(KC_LSHIFT);
    if (clockwise) {
      tap_code(KC_RIGHT);
    } else {
      tap_code(KC_LEFT);
    }
    register_code(KC_LSHIFT);
  } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
  // cursor up/down
    unregister_code(KC_RSHIFT);
    if (clockwise) {
      tap_code(KC_UP);
    } else {
      tap_code(KC_DOWN);
    }
    register_code(KC_RSHIFT);
  } else {
  // mousewheel
    if (clockwise) {
      tap_code(KC_WH_U);
    } else {
      tap_code(KC_WH_D);
    }
  }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

