#include QMK_KEYBOARD_H
#include <string.h>
#include <ctype.h>

enum layers {
    QWERTY = 0,
    GAME,
    NUMS,
    PUNCTS,
    CURSOR,
    MOUSE,
    ADJUST
};


#ifdef OLED_ENABLE
static void render_status(void) {

    // Host Keyboard Layer Status
    oled_write_P(PSTR("\n  __\n_/ \\_\n\n"), false);
    switch (get_highest_layer(layer_state)) {
        case QWERTY:
            oled_write_P(PSTR("  O.o\n"), false);
            break;
        case NUMS:
            oled_write_P(PSTR("  9.6\n"), false);
            break;
        case PUNCTS:
            oled_write_P(PSTR("  @.#\n"), false);
            break;
        case CURSOR:
            oled_write_P(PSTR("-> <-\n"), false);
            break;
        case MOUSE:
            oled_write_P(PSTR("`-(:>\n"), false);
            break;
        case GAME:
            oled_write_P(PSTR(":D D:\n"), false);
            break;
        case ADJUST:
            oled_write_P(PSTR("  } {\n"), false);
            break;
        default:
            oled_write_P(PSTR("Hrm\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUM ") : PSTR("\n"), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR(" cAp$ ") : PSTR("    \n"), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRL ") : PSTR("\n"), false);
}

bool oled_task_user(void) {
    render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    return false;
}
#endif

bool app_swinching = false;
uint16_t app_swinching_time;

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    // app/tab switcher
    // no layer, alt, ctl, gui pressed
    // either encoder
    if (get_mods() & (MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL) |
                      MOD_BIT(KC_RALT) | MOD_BIT(KC_RCTL) |
                      MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI)) ) {
        if (clockwise) {
          tap_code(KC_TAB);
        } else {
          tap_code16(S(KC_TAB));
        }
    }
    else if (IS_LAYER_ON(CURSOR)) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    // magnify - linux style
    else if (IS_LAYER_ON(PUNCTS)) {
        if (clockwise) {
            tap_code16(C(S(KC_EQL)));
        } else {
            tap_code16(C(KC_MINS));
        }
    }
    // magnify - osx style
    else if (IS_LAYER_ON(NUMS)) {
        if (clockwise) {
            tap_code16(G(S(KC_EQL)));
        } else {
            tap_code16(G(KC_MINS));
        }
    }
    else if (IS_LAYER_ON(MOUSE)) {
        // horizontal mouse wheel
        if (clockwise) {
            tap_code(KC_WH_R);
        } else {
            tap_code(KC_WH_L);
        }
    }
    else {
        // vertical mouse wheel
        if (clockwise) {
            tap_code(KC_WH_U);
        } else {
            tap_code(KC_WH_D);
        }
    }
    return false;
}
#endif

void matrix_scan_user(void) {
    if (app_swinching && timer_elapsed(app_swinching_time) > 989) {
        unregister_code16(KC_LGUI);
        app_swinching = false;
    }
}

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
        case APPSWC:
            if (record->event.pressed) {
                tap_code16(G(KC_TAB));
            }
            break;
        case WINSWC:
            if (record->event.pressed) {
                tap_code16(G(KC_GRAVE));
            }
            break;
    }

    return true;
}
