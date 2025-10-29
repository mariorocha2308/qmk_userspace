// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include <stdio.h>

#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
// const rgblight_segment_t PROGMEM capslock[] = RGBLIGHT_LAYER_SEGMENTS(
//     {6, 4, HSV_GREEN},       // Light 4 LEDs, starting with LED 6
//     {12, 4, HSV_GREEN}       // Light 4 LEDs, starting with LED 12
// );
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
// const rgblight_segment_t PROGMEM qwerty[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 2, HSV_CYAN}
// );
// // Light LEDs 11 & 12 in purple when keyboard layer 2 is active
// const rgblight_segment_t PROGMEM lower[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 2, HSV_RED}
// );
// // Light LEDs 13 & 14 in green when keyboard layer 3 is active
// const rgblight_segment_t PROGMEM raise[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 2, HSV_PURPLE}
// );
// // Light LEDs 13 & 14 in green when keyboard layer 3 is active
// // const rgblight_segment_t PROGMEM adjust[] = RGBLIGHT_LAYER_SEGMENTS(
// //     {13, 2, HSV_YELLOW}
// // );
//
// // Now define the array of layers. Later layers take precedence
// const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//     qwerty,    // Overrides caps lock layer
//     lower,    // Overrides other layers
//     raise // Overrides other layers
//     // adjust
// );
//
// void keyboard_post_init_user(void) {
//     // Enable the LED layers
//     rgblight_layers = my_rgb_layers;
// }
//
// // bool led_update_user(led_t led_state) {
// //     rgblight_set_layer_state(0, led_state.caps_lock);
//     //     return true;
//     // }
//
//     layer_state_t default_layer_state_set_user(layer_state_t state) {
//         rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
//         return state;
//     }
//
//     layer_state_t layer_state_set_user(layer_state_t state) {
//         rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
//         rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
//         return state;
//     }

    const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_ESC,    KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
        KC_TAB,    KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_ENT,
        KC_CAPS,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_PGUP,
        KC_LSFT,   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,    XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_PGDN,
                        KC_LCTL,KC_LGUI,KC_LALT, MO(_LOWER), KC_SPC,           KC_SPC, MO(_RAISE), KC_RALT, KC_RCTL, KC_RSFT
    ),

    [_LOWER] = LAYOUT(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,
        KC_LGUI, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_HOME, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_PGDN,
                            _______, _______, _______, _______, _______,       _______, MO(_ADJUST), _______, _______, _______
    ),

    [_RAISE] = LAYOUT(
        _______, _______ , _______ , _______ , _______ , _______,                   _______,  _______  , _______,  _______ ,  _______ ,_______,
        KC_TAB,  KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        KC_LCTL, KC_QUOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
                        _______, _______, _______, MO(_ADJUST), _______,       _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WREF,
        RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, KC_BRIU, KC_VOLU,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        RM_NEXT, RM_HUED, RM_SATD, RM_VALD, KC_BRID, KC_VOLD, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______
  )
};

