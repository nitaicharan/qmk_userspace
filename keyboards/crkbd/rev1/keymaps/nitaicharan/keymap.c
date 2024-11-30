#include QMK_KEYBOARD_H
#include "print.h"

enum layers {
    _BASE_LAYER = 0,
    _NUMBER_LAYER = 1,
    _MEDIA_LAYER = 2
};

enum custom_keys {
    CKC_1_1 = SAFE_RANGE,
    CKC_1_4,
    CKC_1_12,
    CKC_1_13,
    CKC_1_14,
    CKC_1_15,
    CKC_1_16,
    CKC_1_17,
    CKC_1_18,
    CKC_1_19,
    CKC_1_20,
    CKC_1_21,
    CKC_1_22,
    CKC_1_23,
    CKC_1_24,
    CKC_1_25,
    CKC_1_31,
    CKC_1_33,
    CKC_1_34,
    CKC_1_35,
    CKC_1_36,
    // Symbols
    CKC_SLSH_BSLS,              // Forward slash and backslash
    CKC_EQUL_UNDS,              // Equal and underscore
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE_LAYER] = LAYOUT_split_3x6_3(
  //|-------------------------------------------------------------------------------------------------------.                                ,-------------------------------------------------------------------------------------------------------|
        LT(_NUMBER_LAYER, KC_GRV),          KC_Q,          KC_W,       CKC_1_4,          KC_R,          KC_T,                                           KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,                    CKC_1_12,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+----------------------------|
                         CKC_1_13,      CKC_1_14,      CKC_1_15,      CKC_1_16,      CKC_1_17,      CKC_1_18,                                       CKC_1_19,      CKC_1_20,      CKC_1_21,      CKC_1_22,      CKC_1_23,                    CKC_1_24,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+----------------------------|
                         CKC_1_25,          KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,                                       CKC_1_31,          KC_M,      CKC_1_33,      CKC_1_34,      CKC_1_35,                    CKC_1_36,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+----------------------------|
                                                                               LGUI_T(KC_DEL),      KC_SPACE,       KC_LALT,          KC_RALT,      KC_SPACE,              RGUI_T(KC_BSPC)
                                                             //`-----------------------------------------------------------'  `-----------------------------------------------------------'
  ),

    [_NUMBER_LAYER] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------------------------------------------------------------.                                ,-------------------------------------------------------------------------------------------------------.
                          XXXXXXX,       XXXXXXX,        KC_F12,         KC_F9,         KC_F8,         KC_F7,                                           KC_7,          KC_8,          KC_9,          KC_0, CKC_SLSH_BSLS,               CKC_EQUL_UNDS,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+----------------------------|
                          KC_TRNS,       XXXXXXX,        KC_F11,         KC_F6,         KC_F5,         KC_F4,                                           KC_4,          KC_5,          KC_6,       XXXXXXX,       XXXXXXX,                     KC_TRNS,
  //|----------------------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+----------------------------|
                          KC_TRNS,       XXXXXXX,        KC_F10,         KC_F3,         KC_F2,         KC_F1,                                           KC_1,          KC_2,          KC_3,       KC_PSCR,       XXXXXXX,                     KC_TRNS,
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


uint16_t last_key_timer;
uint16_t rctrl_timer;
uint16_t lctrl_timer;
uint16_t rsft_timer;
uint16_t lsft_timer;
uint16_t lalt_timer;
uint16_t ralt_timer;
uint16_t lgui_timer;
uint16_t rgui_timer;


bool ckc_plus_mnus_registed = false;

void watch_modifiers(uint16_t keycode, bool is_pressed) {
    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "watch_modifiers", keycode, is_pressed);
    bool is_rctl = keycode == KC_RIGHT_CTRL;
    bool is_lctl = keycode == KC_LEFT_CTRL;
    bool is_lsft = keycode == KC_LEFT_SHIFT;
    bool is_rsft = keycode == KC_RIGHT_SHIFT;
    bool is_lalt = keycode == KC_LEFT_ALT;
    bool is_ralt = keycode == KC_RIGHT_ALT;
    bool is_lgui = keycode == KC_LEFT_GUI;
    bool is_rgui = keycode == KC_RIGHT_GUI;

    if (is_pressed) {
        last_key_timer = timer_read();
    }

    if (!is_rsft && !is_lsft && !is_rctl && !is_lctl && !is_lalt && !is_ralt && !is_lgui && !is_rgui) {
        return;
    }

    if (is_rctl) {
        if (is_pressed) {
            rctrl_timer = last_key_timer;
            return;
        }

        return;
    }

    if (is_lctl) {
        if (is_pressed) {
            lctrl_timer = last_key_timer;
            return;
        }

        return;
    }

    if (is_rsft) {
        if (is_pressed) {
            rsft_timer = last_key_timer;
            return;
        }

        return;
    }

    if (is_lsft) {
        if (is_pressed) {
            lsft_timer = last_key_timer;
            return;
        }

        return;
    }

    if (is_lalt) {
        if (is_pressed) {
            lalt_timer = last_key_timer;
            return;
        }
        return;
    }

    if (is_ralt) {
        if (is_pressed) {
            ralt_timer = last_key_timer;
            return;
        }
        return;
    }

    if (is_lgui) {
        if (is_pressed) {
            lgui_timer = last_key_timer;
            return;
        }
        return;
    }

    if (is_rgui) {
        if (is_pressed) {
            rgui_timer = last_key_timer;
            return;
        }
        return;
    }
}

