/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include "version.h"
#include <keymap_spanish_latin.h>
#include <stdbool.h>

enum {
    TD_CTN,
    TD_SHIFT,
    TD_ALT,
    TD_TAB,
    TD_COMM,
    TD_DOT,
    TD_BRC,
    TD_SBRC,
    TD_PAR,
    TD_GRV,
    TD_ABK,
    TD_MINS,
    TD_SPC,
    TD_EXL,
    TD_QUES,
    TD_PERC,
    TD_SLSH,
    TD_1,
    TD_2,
    TD_3,
    TD_4,
    TD_5,
    TD_6,
    TD_7,
    TD_8,
    TD_9,
    TD_0,
};

bool isWindows = false; // Change to make default config Windows

void dance_ctn_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (isWindows == true) {
        register_code (KC_LCTL); 
    } else {
        register_code (KC_LGUI); 
    }
  } else if (state->count == 2) {
    if (isWindows == true) {
        register_code (KC_LGUI); 
    } else {
        register_code (KC_LCTL); 
    }
  } else if (state->count == 3) {
    register_code (KC_LCTL);
    register_code (KC_LGUI);
  } else {
    if (isWindows == true) {
        isWindows = false;
    } else {
        isWindows = true;
    }
  }
}
void dance_ctn_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (isWindows == true) {
        unregister_code (KC_LCTL); 
    } else {
        unregister_code (KC_LGUI); 
    }
  } else if (state->count == 2) {
    if (isWindows == true) {
        unregister_code (KC_LGUI); 
    } else {
        unregister_code (KC_LCTL); 
    }
  } else if (state->count == 3) {
    unregister_code (KC_LCTL);
    unregister_code (KC_LGUI);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // tap twice for change
    [TD_CTN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_ctn_finished, dance_ctn_reset),
    [TD_BRC] = ACTION_TAP_DANCE_DOUBLE(ES_LCBR, ES_RCBR),
    [TD_SBRC] = ACTION_TAP_DANCE_DOUBLE(ES_LBRC, ES_RBRC),
    [TD_PAR] = ACTION_TAP_DANCE_DOUBLE(ES_LPRN, ES_RPRN),
    [TD_SHIFT] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_ALT] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_RALT),
    [TD_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),
    [TD_COMM] = ACTION_TAP_DANCE_DOUBLE(ES_COMM, ES_SCLN),
    [TD_DOT] = ACTION_TAP_DANCE_DOUBLE(ES_DOT, ES_COLN),
    [TD_GRV] = ACTION_TAP_DANCE_DOUBLE(ES_GRV, ES_TILD),
    [TD_ABK] = ACTION_TAP_DANCE_DOUBLE(ES_LABK, ES_RABK),
    [TD_MINS] = ACTION_TAP_DANCE_DOUBLE(ES_MINS, ES_UNDS),
    [TD_SPC] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, ES_ACUT),
    [TD_EXL] = ACTION_TAP_DANCE_DOUBLE(ES_EXLM, ES_IEXL),
    [TD_QUES] = ACTION_TAP_DANCE_DOUBLE(ES_QUES, ES_IQUES),
    [TD_PERC] = ACTION_TAP_DANCE_DOUBLE(ES_PERC, ES_CIRC),
    [TD_SLSH] = ACTION_TAP_DANCE_DOUBLE(ES_SLSH, ES_BSLS),
    [TD_1] = ACTION_TAP_DANCE_DOUBLE(KC_KP_1, KC_F1),
    [TD_2] = ACTION_TAP_DANCE_DOUBLE(KC_KP_2, KC_F2),
    [TD_3] = ACTION_TAP_DANCE_DOUBLE(KC_KP_3, KC_F3),
    [TD_4] = ACTION_TAP_DANCE_DOUBLE(KC_KP_4, KC_F4),
    [TD_5] = ACTION_TAP_DANCE_DOUBLE(KC_KP_5, KC_F5),
    [TD_6] = ACTION_TAP_DANCE_DOUBLE(KC_KP_6, KC_F6),
    [TD_7] = ACTION_TAP_DANCE_DOUBLE(KC_KP_7, KC_F7),
    [TD_8] = ACTION_TAP_DANCE_DOUBLE(KC_KP_8, KC_F8),
    [TD_9] = ACTION_TAP_DANCE_DOUBLE(KC_KP_9, KC_F9),
    [TD_0] = ACTION_TAP_DANCE_DOUBLE(KC_KP_0, KC_F10),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-------------------------------------------------------.
    TD(TD_TAB), ES_Q,    ES_W,    ES_E,    ES_R,    ES_T,                         ES_Y,    ES_U,    ES_I,    ES_O,    ES_P,   KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+----------|
    TD(TD_ALT),  ES_A,    ES_S,    ES_D,    ES_F,   ES_G,                         ES_H,   ES_J,     ES_K,    ES_L, ES_NTIL, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+----------|
    TD(TD_CTN), ES_Z,    ES_X,    ES_C,    ES_V,   ES_B,                          ES_N,   ES_M,   TD(TD_COMM), TD(TD_DOT), TD(TD_MINS), TD(TD_SHIFT),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+----------|
                                           TT(4),  TT(2),  TD(TD_SPC), TD(TD_SPC), TT(1), TT(3)
                                      //`--------------------------'  `--------------------------'
  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     TD(TD_TAB), TD(TD_PERC), ES_AMPR, ES_PIPE, TD(TD_QUES), TD(TD_EXL),          KC_7,    KC_8,   KC_9,   ES_MINS,  KC_UP,  ES_PLUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     TD(TD_ALT), ES_DLR, TD(TD_ABK), TD(TD_BRC), TD(TD_PAR), TD(TD_SBRC),         KC_4,   KC_5,    KC_6,   KC_LEFT, KC_DOWN, KC_RIGHT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     TD(TD_CTN), ES_HASH, ES_AT, ES_QUOT, ES_DQUO, TD(TD_GRV),                    KC_1,   KC_2,    KC_3,   TD(TD_SLSH), ES_ASTR, TD(TD_SHIFT),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_TAB,  ES_EQL,  KC_SPC,     KC_SPC,   TT(1),   KC_0
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MPRV, KC_MNXT, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EJCT,                      KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX, KC_CALC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP, KC_WAKE,                      KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, KC_MYCM,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_PWR, TT(2),  KC_SPC,      KC_SPC, XXXXXXX , XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    TD(TD_TAB), ES_Q,    ES_W,    ES_E,    ES_R,    ES_T,                       TD(TD_7), TD(TD_8), TD(TD_9), ES_MINS,  KC_UP,  ES_PLUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    TD(TD_ALT),  ES_A,    ES_S,    ES_D,    ES_F,   ES_G,                       TD(TD_4), TD(TD_5), TD(TD_6), KC_LEFT, KC_DOWN, KC_RIGHT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    TD(TD_CTN), ES_Z,    ES_X,    ES_C,    ES_V,   ES_B,                        TD(TD_1), TD(TD_2), TD(TD_3), ES_SLSH, ES_ASTR, TD(TD_SHIFT),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        TD(TD_CTN), TD(TD_SHIFT),KC_SPC, KC_SPC, TT(3),  TD(TD_0)
                                      //`--------------------------'  `--------------------------'
  ),

  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_HUD, RGB_HUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_RMOD, RGB_MOD,                     RGB_VAD, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_SAD, RGB_SAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          TT(4),  XXXXXXX,  KC_SPC,     KC_SPC, RGB_TOG, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_QWERTY 0
