#include QMK_KEYBOARD_H
#include "print.h"

enum layers {
    _BASE_LAYER = 0,
    _NUMBER_LAYER = 1,
    _MEDIA_LAYER = 2
};

enum custom_keys {
    CKC_QSTM_PIPE = SAFE_RANGE,
    CKC_MORE_LESS,
    CKC_SLSH_BSLS,
    CKC_DOT_COMMA,
    CKC_EQUL_UNDS,
    CKC_PLUS_MNUS,
    CKC_LCBS_RCBS,
    CKC_LSBS_RSBS,
    CKC_LPTS_RPTS,
    CKC_SQUT_DQUT,
    CKC_RCTL,
    CKC_LCTL,
    CKC_RSFT,
    CKC_LSFT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE_LAYER] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------------------------------------------------------------.                                ,-------------------------------------------------------------------------------------------------------.
        LT(_NUMBER_LAYER, KC_GRV),          KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,                                           KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,               CKC_LCBS_RCBS,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+----------------------------|
                         CKC_LSFT,          KC_A,          KC_S,          KC_D,          KC_F,          KC_G,                                           KC_H,          KC_J,          KC_K,          KC_L,       KC_SCLN,                    CKC_RSFT,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+----------------------------|
                         CKC_LCTL,          KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,                                           KC_N,          KC_M, CKC_MORE_LESS, CKC_DOT_COMMA, CKC_SLSH_BSLS,                    CKC_RCTL,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+----------------------------|
                                                                               LGUI_T(KC_DEL),      KC_SPACE,       KC_LALT,          KC_RALT,      KC_SPACE,              RGUI_T(KC_BSPC)
                                                             //`-----------------------------------------------------------'  `-----------------------------------------------------------'
  ),

    [_NUMBER_LAYER] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------------------------------------------------------------.                                ,-------------------------------------------------------------------------------------------------------.
                          XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                           KC_7,          KC_8,          KC_9,          KC_0, CKC_QSTM_PIPE,               CKC_EQUL_UNDS,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+----------------------------|
                          KC_TRNS,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                           KC_4,          KC_5,          KC_6,       XXXXXXX,       XXXXXXX,                     KC_TRNS,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+----------------------------|
                          KC_TRNS,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                           KC_1,          KC_2,          KC_3,       KC_PSCR,       XXXXXXX,                     KC_TRNS,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+----------------------------|
                                                                                      KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS,       KC_TRNS,                      KC_TRNS
                                                             //`-----------------------------------------------------------'  `-----------------------------------------------------------'
  ),

    [_MEDIA_LAYER] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------------------------------------------------------------.                                ,-------------------------------------------------------------------------------------------------------.
                          XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                     XXXXXXX,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+----------------------------|
                          KC_TRNS,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                        XXXXXXX,       KC_VOLD,       KC_VOLU,      XXXXXXX,       XXXXXXX,                      KC_TRNS,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+----------------------------|
                          KC_TRNS,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                        XXXXXXX,       UG_VALD,       UG_VALU,       XXXXXXX,       XXXXXXX,                     KC_TRNS,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+----------------------------|
                                                                                      KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS,       KC_TRNS,                      KC_TRNS
                                                             //`-----------------------------------------------------------'  `-----------------------------------------------------------'
  )
};

bool rctrl_held = false;
bool lctrl_held = false;
bool rsft_held = false;
bool lsft_held = false;

uint16_t last_key_timer;
uint16_t rctrl_timer;
uint16_t lctrl_timer;
uint16_t rsft_timer;
uint16_t lsft_timer;

bool is_tap_rctrl;
bool is_tap_lctrl;
bool is_tap_rsft;
bool is_tap_lsft;