bool ckc_1_13(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == CKC_1_13;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "CKC_1_13", keycode, is_pressed);

    if (get_mods() & MOD_MASK_SHIFT) {
        uint8_t mod_state = get_mods();
        set_mods(mod_state & ~MOD_MASK_SHIFT);
        tap_code(KC_MINUS);
        set_mods(mod_state);
        return true;
    }

    tap_code16(S(KC_EQUAL));
    return true;
}

bool ckc_1_24(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == CKC_1_24;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "CKC_1_24", keycode, is_pressed);

    if (get_mods() & MOD_MASK_SHIFT) {
        tap_code16(S(KC_QUOTE));
        return true;
    }

    tap_code(KC_QUOTE);
    return true;
}

bool ckc_1_25(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == CKC_1_25;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "CK_1_25", keycode, is_pressed);

    if (get_mods() & MOD_MASK_SHIFT) {
        uint8_t mod_state = get_mods();
        set_mods(mod_state & ~MOD_MASK_SHIFT);
        tap_code(KC_RBRC);
        set_mods(mod_state);
        return true;
    }

    tap_code(KC_LBRC);
    return true;
}

bool ckc_1_36(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == CKC_1_36;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "CKC_1_36", keycode, is_pressed);

    if (get_mods() & MOD_MASK_SHIFT) {
        tap_code16(S(KC_0));
        return true;
    }

    tap_code16(S(KC_9));
    return true;
}

bool ckc_1_35(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == CKC_1_35;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "CKC_1_35", keycode, is_pressed);

    if (get_mods() & MOD_MASK_SHIFT) {
        tap_code16(S(KC_BSLS));
        return true;
    }

    tap_code16(S(KC_SLASH));
    return true;
}

bool ckc_1_33(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == CKC_1_33;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "CKC_1_33", keycode, is_pressed);

    if (get_mods() & MOD_MASK_SHIFT) {
        tap_code16(S(KC_DOT));
        return true;
    }

    tap_code16(S(KC_COMMA));
    return true;
}

bool ckc_1_34(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == CKC_1_34;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "CKC_1_34", keycode, is_pressed);

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

bool ckc_equl_unds(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == CKC_EQUL_UNDS;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "CKC_EQUL_UNDS", keycode, is_pressed);

    if (get_mods() & MOD_MASK_SHIFT) {
        tap_code16(S(KC_MINUS));
        return true;
    }

    tap_code(KC_EQUAL);
    return true;

}

bool ckc_1_12(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == CKC_1_12;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "CKC_1_12", keycode, is_pressed);

    if (get_mods() & MOD_MASK_SHIFT) {
        tap_code16(S(KC_RIGHT_BRACKET));
        return true;
    }

    tap_code16(S(KC_LEFT_BRACKET));
    return true;
}