#define L_SYMBOLS_NUMPAD 2
#define L_MEDIA 4
#define L_GAIMING 8
#define L_ADJUST 16

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
      case L_QWERTY:
          oled_write_ln_P(PSTR("Default"), false);
          break;
      case L_SYMBOLS_NUMPAD:
          oled_write_ln_P(PSTR("Symbols - Numpad"), false);
          break;
      case L_MEDIA:
          oled_write_ln_P(PSTR("Media"), false);
          break;
      case L_GAIMING:
          oled_write_ln_P(PSTR("Gaming"), false);
          break;
      case L_ADJUST:
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE

// RGB LAYER CONFIGURATION
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i <= led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
          case 1:
            if((i == 6) || (i >= 13 && i <= 14) || (i >= 40 && i <= 41) || (i == 33)){
              rgb_matrix_set_color(i, RGB_CHARTREUSE);
            }
            break;
          case 2:
            if((i == 6) || (i >= 13 && i <= 14) || (i >= 40 && i <= 41) || (i == 33)){
              rgb_matrix_set_color(i, RGB_ORANGE);
            }
            break;
          case 3:
            if((i == 6) || (i >= 13 && i <= 14) || (i >= 40 && i <= 41) || (i == 33)){
              rgb_matrix_set_color(i, RGB_CYAN);
            }
            break;
          case 4:
            if((i == 6) || (i >= 13 && i <= 14) || (i >= 40 && i <= 41) || (i == 33)){
              rgb_matrix_set_color(i, RGB_AZURE);
            }
            break;
          default:
            if (isWindows != false){ // Change to false if main config is Mac
              rgb_matrix_set_color(26, RGB_WHITE);
            }
            if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
              rgb_matrix_set_color(53, RGB_WHITE);
            }
            break;
        }
    }
}
