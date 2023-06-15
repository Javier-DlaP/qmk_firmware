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

enum custom_keycodes {
  KCI_COMM = SAFE_RANGE,
  KCI_DOT,
  KCI_LBRC,
  KCI_RBRC,
  KCI_SCLN,
  KCI_TLD,
  KCI_QUT,
  KCI_EQL,
  KCC_1,
  KCC_2,
  KCC_3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [0] = LAYOUT_split_3x6_3(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,KCI_SCLN, KC_LGUI,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,KCI_COMM, KCI_DOT,KCI_LBRC,KCI_RBRC,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_LSFT,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_RALT
                                       //`--------------------------'  `--------------------------'
 
   ),
 
   [1] = LAYOUT_split_3x6_3(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_ESC,  KC_F12,   KC_F7,   KC_F8,   KC_F9, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	KC_TAB,  KC_F11,   KC_F4,   KC_F5,   KC_F6, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, KC_LGUI,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LCTL,  KC_F10,   KC_F1,   KC_F2,   KC_F3, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_LSFT, _______,  KC_SPC,     KC_ENT,   MO(3), KC_LALT
                                       //`--------------------------'  `--------------------------'
   ),

   [2] = LAYOUT_split_3x6_3(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_GRV, KC_PSLS,    KC_7,    KC_8,    KC_9, KC_PMNS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_CAPS, KC_PAST,    KC_4,    KC_5,    KC_6, KC_PPLS,                      XXXXXXX, XXXXXXX, KCI_QUT, KCI_TLD, KC_SLSH, KC_LGUI,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LCTL,    KC_0,   KCC_1,   KCC_2,   KCC_3,  KC_DOT,                      KC_SCLN, XXXXXXX,  KC_EQL, KCI_EQL,LSFT(KC_8),LSFT(KC_9),
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_LSFT,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
                                       //`--------------------------'  `--------------------------'
   ),

     [3] = LAYOUT_split_3x6_3(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,                      XXXXXXX, KC_WH_D, KC_WH_U, XXXXXXX, KC_VOLD, KC_VOLU,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_MPRV, KC_MNXT,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       QK_BOOT, DB_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_BTN1, KC_BTN2, XXXXXXX, KC_MUTE, KC_MPLY,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_LSFT, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                       //`--------------------------'  `--------------------------'
   )
};

// Custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {

    case KCI_COMM:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSFT)){
	  unregister_code(KC_LSFT);
          register_code(KC_NUBS);
	  register_code(KC_LSFT);
        } else {
          register_code(KC_COMM);
        }
      } else {
        unregister_code(KC_COMM);
        unregister_code(KC_NUBS);
      }
      return false;

    case KCI_DOT:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSFT)){
          register_code(KC_NUBS);
        } else {
          register_code(KC_DOT);
        }
      } else {
        unregister_code(KC_DOT);
        unregister_code(KC_NUBS);
      }
      return false;

    case KCI_LBRC:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSFT)){
          unregister_code(KC_LSFT);
          register_code(KC_RALT);
          register_code(KC_QUOT);
          unregister_code(KC_RALT);
          register_code(KC_LSFT);
        } else {
          register_code(KC_RALT);
          register_code(KC_LBRC);
          unregister_code(KC_RALT);
        }
      } else {
        unregister_code(KC_QUOT);
        unregister_code(KC_LBRC);
      }
      return false;

    case KCI_RBRC:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSFT)){
          unregister_code(KC_LSFT);
          register_code(KC_RALT);
          register_code(KC_NUHS);
          unregister_code(KC_RALT);
          register_code(KC_LSFT);
        } else {
          register_code(KC_RALT);
          register_code(KC_RBRC);
          unregister_code(KC_RALT);
        }
      } else {
        unregister_code(KC_RALT);
        unregister_code(KC_RBRC);
      }
      return false;

    case KCI_SCLN:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSFT)){
          register_code(KC_DOT);
        } else {
          register_code(KC_LSFT);
          register_code(KC_COMM);
          unregister_code(KC_LSFT);
        }
      } else {
        unregister_code(KC_DOT);
        unregister_code(KC_COMM);
      }
      return false;

    case KCI_TLD:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSFT)){
          register_code(KC_LBRC);
        } else {
	  if (get_mods() & MOD_BIT(KC_RALT)){
            unregister_code(KC_RALT);
            register_code(KC_LBRC);
            register_code(KC_RALT);
 	  } else {
            register_code(KC_QUOT);
	  }
        }
      } else {
        unregister_code(KC_LBRC);
        unregister_code(KC_QUOT);
      }
      return false;

    case KCI_QUT:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSFT)){
          register_code(KC_2);
        } else {
          register_code(KC_MINS);
        }
      } else {
        unregister_code(KC_MINS);
        unregister_code(KC_2);
      }
      return false;

    case KCI_EQL:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSFT)){
          register_code(KC_MINS);
        } else {
	  register_code(KC_LSFT);
          register_code(KC_1);
          unregister_code(KC_LSFT);
        }
      } else {
        unregister_code(KC_MINS);
        unregister_code(KC_1);
      }
      return false;

    case KCC_1:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSFT)){
	  unregister_code(KC_LSFT);
	  register_code(KC_RALT);
          register_code(KC_1);
	  unregister_code(KC_RALT);
	  register_code(KC_LSFT);
        } else {
	  if (get_mods() & MOD_BIT(KC_RALT)){
	    unregister_code(KC_RALT);
	    register_code(KC_LSFT);
            register_code(KC_1);
	    unregister_code(KC_LSFT);
	    register_code(KC_RALT);
	  } else {
            register_code(KC_1);
	  }
        }
      } else {
        unregister_code(KC_1);
      }
      return false;

    case KCC_2:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSFT)){
	  unregister_code(KC_LSFT);
	  register_code(KC_RALT);
          register_code(KC_2);
	  unregister_code(KC_RALT);
	  register_code(KC_LSFT);
        } else {
	  if (get_mods() & MOD_BIT(KC_RALT)){
	    unregister_code(KC_RALT);
	    register_code(KC_LSFT);
            register_code(KC_2);
	    unregister_code(KC_LSFT);
	    register_code(KC_RALT);
	  } else {
            register_code(KC_2);
	  }
        }
      } else {
        unregister_code(KC_2);
      }
      return false;

    case KCC_3:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSFT)){
	  unregister_code(KC_LSFT);
	  register_code(KC_RALT);
          register_code(KC_3);
	  unregister_code(KC_RALT);
	  register_code(KC_LSFT);
        } else {
	  if (get_mods() & MOD_BIT(KC_RALT)){
	    unregister_code(KC_RALT);
	    register_code(KC_LSFT);
            register_code(KC_3);
	    unregister_code(KC_LSFT);
	    register_code(KC_RALT);
	  } else {
            register_code(KC_3);
	  }
        }
      } else {
        unregister_code(KC_3);
      }
      return false;

    default:
      return true;
  }
}
