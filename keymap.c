#include QMK_KEYBOARD_H
#include "leader.h"
#include "keymap_japanese.h"
#include "keymap_us_international.h"
#include "g/keymap_combo.h"
#ifdef HOMEROW
  // Left-hand home row mods
  #define HO_A LGUI_T(OM_A)
  #define HO_I LALT_T(OM_I)
  #define HO_E LSFT_T(OM_E)
  #define HO_U LCTL_T(OM_U)
  // Right-hand home row mods
  #define HO_T RCTL_T(OM_T)
  #define HO_S RSFT_T(OM_S)
  #define HO_R LALT_T(OM_R)
  #define HO_N RGUI_T(OM_N)
#else
  // Left-hand home row mods
  #define HO_A OM_A
  #define HO_I OM_I
  #define HO_E OM_E
  #define HO_U OM_U

  // Right-hand home row mods
  #define HO_T OM_T
  #define HO_S OM_S
  #define HO_R OM_R
  #define HO_N OM_N
#endif

// esc hold shift
#define SH_ESC LSFT_T(KC_ESC)
#define OS_ALT OSM(MOD_LALT)
#define OS_CTL OSM(MOD_LCTL)
#define OS_GUI OSM(MOD_LGUI)

#define M_SYM MO(_SYMBOLS)
#define M_NUM MO(_NUMPAD)
#define M_NAV MO(_NAV)
#define M_FN  MO(_FUNCTION)
enum layers {
    _COMAK = 0,
    _SYMBOLS  ,
    _NAV      ,
    _NUMPAD   ,
    _FUNCTION ,

};

enum custom_keycodes {
    LEADER = SAFE_RANGE,
    CU_TDOT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COMAK] = LAYOUT(
     KC_TAB  , US_Q , US_W   ,  US_F  ,   US_P ,   US_B   ,                                         US_J   , US_L   , US_U     , US_Y  , US_SCLN, KC_TAB  ,
     KC_ESC  , US_A , US_R   ,  US_S  ,   US_T ,   US_G   ,                                         US_M   , US_N   , US_E     , US_I  , US_O   , US_ACUT ,
     LEADER  , US_Z , US_X   ,  US_C  ,   US_D ,   US_V   , US_CCED , M_NUM ,     _______, US_EACU, US_K   , US_H   , US_COMM  , US_DOT, US_SLSH, _______ ,
                                OS_CTL,   OS_ALT , KC_SPC , KC_LSFT , M_NAV ,     M_FN   , M_SYM  , KC_ENT , KC_BSPC, KC_RIGHT
    ),

    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_HOME, KC_PGDN, KC_PGUP, KC_END ,  KC_DEL , _______,
      _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                                     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT,  KC_INS , _______,
      _______, _______, _______, _______, KC_ESC , _______, _______, KC_SLCK, _______, _______, KC_PAUSE,KC_MPRV, KC_MPLY, KC_MNXT,  KC_PSCR, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

     [_SYMBOLS] = LAYOUT(
       _______, _______, _______, _______, _______, _______,                                      _______, _______, _______, _______, _______, _______,
       US_LABK, US_RABK, _______, US_LPRN, US_RPRN, _______,                                      _______, US_ASTR, US_DTIL, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, CU_TDOT, _______, _______,
                                  _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
     ),

     [_NUMPAD] = LAYOUT(
       _______, _______, _______, _______, _______, _______,                                      US_MINS, US_7   , US_8   , US_9   , US_DOT , _______,
       _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                                      US_PLUS, US_4   , US_5   , US_6   , US_0   , US_COMM,
       _______, _______, _______, _______, KC_ESC , _______, _______, _______,  _______, _______, US_ASTR, US_1   , US_2   , US_3   , US_SLSH, _______,
                                  _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
     ),

     [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

     /* [_JP_TH] = LAYOUT( */
     /*   _______, OM_Q   , OM_W   , OM_E   , OM_R   , OM_T   ,                                      OM_Y   , OM_U   , OM_I   , OM_O   , OM_P   , OM_LBRC, */
     /*   JP_KANA, OM_A   , OM_S   , OM_D   , OM_F   , OM_G   ,                                      OM_H   , OM_J   , OM_K   , OM_L   , OM_SCLN, OM_RBRC, */
     /*   _______, OM_Z   , OM_X   , OM_C   , OM_V   , OM_B   , _______, _______,  _______, _______, OM_N   , OM_M   , OM_COMM, OM_DOT , OM_SLSH, XXXXXXX, */
     /*                              _______, KC_LSFT, JP_MHEN, _______, _______,  _______, _______, JP_HENK, KC_RSFT, JP_ZKHK */
     /* ), */

     /* [_COMAK] = LAYOUT( */
     /* KC_TAB , OM_Q ,  OM_W   , OM_F  ,  OM_P ,   OM_B ,                                        OM_J,   OM_L ,  OM_U ,   OM_Y ,OM_SCLN, KC_BSPC, */
     /* KC_ESC , OM_A ,  OM_R   , OM_S  ,  OM_T ,   OM_G ,                                        OM_M,   OM_N ,  OM_E ,   OM_I ,  OM_O ,_______, */
     /* LEADER , OM_Z ,  OM_X   , OM_C  ,  OM_D ,   OM_V , _______, _______,     _______,  OM_RBRC, OM_K,   OM_H ,OM_COMM, OM_DOT ,OM_SLSH, KC_RSFT, */
     /*                              _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______ */
     /* ), */

    };

#ifdef HOMEROW
bool process_global_quick_tap(uint16_t keycode, keyrecord_t *record) {
  static uint16_t global_quick_tap_timer = 0;
  if (keycode < QK_MOD_TAP || keycode > QK_MOD_TAP_MAX) {
    global_quick_tap_timer = timer_read();
    return true;
  }
  if (timer_elapsed(global_quick_tap_timer) > TAPPING_TERM) {
    return true;
  }
  if (record->event.pressed) {
    keycode = keycode & 0xFF;
    global_quick_tap_timer = timer_read();
    tap_code(keycode);
    return false;
  }
  return true;
}
#endif

void *leader_toggles_func(uint16_t keycode) {
    switch (keycode) {
        /* case OM_J: */
        /*   layer_move(_JP_TH); */
        /*   break; */
        /* case OM_C: */
        /*   layer_move(_COMAK); */
        /*   break; */
        /*  case OM_O: */
        /*  case OM_E: //for when we are in qwerty */
        /*  case OM_F: //for when we are in cmak */
        /*   layer_move(_OPTIMOT); */
        /*   break; */
      default:
            break;
    }
    return NULL;
}

void *leader_start_func(uint16_t keycode) {
    switch (keycode) {
        /* case KC_L: */
        /*     return leader_layers_func; // function to swap between my layers */
        /* case OM_T: */
        /* case OM_J: //for when we are in qwerty */
        /* case OM_N: //for when we are in cmak */
        /*     return leader_toggles_func; // function to swap between my layers */
        /* case KC_R: */
        /*     reset_keyboard(); // here LDR r will reset the keyboard */
        /*     return NULL; // signal that we're done */
       default:
            return NULL;
    }
    return NULL;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process leader key sequences
  if (!process_leader(keycode, record)) {
      return false;
  }
#ifdef HOMEROW
  return process_global_quick_tap(keycode, record);
#endif
     switch (keycode) {
        case LEADER:
            if (record->event.pressed) {
                start_leading();
            }
            return false;
       default:
            return true;  // Process all other keycodes normally
    }
}