void watch_modifiers(uint16_t keycode, keyrecord_t *record) {
    bool is_rctl = keycode == CKC_RCTL;
    bool is_lctl = keycode == CKC_LCTL;
    bool is_rsft = keycode == CKC_RSFT;
    bool is_lsft = keycode == CKC_LSFT;

    if (record->event.pressed) {
        last_key_timer = timer_read();
    }

    if (!is_rsft && !is_lsft && !is_rctl && !is_lctl) {
        return;
    }

    if (is_rctl) {
        rctrl_held = record->event.pressed;

        if (record->event.pressed) {
            rctrl_timer = timer_read();
            return;
        }

        is_tap_rctrl = timer_elapsed(rctrl_timer) < TAPPING_TERM;
        return;
    }

    if (is_lctl) {
        lctrl_held = record->event.pressed;

        if (record->event.pressed) {
            lctrl_timer = timer_read();
            return;
        }

        is_tap_lctrl = timer_elapsed(lctrl_timer) < TAPPING_TERM;
        return;
    }

    if (is_rsft) {
        rsft_held = record->event.pressed;

        if (record->event.pressed) {
            rsft_timer = timer_read();
            return;
        }

        is_tap_rsft = timer_elapsed(rsft_timer) < TAPPING_TERM;
        return;
    }

    if (is_lsft) {
        lsft_held = record->event.pressed;

        if (record->event.pressed) {
            lsft_timer = timer_read();
            return ;
        }

        is_tap_lsft = timer_elapsed(lsft_timer) < TAPPING_TERM;
        return;
    }
}

bool ckc_qstm_pipe(uint16_t keycode, keyrecord_t *record) {
    bool is_key = keycode == CKC_QSTM_PIPE;
    bool is_held = record->event.pressed;

    if (!is_key || !is_held){
        return false;
    }

    if (lsft_held) {
        register_code(KC_LEFT_SHIFT);
        tap_code(KC_BSLS);
        unregister_code(KC_LEFT_SHIFT);
        return true;
    }

    register_code(KC_LEFT_SHIFT);
    tap_code(KC_SLASH);
    unregister_code(KC_LEFT_SHIFT);
    return true;
}

bool ckc_more_less(uint16_t keycode, keyrecord_t *record) {
    bool is_key = keycode == CKC_MORE_LESS;
    bool is_held = record->event.pressed;

    if (!is_key || !is_held){
        return false;
    }

    if (lsft_held) {
        register_code(KC_LEFT_SHIFT);
        tap_code(KC_DOT);
        unregister_code(KC_LEFT_SHIFT);
        return true;
    }

    register_code(KC_LEFT_SHIFT);
    tap_code(KC_COMMA);
    unregister_code(KC_LEFT_SHIFT);
    return true;
}

bool ckc_dot_comma(uint16_t keycode, keyrecord_t *record) {
    bool is_key = keycode == CKC_DOT_COMMA;
    bool is_held = record->event.pressed;

    if (!is_key || !is_held){
        return false;
    }

    if (lsft_held) {
        unregister_code(KC_LEFT_SHIFT);
        tap_code(KC_COMMA);
        register_code(KC_LEFT_SHIFT);
        return true;
    }

    tap_code(KC_DOT);
    return true;
}

bool ckc_equl_unds(uint16_t keycode, keyrecord_t *record) {
    bool is_key = keycode == CKC_EQUL_UNDS;
    bool is_held = record->event.pressed;

    if (!is_key || !is_held){
        return false;
    }

    if (lsft_held) {
        register_code(KC_LEFT_SHIFT);
        tap_code(KC_MINUS);
        unregister_code(KC_LEFT_SHIFT);
        return true;
    }

    tap_code(KC_EQUAL);
    return true;

}

bool ckc_lcbs_rcbs(uint16_t keycode, keyrecord_t *record) {
    bool is_key = keycode == CKC_LCBS_RCBS;
    bool is_held = record->event.pressed;

    if (!is_key || !is_held){
        return false;
    }

    if (lsft_held) {
        register_code(KC_LEFT_SHIFT);
        tap_code(KC_RIGHT_BRACKET);
        unregister_code(KC_LEFT_SHIFT);
        return true;
    }


    register_code(KC_LEFT_SHIFT);
    tap_code(KC_LEFT_BRACKET);
    unregister_code(KC_LEFT_SHIFT);
    return true;
}

