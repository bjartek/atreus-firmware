#include "keymap_common.h"
#include <avr/pgmspace.h>
#include "actionmap.h"
#include "action_code.h"


/* Linewise word skipping */
/* bjartek atreus layout. The defalt layers are almost the samw as qwerty. The difference is:
 * - all the mods are oneshot. see here for information about this. https://github.com/tmk/tmk_keyboard/blob/master/tmk_core/doc/keymap.md
 * - layer one has norwegian special characters at AEO positions
 * - needs intl english layout
 */


#define AC_NO_AA ACTION_MODS_KEY(MOD_RALT, KC_W)
#define AC_NO_AE ACTION_MODS_KEY(MOD_RALT, KC_Z)
#define AC_NO_OE ACTION_MODS_KEY(MOD_RALT, KC_L)

const uint16_t PROGMEM actionmaps[][MATRIX_ROWS][MATRIX_COLS] = {
  KEYMAP( /* 0: mostly letters */
    Q,   W,         E,         R,         T,   					 /*|,, |*/           Y,          U,          I,    O,    P,    \
    A,   S,         D,         F,         G,   					 /*|,, |*/           H,          J,          K,    L,    SCLN, \
    Z,   X,         C,         V,         B,   					 /*|,, |*/           N,          M,          COMM, DOT,  SLSH, \
    ESC, OSM(RALT), OSM(LGUI), OSM(LSFT), TAP(1,BSPC), OSM(LCTL), OSM(LALT), TAP(2,SPC), TAP(3,TAB), MINS, QUOT, ENT
  ),
  KEYMAP( /* layer one is mostly for programming and shell. lots of idea shortcute on left, not sure how much i will use them.*/
    ACK(7),  CTRL(W),    NO_AE,      SH(F10),     ACSK(L),                     SH(6), SH(LBRC), SH(RBRC), NO_OE,    SH(1), \
    NO_AA,   CA(LEFT),   CSK(ENT),   CA(RIGHT),   ALT(INS),                    0,     SH(9)   , SH(0),    SH(BSLS), SH(4), \
    CSK(A),  CSK(F),     ACSK(T),    ALT(V),      CSK(BSPC),                   GRAVE, LBRC    , RBRC,     SH(7),    SH(GRAVE), \
    ESC,     OSM(RALT),  OSM(LGUI),  OSM(LSFT),   TRNS, OSM(LCTL), OSM(LALT),  SPC,   OFF(1) ,  SH(2),    SH(3),    EQUAL
  ),
  KEYMAP( /* hold space brings up move pad and numpad */
    INS,      HOME,   UP  ,      END  ,     PGUP,                         SH(5),7     , 8  , 9, SH(8),     \
    DEL,      LEFT,   DOWN,      RIGHT,     PGDN,                         MINS, 4     , 5  , 6, SH(EQUAL), \
    GUI(1),   GUI(2), GUI(3),    GUI(4),    GUI(5),                       SH(4),1     , 2  , 3, BSLS,      \
    ACK(DEL), GUI(D), OSM(LGUI), OSM(LSFT), GSK(Q),OSM(LCTL), OSM(LALT),  TRNS, OFF(1), DOT, 0, EQUAL
  ),
  KEYMAP( /* hold tab to have fpad and mouse */
    F1,     F2,    F3,        F4,         F5,                             WH_D , BTN1   , MS_U , BTN2 , SH(3) , \
    F6,     F7,    F8,        F9,         F10,                            WH_U , MS_L   , MS_D , MS_R , BTN3 , \
    F11,    F12,   F13,       F14,        F15,                            NO   , ACL0   , ACL1 , ACL2 , BTN5 , \
    BOOT, TAB,   OSM(LGUI), OSM(LSFT), CAPSLOCK, OSM(LCTL), OSM(LALT),    SPC  , TRNS   , MINS , QUOT, EQUAL
  ),


};


