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

// tap dance period
#define TAPPING_TERM 175

#define RGBLIGHT_LAYERS