bool ckc_lsbs_rsbs(uint16_t keycode, keyrecord_t *record) {
    bool is_key = keycode == CKC_LSBS_RSBS;
    bool is_held = record->event.pressed;

    if (!is_key || !is_held){
        return false;
    }

    if (!rsft_held) {
        tap_code(KC_LBRC);
        return true;
    }

    unregister_code(KC_RIGHT_SHIFT);
    tap_code(KC_RBRC);
    register_code(KC_RIGHT_SHIFT);
    return true;
}

bool ckc_slsh_bsls(uint16_t keycode, keyrecord_t *record) {
    bool is_key = keycode == CKC_SLSH_BSLS;
    bool is_held = record->event.pressed;

    if (!is_key || !is_held){
        return false;
    }

    if (lsft_held) {
        unregister_code(KC_LEFT_SHIFT);
        tap_code(KC_BACKSLASH);
        register_code(KC_LEFT_SHIFT);
        return true;
    }

    tap_code(KC_SLASH);
    return true;

}

bool ckc_plus_mnus(uint16_t keycode, keyrecord_t *record) {
    bool is_key = keycode == CKC_PLUS_MNUS;
    bool is_held = record->event.pressed;

    if (!is_key || !is_held){
        return false;
    }

    if (rsft_held) {
        unregister_code(KC_RIGHT_SHIFT);
        tap_code(KC_MINUS);
        register_code(KC_RIGHT_SHIFT);
        return true;
    }
    register_code(KC_LEFT_SHIFT);
    tap_code(KC_EQUAL);
    unregister_code(KC_LEFT_SHIFT);
    return true;
}

bool ckc_lpts_rpts(uint16_t keycode, keyrecord_t *record) {
    bool is_key = keycode == CKC_LPTS_RPTS;
    bool is_held = record->event.pressed;

    if (!is_key || !is_held){
        return false;
    }

    if (lsft_held) {
        register_code(KC_LEFT_SHIFT);
        tap_code(KC_0);
        unregister_code(KC_LEFT_SHIFT);
        return true;
    }

    register_code(KC_LEFT_SHIFT);
    tap_code(KC_9);
    unregister_code(KC_LEFT_SHIFT);
    return true;
}

bool ckc_squt_dqut(uint16_t keycode, keyrecord_t *record) {
    bool is_key = keycode == CKC_SQUT_DQUT;
    bool is_held = record->event.pressed;

    if (!is_key || !is_held){
        return false;
    }

    if (lsft_held) {
        register_code(KC_LEFT_SHIFT);
        tap_code(KC_QUOTE);
        unregister_code(KC_LEFT_SHIFT);
        return true;
    }

    tap_code(KC_QUOTE);
    return true;
}

bool ckc_rctl(uint16_t keycode, keyrecord_t *record) {
    bool is_key = keycode == CKC_RCTL;
    bool is_held = record->event.pressed;


    if (!is_key){
        return false;
    }

    if (is_held) {
        register_code(KC_RIGHT_CTRL);
        rctrl_timer = timer_read();
        return true;
    }

    unregister_code(KC_RIGHT_CTRL);
    is_tap_rctrl = timer_elapsed(rctrl_timer) < TAPPING_TERM;

    if (!is_tap_rctrl || rctrl_timer < last_key_timer) {
        return false;
    }

    record->event.pressed = 1;
    bool response = ckc_lpts_rpts(CKC_LPTS_RPTS, record);
    record->event.pressed = 0;
    return response;
}

