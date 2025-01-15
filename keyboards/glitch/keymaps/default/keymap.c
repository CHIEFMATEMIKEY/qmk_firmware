#include QMK_KEYBOARD_H

enum layers {
  _ALPHA,
  _SYMBOL,
  _NUMBER,
  _NAVIGATION,
  _TAB,
  _MACRO,
  LAYER_LENGTH
};


enum tapdances {
  TD_QTAB,
  TD_SBKT,
  TD_CBKT,
  TD_PARN,
  TD_LTGT,
  TD_SHCAPS,
  TD_SLASHS,
  TD_CTTAB,
  TD_COLONSEMI,
  TD_CTRLLEFT,
  TD_CTRLRIGHT,
  TD_CTRLUP,
  TD_CTRLDOWN,
  TAPDANCE_LENGTH
};

enum combos {
  COMBO_MACRO,
  COMBO_LENGTH,
  COMBO_QUESTION

};

// begin tapdances
#define KC_QTAB      TD(TD_QTAB)
#define KC_SBKT      TD(TD_SBKT)
#define KC_CBKT      TD(TD_CBKT)
#define KC_PARN      TD(TD_PARN)
#define KC_LTGT      TD(TD_LTGT)
#define KC_SHCAPS    TD(TD_SHCAPS)
#define KC_SLASHS    TD(TD_SLASHS)
#define KC_ALTLAY    TD(TD_ALTLAY)
#define KC_CTTAB     TD(TD_CTTAB)
#define KC_COLONSEMI TD(TD_COLONSEMI)
#define KC_CTRLLEFT  TD(TD_CTRLLEFT)
#define KC_CTRLRIGHT TD(TD_CTRLRIGHT)
#define KC_CTRLUP    TD(TD_CTRLUP)
#define KC_CTRLDOWN  TD(TD_CTRLDOWN)



#define KC_GUIX      LGUI_T(KC_X)
#define KC_ALTC      LALT_T(KC_C)
#define KC_CTBS      LCTL(KC_BSPC)
#define KC_SHTAB     LSFT(KC_TAB)
#define KC_CTRLTAB   LCTL(KC_TAB)
#define KC_CTRLSHTAB RCS(KC_TAB)
#define KC_CTRLSHT   LCTL(S(KC_T))
#define KC_SCRNSHT   LGUI(S(KC_S))

// oneshots
#define KC_OSFT   OSM(MOD_LSFT)
#define KC_OALT   OSM(MOD_LALT)

// layer changing

#define KC_OSYM   MO(_SYMBOL)
#define KC_ONUM   LT(_NUMBER, KC_BSPC)
#define KC_ONAV   MO(_NAVIGATION)
#define KC_OTAB   LT(_TAB, KC_LALT)

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_GUIX:
        case KC_ALTC:
            return TAPPING_TERM * 2;
        default:
            return TAPPING_TERM;
    }
}

enum macros {
    NEXTTAB = SAFE_RANGE,
    PREVTAB,
    SMILE,
    ANGRY,
    MWAHAHA,
    PASSWORD,
    PASSWORD1,
    SAP,
    WFH,
};


// tapdances
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_QTAB]   = ACTION_TAP_DANCE_DOUBLE(KC_TAB,  KC_Q),
    [TD_SBKT]   = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TD_CBKT]   = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_PARN]   = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_LTGT]   = ACTION_TAP_DANCE_DOUBLE(KC_LABK, KC_RABK),
    [TD_SHCAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_SLASHS] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
    [TD_CTTAB]  = ACTION_TAP_DANCE_DOUBLE(KC_CTRLTAB, KC_CTRLSHTAB),
    [TD_COLONSEMI]  = ACTION_TAP_DANCE_DOUBLE(KC_COLON, KC_SCOLON),
    [TD_CTRLLEFT]  = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, C(KC_LEFT)),
    [TD_CTRLRIGHT]  = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT, C(KC_RIGHT)),
    [TD_CTRLUP]  = ACTION_TAP_DANCE_DOUBLE(KC_UP, C(KC_UP)),
    [TD_CTRLDOWN]  = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, C(KC_DOWN)),
