#include QMK_KEYBOARD_H

//enum layer_number {
//  _COLEMAK = 0,
//  _NUMSYMS = 1,
//  _META = 2,
//  _FIGHT = 3,
//};

enum layer_names {
  _COLEMAK,
  _SHIFTA,
  _QWERTY,
  _NUMSYMS,
  _META,
  _FIGHT
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS, KC_LSFT, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_DEL, KC_SPC, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_LGUI, MO(3), KC_LALT, KC_SPC, KC_BSPC, TT(4), MO(3), KC_RSFT),
  [1] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS, KC_A, KC_LSFT, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_Z, KC_LCTL, KC_X, KC_C, KC_V, KC_B, KC_DEL, KC_SPC, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_LGUI, MO(3), KC_LALT, KC_SPC, KC_BSPC, TT(4), MO(3), KC_RSFT),
  [2] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_DEL, KC_SPC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_LGUI, MO(3), KC_LALT, KC_SPC, KC_BSPC, TT(4), MO(3), KC_RSFT),
	[3] = LAYOUT(KC_TRNS, KC_HOME, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TRNS, KC_END, KC_GRV, KC_UP, KC_LPRN, KC_RPRN, KC_CIRC, KC_P7, KC_P8, KC_P9, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_EQL, KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_TRNS, KC_TRNS, KC_PGDN, KC_PSCR, KC_LBRC, KC_RBRC, KC_CAPS, KC_TRNS, KC_TRNS, KC_PMNS, KC_P1, KC_P2, KC_P3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_TRNS, KC_PDOT),
	[4] = LAYOUT(TG(4), KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_NUM, TG(2), TG(5), TG(1), KC_F1, KC_F12, KC_TRNS, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_NO, LGUI(KC_L), KC_NO, KC_NO, LSG(KC_LEFT), LSG(KC_RGHT), KC_TRNS, KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_DOWN, KC_UP, KC_TRNS, KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_TRNS, KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_LEFT, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_RALT),
  [5] = LAYOUT(KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TG(5), KC_TAB, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_F, KC_NO, KC_C, KC_X, KC_Z, KC_V, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ENT, KC_NO, KC_NO, KC_LALT, KC_SPC, KC_BSPC, KC_NO, KC_NO, KC_NO)
};





//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln("~ * ~ junbuild ~ * ~", false);
    oled_write_ln(" ", false);

    //oled_write_ln(read_layer_state(), false);
    
    // Switch on current active layer
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK :
            oled_write_ln("   COLEMAK", false);
            break;
        case _SHIFTA :
            oled_write_ln("   S H I F T - A", false);
            break;
        case _QWERTY :
            oled_write_ln("Q W E R T Y M O D E", false);
            break;
        case _NUMSYMS :
            oled_write_ln("%  NUMSYMS  %", false);
            break;
        case _META : 
            oled_write_ln("               META", false);
            break;
        case _FIGHT :
            oled_write_ln("!!!  FIGHT  !!!", false);
            break;
    }

    // Caps lock status
    //led_t led_state = host_keyboard_led_state();
    //oled_write_P(led_state.caps_lock ? PSTR("Caps Lock On") : PSTR("Caps Lock Off"), false);

    //oled_write_ln(read_keylog(), false);
    //oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   if (record->event.pressed) {
// #ifdef OLED_ENABLE
//     set_keylog(keycode, record);
// #endif
//     // set_timelog();
//   }
//   return true;
// }
