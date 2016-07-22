#include "keymap_common.h"
#include <avr/pgmspace.h>
#include "actionmap.h"
#include "action_code.h"

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
         TAP(6,A), TAP(5,S), TAP(4,D), TAP(3,F), G,            H, J, K, L, SCLN,         \
         Z, X, C, V, B,            N, M, COMM, DOT, SLSH,    \
         TAPK(RALT,ESC), TAB, OSM(LGUI), OSM(LSFT), BSPC, OSM(LCTL), OSM(LALT),  SPC, TAPT(1), MINS, QUOT, TAPK(RALT,ENT)
  ),
  /* 1: punctuation and numbers TODO: merge this and the next one into one layer for cli/vim */
  FN_ARROW_LAYER,                                 \
  /* 2: arrows and function keys */
  LAYER_TWO, \
	KEYMAP( /* FN pad while holding f */
    NO, NO, NO, NO, NO,           F1, F2, F3, F4, F5, \
    NO, NO, NO, TRNS, NO,           F6, F7, F8, F9, F10, \
    NO, NO, NO, NO, BOOT,         F11, F12, F13, F14, F15, \
    OFF(3), TAB, OSM(LGUI), OSM(LSFT), CS, OSM(LCTL), OSM(LALT), AS, AC, MINS, QUOT, TAPK(RALT,ENT)
	),
KEYMAP( /* numpad while holding d */
	NO, NO, NO, NO, NO,        SH(GRAVE), 7  , 8  , 9, SH(8),      \
	NO, NO, TRNS, OSM(LGUI), NO, MINS     , 4  , 5  , 6, SH(EQUAL),  \
	NO, NO, NO, NO, BOOT,      SH(7)    , 1  , 2  , 3, BSLS,          \
	OFF(4), TAB, OSM(LGUI), OSM(LSFT), CS, OSM(LCTL), OSM(LALT), AS, AC, DOT, 0, EQUAL
	),
KEYMAP( /* movement pad while holding down s */
	NO, NO, NO, NO, NO,        PGUP, HOME, UP  , END  , INS,  \
	NO, TRNS, NO, NO, NO,        PGDN, LEFT, DOWN, RIGHT, DEL,  \
	NO, NO, NO, NO, BOOT,      NO,   WL,   NO,   WR,    NO,   \
	OFF(5), TAB, OSM(LGUI), OSM(LSFT), CS, OSM(LCTL), OSM(LALT), AS, AC, MINS, QUOT, TAPK(RALT,ENT)
	),
KEYMAP( /* mouse pad while holding down a */
 NO,     NO   , NO   , NO   , NO                 , WH_D , BTN1   , MS_U , BTN2 , BTN3 , \
 TRNS,   ACL0 , ACL1 , ACL2 , NO                 , WH_U , MS_L   , MS_D , MS_R , BTN4 , \
 NO,     NO   , NO   , NO   , NO                 , NO   , WH_L   , NO   , WH_R , BTN5 , \
 OFF(6), TAB, OSM(LGUI), OSM(LSFT), CS, OSM(LCTL), OSM(LALT), AS, AC, MINS, QUOT, TAPK(RALT,ENT)
	),
};
