#include QMK_KEYBOARD_H
#include "print.h"
enum layers {
    _BASE_LAYER = 0,
    _LAYER_1 = 1,
    _LAYER_2 = 2,
    _LAYER_3 = 3,
    _LAYER_4 = 4,
    _LAYER_5 = 5,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE_LAYER] = LAYOUT_split_3x6_3(
   //|-------------------------------------------------------------------------------------------------------.                                ,-------------------------------------------------------------------------------------------------------|
                           XXXXXXX,          KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,                                           KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,                     XXXXXXX,
   //|----------------------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+----------------------------|
                           XXXXXXX,        LALT_A,        LSFT_S,        LCTL_D,          L4_F,          KC_G,                                           KC_H,          L5_J,        RCTL_K,        RSFT_L,     LALT_SCLN,                     XXXXXXX,
   //|----------------------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+----------------------------|
                           XXXXXXX,          KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,                                           KC_N,          KC_M,       KC_LABK,        KC_DOT,   KC_QUESTION,                     XXXXXXX,
   //|----------------------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+----------------------------|
                                                                                        KC_DEL,        L1_SPC,       KC_LGUI,   KC_RGUI,       L2_SPC,        KC_BSPC
                                                             //`-----------------------------------------------------------'  `-----------------------------------------------------------'
  ),

    [_LAYER_1] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------------------------------------------------------------.                                ,-------------------------------------------------------------------------------------------------------.
                          XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                        MS_BTN2,       MS_BTN1,       XXXXXXX,       XXXXXXX,       XXXXXXX,                     XXXXXXX,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+----------------------------|
                          XXXXXXX,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       XXXXXXX,                                        MS_WHLL,       MS_WHLD,       MS_WHLU,       MS_WHLR,       XXXXXXX,                     XXXXXXX,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+----------------------------|
                          XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                        XXXXXXX,       KC_VOLD,       KC_VOLU,       KC_PSCR,       XXXXXXX,                     XXXXXXX,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+----------------------------|
                                                                                      KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS,       KC_TRNS,       KC_TRNS
                                                             //`-----------------------------------------------------------'  `-----------------------------------------------------------'
  ),
    [_LAYER_2] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------------------------------------------------------------.                                ,-------------------------------------------------------------------------------------------------------.
                          XXXXXXX,       XXXXXXX,        KC_F12,         KC_F9,         KC_F8,         KC_F7,                                        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                     XXXXXXX,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+----------------------------|
                          XXXXXXX,       XXXXXXX,        KC_F11,         KC_F6,         KC_F5,         KC_F4,                                        XXXXXXX,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,                     XXXXXXX,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+----------------------------|
                          XXXXXXX,       XXXXXXX,        KC_F10,         KC_F3,         KC_F2,         KC_F1,                                        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                     XXXXXXX,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+----------------------------|
                                                                                      KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS,       KC_TRNS,       KC_TRNS
                                                             //`-----------------------------------------------------------'  `-----------------------------------------------------------'
  ),
    [_LAYER_3] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------------------------------------------------------------.                                ,-------------------------------------------------------------------------------------------------------.
                          XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                     XXXXXXX,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+----------------------------|
                          XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                     XXXXXXX,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+----------------------------|
                          XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                     XXXXXXX,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+----------------------------|
                                                                                      XXXXXXX,       XXXXXXX,       XXXXXXX,          XXXXXXX,       XXXXXXX,                      XXXXXXX
                                                             //`-----------------------------------------------------------'  `-----------------------------------------------------------'
  ),
    [_LAYER_4] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------------------------------------------------------------.                                ,-------------------------------------------------------------------------------------------------------.
                          XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                     LSFT(KC_6),      KC_ENTER,      KC_EQUAL,    LSFT(KC_4),       KC_LCBR,                     XXXXXXX,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+----------------------------|
                          XXXXXXX,       KC_LALT,       KC_LSFT,       KC_LCTL,       XXXXXXX,       XXXXXXX,                                        KC_LEFT,       KC_DOWN,         KC_UP,      KC_RIGHT,       KC_QUOT,                     XXXXXXX,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+----------------------------|
                          XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                         KC_TAB,     KC_ESCAPE,    LSFT(KC_5),      KC_SLASH,       KC_LPRN,                     XXXXXXX,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+----------------------------|
                                                                                      KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS,  RGUI(KC_SPC),       KC_TRNS
                                                             //`-----------------------------------------------------------'  `-----------------------------------------------------------'
  ),
    [_LAYER_5] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------------------------------------------------------------.                                ,-------------------------------------------------------------------------------------------------------.
                          XXXXXXX,        KC_GRV,          KC_0,          KC_9,          KC_8,          KC_7,                                        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                     XXXXXXX,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+----------------------------|
                          XXXXXXX,       KC_MINS,       XXXXXXX,          KC_6,          KC_5,          KC_4,                                        XXXXXXX,       XXXXXXX,       KC_LCTL,       KC_LSFT,       KC_LALT,                     XXXXXXX,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+----------------------------|
                          XXXXXXX,       KC_LBRC,       XXXXXXX,          KC_3,          KC_2,          KC_1,                                        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                     XXXXXXX,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+----------------------------|
                                                                                      KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS,       KC_TRNS,                      KC_TRNS
                                                             //`-----------------------------------------------------------'  `-----------------------------------------------------------'
  )

};


