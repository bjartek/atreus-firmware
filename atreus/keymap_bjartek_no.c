#include "keymap_common.h"
#include <avr/pgmspace.h>
#include "actionmap.h"
#include "action_code.h"


/* bjartek atreus layout for norwegian keyboard
 * - all the mods are oneshot. see here for information about this. https://github.com/tmk/tmk_keyboard/blob/master/tmk_core/doc/keymap.md
 * - layer one has norwegian special characters at AEO positions
 * - needs no keyboard layout
 */

// Norwegian keyboard does not have the same posibilites as english does on some of the keys so on some mapping shift is not so usable
#define AC_NO_AA KC_LBRC
#define AC_NO_ACNT KC_RBRC
#define AC_NO_AE KC_QUOT
#define AC_NO_OE KC_SCLN
#define AC_NO_LT KC_NONUS_BSLASH
#define AC_NO_PLUS KC_MINS
#define AC_NO_BSLS KC_EQUAL
#define AC_NO_QUOTE KC_BSLS
#define AC_NO_MINS KC_SLSH
#define AC_NO_PIPE KC_GRAVE

#define AC_QM ACTION_MODS_KEY(MOD_LSFT, KC_MINS)
#define AC_QMS ACTION_MODS_TAP_KEY(MOD_LSFT,ACTION_MODS_KEY(MOD_LSFT, KC_MINS))

const uint16_t PROGMEM actionmaps[][MATRIX_ROWS][MATRIX_COLS] = {
  KEYMAP( /* 0: mostly letters */
    Q,   W,         E,         R,         T,   					 /*|,, |*/           Y,          U,          I,   		 O,    P,    \
    A,   S,         D,         F,         G,   					 /*|,, |*/           H,          J,          K,   		 L,    COMM, \
		TAPK(LSFT,Z),   X,         C,         V,         B,  /*|,, |*/           N,          M,       COMM,        DOT,  TAPK(LSFT, KP_SLASH), \
    ESC, OSM(RALT), OSM(LGUI), OSM(LSFT), TAP(1,BSPC), OSM(LCTL), OSM(LALT), TAP(2,SPC), TAP(3,TAB), NO_MINS, SH(2), ENT
  ),
  KEYMAP( /* layer one is mostly for programming and shell. lots of idea shortcute on left, not sure how much i will use them.*/
    ACK(7),  CTRL(W),    NO_AE,      SH(F10),     ACSK(L),                     SH(NO_ACNT), RA(7), RA(0), NO_OE,   SH(1), \
    NO_AA,   ACK(LEFT),  CSK(ENT),   ACK(RIGHT),  ALT(INS),                    0,           SH(8)  , SH(9),   NO_PIPE, RA(4), \
    CSK(A),  CSK(F),     ACSK(T),    ALT(V),      CTRL(F9),                    SH(NO_BSLS), RA(8), RA(9), SH(6),   RA(NO_ACNT), \
    ESC,     OSM(RALT),  OSM(LGUI),  OSM(LSFT),   TRNS, OSM(LCTL), OSM(LALT),  SPC,         OFF(1) , RA(2), NO_QUOTE,   KP_EQUAL
  ),
  KEYMAP( /* hold space brings up move pad and numpad */
    INS,      HOME,   UP  ,      END  ,     PGUP,                          SH(5),   7     , 8  , 9, SH(NO_QUOTE),     \
    DEL,      LEFT,   DOWN,      RIGHT,     PGDN,                          NO_MINS, 4     , 5  , 6, NO_PLUS, \
    GUI(1),   GUI(2), GUI(3),    GUI(4),    GUI(5),                        RA(4),   1     , 2  , 3, NO_BSLS,      \
    ACK(DEL), GSK(Q),OSM(LGUI), OSM(LSFT), GUI(D) ,OSM(LCTL), OSM(LALT),  TRNS,    OFF(1), DOT, 0, KP_EQUAL
  ),
  KEYMAP( /* hold tab to have fpad and mouse */
    F1,     F2,    F3,        F4,         F5,                             WH_D , BTN1   , MS_U , BTN2 , SH(3) , \
    F6,     F7,    F8,        F9,         F10,                            WH_U , MS_L   , MS_D , MS_R , BTN3 , \
    F11,    F12,   F13,       F14,        BOOT,                           NO   , ACL0   , NO_LT , SH(NO_LT) , BTN4 , \
    BOOT, TAB,   OSM(LGUI), OSM(LSFT), CAPSLOCK, OSM(LCTL), OSM(LALT),    SPC  , TRNS   , MINS , SH(NO_BSLS), KP_EQUAL
  ),


};
