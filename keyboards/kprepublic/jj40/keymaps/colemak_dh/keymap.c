/* Copyright 2019
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _INTRL,
  _STENO,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define INTRL MO(_INTRL)
#define STENO  TG(_STENO)

enum unicode_names {
    A_ACUTE_LO,
    A_ACUTE_UP,
    A_GONEK_LO,
    A_GONEK_UP,
    A_UMLAUT_LO,
    A_UMLAUT_UP,
    C_ACUTE_LO,
    C_ACUTE_UP,
    E_ACUTE_LO,
    E_ACUTE_UP,
    E_GONEK_LO,
    E_GONEK_UP,
    I_ACUTE_LO,
    I_ACUTE_UP,
    L_STROKE_LO,
    L_STROKE_UP,
    N_ACUTE_LO,
    N_ACUTE_UP,
    N_TILDE_LO,
    N_TILDE_UP,
    O_ACUTE_LO,
    O_ACUTE_UP,
    O_UMLAUT_LO,
    O_UMLAUT_UP,
    S_ACUTE_LO,
    S_ACUTE_UP,
    ESZETT_LO,
    ESZETT_UP,
    U_ACUTE_LO,
    U_ACUTE_UP,
    U_UMLAUT_LO,
    U_UMLAUT_UP,
    Z_ACUTE_LO,
    Z_ACUTE_UP,
    Z_DOT_LO,
    Z_DOT_UP,
};

const uint32_t PROGMEM unicode_map[] = {
    [A_ACUTE_LO]  = 0x00E1, // á
    [A_ACUTE_UP]  = 0x00C1, // Á
    [A_GONEK_LO]  = 0x0105, // ą
    [A_GONEK_UP]  = 0x0104, // Ą
    [A_UMLAUT_LO] = 0x00E4, // ä
    [A_UMLAUT_UP] = 0x00C4, // Ä
    [C_ACUTE_LO]  = 0x0107, // ć
    [C_ACUTE_UP]  = 0x0106, // Ć
    [E_ACUTE_LO]  = 0x00E9, // é
    [E_ACUTE_UP]  = 0x00C9, // É
    [E_GONEK_LO]  = 0x0119, // ę
    [E_GONEK_UP]  = 0x0118, // Ę
    [I_ACUTE_LO]  = 0x00ED, // í
    [I_ACUTE_UP]  = 0x00CD, // Í
    [L_STROKE_LO] = 0x0142, // ł
    [L_STROKE_UP] = 0x0141, // Ł
    [N_ACUTE_LO]  = 0x0144, // ń
    [N_ACUTE_UP]  = 0x0143, // Ń
    [N_TILDE_LO]  = 0x00F1, // ñ
    [N_TILDE_UP]  = 0x00D1, // Ñ
    [O_ACUTE_LO]  = 0x00F3, // ó
    [O_ACUTE_UP]  = 0x00D3, // Ó
    [O_UMLAUT_LO] = 0x00F6, // ö
    [O_UMLAUT_UP] = 0x00D6, // Ö
    [S_ACUTE_LO]  = 0x015B, // ś
    [S_ACUTE_UP]  = 0x015A, // Ś
    [ESZETT_LO]   = 0x00DF, // ß
    [ESZETT_UP]   = 0x1E9E, // ẞ
    [U_ACUTE_LO]  = 0x00FA, // ú
    [U_ACUTE_UP]  = 0x00DA, // Ú
    [U_UMLAUT_LO] = 0x00FC, // ü
    [U_UMLAUT_UP] = 0x00DC, // Ü
    [Z_ACUTE_LO]  = 0x017A, // ź
    [Z_ACUTE_UP]  = 0x0179, // Ź
    [Z_DOT_LO]    = 0x017C, // ż
    [Z_DOT_UP]    = 0x017B, // Ż
};

#define A_ACUTE   UP(A_ACUTE_LO, A_ACUTE_UP)
#define A_GONEK   UP(A_GONEK_LO, A_GONEK_UP)
#define A_UMLAUT  UP(A_UMLAUT_LO, A_UMLAUT_UP)
#define C_ACUTE   UP(C_ACUTE_LO, C_ACUTE_UP)
#define E_ACUTE   UP(E_ACUTE_LO, E_ACUTE_UP)
#define E_GONEK   UP(E_GONEK_LO, E_GONEK_UP)
#define I_ACUTE   UP(I_ACUTE_LO, I_ACUTE_UP)
#define L_STROKE  UP(L_STROKE_LO, L_STROKE_UP)
#define N_ACUTE   UP(N_ACUTE_LO, N_ACUTE_UP)
#define N_TILDE   UP(N_TILDE_LO, N_TILDE_UP)
#define O_ACUTE   UP(O_ACUTE_LO, O_ACUTE_UP)
#define O_UMLAUT  UP(O_UMLAUT_LO, O_UMLAUT_UP)
#define S_ACUTE   UP(S_ACUTE_LO, S_ACUTE_UP)
#define ESZETT    UP(ESZETT_LO, ESZETT_UP)
#define U_ACUTE   UP(U_ACUTE_LO, U_ACUTE_UP)
#define U_UMLAUT  UP(U_UMLAUT_LO, U_UMLAUT_UP)
#define Z_ACUTE   UP(Z_ACUTE_LO, Z_ACUTE_UP)
#define Z_DOT     UP(Z_DOT_LO, Z_DOT_UP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |   -  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Alt  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Bksp |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GUI  | Esc  |      |Lower | Shft |    Space    |Raise |Intrl |RCtrl |Steno |LCtrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit(
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS,
  KC_LALT, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_BSPC, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  KC_LGUI, KC_ESC,  _______, LOWER,   KC_LSFT,     KC_SPC,       RAISE,   INTRL,   KC_RCTL, STENO,   KC_LCTL,
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   ~  |   +  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |Sh+F1 |Sh+F2 |Sh+F3 |Sh+F4 |Sh+F5 |Sh+F6 | Home | PgDn | PgUp |  End |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Del  |Sh+F7 |Sh+F8 |Sh+F9 |Sh+F10|Sh+F11|Sh+F12|      |   {  |   }  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit(
  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_TILD,  KC_PLUS,
  _______,  S(KC_F1), S(KC_F2), S(KC_F3), S(KC_F4), S(KC_F5), S(KC_F6), KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   _______,
  KC_DEL,   S(KC_F7), S(KC_F8), S(KC_F9), S(KC_F10),S(KC_F11),S(KC_F12),_______,  KC_LCBR,  KC_RCBR,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,       _______,       _______,  _______,  _______,  _______,  _______,
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   `  |   =  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | Left | Down |  Up  |Right |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |   [  |   ]  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,  KC_EQL,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_LBRC, KC_RBRC, _______, _______,
  _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______,
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |Reset |      |      |      |      |      |      | Bri- | Bri+ |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Mute | Vol- | Vol+ |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |RGB Tg|RGB Md|      |      |      | Play | Prev | Next |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_planck_mit(
  _______, QK_BOOT, _______, _______, _______, _______, _______, _______, KC_BRID, KC_BRIU, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
  _______, _______, RGB_TOG, RGB_MOD, _______, _______, _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______,
  _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______,
),

/* International Layer
 * ,-----------------------------------------------------------------------------------.
 * |      |   Ą  |      |   Ś  |      |      |      |   Ł  |   Ü  |   Ú  |   Ó  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   Ä  |   Á  |   ß  |      |      |      |   Ń  |   Ę  |   Í  |   Ö  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   Ż  |   Ź  |   Ć  |      |      |      |   Ñ  |   É  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_INTRL] =  LAYOUT_planck_mit(
  _______,  A_GONEK,  _______,  S_ACUTE,  _______,  _______,  _______,  L_STROKE, U_UMLAUT, U_ACUTE,  O_ACUTE,  _______,
  _______,  A_UMLAUT, A_ACUTE,  ESZETT,   _______,  _______,  _______,  N_ACUTE,  E_GONEK,  I_ACUTE,  O_UMLAUT, _______,
  _______,  Z_DOT,    Z_ACUTE,  C_ACUTE,  _______,  _______,  _______,  N_TILDE,  E_ACUTE,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,       _______,       _______,  _______,  _______,  _______,  _______,
),

/* Steno
 * ,-----------------------------------------------------------------------------------.
 * |  N/A |  S-  |  T-  |  P-  |  H-  |   *  |   *  |  -F  |  -P  |  -L  |  -T  |  -D  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  N/A |  S-  |  K-  |  W-  |  R-  |   *  |   *  |  -R  |  -B  |  -G  |  -S  |  -Z  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  #1  |  #2  |  #3  |  #4  |  #5  |  #6  |  #7  |  #8  |  #9  |  #A  |  #B  |  #C  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  N/A |  N/A |  N/A | A(v) | O(v) |      Fn     | E(v) | U(v) |  N/A |      |  N/A |
 * `-----------------------------------------------------------------------------------'
 */
[_STENO] =  LAYOUT_planck_mit(
  XXXXXXX, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
  XXXXXXX, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
  STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,
  XXXXXXX, XXXXXXX, XXXXXXX, STN_A,   STN_O,        STN_FN,      STN_E,   STN_U,   XXXXXXX, _______, XXXXXXX,
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