bool kc_minus(uint16_t keycode, bool is_pressed, bool is_tap) {
    bool is_key = keycode == KC_MINS;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "KC_MINS", keycode, is_pressed);

    if (!(get_mods() & MOD_MASK_SHIFT)) {
        return false;
    }

    tap_code(KC_EQUAL);
    return true;
}

bool kc_left_bracket(uint16_t keycode, bool is_pressed, bool is_tap) {
    bool is_key = keycode == KC_LBRC;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "kc_left_bracket", keycode, is_pressed);

    if (!(get_mods() & MOD_MASK_SHIFT)) {
        return false;
    }

    uint8_t mod_state = get_mods();
    set_mods(mod_state & ~MOD_MASK_SHIFT);
    tap_code(KC_RIGHT_BRACKET);
    set_mods(mod_state);
    return true;
}

bool kc_left_paren(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == KC_LEFT_PAREN;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "KC_LEFT_PAREN", keycode, is_pressed);

    if (get_mods() & MOD_MASK_SHIFT) {
        tap_code(KC_0);
        return true;
    }

    tap_code16(KC_LEFT_PAREN);
    return true;
}

bool kc_question(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == KC_QUESTION;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "KC_QUESTION", keycode, is_pressed);

    if (get_mods() & MOD_MASK_SHIFT) {
        tap_code(KC_BACKSLASH);
        return true;
    }

    tap_code16(KC_QUESTION);
    return true;
}

bool kc_lcbr(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == KC_LCBR;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "KC_LCBR", keycode, is_pressed);

    if (get_mods() & MOD_MASK_SHIFT) {
        tap_code(KC_RIGHT_BRACKET);
        return true;
    }

    tap_code16(S(KC_LEFT_BRACKET));
    return true;
}

bool kc_equal(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == KC_EQUAL;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "KC_EQUAL", keycode, is_pressed);

    if (get_mods() & MOD_MASK_SHIFT) {
        tap_code(KC_MINUS);
        return true;
    }

    tap_code(KC_EQUAL);
    return true;
}

bool kc_slash(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == KC_SLASH;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "KC_SLASH", keycode, is_pressed);

    if (get_mods() & MOD_MASK_SHIFT) {
        uint8_t mod_state = get_mods();
        set_mods(mod_state & ~MOD_MASK_SHIFT);
        tap_code(KC_BACKSLASH);
        set_mods(mod_state);
        return true;
    }

    tap_code(KC_SLASH);
    return true;
}