bool ckc_slsh_bsls(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == CKC_SLSH_BSLS;

    if (!is_key || !is_pressed){
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "CKC_SLSH_BSLS", keycode, is_pressed);

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

bool ckc_1_15(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == CKC_1_15;

    if (!is_key) {
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "CKC_1_15", keycode, is_pressed);

    if (is_pressed && get_mods() & MOD_MASK_SHIFT) {
        uint8_t mod_state = get_mods();
        set_mods(mod_state & ~MOD_MASK_SHIFT);
        tap_code16(S(KC_S));
        set_mods(mod_state);
        return true;
    }

    if (is_pressed) {
        register_code(KC_LEFT_SHIFT);
        watch_modifiers(KC_LEFT_SHIFT, is_pressed);
        return true;
    }

    unregister_code(KC_LEFT_SHIFT);
    if (timer_elapsed(lsft_timer) < TAPPING_TERM) {
        tap_code(KC_S);
    }
    return true;
}

bool ckc_1_14(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == CKC_1_14;

    if (!is_key) {
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "CKC_1_14", keycode, is_pressed);

    if (is_pressed) {
        register_code(KC_LEFT_ALT);
        watch_modifiers(KC_LEFT_ALT, is_pressed);
        return true;
    }

    unregister_code(KC_LEFT_ALT);
    if (timer_elapsed(lalt_timer) < TAPPING_TERM) {
        tap_code(KC_A);
    }
    return true;
}

bool ckc_1_16(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == CKC_1_16;

    if (!is_key) {
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "CKC_1_16", keycode, is_pressed);

    if (is_pressed) {
        register_code(KC_LEFT_CTRL);
        watch_modifiers(KC_LEFT_CTRL, is_pressed);
        return true;
    }

    unregister_code(KC_LEFT_CTRL);
    if (timer_elapsed(lctrl_timer) < TAPPING_TERM) {
        tap_code(KC_D);
    }
    return true;
}

bool ckc_1_17(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == CKC_1_17;

    if (!is_key) {
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "CKC_1_17", keycode, is_pressed);

    if (is_pressed) {
        register_code(KC_LEFT_GUI);
        watch_modifiers(KC_LEFT_GUI, is_pressed);
        return true;
    }

    unregister_code(KC_LEFT_GUI);
    if (timer_elapsed(lgui_timer) < TAPPING_TERM) {
        tap_code(KC_F);
    }
    return true;
}

bool ckc_1_19(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == CKC_1_19;

    if (!is_key) {
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "CKC_1_19", keycode, is_pressed);

    if (!is_pressed) {
        return true;
    }

    if (get_mods() & MOD_MASK_GUI) {
        uint8_t mod_state = get_mods();
        set_mods(mod_state & ~MOD_MASK_GUI);
        tap_code(KC_LEFT);
        set_mods(mod_state);
        return true;
    }

    tap_code(KC_H);
    return true;
}

bool ckc_1_20(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == CKC_1_20;

    if (!is_key) {
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "CKC_1_20", keycode, is_pressed);

    if (is_pressed && get_mods() & MOD_MASK_GUI) {
        uint8_t mod_state = get_mods();
        set_mods(mod_state & ~MOD_MASK_GUI);
        tap_code(KC_DOWN);
        set_mods(mod_state);
        return true;
    }

    if (is_pressed) {
        register_code(KC_RIGHT_GUI);
        watch_modifiers(KC_RIGHT_GUI, is_pressed);
        return true;
    }

    unregister_code(KC_RIGHT_GUI);
    if (timer_elapsed(rgui_timer) > TAPPING_TERM) {
        return true;
    }

    tap_code(KC_J);
    return true;
}

bool ckc_1_21(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == CKC_1_21;

    if (!is_key) {
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "CKC_1_21", keycode, is_pressed);

    if (is_pressed && get_mods() & MOD_MASK_GUI) {
        uint8_t mod_state = get_mods();
        set_mods(mod_state & ~MOD_MASK_GUI);
        tap_code(KC_UP);
        set_mods(mod_state);
        return true;
    }

    if (is_pressed) {
        register_code(KC_RIGHT_CTRL);
        watch_modifiers(KC_RIGHT_CTRL, is_pressed);
        return true;
    }

    unregister_code(KC_RIGHT_CTRL);
    if (timer_elapsed(rctrl_timer) > TAPPING_TERM) {
        return true;
    }

    tap_code(KC_K);
    return true;
}

bool ckc_1_22(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == CKC_1_22;

    if (!is_key) {
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "CKC_1_22", keycode, is_pressed);

    if (is_pressed && get_mods() & MOD_MASK_GUI) {
        uint8_t mod_state = get_mods();
        set_mods(mod_state & ~MOD_MASK_GUI);
        tap_code(KC_RIGHT);
        set_mods(mod_state);
        return true;
    }

    if (is_pressed && get_mods() & MOD_MASK_SHIFT) {
        uint8_t mod_state = get_mods();
        set_mods(mod_state & ~MOD_MASK_SHIFT);
        tap_code16(S(KC_L));
        set_mods(mod_state);
        return true;
    }

    if (is_pressed) {
        register_code(KC_RIGHT_SHIFT);
        watch_modifiers(KC_RIGHT_SHIFT, is_pressed);
        return true;
    }

    unregister_code(KC_RIGHT_SHIFT);
    if (timer_elapsed(rsft_timer) > TAPPING_TERM) {
        return true;
    }

    tap_code(KC_L);
    return true;
}

bool ckc_1_23(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == CKC_1_23;

    if (!is_key) {
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "CKC_1_23", keycode, is_pressed);

    if (is_pressed) {
        register_code(KC_RIGHT_ALT);
        watch_modifiers(KC_RIGHT_ALT, is_pressed);
        return true;
    }

    unregister_code(KC_RIGHT_ALT);
    if (timer_elapsed(ralt_timer) < TAPPING_TERM) {
        tap_code(KC_SEMICOLON);
    }
    return true;
}

bool ckc_1_4(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == CKC_1_4;

    if (!is_key) {
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "CKC_1_4", keycode, is_pressed);

    if (!is_pressed) {
        return true;
    }

    if (get_mods() & MOD_MASK_GUI) {
        uint8_t mod_state = get_mods();
        set_mods(mod_state & ~MOD_MASK_GUI);
        tap_code(KC_ENTER);
        set_mods(mod_state);
        return true;
    }

    tap_code(KC_E);

    return true;
}

bool ckc_1_18(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == CKC_1_18;

    if (!is_key) {
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "CKC_1_18", keycode, is_pressed);

    if (!is_pressed) {
        return true;
    }

    if (get_mods() & MOD_MASK_GUI) {
        uint8_t mod_state = get_mods();
        set_mods(mod_state & ~MOD_MASK_GUI);
        tap_code(KC_ESC);
        set_mods(mod_state);
        return true;
    }

    tap_code(KC_G);
    return true;
}

bool ckc_1_31(uint16_t keycode, bool is_pressed) {
    bool is_key = keycode == CKC_1_31;

    if (!is_key) {
        return false;
    }

    dprintf("Location: %s, kc: 0x%04X, pressed: %u\n", "CKC_1_31", keycode, is_pressed);

    if (!is_pressed) {
        return true;
    }

    if (get_mods() & MOD_MASK_GUI) {
        uint8_t mod_state = get_mods();
        set_mods(mod_state & ~MOD_MASK_GUI);
        tap_code(KC_TAB);
        set_mods(mod_state);
        return true;
    }

    tap_code(KC_N);
    return true;
}


void debug_log(char location[], uint16_t keycode, keyrecord_t *record) {
    dprintf("Location: %s, kc: 0x%04X, pressed: %u, time: %5u, int: %u, count: %u\n", location, keycode, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
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

    debug_log("process_record_user", keycode, record);
    watch_modifiers(keycode, record->event.pressed);

    if(ckc_1_4(keycode, record->event.pressed)){
        return false;
    }

    if(ckc_1_12(keycode, record->event.pressed)){
        return false;
    }

    if(ckc_1_13(keycode, record->event.pressed)){
        return false;
    }

    if(ckc_1_14(keycode, record->event.pressed)){
        return false;
    }

    if(ckc_1_15(keycode, record->event.pressed)){
        return false;
    }

    if(ckc_1_16(keycode, record->event.pressed)){
        return false;
    }

    if(ckc_1_17(keycode, record->event.pressed)){
        return false;
    }

    if(ckc_1_18(keycode, record->event.pressed)){
        return false;
    }

    if(ckc_1_19(keycode, record->event.pressed)){
        return false;
    }

    if(ckc_1_20(keycode, record->event.pressed)){
        return false;
    }

    if(ckc_1_21(keycode, record->event.pressed)){
        return false;
    }

    if(ckc_1_22(keycode, record->event.pressed)){
        return false;
    }

    if(ckc_1_23(keycode, record->event.pressed)){
        return false;
    }

    if(ckc_1_24(keycode, record->event.pressed)){
        return false;
    }

    if(ckc_1_25(keycode, record->event.pressed)){
        return false;
    }

    if(ckc_1_31(keycode, record->event.pressed)){
        return false;
    }

    if(ckc_slsh_bsls(keycode, record->event.pressed)){
        return false;
    }

    if(ckc_equl_unds(keycode, record->event.pressed)){
        return false;
    }

    if(ckc_1_34(keycode, record->event.pressed)){
        return false;
    }

    if(ckc_1_33(keycode, record->event.pressed)){
        return false;
    }

    if(ckc_1_35(keycode, record->event.pressed)){
        return false;
    }

    if(ckc_1_36(keycode, record->event.pressed)){
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
