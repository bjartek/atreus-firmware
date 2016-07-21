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

#define AC_AC ACTION_MODS(MOD_LALT | MOD_LCTL)
#define AC_CS ACTION_MODS(MOD_LSFT | MOD_LCTL)
#define AC_AS ACTION_MODS(MOD_LALT | MOD_LSFT)
#define AC_ACS ACTION_MODS(MOD_LALT | MOD_LCTL | MOD_LSFT)

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
  KEYMAP( /* 0: mostly letters */
				 Q, W, E, R, T,            Y, U, I, O, P,            \
         A, S, TAP(4,D), TAP(3,F), G,            H, J, K, L, SCLN,         \
         Z, X, C, V, B,            N, M, COMM, DOT, SLSH,    \
         TAPK(RALT,ESC), TAB, OSM(LGUI), OSM(LSFT), BSPC, OSM(LCTL), OSM(LALT),  SPC, TAPT(1), MINS, QUOT, TAPK(RALT,ENT)
  ),
  /* 1: punctuation and numbers */
  FN_ARROW_LAYER,                                 \
  /* 2: arrows and function keys */
  LAYER_TWO, \
	KEYMAP( /* FN pad while holding f */
    NO, NO, NO, NO, NO,           F1, F2, F3, F4, F5, \
    NO, NO, NO, NO, NO,           F6, F7, F8, F9, F10, \
    NO, NO, NO, NO, BOOT,         F11, F12, F13, F14, F15, \
    OFF(3), TAB, OSM(LGUI), OSM(LSFT), CS, OSM(LCTL), OSM(LALT), AS, AC, MINS, QUOT, TAPK(RALT,ENT)
	),
KEYMAP( /* numpad while holding d */
	NO, NO, NO, NO, NO,        SH(GRAVE), 7  , 8  , 9, SH(8),      \
	NO, NO, NO, OSM(LGUI), NO, MINS     , 4  , 5  , 6, SH(EQUAL),  \
	NO, NO, NO, NO, BOOT,      SH(7)    , 1  , 2  , 3, BSLS,          \
	OFF(4), TAB, OSM(LGUI), OSM(LSFT), CS, OSM(LCTL), OSM(LALT), AS, AC, DOT, 0, EQUAL
	),
};
