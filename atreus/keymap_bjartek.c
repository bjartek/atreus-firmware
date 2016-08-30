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
 * - on all but the main layer there are mappings for combining modifier keys.
 */

const uint16_t PROGMEM actionmaps[][MATRIX_ROWS][MATRIX_COLS] = {
  KEYMAP( /* 0: mostly letters */
    Q,               W,     E,         R,         T,   					 /*|,, |*/          Y,          U,   I,    O,    P,    \
    A,               S,     D,         F,         G,   					 /*|,, |*/          H,          J,   K,    L,    SCLN, \
    Z,               X,     C,         V,         B,   					 /*|,, |*/          N,          M,   COMM, DOT,  SLSH, \
    TAPK(RALT, ESC), ON(2), OSM(LGUI), OSM(LSFT), TAP(1,BSPC), OSM(LCTL), OSM(LALT), TAP(2,SPC), TAP(3,TAB), MINS, QUOT, TAPK(RALT,ENT)
  ),
  KEYMAP( /* layer one is mostly for programming and shell. lots of idea shortcute on left, not sure how much i will use them.*/
    ACK(7),          CTRL(W),    ACSK(T),    SH(F10),     ACSK(L),                    SH(6), SH(LBRC), SH(RBRC), SH(7),    SH(1), \
    CSK(A),          CSK(SPACE), CSK(ENT),   ALT(ENT),    ALT(INS),                   0,     SH(9)   , SH(0),    SH(BSLS), SH(4), \
    ACSK(N),         CSK(F),     CSK(R),     ALT(V),      BOOT,                       GRAVE, LBRC    , RBRC,     SH(3),    SH(GRAVE), \
    TAPK(RALT, ESC), TAB,        OSM(LGUI),  OSM(LSFT),   TRNS, OSM(LCTL), OSM(LALT), SPC,   OFF(1) ,      MINS,    SH(2),    TAPK(RALT,ENT)
  ),
  KEYMAP( /* hold space brings up move pad and numpad */
    INS,      HOME,   UP  ,      END  ,     PGUP,                         SH(5),7     , 8  , 9, SH(8),     \
    DEL,      LEFT,   DOWN,      RIGHT,     PGDN,                         MINS, 4     , 5  , 6, SH(EQUAL), \
    GUI(1),   GUI(2), GUI(3),    GUI(4),    GUI(5),                       NO,   1     , 2  , 3, BSLS,      \
    ACK(DEL), GUI(D), OSM(LGUI), OSM(LSFT), CSK(Q),OSM(LCTL), OSM(LALT),  TRNS, OFF(2), DOT, 0, EQUAL
  ),
  KEYMAP( /* hold tab to have fpad and mouse */
    F1,     F2,    F3,        F4,         F5,                             WH_D , BTN1   , MS_U , BTN2 , BTN3 , \
    F6,     F7,    F8,        F9,         F10,                            WH_U , MS_L   , MS_D , MS_R , BTN4 , \
    F11,    F12,   F13,       F14,        F15,                            NO   , ACL0   , ACL1 , ACL2 , BTN5 , \
    OFF(3), TAB,   OSM(LGUI), OSM(LSFT), CAPSLOCK, OSM(LCTL), OSM(LALT),  SPC,    TRNS,      MINS,  QUOT,  TAPK(RALT,ENT)
  ),

};

