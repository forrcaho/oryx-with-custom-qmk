#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           TG(1),                                          TG(3),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_CAPS,        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_ESCAPE,                                      KC_ESCAPE,      KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_EQUAL,       
    KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           LGUI(LSFT(KC_S)),                                                                LGUI(LSFT(KC_S)),KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
    CW_TOGG,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_BSLS,        
    KC_LEFT_SHIFT,  KC_LEFT_GUI,    KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_SPACE,       LGUI(LCTL(KC_LEFT)),                                                                                                LGUI(LCTL(KC_RIGHT)),KC_SPACE,       KC_RIGHT_ALT,   KC_RIGHT_CTRL,  KC_RIGHT_GUI,   KC_RIGHT_SHIFT, 
    KC_ENTER,       MO(2),          KC_BSPC,                        KC_BSPC,        MO(2),          KC_ENTER
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LSFT(KC_PSCR),                                                                  KC_PSCR,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(LCTL(KC_LEFT)),                                                                                                LALT(LCTL(KC_RIGHT)),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME,        KC_UP,          KC_PAGE_UP,     KC_INSERT,      KC_F12,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_END,         KC_DOWN,        KC_PGDN,        KC_DELETE,      KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPC,        KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_MINUS,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_NUM,         KC_TRANSPARENT, KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_PLUS,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_SLASH,       KC_X,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_C,                                           KC_TRANSPARENT, KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_ENTER,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_KP_0,        KC_KP_0,        KC_KP_DOT,      KC_KP_ENTER,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {151,255,123}, {151,255,123}, {151,255,123}, {151,255,123}, {151,143,251}, {151,255,123}, {151,255,123}, {152,255,255}, {151,255,123}, {151,143,251}, {151,255,123}, {151,255,123}, {152,255,255}, {151,255,123}, {151,143,251}, {151,255,123}, {151,255,123}, {152,255,255}, {151,255,123}, {151,143,251}, {151,255,123}, {151,255,123}, {152,255,255}, {151,255,123}, {151,255,123}, {151,255,123}, {151,255,123}, {151,255,123}, {151,255,123}, {188,255,255}, {151,255,123}, {151,255,123}, {152,255,255}, {74,255,255}, {152,255,255}, {152,255,255}, {151,255,123}, {151,255,123}, {151,255,123}, {151,255,123}, {151,143,251}, {151,255,123}, {151,255,123}, {152,255,255}, {151,255,123}, {151,143,251}, {151,255,123}, {151,255,123}, {152,255,255}, {151,255,123}, {151,143,251}, {151,255,123}, {151,255,123}, {152,255,255}, {151,255,123}, {151,143,251}, {151,255,123}, {151,255,123}, {152,255,255}, {151,255,123}, {151,255,123}, {151,255,123}, {151,255,123}, {151,255,123}, {151,255,123}, {41,255,255}, {151,255,123}, {151,255,123}, {152,255,255}, {74,255,255}, {152,255,255}, {152,255,255} },

    [1] = { {188,255,110}, {188,255,110}, {188,255,110}, {188,255,110}, {188,139,255}, {188,255,110}, {188,255,110}, {188,255,255}, {188,255,110}, {188,139,255}, {188,255,110}, {188,255,110}, {188,255,255}, {188,255,110}, {188,139,255}, {188,255,110}, {188,255,110}, {188,255,255}, {188,255,110}, {188,139,255}, {188,255,110}, {188,255,110}, {188,255,255}, {188,255,110}, {188,255,110}, {188,255,110}, {188,255,110}, {188,255,110}, {188,255,110}, {152,255,255}, {188,255,110}, {188,255,110}, {188,255,255}, {74,255,255}, {188,255,255}, {188,255,255}, {188,255,110}, {188,255,110}, {188,255,110}, {188,255,110}, {188,139,255}, {188,255,110}, {188,255,110}, {188,255,255}, {188,255,110}, {188,139,255}, {188,255,110}, {188,255,110}, {188,255,255}, {188,255,110}, {188,139,255}, {188,255,110}, {188,255,110}, {188,255,255}, {188,255,110}, {188,139,255}, {188,255,110}, {188,255,110}, {188,255,255}, {188,255,110}, {188,255,110}, {188,255,110}, {188,255,110}, {188,255,110}, {188,255,110}, {41,255,255}, {188,255,110}, {188,255,110}, {188,255,255}, {74,255,255}, {188,255,255}, {188,255,255} },

    [2] = { {74,255,112}, {74,255,112}, {74,255,112}, {74,255,112}, {74,130,255}, {74,255,112}, {74,255,112}, {74,255,255}, {74,255,112}, {74,130,255}, {74,255,112}, {74,255,112}, {74,255,255}, {74,255,112}, {74,130,255}, {74,255,112}, {74,255,112}, {74,255,255}, {74,255,112}, {74,130,255}, {74,255,112}, {74,255,112}, {74,255,255}, {74,255,112}, {74,255,112}, {74,255,112}, {74,255,112}, {74,255,112}, {74,255,112}, {188,255,255}, {74,255,112}, {74,255,112}, {74,255,255}, {152,255,255}, {74,255,255}, {74,255,255}, {74,255,112}, {74,255,112}, {74,255,112}, {74,255,112}, {74,130,255}, {74,255,112}, {74,255,112}, {74,255,255}, {74,255,112}, {74,130,255}, {74,255,112}, {74,255,112}, {74,255,255}, {74,255,112}, {74,130,255}, {74,255,112}, {74,255,112}, {74,255,255}, {74,255,112}, {74,130,255}, {74,255,112}, {74,255,112}, {74,255,255}, {74,255,112}, {74,255,112}, {74,255,112}, {74,255,112}, {74,255,112}, {74,255,112}, {41,255,255}, {74,255,112}, {74,255,112}, {74,255,255}, {152,255,255}, {74,255,255}, {74,255,255} },

    [3] = { {41,183,142}, {41,183,142}, {41,183,142}, {41,183,142}, {41,183,142}, {41,255,255}, {41,255,255}, {41,255,255}, {16,255,244}, {41,183,142}, {41,255,255}, {41,255,255}, {16,255,244}, {16,255,244}, {41,183,142}, {41,255,255}, {41,255,255}, {41,255,255}, {16,255,244}, {41,183,142}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,183,142}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {188,255,255}, {41,183,142}, {41,183,142}, {41,255,255}, {41,183,142}, {41,183,142}, {41,183,142}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {249,255,137}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );   
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}



