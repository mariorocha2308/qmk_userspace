// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include <stdio.h>

#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    // _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

// enum custom_keycodes {
//     KC_PRVWD = QK_USER,
//     KC_NXTWD,
//     KC_LSTRT,
//     KC_LEND
// };

// #define KC_QWERTY PDF(_QWERTY)
// #define KC_COLEMAK PDF(_COLEMAK)

// void suspend_power_down_user(void) {
//     #ifdef RGB_MATRIX_ENABLE
//         rgb_matrix_set_suspend_state(true);
//         rgb_matrix_disable();
//     #endif
// }
//
// void suspend_wakeup_init_user(void) {
//     #ifdef RGB_MATRIX_ENABLE
//         rgb_matrix_set_suspend_state(false);
//         rgb_matrix_enable();
//     #endif
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//         case _QWERTY:
//             // Layer base - apagar efectos especiales
//             // rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
//             // rgb_matrix_sethsv(HSV_TEAL);
//             // Layer base - Teal
//             rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
//             rgblight_sethsv(HSV_TEAL);
//             break;
//         case 1:
//             // Layer 1 - Red
//             // rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
//             // rgb_matrix_sethsv(HSV_RED);
//             break;
//         case 2:
//             // Layer 2 - Cyan
//             // rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
//             // rgb_matrix_sethsv(HSV_CYAN);
//             break;
//         case 3:
//             // Layer 3 - Yellow
//             // rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
//             // rgb_matrix_sethsv(HSV_YELLOW);
//             break;
//     }
//     return state;
// }
//
// // Para Caps Lock
// bool led_update_user(led_t led_state) {
//     if (led_state.caps_lock) {
//         // rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
//         // rgb_matrix_sethsv(HSV_GREEN);
//     } else {
//         // Volver al color del layer actual
//         layer_state_set_user(layer_state);
//     }
//     return true;
// }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Enter|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Caps |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | PUp  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |PDown |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LGUI | LAlt |LOWER | /Space  /       \Space \  |RAISE | RALT | RCTL | RShift |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

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
//
// bool encoder_update_kb(uint8_t index, bool clockwise) {
//     if (!encoder_update_user(index, clockwise)) {
//       return false; /* Don't process further events if user function exists and returns false */
//     }
//     if (index == 0) { /* First encoder */
//         if (clockwise) {
//             tap_code(KC_PGDN);
//         } else {
//             tap_code(KC_PGUP);
//         }
//     } else if (index == 1) { /* Second encoder */
//         if (clockwise) {
//             rgb_matrix_increase_hue();
//         } else {
//             rgb_matrix_decrease_hue();
//         }
//     }
//     return true;
// }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case KC_PRVWD:
//             if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                     register_mods(mod_config(MOD_LALT));
//                     register_code(KC_LEFT);
//                 } else {
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_LEFT);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LALT));
//                     unregister_code(KC_LEFT);
//                 } else {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_LEFT);
//                 }
//             }
//             break;
//         case KC_NXTWD:
//              if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                     register_mods(mod_config(MOD_LALT));
//                     register_code(KC_RIGHT);
//                 } else {
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_RIGHT);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LALT));
//                     unregister_code(KC_RIGHT);
//                 } else {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_RIGHT);
//                 }
//             }
//             break;
//         case KC_LSTRT:
//             if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                      //CMD-arrow on Mac, but we have CTL and GUI swapped
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_LEFT);
//                 } else {
//                     register_code(KC_HOME);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_LEFT);
//                 } else {
//                     unregister_code(KC_HOME);
//                 }
//             }
//             break;
//         case KC_LEND:
//             if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                     //CMD-arrow on Mac, but we have CTL and GUI swapped
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_RIGHT);
//                 } else {
//                     register_code(KC_END);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_RIGHT);
//                 } else {
//                     unregister_code(KC_END);
//                 }
//             }
//             break;
//     }
//     return true;
// }
