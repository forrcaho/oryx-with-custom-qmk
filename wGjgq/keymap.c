#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

// Milliseconds the backlight is off (or on) when blinking to show
// caps lock is on. In other words, half the time of a full blink cycle.
#define CAPS_LOCK_BLINK_MS 550

// This is the half cycle duration for caps word blink.
#define CAPS_WORD_BLINK_MS 275

#define LAYER0_HSV {152, 255, 255}

#define LAYER1_HSV {188, 255, 255}

#define LAYER2_HSV {74, 255, 255}

#define LAYER3_HSV {41, 255, 255}

#define LAYER1_KEY 29
#define LAYER2L_KEY 33
#define LAYER2R_KEY 69
#define LAYER3_KEY 65

#define SET_LAYER_KEY(LAYER, KEY, VALUES)                                      \
  {                                                                            \
    const uint8_t values[] = VALUES;                                           \
    ledmap[LAYER][KEY][0] = values[0];                                         \
    ledmap[LAYER][KEY][1] = values[1];                                         \
    ledmap[LAYER][KEY][2] = values[2];                                         \
  }

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  /* fc-added */
  PG_AMP,
  PG_ARRO,
  PG_ENDC,
  PG_EQEQ,
  PG_EQL,
  PG_LBRK,
  PG_LPAR,
  PG_MINS,
  PG_NEEQ,
  PG_QMRK,
  PG_RBRK,
  PG_RPAR,
  PG_SLAS,
  PG_VBAR,
  /* end fc-added */
};

// clang-format off
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
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_TRANSPARENT, PG_AMP,         PG_LPAR,        PG_RPAR,        PG_NEEQ,        KC_TRANSPARENT,                KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME,        KC_UP,          KC_PGUP,        KC_INSERT,      KC_F12,
    KC_TRANSPARENT, PG_ENDC,        PG_VBAR,        PG_LBRK,        PG_RBRK,        PG_EQEQ,        KC_TRANSPARENT,                KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_CAPS_LOCK,   PG_SLAS,        PG_QMRK,        PG_EQL,         PG_MINS,        PG_ARRO,                                                       KC_TRANSPARENT, KC_END,         KC_DOWN,        KC_PGDN,        KC_DELETE,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
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
// clang-format on

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) { rgb_matrix_enable(); }

