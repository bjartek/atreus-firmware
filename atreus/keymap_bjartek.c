#include "keymap_common.h"
#include <avr/pgmspace.h>
#include "actionmap.h"
#include "action_code.h"


/* bjartek atreus layout for norwegian keyboard
 * - all the mods are oneshot. see here for information about this. https://github.com/tmk/tmk_keyboard/blob/master/tmk_core/doc/keymap.md
 * - layer one has norwegian special characters at AEO positions
 * - needs us mac keyboard layout
 */

const uint16_t PROGMEM actionmaps[][MATRIX_ROWS][MATRIX_COLS] = {
KEYMAP(
Q       , W        , E        , R        , T          ,                       Y         , U         , I       , O         , P        , \
A       , S        , D        , F        , G          ,                       H         , J         , K       , L         , SCLN     , \
Z       , X        , C        , V        , B          ,                       N         , M         , COMM    , DOT       , SLSH     , \
ESC     , OSM(RALT), OSM(LCTL), OSM(LSFT), TAP(1,BSPC), OSM(LGUI), OSM(LALT), TAP(2,SPC), TAP(3,TAB), MINS    , QUOT      , ENT     ),

KEYMAP(
AGK(F7) , GUI(F12) , RA(QUOT) , ACK(R)   , AGSK(L)    ,                       SH(6)     , SH(LBRC)  , SH(RBRC), RA(O)     , SH(1)    , \
RA(A)   , GUI(LBRC), CSK(ENT) , GUI(RBRC), GSK(T)    ,                       0         , SH(9)     , SH(0)   , SH(BSLS)  , SH(4)    , \
GSK(A)  , GSK(F)   , CTRL(T)  , ALT(V)   , GUI(F9)    ,                       GRAVE     , LBRC      , RBRC    , SH(7)     , SH(GRAVE), \
GA      , OSM(RALT), OSM(LCTL), OSM(LSFT), TRNS       , OSM(LGUI), OSM(LALT), SPC       , OFF(1)    , SH(2)   , QUOT      , OSM(LGUI)),

KEYMAP(
INS     , HOME     , UP       , END      , PGUP       ,                       SH(5)     , 7         , 8       , 9         , SH(8)    , \
DEL     , LEFT     , DOWN     , RIGHT    , PGDN       ,                       MINS      , 4         , 5       , 6         , SH(EQUAL), \
VOLU    , MPRV     , MPLY     , MNXT     , GSK(Q)     ,                       SH(4)     , 1         , 2       , 3         , BSLS     , \
VOLD    , MUTE     , OSM(LCTL), OSM(LSFT), CSK(SPC)   , OSM(LGUI), OSM(LALT), TRNS      , OFF(1)    , DOT     , 0         , KP_EQUAL),

KEYMAP(
F1      , F2       , F3       , F4       , F5         ,                       WH_D      , BTN1      , MS_U    , BTN2      , SH(3)    , \
F6      , F7       , F8       , F9       , F10        ,                       WH_U      , MS_L      , MS_D    , MS_R      , BTN3     , \
F11     , F12      , F13      , F14      , BOOT       ,                       NO        , ACL0      , NO      , NO        , NO       , \
GA      , OSM(RALT), OSM(LCTL), OSM(LSFT), GS         , OSM(LGUI), OSM(LALT), SPC       , TRNS      , MINS    , SH(BSLS)  , KP_EQUAL)

};