//    [TD_ALTLAY] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_OTAB)
};
// end tapdances

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM combo_macro[] = { KC_OSYM, KC_ONAV, COMBO_END };
const uint16_t PROGMEM combo_question[] = { KC_SHCAPS, KC_ENT, COMBO_END };

combo_t key_combos[] = { 
  [COMBO_MACRO]        = COMBO(combo_macro, OSL(_MACRO)),
  [COMBO_QUESTION]     = COMBO(combo_question, KC_QUES)
};


uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  switch(index) {
    case COMBO_MACRO: // extending the combo term here helps reduce sticky layers some more.
      return 250;
    default:
      return COMBO_TERM;
  }
}
// end combos
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case NEXTTAB:
        if (record->event.pressed) {
            // when keycode nexttab is pressed
            SEND_STRING(SS_LALT("KC_TAB"));
        } else {
            // when keycode nexttab is released
        }
        break;

    case PREVTAB:
        if (record->event.pressed) {
            // when keycode prevtab is pressed
            SEND_STRING("PREVTAB");
        } else {
            // when keycode prevtab is released
        }
        break;

    case SMILE:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(":)"));
 //          SEND_STRING(SS_LCTL("ac")); // selects all and copies
        }
        break;

    case ANGRY:
        if (record->event.pressed) {
            // when keycode prevtab is pressed
            SEND_STRING(">:(");
        } else {
            // when keycode prevtab is released
        }
        break;

   case MWAHAHA:
        if (record->event.pressed) {
            // when keycode prevtab is pressed
            SEND_STRING(">:)");
        } else {
            // when keycode prevtab is released
        }
        break; 

//    case PASSWORD:
//        if (record->event.pressed) {
//            // when keycode prevtab is pressed
//            SEND_STRING("oster102" SS_TAP(X_TAB) "Mikeysch003" SS_TAP(X_ENT));
//        } else {
//            // when keycode prevtab is released
//        }
//        break;

    case PASSWORD1:
        if (record->event.pressed) {
            // when keycode prevtab is pressed
            SEND_STRING("Mikeysch005" SS_TAP(X_ENT));
            //(KC_CTBS SEND_STRING("Mikeysch004") SS_TAP(X_ENT));
        } else {
            // when keycode prevtab is released
        }
        break;

    case SAP:
        if (record->event.pressed) {
            // when keycode prevtab is pressed
           SEND_STRING("OsterhaudtM" SS_TAP(X_TAB) "Mikeysch005" SS_TAP(X_ENT));
        } else {
            // when keycode prevtab is released
        }
        break;

    case WFH:
        if (record->event.pressed) {
            // when keycode prevtab is pressed
           SEND_STRING("michael.osterhaudt@ima.it" SS_TAP(X_ENT) "Mikeysch005" SS_TAP(X_ENT));
        } else {
            // when keycode prevtab is released
        }
        break;
    
    }
    return true;
};

// TO MAKE KEYBOARD
//   USE MSYS2 MINGW64
//    cd /E/programs/keyboards/qmk_firmware
//    make glitch:default

//   USE QMK TOOLBOX