bool ckc_lctl(uint16_t keycode, keyrecord_t *record) {
    bool is_key = keycode == CKC_LCTL;
    bool is_held = record->event.pressed;


    if (!is_key){
        return false;
    }

    if (is_held) {
        register_code(KC_LEFT_CTRL);
        lctrl_timer = timer_read();
        return true;
    }

    unregister_code(KC_LEFT_CTRL);
    is_tap_lctrl = timer_elapsed(lctrl_timer) < TAPPING_TERM;

    if (!is_tap_lctrl || lctrl_timer < last_key_timer) {
        return false;
    }

    record->event.pressed = 1;
    bool response = ckc_lsbs_rsbs(CKC_LSBS_RSBS, record);
    record->event.pressed = 0;
    return response;
}

bool ckc_lsft(uint16_t keycode, keyrecord_t *record) {
    bool is_key = keycode == CKC_LSFT;
    bool is_held = record->event.pressed;


    if (!is_key){
        return false;
    }

    if (is_held) {
        register_code(KC_LEFT_SHIFT);
        lsft_timer = timer_read();
        return true;
    }

    unregister_code(KC_LEFT_SHIFT);
    is_tap_lsft = timer_elapsed(lsft_timer) < TAPPING_TERM;

    if (!is_tap_lsft || lsft_timer < last_key_timer) {
        return false;
    }


    record->event.pressed = 1;
    bool response = ckc_plus_mnus(CKC_PLUS_MNUS, record);
    record->event.pressed = 0;
    return response;
}

bool ckc_rsft(uint16_t keycode, keyrecord_t *record) {
    bool is_key = keycode == CKC_RSFT;
    bool is_held = record->event.pressed;


    if (!is_key){
        return false;
    }

    if (is_held) {
        register_code(KC_RIGHT_SHIFT);
        rsft_timer = timer_read();
        return true;
    }

    unregister_code(KC_RIGHT_SHIFT);
    is_tap_rsft = timer_elapsed(rsft_timer) < TAPPING_TERM;

    if (!is_tap_rsft || rsft_timer < last_key_timer) {
        return false;
    }

    record->event.pressed = 1;
    bool response = ckc_squt_dqut(CKC_SQUT_DQUT, record);
    record->event.pressed = 0;
    return response;
}

void debug_log(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
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

    debug_log(keycode, record);
    watch_modifiers(keycode, record);

    if(ckc_lcbs_rcbs(keycode, record)){
        return false;
    }

    if(ckc_slsh_bsls(keycode, record)){
        return false;
    }

    if(ckc_equl_unds(keycode, record)){
        return false;
    }

    if(ckc_dot_comma(keycode, record)){
        return false;
    }

    if(ckc_more_less(keycode, record)){
        return false;
    }

    if(ckc_qstm_pipe(keycode, record)){
        return false;
    }

    if(ckc_rctl(keycode, record)){
        return false;
    }

    if(ckc_lctl(keycode, record)){
        return false;
    }

    if(ckc_rsft(keycode, record)){
        return false;
    }

    if(ckc_lsft(keycode, record)){
        return false;
    }

    return true;
}


const key_override_t delete_key_override = ko_make_basic(KC_RSFT, RGUI_T(KC_BSPC), KC_DEL);
const key_override_t left_key_override = ko_make_basic(MOD_MASK_GUI, KC_H, KC_LEFT);
const key_override_t right_key_override = ko_make_basic(MOD_MASK_GUI, KC_L, KC_RIGHT);
const key_override_t up_key_override = ko_make_basic(MOD_MASK_GUI, KC_K, KC_UP);
const key_override_t down_key_override = ko_make_basic(MOD_MASK_GUI, KC_J, KC_DOWN);
const key_override_t enter_key_override = ko_make_basic(MOD_MASK_GUI, KC_E, KC_ENTER);
const key_override_t escape_key_override = ko_make_basic(MOD_MASK_GUI, KC_G, KC_ESC);
const key_override_t tab_key_override = ko_make_basic(MOD_MASK_GUI, KC_N, KC_TAB);

const key_override_t **key_overrides = (const key_override_t *[]){
	&delete_key_override,
    &left_key_override,
    &right_key_override,
    &up_key_override,
    &down_key_override,
    &enter_key_override,
    &escape_key_override,
    &tab_key_override,
    NULL
};
