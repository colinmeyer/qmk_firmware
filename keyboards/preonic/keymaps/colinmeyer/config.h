#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PREONIC_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

#define MUSIC_MASK (keycode != KC_NO)

// ec11 clone is backwards
#define ENCODER_DIRECTION_FLIP

// for media keys (volume) to work from the rotor
#define TAP_CODE_DELAY 10

// MT / tap dance period
#define TAPPING_TERM 175

// MT options for HR mods
// https://precondition.github.io/home-row-mods#tap-hold-configuration-settings 
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#define PERMISSIVE_HOLD
#define RETRO_TAPPING_PER_KEY

#define RGBLIGHT_LAYERS
