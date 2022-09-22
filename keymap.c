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

#include <stdbool.h>

#include <keymap_us_international.h>

enum {
    TD_CTN,
    TD_ENTER,
    TD_SHIFT,
    TD_ALT,
    TD_TAB,
    TD_COMM,
    TD_DOT,
    TD_EQL,
    TD_BRC,
    TD_SBRC,
    TD_PAR,
    TD_GRV,
    TD_BSLS
};

bool isWindows = true;

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

void dance_grv_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
   SEND_STRING("`");
  } else {
    SEND_STRING("~"); 
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // tap twice for change
    [TD_CTN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_ctn_finished, dance_ctn_reset),
    [TD_BRC] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_LBRC), LSFT(KC_RBRC)),
    [TD_SBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TD_PAR] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_9), LSFT(KC_0)),
    [TD_ENTER] = ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_MINS),
    [TD_SHIFT] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_ALT] = ACTION_TAP_DANCE_DOUBLE(KC_RALT, KC_LALT),
    [TD_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),
    [TD_COMM] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_SCLN),
    [TD_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, LSFT(KC_SCLN)),
    [TD_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, LSFT(KC_MINS)),
    [TD_GRV] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_grv_finished, NULL),
    [TD_BSLS] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_BSLS), KC_BSLS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-------------------------------------------------------.
    TD(TD_TAB),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+----------|
    TD(TD_ALT),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,   KC_J,    KC_K,    KC_L, TD(TD_EQL), TD(TD_ENTER),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+----------|
    TD(TD_CTN),   KC_Z,    KC_X,    KC_C,  KC_V,   KC_B,                          KC_N,   KC_M, TD(TD_COMM), TD(TD_DOT),  KC_SLSH, TD(TD_SHIFT),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+----------|
                                          TT(4),   TT(2),  KC_SPC,     KC_SPC,   TT(1), TT(3)
                                      //`--------------------------'  `--------------------------'
  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     TD(TD_TAB), LSFT(KC_5), LSFT(KC_3), LSFT(KC_7), LSFT(KC_1), LSFT(KC_SLSH),  KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS,  KC_UP,  KC_PPLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     TD(TD_ALT), LSFT(KC_4), TD(TD_BSLS), TD(TD_BRC), TD(TD_PAR), TD(TD_SBRC),   KC_KP_4, KC_KP_5, KC_KP_6, KC_LEFT, KC_DOWN, KC_RIGHT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     TD(TD_CTN), LSFT(KC_6), LSFT(KC_2), KC_QUOT, LSFT(KC_QUOT), TD(TD_GRV),     KC_KP_1, KC_KP_2, KC_KP_3, KC_PSLS, KC_PAST, TD(TD_SHIFT),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX,  KC_TAB,  KC_SPC,     KC_SPC,   TT(1),   KC_KP_0
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, TT(2),  KC_SPC,      KC_SPC, XXXXXXX , XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,  KC_SPC,     KC_SPC, XXXXXXX, TT(3)
                                      //`--------------------------'  `--------------------------'
  ),

  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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
        /*case L_ADJUST:
        case L_ADJUST|L_SYMBOLS_NUMPAD:
        case L_ADJUST|L_MEDIA:
        case L_ADJUST|L_SYMBOLS_NUMPAD|L_MEDIA:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;*/
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
