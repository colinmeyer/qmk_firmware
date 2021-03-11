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

/* layer names */
enum bbtiny_layers {
    DEFAULT,
    CURSOR
};




uint8_t rotary_keycode = KC_A;

void encoder_update_user(uint8_t index, bool clockwise) {
    if(IS_LAYER_ON(CURSOR)) {
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }
    } else {
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
}


// Tap dance enums
enum {
    TYPE,
    RUBOUT
};

uint8_t cur_dance(qk_tap_dance_state_t *state);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEFAULT] = LAYOUT(
    TD(TYPE), TD(RUBOUT)
  ),

  [CURSOR] = LAYOUT(
    _______, _______
  )
};


enum {
    NO_TAP = 0,
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    TRIPLE_TAP,
    TRIPLE_HOLD,
    MUMBLETAP
};

/* tap dance for MT functions w/ mods */
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->pressed && !state->interrupted) return SINGLE_HOLD;
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


uint8_t type_state = NO_TAP;

void type_finished(qk_tap_dance_state_t *state, void *user_data) {
    type_state = cur_dance(state);
    switch (type_state) {
        case SINGLE_TAP:
            tap_code(rotary_keycode);
            break;
        case SINGLE_HOLD:
            tap_code16(S(rotary_keycode));
            break;
        case DOUBLE_TAP:
            tap_code(KC_SPACE);
            break;
        case DOUBLE_HOLD:
            tap_code(KC_TAB);
            break;
        case TRIPLE_TAP:
            tap_code(KC_ENTER);
            break;
        case TRIPLE_HOLD:
            tap_code(KC_ENTER);
    }
}


void type_reset(qk_tap_dance_state_t *state, void *user_data) {
	type_state = NO_TAP;
}


uint8_t rubout_state = NO_TAP;

void rubout_finished(qk_tap_dance_state_t *state, void *user_data) {
    rubout_state = cur_dance(state);
    switch (rubout_state) {
        case SINGLE_TAP:
            tap_code(KC_BSPACE);
            break;
        case SINGLE_HOLD:
            layer_on(CURSOR);
            tap_code16(KC_LCBR);
            break;
        case DOUBLE_TAP:
            tap_code16(KC_HASH);
            tap_code(KC_B);
            tap_code(KC_B);
            tap_code(KC_T);
            tap_code(KC_I);
            tap_code(KC_N);
            tap_code(KC_Y);
            tap_code(KC_SPACE);
            break;
    }
}

void rubout_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (rubout_state) {
        case SINGLE_HOLD:
            tap_code16(KC_RCBR);
            layer_off(CURSOR);
            break;
    }
	rubout_state = NO_TAP;
}


qk_tap_dance_action_t tap_dance_actions[] = {
    [TYPE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, type_finished, type_reset),
    [RUBOUT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rubout_finished, rubout_reset)
};