// begin layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ALPHA] = LAYOUT(
    KC_QTAB,    KC_W,       KC_F,       KC_P,       KC_B,                KC_J,        KC_L,       KC_U,       KC_Y,       KC_QUOT,       \
    KC_A,       KC_R,       KC_S,       KC_T,       KC_G,                KC_M,        KC_N,       KC_E,       KC_I,       KC_O,    \
    KC_Z,       KC_GUIX,    KC_ALTC,    KC_D,       KC_V,                KC_K,        KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,    \
                KC_LALT,    KC_LCTL,    KC_ONUM,    KC_ONAV,             KC_OSYM,     KC_SPC,     KC_SHCAPS,  KC_ENT
  ),            // otab
  [_SYMBOL] = LAYOUT(
    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                KC_6,        KC_7,      KC_8,       KC_9,       KC_0,    \
    KC_EXLM,    KC_AT,      KC_HASH,    KC_SLASHS,  KC_PERC,             KC_COLONSEMI,KC_EQL,    KC_ASTR,    KC_PARN,    KC_SBKT,  \
    KC_DLR,     KC_LABK,    KC_GRV,     KC_RABK,    KC_AMPR,             KC_UNDS,     KC_PLUS,   KC_MINS,    KC_CBKT,    KC_ENT,    \
                KC_LALT,    KC_LCTL,    KC_DEL,     KC_ONAV,             KC_OSYM,     KC_SPC,    KC_OSFT,    KC_ENT
  ),
  [_NUMBER] = LAYOUT(
    KC_ESC,     KC_NO,      KC_NO,      KC_NO,      KC_DEL,              KC_7,        KC_8,      KC_9,      KC_PAST,      KC_PSLS,      \
    KC_NO,      KC_BSPC,    KC_CTBS,    KC_CTBS,    KC_BSPC,             KC_4,        KC_5,      KC_6,      KC_PPLS,      KC_PMNS,       \
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,               KC_1,        KC_2,      KC_3,      KC_DOT,       KC_NO,      \
                KC_LALT,    KC_LCTL,    KC_DEL,     KC_ONAV,             KC_OSYM,     KC_SPC,    KC_OSFT,   KC_ENT
  ),
  [_NAVIGATION] = LAYOUT(
    KC_ESC,     KC_F20,     KC_UP,      KC_CTRLSHT, KC_F5,               KC_PGUP,     KC_HOME,    KC_CTRLUP,  KC_END,     KC_VOLU,    \
    KC_LSFT,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_CTTAB,            KC_PGDN,     KC_CTRLLEFT,KC_CTRLDOWN,KC_CTRLRIGHT,KC_VOLD,     \
    KC_ENT,     KC_J,       KC_K,       KC_L,       KC_SPC,              KC_NO,       KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_ENT,     \
                KC_LALT,    KC_LCTL,    KC_DEL,     KC_ONAV,             KC_OSYM,     KC_SPC,     KC_OSFT,    KC_ENT
  ),
  [_TAB] = LAYOUT(
    KC_TAB,     KC_NO,      KC_NO,      KC_NO,      KC_NO,               KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      \
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,               KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      \
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,               KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      \
                KC_LALT,    KC_LCTL,    KC_DEL,    KC_ONAV,              KC_OSYM,     KC_SPC,     KC_OSFT,    KC_ENT
  ),
  [_MACRO] = LAYOUT(
    NEXTTAB,   PREVTAB,     KC_NO,      KC_SCRNSHT, ANGRY,               PASSWORD1,   KC_NO,      KC_NO,      KC_NO,      KC_NO,      \
    KC_CTRLTAB,KC_CTRLSHTAB,KC_NO,      KC_NO,      SMILE,               SAP,         KC_NO,      KC_NO,      KC_LBRC,    KC_RBRC,      \
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      MWAHAHA,             WFH,         KC_NO,      KC_NO,      KC_NO,      KC_NO,      \
                KC_LALT,    KC_LCTL,    KC_DEL,     KC_ONAV,          
                KC_OSYM,    KC_SPC,     KC_OSFT,    KC_ENT
  )
}; 

