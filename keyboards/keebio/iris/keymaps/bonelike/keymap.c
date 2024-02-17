// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"
//#include "keymap_german_mac_iso.h"
#include "sendstring_german.h"


#define _BONE 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _HOTKEY 4
#define _QWERTZ 5

// function declaration
void winrun(char prog[]);

enum custom_keycodes {
  BONE = SAFE_RANGE,
  QWERTZ,
  LOWER,
  RAISE,
  ADJUST,
  HOTKEY,
  MEDGE,
  MOUTLOOK,
  MNOTEPAD,
  MTEAMS,
  MFIREFOX,
  MVSCODE,
  MSQL,
  MONENOTE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BONE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_SLEP,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_J,    KC_D,    DE_UDIA,    DE_ADIA,    DE_ODIA,                               KC_P,    KC_H,    KC_L,    KC_M,    KC_W,    DE_SS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC, LGUI_T(KC_C), LALT_T(KC_T), LCTL_T(KC_I), LSFT_T(KC_E), KC_O,            KC_B, RSFT_T(KC_N), RCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_G), KC_Q,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,  KC_F,    KC_V,   KC_U, KC_A, KC_X, KC_HOME,          KC_END,  DE_Y,    DE_Z,   KC_COMM,  KC_DOT,  KC_K,  KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                           LT(_HOTKEY,KC_ESC),LT(_LOWER,KC_SPC), LT(_HOTKEY,KC_BSPC),         KC_SPC,  LT(_RAISE,KC_ENT),   LT(_ADJUST,KC_TAB)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     QK_BOOT,  KC_1,   KC_BSPC, KC_DEL,   KC_4,    KC_5,                               KC_0,   KC_7,    KC_8,     KC_9,   KC_PLUS, KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL, KC_TRNS, KC_LEFT, KC_RGHT, KC_UP, KC_PGUP,                                KC_RBRC, RSFT_T(KC_4), RCTL_T(KC_5), LALT_T(KC_6), LGUI_T(KC_COMM), KC_DOT, 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     BL_STEP, KC_TRNS, KC_LBRC, KC_INS, KC_DOWN, KC_PGDN, KC_LPRN,           KC_SPC, KC_RCBR, KC_1, KC_2, KC_3, KC_COLN, KC_TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    CW_TOGG, _______, KC_DEL,                    KC_0,    ADJUST, KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, DE_EURO, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,                            DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  DE_AMPR, KC_TRNS, 
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,                            DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_AT, 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, DE_HASH, DE_DLR, DE_PIPE, DE_TILD, KC_GRV, KC_LPRN,          KC_TRNS, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, KC_TRNS, 
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, ADJUST, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, QK_BOOT,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, KC_MS_U, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, LGUI_T(KC_C), LALT_T(KC_T), LCTL_T(KC_PSTE), LSFT_T(KC_COPY), _______,   KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, KC_CUT, _______, DF(_QWERTZ),       DF(_ADJUST), KC_WH_D, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, DF(_BONE), DF(_BONE)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
    [_HOTKEY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_SLEP, LGUI(KC_1),LGUI(KC_2),LGUI(KC_3),LGUI(KC_4),LGUI(KC_5),               LGUI(KC_6),LGUI(KC_7),LGUI(KC_8),LGUI(KC_9),LGUI(KC_0),KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_J,    KC_D,    KC_U,    KC_A,    KC_X,                               MNOTEPAD,    KC_H,  KC_L,  LGUI(KC_2), KC_W,   DE_SS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC, MVSCODE, MTEAMS, LCTL_T(KC_I), MEDGE, MOUTLOOK,                          KC_B,    MONENOTE, KC_R,    MSQL,    KC_G,    KC_Q,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, MFIREFOX, KC_V,   DE_UDIA, DE_ADIA, DE_ODIA, KC_HOME,          KC_END,  DE_Y,    DE_Z,   KC_COMM,  KC_DOT,  KC_K,  KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______,  _______,   _______,                 _______,  _______,   _______ 
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_QWERTZ] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_SLEP,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               DE_Z,    KC_U,    KC_I,    KC_O,    KC_P,    DE_UDIA,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,            KC_H, RSFT_T(KC_J), RCTL_T(KC_K), LALT_T(KC_L), LGUI_T(DE_ODIA), DE_ADIA,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,  DE_Y,    KC_X,   DE_C, DE_V, DE_B, KC_HOME,          KC_END,  DE_N,    DE_M,   KC_COMM,  KC_DOT,  KC_K,  DE_SS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LT(_HOTKEY,KC_ESC),   MO(_LOWER),   KC_SPC,                    KC_ENT,  MO(_RAISE),   LT(_ADJUST,KC_TAB)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};


void winrun(char prog[]) {
  SEND_STRING(SS_LALT(" "));
  SEND_STRING(SS_DELAY(200) "<");
  send_string(prog);
  SEND_STRING(SS_DELAY(100) "\n");
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BONE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BONE);
      }
      return false;
      break;
   case QWERTZ:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTZ);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
   // Macros
   case MEDGE:
      if (record->event.pressed) {
        winrun("edge");
      }
      return false;
      break;
   case MOUTLOOK:
      if (record->event.pressed) {
        winrun("outlook");
      }
      return false;
      break;
   case MNOTEPAD:
      if (record->event.pressed) {
        winrun("notepad++");
      }
      return false;
      break;
   case MTEAMS:
      if (record->event.pressed) {
        winrun("teams.exe");
      }
      return false;
      break;
   case MFIREFOX:
      if (record->event.pressed) {
        winrun("firefox");
      }
      return false;
      break;
   case MVSCODE:
      if (record->event.pressed) {
        winrun("visual studio");
      }
      return false;
      break;
   case MSQL:
      if (record->event.pressed) {
        winrun("sql");
      }
      return false;
      break;
   case MONENOTE:
      if (record->event.pressed) {
        winrun("onenote.exe");
      }
      return false;
      break;
  }
  return true;
}

// Adding keycodes not deactivatin caps word
// DE_UNDS
// DE_MINS
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case DE_UNDS:
        case DE_MINS: 
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}