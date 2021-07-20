/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <string.h>
#include <ctype.h>

char beyonkle[18] = "beyonkle";

void gen_beyonkle(bool rCaps) {
  beyonkle[0] = 'b';
  uint8_t numEs = rand() % 8 + 2;
  for (uint8_t i = 1; i <= numEs; i++) {
    beyonkle[i] = 'e';
  }
  strcpy(beyonkle + numEs +1,"yonkle\n");
  uint8_t i=0;
  while (beyonkle[i]) {
    if (rand() % 100 < 30) {
      beyonkle[i] = toupper(beyonkle[i]);
    }
    i++;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BEYONK:
            if (record->event.pressed) {
                // when keycode B_START is pressed
                gen_beyonkle(true);
                send_string(beyonkle);
            } else {
                // when keycode B_START is released
            }
            break;
    }
    return true;
}


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (get_mods() & (MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL)) ) {
        if (clockwise) {
          tap_code(KC_TAB);
        } else {
          tap_code16(S(KC_TAB));
        }
    } else if (get_mods() & MOD_BIT(KC_LALT)) {
        unregister_code16(KC_LALT);
        if (clockwise) {
          tap_code16(G(KC_GRAVE));
        } else {
          tap_code16(G(S(KC_GRAVE)));
        }
        register_code16(KC_LALT);
    } else {
        if (clockwise) {
          tap_code(KC_VOLU);
        } else {
          tap_code(KC_VOLD);
        }
    }
    return true;
}
