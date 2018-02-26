#include "diverge_tm.h"
#include "action_layer.h"
#include "eeconfig.h"


extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER = LT(_LOWER, KC_SPC),
  RAISE = LT(_RAISE, KC_ENT),
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.                  ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |                  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |                  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * | Esc  | GUI  |  `   | Alt  | Lower/Space |                  | Raise/Enter | Alt  |      |      | Esc  |
 * `-----------------------------------------'                  `-----------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT , \
  KC_ESC,  KC_LGUI, KC_GRV, KC_LALT,  LOWER,                     RAISE,   KC_RALT, XXXXXXX, XXXXXXX, KC_ESC  \
),

/* Lower
 * ,------------------------------------------                  |-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |                  |   *  |   7  |   8  |   9  |   (  |  )   |
 * |------+------+------+------+------+-------                  |------+------+------+------+------+------|
 * |   \  |   ^  |   &  |   *  |   =  |   )  |                  |   +  |   4  |   5  |   6  |   {  |  }   |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |   |  |   [  |   ]  |   {  |   }  |                  |   -  |   1  |   2  |   3  |   [  |  ]   |
 * |------+------+------+------+------+------+                  |------+------+------+------+------+------|
 * |      |      |      |      |             |                  |    Enter    |   0  |   .  |   /  |      |
 * `------------------------------------------                  |-----------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_ASTR, KC_7,    KC_8,    KC_9,    KC_LPRN, KC_RPRN, \
  KC_BSLS, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL,  KC_UNDS, KC_PLUS, KC_4,    KC_5,    KC_6,    KC_LCBR, KC_RCBR, \
  _______, KC_PIPE, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_MINUS,KC_1,    KC_2,    KC_3,    KC_LBRC, KC_RBRC, \
  _______, _______, _______, _______, _______,                   KC_ENT,  KC_0,    KC_DOT,  KC_SLSH, XXXXXXX \
),

/* Raise
 * ,------------------------------------------                  |-----------------------------------------.
 * |      |      |      |      |      |      |                  | Home | PgDn | PgUp | End  |   0  | Del  |
 * |------+------+------+------+------+-------                  |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                  | Left | Down |  Up  | Right|      |  \   |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |                  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+                  |------+------+------+------+------+------|
 * |      |      |      |      |  Backspace  |                  |             | Next | Vol- | Vol+ | Play |
 * `------------------------------------------                  |-----------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_0,    KC_DEL, \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RBRC, KC_BSLS, \
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, _______, _______, _______, _______,\
  _______, _______, _______, _______, KC_BSPC,                   _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Adjust (Lower + Raise)
 * ,------------------------------------------                  |-----------------------------------------.
 * |      | Reset|      |      |      |      |                  |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------                  |------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|                  |AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+                  |------+------+------+------+------+------|
 * |      |      |      |      |      |                         |      |      |      |      |      |      |
 * `------------------------------------------                  |-----------------------------------------'
 */
[_ADJUST] =  KEYMAP( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______ \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
eloat tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
