// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "factory.h"



enum custom_keycodes {
    WORDCOUNT = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(   //Numpad
        TO(0),         TO(1),         TO(2),             TO(3),
        RGB_VAI,       KC_KP_SLASH,   KC_KP_ASTERISK,    KC_KP_MINUS,
        KC_KP_7,       KC_KP_8,       KC_KP_9,           KC_KP_PLUS,
        KC_KP_4,       KC_KP_5,       KC_KP_6,           KC_PERCENT,
        KC_KP_1,       KC_KP_2,       KC_KP_3,           KC_KP_EQUAL,
        KC_BACKSPACE,  KC_KP_0,       KC_KP_DOT,         KC_ENTER
    ),
    [1] = LAYOUT(   //Arrows
        _______,       _______,       _______,            _______,
        RGB_VAI,       KC_INSERT,     KC_SCROLL_LOCK,     KC_PRINT_SCREEN,
        XXXXXXX,       XXXXXXX,       XXXXXXX,            XXXXXXX,
        KC_HOME,       KC_PGUP,       KC_PGDN,            KC_END,
        XXXXXXX,       KC_UP,         XXXXXXX,            XXXXXXX,
        KC_LEFT,       KC_DOWN,       KC_RIGHT,           _______
    ),
    [2] = LAYOUT(   //Docs
        _______,       _______,       _______,            _______,
        C(KC_B),       C(KC_I),       C(KC_U),            LSA(KC_5),
        RCS(KC_L),     RCS(KC_E),     RCS(KC_R),          WORDCOUNT,
        LCA(KC_4),     LCA(KC_5),     XXXXXXX,            RCS(KC_8),
        LCA(KC_1),     LCA(KC_2),     LCA(KC_3),          RCS(KC_7),
        XXXXXXX,       LCA(KC_0),     XXXXXXX,            _______
    ),
    [3] = LAYOUT(   //Windows
        _______,       _______,       _______,            _______,
        RGB_VAI,       C(KC_T),       C(KC_W),            RCS(KC_T),
        C(KC_Z),       C(KC_Y),       XXXXXXX,            XXXXXXX,
        A(KC_4),       A(KC_5),       A(KC_6),            XXXXXXX,
        A(KC_1),       A(KC_2),       A(KC_3),            XXXXXXX,
        LCA(KC_N),     LCA(KC_F),     LCA(KC_T),          _______
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case WORDCOUNT:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL)
						SS_DOWN(X_LSFT)
							SS_TAP(X_C)
						SS_UP(X_LCTL)
					SS_UP(X_LSFT)
					SS_DELAY(250) 
                    SS_TAP(X_SPACE)
                    SS_DELAY(50) 
                    SS_TAP(X_TAB) 
                    SS_DELAY(50)
                    SS_TAP(X_TAB)
                    SS_DELAY(50)
                    SS_TAP(X_ENTER));
              }
      return false;
  }
  return true;
}

