/* Copyright 2015-2017 Jack Humbert
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
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};


/* tap dance stuff */
typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP, // Send two single taps
    TRIPLE_TAP,
    TRIPLE_HOLD
};

// Tap dance enums
enum {
    OS_OSTAB,
	ALT_ALTTAB,
	CTL_OSTIC
};

uint8_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void os_finished(qk_tap_dance_state_t *state, void *user_data);
void os_reset(qk_tap_dance_state_t *state, void *user_data);
void alt_finished(qk_tap_dance_state_t *state, void *user_data);
void alt_reset(qk_tap_dance_state_t *state, void *user_data);
void ctl_finished(qk_tap_dance_state_t *state, void *user_data);
void ctl_reset(qk_tap_dance_state_t *state, void *user_data);



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *    0      1      2      3      4      5      6      7      8      9      10      11
 * ,-----------------------------------------------------------------------------------.
 * |RtrF13|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Ctr/Es|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Cap/sf|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Sh/Ent|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  `   | Ctrl | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_F13,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  LCTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  LSFT_T(KC_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
  KC_GRAVE, TD(CTL_OSTIC), TD(OS_OSTAB), TD(ALT_ALTTAB), LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),


/* Lower
 *    0      1      2      3      4      5      6      7      8      9      10      11
 * ,-----------------------------------------------------------------------------------.
 * | Mute |      |      |      |      |      |      |      |      |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |   =  |   +  |   -  |   *  |   /  |   [  |   ]  |  |   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |      |      |      |Mouse |      |   -  |   _  |   +  |   {  |   }  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
//    0       1        2        3        4        5        6        7        8        9        10      11
  KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, KC_BSPC,
  _______, _______, _______, _______, KC_EQL,  KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, KC_LBRC, KC_RBRC, KC_PIPE,
  KC_LCTL, _______, _______, _______, TG(_MOUSE), _______, KC_MINS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_BSLS,
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
 * | Caps |      |      |      |      |      |      |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |ISO # |ISO / | Pg Up| Pg Dn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, DM_PLY1, DM_PLY2, DM_REC1, DM_REC2, DM_RSTP, _______, _______, _______, _______, _______, KC_F12,
  KC_CAPS, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
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
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|RGBTOG|RGBHUI|RGBSAI|RGBVAI|RGBMOD|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |RGBHUD|RGBSAD|RGBVAD|RGBRMD|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______,  _______, _______,
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
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, 
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, 
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, 
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, 
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______
)
*/


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
      }
    return true;
};


/* tap dance for MT functions w/ mods */
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    }
    if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TRIPLE_TAP;
        else return TRIPLE_HOLD;
    } else return 8; // Magic number. At some point this method will expand to work for more presses
}

// Create an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {
    .is_press_action = true,
    .state = 0
};

void os_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP: register_code16(G(KC_TAB)); break;
        case SINGLE_HOLD: register_code16(KC_LGUI); break;
    }
}

void os_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case SINGLE_TAP: unregister_code16(G(KC_TAB)); break;
        case SINGLE_HOLD: unregister_code16(KC_LGUI); break;
    }
    xtap_state.state = 0;
}

void alt_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP: register_code16(A(KC_TAB)); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
    }
}

void alt_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case SINGLE_TAP: unregister_code16(A(KC_TAB)); break;
        case SINGLE_HOLD: unregister_code16(KC_LALT); break;
    }
    xtap_state.state = 0;
}

void ctl_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP: register_code16(G(KC_GRAVE)); break;
        case SINGLE_HOLD: register_code16(KC_LCTL); break;
    }
}

void ctl_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case SINGLE_TAP: unregister_code16(G(KC_GRAVE)); break;
        case SINGLE_HOLD: unregister_code16(KC_LCTL); break;
    }
    xtap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [OS_OSTAB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, os_finished, os_reset),
    [ALT_ALTTAB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_finished, alt_reset),
    [CTL_OSTIC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctl_finished, ctl_reset),
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

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
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
