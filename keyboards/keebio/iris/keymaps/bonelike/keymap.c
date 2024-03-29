// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"
//#include "keymap_german_mac_iso.h"
#include "sendstring_german.h"


#define _BONE 0
#define _LOWER 1
#define _RAISE 2
#define _MOUSE 3
#define _FUNC 4


enum custom_keycodes {
  BONE = SAFE_RANGE,
  LOWER,
  RAISE,
  MOUSE,
  FUNC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BONE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,    KC_NO,                           KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_J,    KC_D,    DE_UDIA, DE_ADIA, DE_ODIA,                             KC_P,    KC_H,    KC_L,    KC_M,    KC_W,    DE_SS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC, LGUI_T(KC_C), LALT_T(KC_T), LCTL_T(KC_I), LSFT_T(KC_E), KC_O,            KC_B, RSFT_T(KC_N), RCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_G), KC_Q,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,  KC_F,    KC_V,   KC_U,     KC_A,   KC_X,    KC_HOME,          KC_END,  DE_Y,    DE_Z,   KC_COMM,  KC_DOT,  KC_K,    KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                           LT(_FUNC,KC_ESC),LT(_LOWER,KC_SPC), LT(_MOUSE,KC_BSPC),         KC_SPC,  LT(_RAISE,KC_ENT),   LT(_MOUSE,KC_TAB)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,    KC_NO,                           KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   _______, KC_BSPC, KC_DEL,  _______, _______,                             KC_0,   KC_7,    KC_8,     KC_9,   KC_PLUS, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL, _______, KC_LEFT, KC_RGHT, KC_UP, KC_PGUP,                                _______, RSFT_T(KC_4), RCTL_T(KC_5), LALT_T(KC_6), LGUI_T(KC_COMM), KC_DOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     BL_STEP, _______, KC_HOME, KC_END, KC_DOWN, KC_PGDN, _______,           KC_SPC, _______, KC_1, KC_2, KC_3, KC_DOT, KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    CW_TOGG, _______, KC_DEL,                    KC_0,    KC_0, KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, DE_EURO, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,                            DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  DE_AMPR, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,                            DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_AT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, DE_HASH,  DE_DLR, DE_PIPE, DE_TILD,  KC_GRV, _______,          _______, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, QK_BOOT,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, KC_MUTE,                            _______, _______, KC_MS_U, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, LGUI_T(KC_C), LALT_T(KC_T), LCTL_T(KC_PSTE), LSFT_T(KC_COPY), KC_VOLU,   KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_ACL2, KC_ACL1, KC_ACL0,  KC_VOLD, DF(_BONE),       DF(_MOUSE), KC_WH_D, _______, _______, _______, KC_BTN4, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   KC_BTN1, KC_BTN2, KC_BTN3
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FUNC] = LAYOUT(
 //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
 //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, _______, KC_BSPC, KC_DEL,  _______, _______,                            _______,   KC_F7,  KC_F8,   KC_F9,  KC_F12,  KC_NO,
 //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, _______, KC_LEFT, KC_RGHT, KC_UP, KC_PGUP,                               _______, RSFT_T(KC_F4), RCTL_T(KC_F5), LALT_T(KC_F6), LGUI_T(KC_F11), KC_NO,
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    _______, _______, KC_HOME, KC_END, KC_DOWN, KC_PGDN, _______,           _______, _______, KC_F1,   KC_F2,   KC_F3,    KC_F10, _______,
 //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                  _______,  _______,  _______
                               // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};



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

// Combos
const uint16_t PROGMEM insert_combo[] = {KC_F, KC_V, COMBO_END};
const uint16_t PROGMEM insert_combo_onefinger[] = {LGUI_T(KC_C), KC_J, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {LSFT_T(KC_E), KC_O, COMBO_END};

combo_t key_combos[] = {
    COMBO(insert_combo, KC_INSERT),
    COMBO(insert_combo_onefinger, KC_INSERT),
    COMBO(esc_combo, KC_ESC),
};

// Encoder
bool encoder_update_user(uint8_t index, bool clockwise) {
// left encoder
    if (index == 0) {
        switch(biton32(layer_state)){
             case 2:
                if (clockwise) {
                register_code(KC_LCTL);
                tap_code(KC_3);
                unregister_code(KC_LCTL);
                } else {
                register_code(KC_LCTL);
                tap_code(KC_1);
                unregister_code(KC_LCTL);
                }
                break;
            case 1:
                if (clockwise) {
                tap_code(KC_MINS);
                } else {
                tap_code(KC_EQL);

                }
                break;
            default:
                if (clockwise){
                    tap_code(KC_VOLU);
                } else{
                    tap_code(KC_VOLD);
                }
                break;
      }
    }
// right encoder
    else if (index == 2) {
        switch(biton32(layer_state)){
            case 1:
                if (clockwise){
                    tap_code(KC_WH_R);
                } else{
                    tap_code(KC_WH_L);
                }
                break;
            case _MOUSE:
                if (clockwise){
                    tap_code(KC_VOLU);
                } else{
                    tap_code(KC_VOLD);
                }
                break;
            default:
                if (clockwise) {
                    tap_code(KC_WH_U);
                } else {
                    tap_code(KC_WH_D);
                }
                break;
      }
}
    return false;
}
