/* Copyright 2021 nilc
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


uint8_t rotary_keycode = KC_A;

void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        rotary_keycode++;
        if (rotary_keycode > KC_0) {
            rotary_keycode = KC_A;
        }
    } else {
        rotary_keycode--;
        if (rotary_keycode < KC_A) {
            rotary_keycode = KC_0;
        }
    }
}


// Tap dance enums
enum {
    TAPKEY
};

uint8_t cur_dance(qk_tap_dance_state_t *state);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    TD(TAPKEY)
  )
};


enum {
    NO_TAP = 0,
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP, // Send two single taps
    TRIPLE_TAP,
    TRIPLE_HOLD,
    MUMBLETAP
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
    } else return MUMBLETAP;
}


uint8_t tap_state = NO_TAP;

void tapkey_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state = cur_dance(state);
    switch (tap_state) {
        case SINGLE_TAP:
            tap_code(rotary_keycode);
            break;
        case SINGLE_HOLD:
            tap_code16(S(rotary_keycode));
            break;
        case DOUBLE_TAP:
            tap_code(KC_BSPACE);
            break;
        case TRIPLE_TAP:
            tap_code(KC_SPACE);
            break;
        case TRIPLE_HOLD:
            tap_code(KC_ENTER);
    }
}


void tapkey_reset(qk_tap_dance_state_t *state, void *user_data) {
	tap_state = NO_TAP;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TAPKEY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tapkey_finished, tapkey_reset)
};