bool rgb_matrix_indicators_user(void) {
    if (layer_state_cmp(layer_state, 0)) {
        // Numpad 
        rgb_matrix_set_color(4,  RGB_WHITE);    // RGB      C1 R2
        rgb_matrix_set_color(7,  RGB_RED);      // 7 	    C1 R3
        rgb_matrix_set_color(6,  RGB_RED);      // 4        C1 R4
        rgb_matrix_set_color(9,  RGB_RED);      // 1 	    C1 R5
        rgb_matrix_set_color(0,  RGB_PINk);     // slash    C2 R2
        rgb_matrix_set_color(1,  RGB_RED);      // 8    	C2 R3
        rgb_matrix_set_color(3,  RGB_RED);      // 5    	C2 R4
        rgb_matrix_set_color(11, RGB_RED);      // 2 		C2 R5
        rgb_matrix_set_color(8,  RGB_Pink);     // BkSp	    C1 R6
        rgb_matrix_set_color(20, RGB_PINK);     // X 		C3 R2
        rgb_matrix_set_color(21, RGB_RED);      // 9		C3 R3
        rgb_matrix_set_color(23, RGB_RED);      // 6		C3 R4
        rgb_matrix_set_color(15, RGB_RED);      // 3		C3 R5
        rgb_matrix_set_color(14, RGB_PINK);     // .		C3 R6 
        rgb_matrix_set_color(18, RGB_PINK);     // -	    C4 R2
        rgb_matrix_set_color(19, RGB_PINK);     // %		C4 R4 
        rgb_matrix_set_color(12, RGB_WHITE);    // Enter    C4 R6
        rgb_matrix_set_color(5,  RGB_RED);      // Numpad   C1 R1
        rgb_matrix_set_color(2,  RGB_GREEN);    // Arrows   C2 R1
        rgb_matrix_set_color(17, RGB_YELLOW);   // Windows	C4 R1
        rgb_matrix_set_color(16, RGB_PINK);     // +		C4 R3
        rgb_matrix_set_color(13, RGB_PINK);     // =		C4 R5
        rgb_matrix_set_color(10, RGB_RED);      // 0		C2 R6
        rgb_matrix_set_color(22, RGB_BLUE);     // Docs     C3 R1
    }
    if (layer_state_cmp(layer_state, 1)) {
        // Arrows 
        rgb_matrix_set_color(4,  RGB_WHITE);        // RGB      C1 R2
        rgb_matrix_set_color(7,  RGB_BLACK);        // None 	C1 R3
        rgb_matrix_set_color(6,  RGB_SPRINGGREEN);  // Home     C1 R4
        rgb_matrix_set_color(9,  RGB_BLACK);        // None 	C1 R5
        rgb_matrix_set_color(0,  RGB_SPRINGGREEN);  // Insert   C2 R2
        rgb_matrix_set_color(1,  RGB_BLACK);        // None    	C2 R3
        rgb_matrix_set_color(3,  RGB_SPRINGGREEN);  // Page Up	C2 R4
        rgb_matrix_set_color(11, RGB_GREEN);        // Up 		C2 R5
        rgb_matrix_set_color(8,  RGB_GREEN);        // Left	    C1 R6
        rgb_matrix_set_color(20, RGB_SPRINGGREEN);  // ScrLck   C3 R2
        rgb_matrix_set_color(21, RGB_BLACK);        // None		C3 R3
        rgb_matrix_set_color(23, RGB_SPRINGGREEN);  // Page Dwn	C3 R4
        rgb_matrix_set_color(15, RGB_BLACK);        // None		C3 R5
        rgb_matrix_set_color(14, RGB_GREEN);        // Right	C3 R6 
        rgb_matrix_set_color(18, RGB_SPRINGGREEN);  // Prt Scr  C4 R2
        rgb_matrix_set_color(19, RGB_SPRINGGREEN);  // End		C4 R4 
        rgb_matrix_set_color(12, RGB_WHITE);        // Enter    C4 R6
        rgb_matrix_set_color(5,  RGB_RED);          // Numpad   C1 R1
        rgb_matrix_set_color(2,  RGB_GREEN);        // Arrows   C2 R1
        rgb_matrix_set_color(17, RGB_YELLOW);       // Windows	C4 R1
        rgb_matrix_set_color(16, RGB_BLACK);        // None		C4 R3
        rgb_matrix_set_color(13, RGB_BLACK);        // None		C4 R5
        rgb_matrix_set_color(10, RGB_GREEN);        // Down		C2 R6
        rgb_matrix_set_color(22, RGB_BLUE);         // Docs     C3 R1
    }
    if (layer_state_cmp(layer_state, 2)) {
        // Docs 
        rgb_matrix_set_color(4,  RGB_BLUE);    // Bold      C1 R2
        rgb_matrix_set_color(7,  RGB_TEAL);    // Left	    C1 R3
        rgb_matrix_set_color(6,  RGB_BLUE);    // Head 4    C1 R4
        rgb_matrix_set_color(9,  RGB_BLUE);    // Head 1    C1 R5
        rgb_matrix_set_color(0,  RGB_BLUE);    // italic    C2 R2
        rgb_matrix_set_color(1,  RGB_TEAL);    // Center 	C2 R3
        rgb_matrix_set_color(3,  RGB_BLUE);    // Head 5 	C2 R4
        rgb_matrix_set_color(11, RGB_BLUE);    // Head 2	C2 R5
        rgb_matrix_set_color(8,  RGB_BLACK);   // None	    C1 R6
        rgb_matrix_set_color(20, RGB_BLUE);    // U Line	C3 R2
        rgb_matrix_set_color(21, RGB_TEAL);    // Right     C3 R3
        rgb_matrix_set_color(23, RGB_BLACK);   // None		C3 R4
        rgb_matrix_set_color(15, RGB_BLUE);    // Head 3    C3 R5
        rgb_matrix_set_color(14, RGB_BLACK);   // None		C3 R6 
        rgb_matrix_set_color(18, RGB_BLUE);    // Stike     C4 R2
        rgb_matrix_set_color(19, RGB_TEAL);    // bullet	C4 R4 
        rgb_matrix_set_color(12, RGB_WHITE);   // Enter     C4 R6
        rgb_matrix_set_color(5,  RGB_RED);     // Numpad    C1 R1
        rgb_matrix_set_color(2,  RGB_GREEN);   // Arrows    C2 R1
        rgb_matrix_set_color(17, RGB_YELLOW);  // Windows	C4 R1
        rgb_matrix_set_color(16, RGB_TEAL);    // WordCount	C4 R3
        rgb_matrix_set_color(13, RGB_TEAL);    // numbers	C4 R5
        rgb_matrix_set_color(10, RGB_BLUE);    // normal	C2 R6
        rgb_matrix_set_color(22, RGB_BLUE);    // Docs      C3 R1
    }
    if (layer_state_cmp(layer_state, 3)) {
        // Windows 
        rgb_matrix_set_color(4,  RGB_WHITE);        // RGB      C1 R2
        rgb_matrix_set_color(7,  RGB_GOLDENROD);    // Undo	    C1 R3
        rgb_matrix_set_color(6,  RGB_YELLOW);       // Desk 4   C1 R4
        rgb_matrix_set_color(9,  RGB_YELLOW);       // Desk 1   C1 R5
        rgb_matrix_set_color(0,  RGB_YELLOW);       // NewTab   C2 R2
        rgb_matrix_set_color(1,  RGB_GOLDENROD);    // Redo    	C2 R3
        rgb_matrix_set_color(3,  RGB_YELLOW);       // Desk 5  	C2 R4
        rgb_matrix_set_color(11, RGB_YELLOW);       // Desk 2   C2 R5
        rgb_matrix_set_color(8,  RGB_GOLDENROD);    // NotePad  C1 R6
        rgb_matrix_set_color(20, RGB_YELLOW);       // CloseTab	C3 R2
        rgb_matrix_set_color(21, RGB_BLACK);        // None		C3 R3
        rgb_matrix_set_color(23, RGB_YELLOW);       // Desk 6	C3 R4
        rgb_matrix_set_color(15, RGB_YELLOW);       // Desk 3	C3 R5
        rgb_matrix_set_color(14, RGB_GOLDENROD);    // Terminal	C3 R6 
        rgb_matrix_set_color(18, RGB_YELLOW);       // Opentab  C4 R2
        rgb_matrix_set_color(19, RGB_BLACK);        // None		C4 R4 
        rgb_matrix_set_color(12, RGB_WHITE);        // Enter    C4 R6
        rgb_matrix_set_color(5,  RGB_RED);          // Numpad   C1 R1
        rgb_matrix_set_color(2,  RGB_GREEN);        // Arrows   C2 R1
        rgb_matrix_set_color(17, RGB_YELLOW);       // Windows	C4 R1
        rgb_matrix_set_color(16, RGB_BLACK);        // None		C4 R3
        rgb_matrix_set_color(13, RGB_BLACK);        // None		C4 R5
        rgb_matrix_set_color(10, RGB_GOLDENROD);    // Files	C2 R6
        rgb_matrix_set_color(22, RGB_BLUE);         // Docs     C3 R1
    }

  return true;
}
