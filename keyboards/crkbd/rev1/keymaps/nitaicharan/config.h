#pragma once

#define BOOTMAGIC_ROW 0
#undef BOOTMAGIC_COLUMN
#define BOOTMAGIC_COLUMN 5
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

//#define USE_MATRIX_I2C

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define TAPPING_TERM 200
#define QUICK_TAP_TERM 0

#define PERMISSIVE_HOLD

#define LALT_A LALT_T(KC_A)
#define LSFT_S LSFT_T(KC_S)
#define LCTL_D LCTL_T(KC_D)
#define LGUI_F LGUI_T(KC_F)
#define RGUI_J RGUI_T(KC_J)
#define RCTL_K RCTL_T(KC_K)
#define RSFT_L RSFT_T(KC_L)
#define LALT_SCLN LALT_T(KC_SCLN)

#define L1_SPC LT(_LAYER_1, KC_SPACE)
#define L2_SPC LT(_LAYER_2, KC_SPACE)
#define L4_F LT(_LAYER_4, KC_F)
#define L5_J LT(_LAYER_5, KC_J)
#define L5_MOD MO(_LAYER_3)

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif
