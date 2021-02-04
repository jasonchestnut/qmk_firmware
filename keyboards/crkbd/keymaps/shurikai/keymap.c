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
#include "shurikai.h"

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |      |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | sftA |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | sft; |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | Tab  | Bspc | Space|Enter |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_corne_wrapper ( \
  _______, _________________BASE_L1___________________,        _________________BASE_R1___________________, _______, \
  _______, _________________BASE_L2___________________,        _________________BASE_R2___________________, _______, \
  _______, _________________BASE_L3___________________,        _________________BASE_R3___________________, _______, \
                              KC_ESC, ____BASE_LT_____,        ____BASE_RT_____, _______                             \
),

/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      | Home |      | PgUp |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |CtlAlt|      | LGUI |      |      | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | End  | PgDn |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_corne_wrapper ( \
  _______, _________________NAVI_L1___________________,        _________________NAVI_R1___________________, _______, \
  _______, _________________NAVI_L2___________________,        _________________NAVI_R2___________________, _______, \
  _______, _________________NAVI_R3___________________,        _________________NAVI_R3___________________, _______, \
                             _______, ____NAVI_LT_____,        ____NAVI_RT_____, _______                             \
),

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |      |Mouse2| MWU  |Mouse1|      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |MouseL|MouseD|MouseU|MouseR|      |      |Mouse1|      |Mouse2|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      | MWL  | MWD  |  MWR |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_corne_wrapper ( \
  _______, _________________MSE_L1____________________,        _________________MSE_R1____________________, _______, \
  _______, _________________MSE_L2____________________,        _________________MSE_R2____________________, _______, \
  _______, _________________MSE_L3____________________,        _________________MSE_R3____________________, _______, \
                             _______, ____MSE_LT______,        ____MSE_RT______, _______                             \
),

/* Right Symbols
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   ~  |   |  |   "  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  ^   |  *   |  &   |      |      |   #  |   -  |   /  |   `  |   $  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   _  |   \  |   '  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RSYMBOL] = LAYOUT_corne_wrapper ( \
  _______, _________________RSYM_L1___________________,        _________________RSYM_R1___________________, _______, \
  _______, _________________RSYM_L2___________________,        _________________RSYM_R2___________________, _______, \
  _______, _________________RSYM_L3___________________,        _________________RSYM_R3___________________, _______, \
                             _______, ____RSYM_LT_____,        ____RSYM_RT_____, _______                             \
),

/* LSYMBOL
 * ,-----------------------------------------------------------------------------------.
 * |      |   :  |   <  |   >  |   ;  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   {  |   }  |   (  |   )  |   @  |      |      |   =  |   +  |   %  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   !  |   [  |   ]  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LSYMBOL] = LAYOUT_corne_wrapper ( \
  _______, _________________LSYM_L1___________________,        _________________LSYM_R1___________________, _______, \
  _______, _________________LSYM_L2___________________,        _________________LSYM_R2___________________, _______, \
  _______, _________________LSYM_L3___________________,        _________________LSYM_R3___________________, _______, \
                             _______, ____LSYM_LT_____,        ____LSYM_RT_____, _______                             \
),

/* NUMBER
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |   +  |   7  |   8  |   9  |   /  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |Shift |      |      |      |      |   -  |   4  |   5  |   6  |   0  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   =  |   1  |   2  |   3  |   *  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBER] = LAYOUT_corne_wrapper ( \
  _______, _________________NUM_L1____________________,        _________________NUM_R1____________________, _______, \
  _______, _________________NUM_L2____________________,        _________________NUM_R2____________________, _______, \
  _______, _________________NUM_L3____________________,        _________________NUM_R3____________________, _______, \
                             _______, ____NUM_LT______,        ____NUM_RT______, _______                             \
),

/* FUNCTION
 * ,-----------------------------------------------------------------------------------.
 * |      |  F10 |  F9  |  F8  |  F7  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F11 |  F6  |  F5  |  F4  |      |      |      |CtrAlt|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F12 |  F3  |  F2  |  F1  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_corne_wrapper ( \
  _______, _________________FN_L1_____________________,        _________________FN_R1_____________________, _______, \
  _______, _________________FN_L2_____________________,        _________________FN_R2_____________________, _______, \
  _______, _________________FN_L3_____________________,        _________________FN_R3_____________________, _______, \
                             _______, ____FN_LT_______,        ____FN_RT_______, _______                             \
),

/* ADJUST
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |   :  | Esc  |      |      |      |      |      | Del  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |   %  |   /  |Enter |      |  Df1 | Gui  |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |   !  |      |  Df0 |      | Ralt,| Rctl.|Reset |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Tab  |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_corne_wrapper ( \
  _______, _________________ADJ_L1____________________,        _________________ADJ_R1____________________, _______, \
  _______, _________________ADJ_L2____________________,        _________________ADJ_R2____________________, _______, \
  _______, _________________ADJ_L3____________________,        _________________ADJ_R3____________________, _______, \
                             _______, ____ADJ_LT______,        ____ADJ_RT______, _______                             \
),

/* RGB
 * ,-----------------------------------------------------------------------------------.
 * |      |  F10 |  F9  |  F8  |  F7  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F11 |  F6  |  F5  |  F4  |      |      |      |CtrAlt|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F12 |  F3  |  F2  |  F1  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RGB_CONTROL] = LAYOUT_corne_wrapper ( \
  _______, _________________RGB_L1____________________,        _________________RGB_R1____________________, _______, \
  _______, _________________RGB_L2____________________,        _________________RGB_R2____________________, _______, \
  _______, _________________RGB_L3____________________,        _________________RGB_R3____________________, _______, \
                             _______, ____RGB_LT______,        ____RGB_RT______, _______                             \
)

};

int RGB_current_mode;

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);
const char *read_current_layer(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_current_layer());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

char layer_state_str[24];

const char* read_current_layer(void) {
    switch (layer_state)
    {
        case _BASE:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Base");
            break;
        case _NAV:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Navigation");
            break;
        case _MOUSE:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Mouse");
            break;
        case _RSYMBOL:
        case _LSYMBOL:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Symbols");
            break;
        case _NUMBER:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Num Pad");
            break;
        case _FUNCTION:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Function");
            break;
        case _ADJUST:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
            break;
        case _RGB_CONTROL:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: RGB Control");
            break;
        default:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
   }

   return layer_state_str;
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  return true;
}
