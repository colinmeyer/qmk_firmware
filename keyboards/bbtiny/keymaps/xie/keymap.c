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

enum rotary_modes {
    ROT_VOLUME = 1,
    ROT_BRIGHT,
    ROT_APP,
    ROT_TAB
};


uint8_t rot_mode = ROT_VOLUME;


void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        switch (rot_mode) {
            case ROT_VOLUME:
                tap_code(KC_VOLU);
                break;
            case ROT_BRIGHT:
                tap_code(KC_BRIGHTNESS_UP);
                break;
            case ROT_APP:
            case ROT_TAB:
                tap_code(KC_TAB);
                break;
        }
    } else {
        switch (rot_mode) {
            case ROT_VOLUME:
                tap_code(KC_VOLD);
                break;
            case ROT_BRIGHT:
                tap_code(KC_BRIGHTNESS_DOWN);
                break;
            case ROT_APP:
            case ROT_TAB:
                tap_code16(S(KC_TAB));
                break;
        }
    }
}



// Tap dance enums
enum {
    TOP,
    BOTTOM
};

uint8_t cur_dance(qk_tap_dance_state_t *state);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    TD(BOTTOM), TD(TOP)
  )
};


enum {
    NO_TAP = 0,
    SINGLE_TAP,
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


uint8_t top_state = NO_TAP;

void top_finished(qk_tap_dance_state_t *state, void *user_data) {
    top_state = cur_dance(state);
    switch (top_state) {
        case SINGLE_TAP:
            register_code(KC_MUTE);
            break;
        case SINGLE_HOLD:
            if (rot_mode == ROT_APP) {
                unregister_code(KC_LGUI);
                rot_mode = ROT_TAB;
                register_code(KC_LCTL);
            } else {
                rot_mode = ROT_BRIGHT;
            }
            break;
    }
}

void top_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (top_state) {
        case SINGLE_TAP:
            unregister_code(KC_MUTE);
            break;
        case SINGLE_HOLD:
            if (rot_mode == ROT_TAB) {
                unregister_code(KC_LCTL);
                rot_mode = ROT_APP;
                register_code(KC_LGUI);
            } else {
                rot_mode = ROT_VOLUME;
            }
            break;
    }
	top_state = NO_TAP;
}


uint8_t bottom_state = NO_TAP;

void bottom_finished(qk_tap_dance_state_t *state, void *user_data) {
    bottom_state = cur_dance(state);
    switch (bottom_state) {
        case SINGLE_TAP:
            tap_code16(G(KC_TAB));
            break;
        case SINGLE_HOLD:
            if (rot_mode == ROT_BRIGHT) {
                rot_mode = ROT_TAB;
                register_code(KC_LCTL);
            } else {
                rot_mode = ROT_APP;
                register_code(KC_LGUI);
            }
            break;
    }
}

void bottom_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (bottom_state) {
        case SINGLE_HOLD:
            if (rot_mode == ROT_TAB) {
                unregister_code(KC_LCTL);
                rot_mode = ROT_BRIGHT;
            } else {
                unregister_code(KC_LGUI);
                rot_mode = ROT_VOLUME;
            }
            break;
    }
	bottom_state = NO_TAP;
}


qk_tap_dance_action_t tap_dance_actions[] = {
    [TOP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, top_finished, top_reset),
    [BOTTOM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, bottom_finished, bottom_reset)
};
