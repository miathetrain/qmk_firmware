// Copyright 2020 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers{
	BASE,
	MEDIA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_61(
		KC_ESC,	KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
		KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
		SC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, SC_RSPC,
		KC_LCTL, KC_LWIN, KC_LALT, KC_SPC, KC_LEFT, KC_DOWN, KC_RIGHT, MO(MEDIA)),

		[MEDIA]   = LAYOUT_61(
		KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
		_______, KC_MRWD, KC_MFFD, KC_BRID, KC_BRIU, _______, KC_PSCR, KC_SCRL, KC_PAUS, _______, _______, RGB_VAD, RGB_VAI, RGB_MOD,
		_______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______, KC_INS, KC_HOME, KC_PGUP, _______, RGB_SPD, RGB_SPI, _______,
		_______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, KC_DEL, KC_END,  KC_PGDN, RGB_HUI, KC_SLSH, _______,
		_______, KC_NO, _______, _______, KC_RALT, _______, KC_RCTL, _______),
};

#ifdef CAPS_LOCK_LED_INDEX
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, 255, 255, 255);
    } else {
        if (!rgb_matrix_get_flags()) {
           RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, 0, 0, 0);
        }
    }
    return true;
}
#endif