// clang-format off
uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
  [0] = {
    {151,255,123}, {151,255,123}, {151,255,123}, {151,255,123}, {151,143,251}, {151,255,123}, {151,255,123}, {152,255,255}, {151,255,123}, {151,143,251},
    {151,255,123}, {151,255,123}, {152,255,255}, {151,255,123}, {151,143,251}, {151,255,123}, {151,255,123}, {152,255,255}, {151,255,123}, {151,143,251},
    {151,255,123}, {151,255,123}, {152,255,255}, {151,255,123}, {151,255,123}, {151,255,123}, {151,255,123}, {151,255,123}, {151,255,123}, {188,255,255},
    {151,255,123}, {151,255,123}, {152,255,255}, {74,255,255}, {152,255,255}, {152,255,255}, {151,255,123}, {151,255,123}, {151,255,123}, {151,255,123},
    {151,143,251}, {151,255,123}, {151,255,123}, {152,255,255}, {151,255,123}, {151,143,251}, {151,255,123}, {151,255,123}, {152,255,255}, {151,255,123},
    {151,143,251}, {151,255,123}, {151,255,123}, {152,255,255}, {151,255,123}, {151,143,251}, {151,255,123}, {151,255,123}, {152,255,255}, {151,255,123},
    {151,255,123}, {151,255,123}, {151,255,123}, {151,255,123}, {151,255,123}, {41,255,255}, {151,255,123}, {151,255,123}, {152,255,255}, {74,255,255},
    {152,255,255}, {152,255,255}
  },
  [1] = {
    {188,255,110}, {188,255,110}, {188,255,110}, {188,255,110}, {188,139,255}, {188,255,110}, {188,255,110}, {188,255,255}, {188,255,110}, {188,139,255},
    {188,255,110}, {188,255,110}, {188,255,255}, {188,255,110}, {188,139,255}, {188,255,110}, {188,255,110}, {188,255,255}, {188,255,110}, {188,139,255},
    {188,255,110}, {188,255,110}, {188,255,255}, {188,255,110}, {188,255,110}, {188,255,110}, {188,255,110}, {188,255,110}, {188,255,110}, {152,255,255},
    {188,255,110}, {188,255,110}, {188,255,255}, {74,255,255}, {188,255,255}, {188,255,255}, {188,255,110}, {188,255,110}, {188,255,110}, {188,255,110},
    {188,139,255}, {188,255,110}, {188,255,110}, {188,255,255}, {188,255,110}, {188,139,255}, {188,255,110}, {188,255,110}, {188,255,255}, {188,255,110},
    {188,139,255}, {188,255,110}, {188,255,110}, {188,255,255}, {188,255,110}, {188,139,255}, {188,255,110}, {188,255,110}, {188,255,255}, {188,255,110},
    {188,255,110}, {188,255,110}, {188,255,110}, {188,255,110}, {188,255,110}, {41,255,255}, {188,255,110}, {188,255,110}, {188,255,255}, {74,255,255},
    {188,255,255}, {188,255,255}
  },
  [2] = {
    {74,255,112}, {74,255,112}, {74,255,112}, {74,255,112}, {74,130,255}, {74,255,112}, {74,255,112}, {74,255,255}, {74,255,112}, {74,130,255},
    {74,255,112}, {74,255,112}, {74,255,255}, {74,255,112}, {74,130,255}, {74,255,112}, {74,255,112}, {74,255,255}, {74,255,112}, {74,130,255},
    {74,255,112}, {74,255,112}, {74,255,255}, {74,255,112}, {74,255,112}, {74,255,112}, {74,255,112}, {74,255,112}, {74,255,112}, {188,255,255},
    {74,255,112}, {74,255,112}, {74,255,255}, {152,255,255}, {74,255,255}, {74,255,255}, {74,255,112}, {74,255,112}, {74,255,112}, {74,255,112},
    {74,130,255}, {74,255,112}, {74,255,112}, {74,255,255}, {74,255,112}, {74,130,255}, {74,255,112}, {74,255,112}, {74,255,255}, {74,255,112},
    {74,130,255}, {74,255,112}, {74,255,112}, {74,255,255}, {74,255,112}, {74,130,255}, {74,255,112}, {74,255,112}, {74,255,255}, {74,255,112},
    {74,255,112}, {74,255,112}, {74,255,112}, {74,255,112}, {74,255,112}, {41,255,255}, {74,255,112}, {74,255,112}, {74,255,255}, {152,255,255},
    {74,255,255}, {74,255,255}
  },
  [3] = {
    {41,183,142}, {41,183,142}, {41,183,142}, {41,183,142}, {41,183,142}, {41,255,255}, {41,255,255}, {41,255,255}, {16,255,244}, {41,183,142},
    {41,255,255}, {41,255,255}, {16,255,244}, {16,255,244}, {41,183,142}, {41,255,255}, {41,255,255}, {41,255,255}, {16,255,244}, {41,183,142},
    {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,183,142}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {188,255,255},
    {41,183,142}, {41,183,142}, {41,255,255}, {41,183,142}, {41,183,142}, {41,183,142}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
    {0,0,0}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126},
    {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126}, {250,255,126},
    {250,255,126}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {249,255,137}, {0,0,0}, {0,0,0}, {0,0,0},
    {0,0,0}, {0,0,0}
  },
};
// clang-format on

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
        .h = pgm_read_byte(&ledmap[layer][i][0]),
        .s = pgm_read_byte(&ledmap[layer][i][1]),
        .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
      rgb_matrix_set_color(i, 0, 0, 0);
    } else {
      RGB rgb = hsv_to_rgb(hsv);
      float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
      rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
    return false;
  }
  if (keyboard_config.disable_layer_led) {
    return false;
  }
  switch (biton32(layer_state)) {
  case 0:
    /* fc-added */
    SET_LAYER_KEY(2, LAYER2L_KEY, LAYER0_HSV)
    SET_LAYER_KEY(2, LAYER2R_KEY, LAYER0_HSV)
    SET_LAYER_KEY(3, LAYER3_KEY, LAYER0_HSV)
    /* end fc-added */
    set_layer_color(0);
    break;
  case 1:
    /* fc-added */
    SET_LAYER_KEY(2, LAYER2L_KEY, LAYER1_HSV)
    SET_LAYER_KEY(2, LAYER2R_KEY, LAYER1_HSV)
    SET_LAYER_KEY(3, LAYER3_KEY, LAYER1_HSV)
    /* end fc-added */
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

/* fc-added */
const key_override_t pg_lbrk_none =
    ko_make_with_layers_and_negmods(0, PG_LBRK, KC_LEFT_CURLY_BRACE, ~0, ~0);
const key_override_t pg_lbrk_shift = ko_make_with_layers_and_negmods(
    MOD_MASK_SHIFT, PG_LBRK, KC_LEFT_BRACKET, ~0, ~MOD_MASK_SHIFT);

const key_override_t pg_lpar_none =
    ko_make_with_layers_and_negmods(0, PG_LPAR, KC_LEFT_PAREN, ~0, ~0);
const key_override_t pg_lpar_shift = ko_make_with_layers_and_negmods(
    MOD_MASK_SHIFT, PG_LPAR, KC_LEFT_ANGLE_BRACKET, ~0, ~MOD_MASK_SHIFT);

const key_override_t pg_rbrk_none =
    ko_make_with_layers_and_negmods(0, PG_RBRK, KC_RIGHT_CURLY_BRACE, ~0, ~0);
const key_override_t pg_rbrk_shift = ko_make_with_layers_and_negmods(
    MOD_MASK_SHIFT, PG_RBRK, KC_RIGHT_BRACKET, ~0, ~MOD_MASK_SHIFT);

const key_override_t pg_rpar_none =
    ko_make_with_layers_and_negmods(0, PG_RPAR, KC_RIGHT_PAREN, ~0, ~0);
const key_override_t pg_rpar_shift = ko_make_with_layers_and_negmods(
    MOD_MASK_SHIFT, PG_RPAR, KC_RIGHT_ANGLE_BRACKET, ~0, ~MOD_MASK_SHIFT);

const key_override_t pg_slas_none =
    ko_make_with_layers_and_negmods(0, PG_SLAS, KC_SLASH, ~0, ~0);
const key_override_t pg_slas_shift = ko_make_with_layers_and_negmods(
    MOD_MASK_SHIFT, PG_SLAS, KC_BACKSLASH, ~0, ~MOD_MASK_SHIFT);

// clang-format off
const key_override_t **key_overrides = (const key_override_t *[]){
    &pg_lbrk_none, &pg_lbrk_shift,
    &pg_lpar_none, &pg_lpar_shift,
    &pg_rbrk_none, &pg_rbrk_shift,
    &pg_rpar_none, &pg_rpar_shift,
    &pg_slas_none, &pg_slas_shift,
    NULL};
// clang-format on
/* end fc-added */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /* fc-added */
  uint8_t std_mods = get_mods();
  uint8_t oneshot_mods = get_oneshot_mods();
  uint8_t all_mods = std_mods | oneshot_mods;
  bool shift_on = all_mods & MOD_MASK_SHIFT;
  bool ctrl_on = all_mods & MOD_MASK_CTRL;

  // None of our special keycodes use ALT or GUI mods (so far), so we
  // check once here at the top and let other code handle it if any of
  // these are set.
  if (all_mods & (MOD_MASK_ALT | MOD_MASK_GUI))
    return true;
  /* end fc-added */
  switch (keycode) {

  case RGB_SLD:
    if (rawhid_state.rgb_control) {
      return false;
    }
    if (record->event.pressed) {
      rgblight_mode(1);
    }
    return false;
    /* fc-added */
    break;
  case KC_CAPS:
    // On caps lock release, if caps lock just got turned off, ensure that
    // backlight is enabled when it stops blinking.
    if (!record->event.pressed) {
      if (!host_keyboard_led_state().caps_lock && !is_caps_word_on()) {
        rgb_matrix_enable();
        // In this case, we want to continue processing
        return true;
      }
    }
    break;
  // Macros
  case PG_AMP:
    if (record->event.pressed) {
      clear_mods();
      clear_oneshot_mods();
      if (shift_on) {
        if (ctrl_on)
          SEND_STRING("&");
        else
          SEND_STRING(" & ");
      } else {
        if (ctrl_on)
          SEND_STRING("&&");
        else
          SEND_STRING(" && ");
      }
      set_mods(std_mods);
      set_oneshot_mods(oneshot_mods);
      return false;
    }
    break;
  case PG_ARRO:
    if (record->event.pressed) {
      clear_mods();
      clear_oneshot_mods();
      if (shift_on) {
        if (ctrl_on)
          SEND_STRING("->");
        else
          SEND_STRING(" -> ");
      } else {
        if (ctrl_on)
          SEND_STRING("=>");
        else
          SEND_STRING(" => ");
      }
      set_mods(std_mods);
      set_oneshot_mods(oneshot_mods);
      return false;
    }
    break;
  case PG_ENDC:
    if (record->event.pressed) {
      clear_mods();
      clear_oneshot_mods();
      if (shift_on) {
        if (ctrl_on)
          SEND_STRING(SS_TAP(X_END));
        else
          SEND_STRING(SS_TAP(X_END) SS_TAP(X_ENTER));
      } else {
        if (ctrl_on)
          SEND_STRING(SS_TAP(X_END) ";");
        else
          SEND_STRING(SS_TAP(X_END) ";" SS_TAP(X_ENTER));
      }
      set_mods(std_mods);
      set_oneshot_mods(oneshot_mods);
      return false;
    }
    break;
  case PG_EQEQ:
    if (record->event.pressed) {
      clear_mods();
      clear_oneshot_mods();
      if (shift_on) {
        if (ctrl_on)
          SEND_STRING("==");
        else
          SEND_STRING(" == ");
      } else {
        if (ctrl_on)
          SEND_STRING("==");
        else
          SEND_STRING(" === ");
      }
      set_mods(std_mods);
      set_oneshot_mods(oneshot_mods);
      return false;
    }
    break;
  case PG_EQL:
    if (record->event.pressed) {
      clear_mods();
      clear_oneshot_mods();
      if (shift_on) {
        if (ctrl_on)
          SEND_STRING("+");
        else
          SEND_STRING(" + ");
      } else {
        if (ctrl_on)
          SEND_STRING("=");
        else
          SEND_STRING(" = ");
      }
      set_mods(std_mods);
      set_oneshot_mods(oneshot_mods);
      return false;
    }
    break;
  case PG_MINS:
    if (record->event.pressed) {
      clear_mods();
      clear_oneshot_mods();
      if (shift_on) {
        if (ctrl_on)
          SEND_STRING("-");
        else
          SEND_STRING(" - ");
      } else {
        if (ctrl_on)
          SEND_STRING("*");
        else
          SEND_STRING(" * ");
      }
      set_mods(std_mods);
      set_oneshot_mods(oneshot_mods);
      return false;
    }
    break;
  case PG_NEEQ:
    if (record->event.pressed) {
      clear_mods();
      clear_oneshot_mods();
      if (shift_on) {
        if (ctrl_on)
          SEND_STRING("!=");
        else
          SEND_STRING(" != ");
      } else {
        if (ctrl_on)
          SEND_STRING("!==");
        else
          SEND_STRING(" !== ");
      }
      set_mods(std_mods);
      set_oneshot_mods(oneshot_mods);
      return false;
    }
    break;
  case PG_QMRK:
    if (record->event.pressed) {
      clear_mods();
      clear_oneshot_mods();
      if (shift_on) {
        if (ctrl_on)
          SEND_STRING("?");
        else
          SEND_STRING(" ? ");
      } else {
        if (ctrl_on)
          SEND_STRING("??");
        else
          SEND_STRING(" ?? ");
      }
      set_mods(std_mods);
      set_oneshot_mods(oneshot_mods);
      return false;
    }
    break;
  case PG_VBAR:
    if (record->event.pressed) {
      clear_mods();
      clear_oneshot_mods();
      if (shift_on) {
        if (ctrl_on)
          SEND_STRING("|");
        else
          SEND_STRING(" | ");
      } else {
        if (ctrl_on)
          SEND_STRING("||");
        else
          SEND_STRING(" || ");
      }
      set_mods(std_mods);
      set_oneshot_mods(oneshot_mods);
      return false;
    }
    break;
    /*end fc-added */
  }
  return true;
}

/* fc-added */
static uint16_t caps_lock_blink_timer = 0;
static uint16_t caps_word_blink_timer = 0;

// This is called after every matrix scan. We make the backlight blink
// when caps lock is on here. To ensure the backlight is in the on state
// when caps lock is turned off, we also watch for the relase of the caps
// lock key in process_record_user().
void housekeeping_task_user(void) {
  if (host_keyboard_led_state().caps_lock) {
    if (timer_elapsed(caps_lock_blink_timer) >= CAPS_LOCK_BLINK_MS) {
      rgb_matrix_toggle();
      caps_lock_blink_timer = timer_read();
    }
  }
  if (is_caps_word_on()) {
    if (timer_elapsed(caps_word_blink_timer) >= CAPS_WORD_BLINK_MS) {
      rgb_matrix_toggle();
      caps_word_blink_timer = timer_read();
    }
  }
}

// This is called when caps word turns on or off.
// We use it here to make sure the backlight is on when the caps
// word blink stops.
void caps_word_set_user(bool active) {
  if (!active) {
    rgb_matrix_enable();
  }
}
/* end fc-added */
