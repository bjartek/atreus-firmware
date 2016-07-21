#include "keymap_common.h"
#include <avr/pgmspace.h>
#include "actionmap.h"
#include "action_code.h"

/* some convenienve macros from https://github.com/audibleblink/atreus-firmware */
/* Enable Momentary Dual Function Modifiers */
#define AC_TAP(layer, key)  ACTION_LAYER_TAP_KEY(layer, AC_##key)

#define AC_TAPK(key1, key2)  ACTION_MODS_TAP_KEY(MOD_##key1, AC_##key2)
/* a macro for a layer switching key that can either be momentary or toggle  */
#define AC_TAPT(layer) ACTION_LAYER_TAP_TOGGLE(layer)

/*a macro for oneshot mods */
#define AC_OSM(key) ACTION_MODS_ONESHOT(MOD_##key)

#define AC_CA ACTION_MODS(MOD_LALT | MOD_LCTL)
#define AC_CAS ACTION_MODS(MOD_LALT | MOD_LCTL | MOD_LSFT)

/* Find tag declaration in Vim*/
#define AC_TAG ACTION_MODS_KEY(MOD_LCTL, KC_RBRC)

/* Linewise word skipping */
#define AC_WL ACTION_MODS_KEY(MOD_LALT, KC_LEFT)
#define AC_WR ACTION_MODS_KEY(MOD_LALT, KC_RIGHT)


/* bjartek atreus layout. The defalt layers are almost the samw as qwerty. The difference is:
 * - all the mods are oneshot. see here for information about this. https://github.com/tmk/tmk_keyboard/blob/master/tmk_core/doc/keymap.md 
 * - holding esc or enter is ralt. i map ralt to norwegian letters in os.
 */

const uint16_t PROGMEM actionmaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
  KEYMAP(Q, W, E, R, T, Y, U, I, O, P,            \
         A, S, D, F, G, H, J, K, L, SCLN,         \
         Z, X, C, V, B, N, M, COMM, DOT, SLSH,    \
         TAPK(RALT,ESC), TAB, OSM(LGUI), OSM(LSFT), BSPC, OSM(LCTL), OSM(LALT),  \
         SPC, TAPT(1), MINS, QUOT, TAPK(RALT,ENT)),              \
  /* 1: punctuation and numbers */
  FN_ARROW_LAYER,                                 \
  /* 2: arrows and function keys */
  LAYER_TWO
};