#ifdef OLED_ENABLE

 static void render_logo(void) {
     // static const char PROGMEM qmk_logo[] = {
     //     0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
     //     0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
     //     0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
     // };
     //
     // oled_write_P(qmk_logo, false);

     // Custom home-made 32x128 art: Gaimon (see images directory)
     // Art was made with Gimp and QMK Logo editor (https://joric.github.io/qle) was used to generate the pixel matrix:
     static const char PROGMEM raw_logo[] = {
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,224,240,240,248,248,248,248,248,248,248,248,248,248,248,248,240,224,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,224,224,224,224,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,255,255,255,127,127, 63, 63, 63, 63, 63, 63,255,255,255,255,255,255,255,254,  0,  0,  0,  0,  0,  0,  0,  0,  0,240,252,254, 14,  7,  7,  3,131,131,135,135,135,134,  0,  0,  0,112,112, 48, 48, 48,112,240,224,128,  0,  0,  0,243,243,  0,  0,  0,  0,240,240, 96,112, 48,112,240,224,192, 96,112, 48,112,240,240,192,  2,  2,198,230,246,118, 54, 54,118,246,230,198,  2,  2,  0,240,240, 96,112, 48, 48,112,243,227,  1,  0, 12, 78,102, 32, 32,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  7, 15,159,223,207, 24,254,249,233,207,207,207,233,249,255, 57,131,223,143,  7,  3,  0,  0,  0,  0,  0, 96,252,184, 16,128,135, 31, 63, 56,112,112, 96, 97, 97,113,113, 63, 63,  0,  0, 62,126,119,103, 99, 99, 99,115,127, 63,  0,  0,  0,127,127,  0,  0,  0,  0,127,127,  0,  0,  0,  0,  0,127,127,  0,  0,  0,  0,  0,127,127,  0,  0, 31, 63,120,112, 98, 98,112,120, 63, 31,  0,  0,  0,127,127,  0,  0,  0,  0,  0,127,127,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0, 19, 31, 31, 31, 15, 15, 31, 31, 31, 23,  0,  0,  1,  1,  0,  0,  0,  0,  0,  0,  0, 24, 28, 15,  5,  7, 13, 24, 28, 14, 12,  8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     };
     oled_write_raw_P(raw_logo, sizeof(raw_logo));
 }


static void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
            break;
    }
}


char     key_name = ' ';
uint16_t last_keycode;
uint8_t  last_row;
uint8_t  last_col;

static const char PROGMEM code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

static void set_keylog(uint16_t keycode, keyrecord_t *record) {
    // save the row and column (useful even if we can't find a keycode to show)
    last_row = record->event.key.row;
    last_col = record->event.key.col;

    key_name     = ' ';
    last_keycode = keycode;
    if (IS_QK_MOD_TAP(keycode)) {
        if (record->tap.count) {
            keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
        } else {
            keycode = 0xE0 + biton(QK_MOD_TAP_GET_MODS(keycode) & 0xF) + biton(QK_MOD_TAP_GET_MODS(keycode) & 0x10);
        }
    } else if (IS_QK_LAYER_TAP(keycode) && record->tap.count) {
        keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
    } else if (IS_QK_MODS(keycode)) {
        keycode = QK_MODS_GET_BASIC_KEYCODE(keycode);
    } else if (IS_QK_ONE_SHOT_MOD(keycode)) {
        keycode = 0xE0 + biton(QK_ONE_SHOT_MOD_GET_MODS(keycode) & 0xF) + biton(QK_ONE_SHOT_MOD_GET_MODS(keycode) & 0x10);
    }
    if (keycode > ARRAY_SIZE(code_to_name)) {
        return;
    }

    // update keylog
    key_name = pgm_read_byte(&code_to_name[keycode]);
}

static const char *depad_str(const char *depad_str, char depad_char) {
    while (*depad_str == depad_char)
        ++depad_str;
    return depad_str;
}

static void oled_render_keylog(void) {
    oled_write_char('0' + last_row, false);
    oled_write_P(PSTR("x"), false);
    oled_write_char('0' + last_col, false);
    oled_write_P(PSTR(", k"), false);
    const char *last_keycode_str = get_u16_str(last_keycode, ' ');
    oled_write(depad_str(last_keycode_str, ' '), false);
    oled_write_P(PSTR(":"), false);
    oled_write_char(key_name, false);
    oled_advance_page(true);
}


 // === QMK OLED API function ===
 // Called at the start of oled_init, weak function overridable by the user
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    //     if (!is_keyboard_master()) {
    //     return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    // }
    // return rotation;
    return is_keyboard_master() ? OLED_ROTATION_0 : OLED_ROTATION_180;
}


 // === QMK OLED API function ===
 // Called at the start of oled_task, weak function overridable by the user
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        render_logo();
    }
    return false;
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
    return process_record_user(keycode, record);
}
#endif