void suspend_power_down_user(void) { oled_off(); }
void suspend_wakup_init_user(void) { oled_on();  }

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

    // void render_logo(void) {
    //     static const unsigned char PROGMEM raw_logo[] = {
    //         0,  0, 64,  1,224,240,250,252,252,252,252,254,254,254,254,254,254,254,254,252,252,248,248,251,228,248, 48,252,254,252,252,252,252,252,253,240,240, 48,216,  1,130,  2,192,  3, 50,  0,254,255,254,254,254,254,254,254,245,240,253,252,252,252,252,252,252,252,252,252,252,252,253,254,252,254,252,252,252,254,254,240,240,247,240,248,252,252,252,254,254,254,254,254,254,254,252,252,252,248,248,232,226,255,252,252,252,252,254,252,252,240,242,  0, 64,  4,252,252,252,252,252,252,252,252,242,240,  0,  0,  0,  0,  0,  0,
    //         0,  0,125,127,255,255,255,255,255,255,255,255,255,255,247,247,243,243,243,247,247,255,255,255,255,255,195,255,255,255,255,255,255,255,255,255,255,192,196,192,  0, 28,  1,  0,  0,  8,127,127,255,255,255,255,255,255,255,255,193,231,207,  7,  7,  7,127,255,255,255,255,255,255,255,255,255,215,215,215, 23,127,127,255,255,255,255,255,255,255,255,255,207,199,243,  3, 11,  3,  7, 15, 15, 63, 63,127,255,127,255,255,255,255,255,255,255,255,252,252,252,255,255,255,255,255,255,255,255,255,255,192,192,200, 16,  0,  0, 
    //         0, 18, 32, 68,  3,  3,  3,103,127,255,255,255,255,255,255,255,255,231,255,223,255,255,255,255,255,255,255,255,255,255, 35, 67,255,255,255,255,255,255,255,255,254,224,224,227,228,232,224,224,243,211, 35,255,255,255,255,255,255,255,255,254,102,130,  3,  1,  3,  3,  3,255,255,255,255,255,255,255,255,254,  0,104, 67,131, 23, 19, 31,255,255,255,255,255,255,255,254,240,224,192,192,192,224,244,240,248,248,255,227,179,255,255,255,255,255,255,255,255,255,207, 15, 15, 79,255,255,255,255,255,255,255,255,254,  0,  0, 
    //         0,  1,  0, 32,  0,  0,  0,  1, 24, 19, 39,143, 15, 95,191, 63, 63,127,127,127,127,127,127,127, 63, 63, 63,159, 95, 63, 24, 24, 15, 63,191, 63, 63, 63, 63, 63, 63,191, 63, 63, 63, 63, 63,191, 63, 63,  0,143, 63, 63, 63,191,127,191,191, 63, 48,  0, 13,103,156,  0,  0, 47,127,191, 63, 63,127,127, 63,127, 67, 64,128, 33, 99,110,216,204, 79, 79,143, 31, 63, 63, 63, 63,127,127,127,127,127,127,191, 63, 63, 31, 31,128, 47,191, 63, 63, 63, 63, 63, 63, 63,  0,  0,  0,  0, 15,191, 63, 63, 63, 63, 63, 63, 63,  0,  0,
    //     };
    //     oled_write_raw_P(raw_logo, sizeof(raw_logo));
    // }

bool oled_task_user(void) {
  // if (!is_keyboard_master()) {
  //   render_logo();
  // }


//  if (is_keyboard_master()) {
//  uint8_t modifiers = get_mods() | get_oneshot_mods();

  // mods
//  oled_set_cursor(0, 11); 
//  oled_write_P(PSTR("SHIFT"), (modifiers & MOD_MASK_SHIFT) || is_caps_word_on());
//  oled_write_P(PSTR("CNTRL"), (modifiers & MOD_MASK_CTRL));

  // layer
//  oled_set_cursor(0, 14);
//  switch(get_highest_layer(layer_state)) {
//      case _ALPHA:
//          oled_write_P(PSTR("ALPHA"), false);
//          break;
//      case _SYMBOL:
//          oled_write_P(PSTR(" SYM "), false);
//          break;
//      case _NUMBER:
//          oled_write_P(PSTR(" NUM "), false);
//          break;
//      case _NAVIGATION:
//          oled_write_P(PSTR(" NAV "), false);
//          break;
//  }
//  }



  return true;
}