bool kc_dot(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == KC_DOT;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "KC_DOT", keycode, is_pressed);

    if (get_mods() & MOD_MASK_SHIFT) {
        uint8_t mod_state = get_mods();
        set_mods(mod_state & ~MOD_MASK_SHIFT);
        tap_code(KC_COMMA);
        set_mods(mod_state);
        return true;
    }

    tap_code(KC_DOT);
    return true;
}

bool kc_labk(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == KC_LABK;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "KC_LABK", keycode, is_pressed);

    if (get_mods() & MOD_MASK_SHIFT) {
        tap_code16(KC_RABK);
        return true;
    }

    tap_code16(KC_LABK);
    return true;
}

bool ms_whlu(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == MS_WHLU;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "MS_WHLU", keycode, is_pressed);

    if (get_mods() & MOD_MASK_SHIFT) {
        tap_code16(MS_UP);
        return true;
    }

    tap_code16(MS_WHLU);
    return true;
}

bool ms_whld(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == MS_WHLD;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "MS_WHLD", keycode, is_pressed);

    if (get_mods() & MOD_MASK_SHIFT) {
        tap_code16(MS_DOWN);
        return true;
    }

    tap_code16(MS_WHLD);
    return true;
}

bool ms_whll(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == MS_WHLL;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "MS_WHLL", keycode, is_pressed);

    if (get_mods() & MOD_MASK_SHIFT) {
        tap_code16(MS_LEFT);
        return true;
    }

    tap_code16(MS_WHLL);
    return true;
}

bool ms_whlr(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == MS_WHLR;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "MS_WHLR", keycode, is_pressed);

    if (get_mods() & MOD_MASK_SHIFT) {
        tap_code16(MS_RGHT);
        return true;
    }

    tap_code16(MS_WHLR);
    return true;
}

#ifdef OLED_ENABLE
#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef OLED_ENABLE
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
#endif

    dprintf("Location: %s, kc: 0x%04X, pressed: %u, time: %5u, int: %u, count: %u\n", "process_record_user", keycode, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);

    if(kc_minus(keycode, record->event.pressed, record->tap.count)){
        return false;
    }

    if(kc_left_bracket(keycode, record->event.pressed, record->tap.count)){
        return false;
    }

    if(kc_left_paren(keycode, record->event.pressed)){
        return false;
    }

    if(kc_question(keycode, record->event.pressed)){
        return false;
    }

    if(kc_lcbr(keycode, record->event.pressed)){
        return false;
    }

    if(kc_equal(keycode, record->event.pressed)){
        return false;
    }

    if(kc_slash(keycode, record->event.pressed)){
        return false;
    }

    if(kc_dot(keycode, record->event.pressed)){
        return false;
    }

    if(kc_labk(keycode, record->event.pressed)){
        return false;
    }

    if(ms_whlu(keycode, record->event.pressed)){
        return false;
    }

    if(ms_whld(keycode, record->event.pressed)){
        return false;
    }

    if(ms_whll(keycode, record->event.pressed)){
        return false;
    }

    if(ms_whlr(keycode, record->event.pressed)){
        return false;
    }

    return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  // debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

// const key_override_t left_key_override = ko_make_basic(MOD_MASK_GUI, KC_H, KC_LEFT);
// const key_override_t right_key_override = ko_make_basic(MOD_MASK_GUI, RSFT_L, KC_RIGHT);
// const key_override_t up_key_override = ko_make_basic(MOD_MASK_GUI, RCTL_K, KC_UP);
// const key_override_t down_key_override = ko_make_basic(MOD_MASK_GUI, RGUI_J, KC_DOWN);
// const key_override_t enter_key_override = ko_make_basic(MOD_MASK_GUI, KC_E, KC_ENTER);
// const key_override_t escape_key_override = ko_make_basic(MOD_MASK_GUI, KC_G, KC_ESC);
// const key_override_t tab_key_override = ko_make_basic(MOD_MASK_GUI, KC_N, KC_TAB);
//
// const key_override_t *key_overrides[] = {
//     &left_key_override,
//     &right_key_override,
//     &up_key_override,
//     &down_key_override,
//     &enter_key_override,
//     &escape_key_override,
//     &tab_key_override,
// };
