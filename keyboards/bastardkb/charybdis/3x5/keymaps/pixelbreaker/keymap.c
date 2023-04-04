/**
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

// To build run:
// qmk compile -kb bastardkb/charybdis/3x5/v2/splinky_3 -km pixelbreaker

// To flash direct run:
// qmk flash -kb bastardkb/charybdis/3x5/v2/splinky_3 -km pixelbreaker

#include QMK_KEYBOARD_H

enum custom_layers { _BASE = 0, _MEDIA, _NAV, _MOUSE, _CODE, _NUM, _FUN, _ADJUST };
enum custom_keycodes {
    WINSWITCH = QK_USER,
    TABSWITCH,
    MACSLEEP,
};
// utils
int max(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}
int min(int num1, int num2) {
    return (num1 > num2) ? num2 : num1;
}

int8_t sign(int x) {
    return (x > 0) - (x < 0);
}

// Automatically enable sniping when the mouse layer is on.
// #define CHARYDIS_AUTO_SNIPING_ON_LAYER _NAV
#ifdef CHARYBDIS_DRAGSCROLL_DPI
#    undef CHARYBDIS_DRAGSCROLL_DPI
#endif
#define CHARYBDIS_DRAGSCROLL_DPI 50

#define ESC_MED LT(_MEDIA, KC_ESC)
#define SPC_NAV LT(_NAV, KC_SPC)
#define TAB_CODE LT(_CODE, KC_TAB)
#define BSP_NUM LT(_NUM, KC_BSPC)
#define ENT_FUN LT(_FUN, KC_ENT)

#define MOUSE(KC) LT(_MOUSE, KC)
#define ADJUST(KC) LT(_ADJUST, KC)

#define USR_RDO G(S(KC_Z))
#define USR_PST G(KC_V)
#define USR_CPY G(KC_C)
#define USR_CUT G(KC_X)
#define USR_UND G(KC_Z)
#define VOL_SML A(KC_LSFT)

#define MS_L KC_MS_LEFT
#define MS_R KC_MS_RIGHT
#define MS_D KC_MS_DOWN
#define MS_U KC_MS_UP

#define WH_L KC_MS_WH_LEFT
#define WH_R KC_MS_WH_RIGHT
#define WH_D KC_MS_WH_DOWN
#define WH_U KC_MS_WH_UP

#define DEL_LINE MEH(KC_DEL)
#define SNIPE SNIPING_MODE

// combos
#define COMBO_COUNT 8
const uint16_t PROGMEM combo_hypr[]      = {SPC_NAV, TAB_CODE, COMBO_END};
const uint16_t PROGMEM combo_meh[]       = {SPC_NAV, ESC_MED, COMBO_END};
const uint16_t PROGMEM combo_winswitch[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_tabswitch[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_at[]        = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_tilde[]     = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_backtick[]  = {LALT_T(KC_L), RCTL_T(KC_QUOT), COMBO_END};
const uint16_t PROGMEM combo_capsword[]  = {LSFT_T(KC_F), RSFT_T(KC_J), COMBO_END};

// clang-format off
enum combos {
    COMBO_HYPR,
    COMBO_MEH,
    COMBO_WINSWITCH,
    COMBO_TABSWITCH,
    COMBO_AT,
    COMBO_BACKTICK,
    COMBO_TILDE,
    COMBO_CAPSWORD,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

combo_t key_combos[COMBO_COUNT] = {
    [COMBO_HYPR]      = COMBO(combo_hypr, KC_HYPR),
    [COMBO_MEH]       = COMBO(combo_meh, KC_MEH),
    [COMBO_WINSWITCH] = COMBO(combo_winswitch, WINSWITCH),
    [COMBO_TABSWITCH] = COMBO(combo_tabswitch, TABSWITCH),
    [COMBO_AT]        = COMBO(combo_at, S(KC_2)),
    [COMBO_TILDE]     = COMBO(combo_tilde, S(KC_GRV)),
    [COMBO_BACKTICK]  = COMBO(combo_backtick, KC_GRV),
    [COMBO_CAPSWORD]  = COMBO(combo_capsword, CW_TOGG),
};
// clang-format on

bool get_combo_must_hold(uint16_t index, combo_t *combo) {
    switch (index) {
        case COMBO_HYPR:
        case COMBO_MEH:
        case COMBO_WINSWITCH:
        case COMBO_TABSWITCH:
            return true;
    }

    return false;
}
// clang-format off
/** Convenience macro. */
#define _KC_LAYOUT_wrapper(                                                                             \
         k00,      k01,      k02,      k03,      k04,      k05,      k06,      k07,      k08,      k09, \
         k10,      k11,      k12,      k13,      k14,      k15,      k16,      k17,      k18,      k19, \
         k20,      k21,      k22,      k23,      k24,      k25,      k26,      k27,      k28,      k29, \
         ...)                                                                                           \
    KC_##k00, KC_##k01, KC_##k02, KC_##k03, KC_##k04, KC_##k05, KC_##k06, KC_##k07, KC_##k08, KC_##k09, \
    KC_##k10, KC_##k11, KC_##k12, KC_##k13, KC_##k14, KC_##k15, KC_##k16, KC_##k17, KC_##k18, KC_##k19, \
    KC_##k20, KC_##k21, KC_##k22, KC_##k23, KC_##k24, KC_##k25, KC_##k26, KC_##k27, KC_##k28, KC_##k29, \
    __VA_ARGS__
#define KC_LAYOUT_wrapper(...) _KC_LAYOUT_wrapper(__VA_ARGS__)

/** Base layer with BÉPO layout. */
#define LAYOUT_BASE_QWERTY KC_LAYOUT_wrapper(               \
       Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, \
       A,    S,    D,    F,    G,    H,    J,    K,    L,    QUOT, \
       Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH, \
       ESC_MED, SPC_NAV, TAB_CODE,   BSP_NUM, ENT_FUN)

/** Convenience key shorthands. */
#define U_NA KC_NO // Present but not available for use.
#define U_NU KC_NO // Available but not used.

/** Convenience row shorthands. */
#define __________________RESET_L__________________    QK_BOOT, U_NA,    U_NA,    U_NA,    U_NA
#define __________________RESET_R__________________    U_NA,    U_NA,    U_NA,    U_NA,    QK_BOOT
#define ______________HOME_ROW_GASC_L______________    KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, U_NA
#define ______________HOME_ROW_GASC_R______________    U_NA,    KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL
#define _________________COPY_PASTA________________    USR_UND, USR_CUT, USR_CPY, USR_PST, USR_RDO


//////////////
/** Layers. */
//////////////

// Navigation.
#define LAYOUT_MEDIA                                                                             \
    __________________RESET_L__________________,    U_NU,    U_NU,    U_NU,    U_NU,    MACSLEEP,\
    ______________HOME_ROW_GASC_L______________,    KC_CAPS, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, \
    _______, _______, _______, VOL_SML, _______,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    \
                         U_NA,    U_NA,    U_NA,    KC_MSTP, KC_MPLY

// Navigation.
#define LAYOUT_NAV                                                                               \
    __________________RESET_L__________________,    DEL_LINE, _______, _______, _______, _______,\
    ______________HOME_ROW_GASC_L______________,    CW_TOGG, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, \
    _________________COPY_PASTA________________,    KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  \
                         U_NA,    U_NA,    U_NA,    KC_BSPC, KC_ENT

// Code.
#define LAYOUT_CODE                                                                              \
    __________________RESET_L__________________,    KC_EXLM, KC_LBRC, KC_RBRC, KC_DLR,  KC_PERC, \
    ______________HOME_ROW_GASC_L______________,    KC_PIPE, KC_LCBR, KC_RCBR, KC_EQL,  KC_SCLN, \
    _________________COPY_PASTA________________,    KC_AMPR, S(KC_9), S(KC_0), S(KC_EQL),KC_BSLS,\
                      U_NA,    U_NA,    U_NA,       KC_DEL, A(KC_3)

// Numerals.
#define LAYOUT_NUM                                                                               \
    KC_LBRC,    KC_7,    KC_8,    KC_9,  KC_EQL,    __________________RESET_R__________________, \
    KC_COLN,    KC_4,    KC_5,    KC_6, KC_MINS,    ______________HOME_ROW_GASC_R______________, \
     KC_GRV,    KC_1,    KC_2,    KC_3, KC_UNDS,    _________________COPY_PASTA________________, \
                       KC_DOT,    KC_0, KC_MINS,    U_NA,    U_NA


// Function keys.
#define LAYOUT_FUN                                                                               \
     KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,    __________________RESET_R__________________, \
     KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SCRL,    ______________HOME_ROW_GASC_R______________, \
     KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS,    _________________COPY_PASTA________________, \
                       KC_APP,  KC_SPC,  KC_TAB,    U_NA,    U_NA
// Mouse (Auto)

/*
#define LAYOUT_MOUSE                                                                            \
    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, \
    _______, KC_BTN3, KC_BTN2, KC_BTN1, _______,    _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______,    _______, WH_L,    WH_D,    WH_U,    WH_R,    \
                      SNIPE,   _______, _______,    _______, _______
*/

// Mouse (manual)
#define LAYOUT_MOUSE                                                                             \
    S_D_MOD, _______, _______, _______, _______,    _______, _______, _______, _______, _______, \
    DPI_MOD, _______, _______, _______, _______,    _______, _______, _______, _______, _______, \
    _______, SNIPE,   _______, _______, _______,    _______, WH_L,    WH_D,    WH_U,    WH_R,    \
                      KC_BTN3, KC_BTN1, KC_BTN2,    _______, _______

// Adjust.
#define LAYOUT_ADJUST                                                                            \
    S_D_MOD, _______, _______, _______, _______,    _______, _______, _______, _______, _______, \
    DPI_MOD, _______, _______, _______, _______,    _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, \
                      _______, _______, _______,    _______, _______


// Layer wrappers
#define _HOME_ROW_MOD_GASC(                                            \
    L00, L01, L02, L03, L04, R05, R06, R07, R08, R09,                  \
    L10, L11, L12, L13, L14, R15, R16, R17, R18, R19,                  \
    ...)                                                               \
             L00,         L01,         L02,         L03,         L04,  \
             R05,         R06,         R07,         R08,         R09,  \
      LCTL_T(L10), LALT_T(L11), LGUI_T(L12), LSFT_T(L13),        L14,  \
             R15,  RSFT_T(R16), RGUI_T(R17), LALT_T(R18), RCTL_T(R19), \
      __VA_ARGS__
#define HOME_ROW_MOD_GASC(...) _HOME_ROW_MOD_GASC(__VA_ARGS__)

#define _MOUSE_MOD(                                               \
    L00, L01, L02, L03, L04, R05, R06, R07, R08, R09,             \
    L10, L11, L12, L13, L14, R15, R16, R17, R18, R19,             \
    L20, L21, L22, L23, L24, R25, R26, R27, R28, R29,             \
    ...)                                                          \
            L00,        L01,        L02,        L03,        L04,  \
            R05,        R06,        R07,        R08,        R09,  \
            L10,        L11,        L12,        L13,        L14,  \
            R15,        R16,        R17,        R18,        R19,  \
      MOUSE(L20),       L21,        L22,        L23,        L24,  \
            R25,        R26,        R27,        R28,  MOUSE(R29), \
      __VA_ARGS__
#define MOUSE_MOD(...) _MOUSE_MOD(__VA_ARGS__)

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_wrapper(
    MOUSE_MOD(HOME_ROW_MOD_GASC(LAYOUT_BASE_QWERTY))
  ),
  [_MEDIA] = LAYOUT_wrapper(LAYOUT_MEDIA),
  [_NAV] = LAYOUT_wrapper(LAYOUT_NAV),
  [_CODE] = LAYOUT_wrapper(LAYOUT_CODE),
  [_NUM] = LAYOUT_wrapper(LAYOUT_NUM),
  [_FUN] = LAYOUT_wrapper(LAYOUT_FUN),
  [_ADJUST] = LAYOUT_wrapper(LAYOUT_ADJUST),
  [_MOUSE]  = LAYOUT_wrapper(LAYOUT_MOUSE),
};
// clang-format on

#if defined(POINTING_DEVICE_ENABLE) && defined(CHARYBDIS_AUTO_SNIPING_ON_LAYER)
layer_state_t layer_state_set_kb(layer_state_t state) {
    state = layer_state_set_user(state);
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#endif // POINTING_DEVICE_ENABLE && CHARYBDIS_AUTO_SNIPING_ON_LAYER

void pointing_device_init_user(void) {
    // set_auto_mouse_enable(true); // always required before the auto mouse feature will work
}

uint8_t track_mode = 0;
#define cursor_mode 0
#define carret_mode 1
#define media_mode 2

int16_t cum_x         = 0;
int16_t cum_y         = 0;
int16_t tap_factor    = 100;
int16_t switch_factor = 250;

bool mouse_is_down = false;
uint16_t last_mouse_press   = 0;

void tap_code_fast(uint8_t code) {
    register_code(code);
    unregister_code(code);
}

void tap_tb(uint8_t keycode0, uint8_t keycode1, uint8_t keycode2, uint8_t keycode3) {
    if (abs(cum_x) + abs(cum_y) >= tap_factor) {
        if (abs(cum_x) > abs(cum_y)) {
            if (cum_x > 0) {
                for (int8_t i = 0; i <= (abs(cum_x) + abs(cum_y)) / tap_factor; i++) {
                    tap_code_fast(keycode0);
                    cum_x = max(cum_x - tap_factor, 0);
                }
                cum_y = 0;
            } else {
                for (int8_t i = 0; i <= (abs(cum_x) + abs(cum_y)) / tap_factor; i++) {
                    tap_code_fast(keycode1);
                    cum_x = min(cum_x + tap_factor, 0);
                }
                cum_y = 0;
            }
        } else {
            if (cum_y > 0) {
                for (int8_t i = 0; i <= (abs(cum_x) + abs(cum_y)) / tap_factor; i++) {
                    tap_code_fast(keycode2);
                    cum_y = max(cum_y - tap_factor, 0);
                }
                cum_x = 0;
            } else {
                for (int8_t i = 0; i <= (abs(cum_x) + abs(cum_y)) / tap_factor; i++) {
                    tap_code_fast(keycode3);
                    cum_y = min(cum_y + tap_factor, 0);
                }
                cum_x = 0;
            }
        }
    }
}

void tap_switcher(void) {
    if (abs(cum_x) + abs(cum_y) >= switch_factor) {
        if (cum_x > 0) {
            for (int8_t i = 0; i <= (abs(cum_x) + abs(cum_y)) / switch_factor; i++) {
                tap_code_fast(KC_TAB);
                cum_x = max(cum_x - switch_factor, 0);
            }
            cum_y = 0;
        } else {
            for (int8_t i = 0; i <= (abs(cum_x) + abs(cum_y)) / switch_factor; i++) {
                register_code(KC_LSFT);
                tap_code_fast(KC_TAB);
                unregister_code(KC_LSFT);
                cum_x = min(cum_x + switch_factor, 0);
            }
            cum_y = 0;
        }
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // dragscroll when on the _NAV layer
    charybdis_set_pointer_dragscroll_enabled(IS_LAYER_ON_STATE(state, _NAV));

    // other trackball modes
    if (IS_LAYER_ON_STATE(state, _MEDIA)) {
        track_mode = media_mode;
    } else if (IS_LAYER_ON_STATE(state, _CODE)) {
        track_mode = carret_mode;
    } else {
        track_mode = cursor_mode;
    }
    return state;
}

bool winswitch_active = false;
bool tabswitch_active = false;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // Pause mouse report updates for short time after clicking to make it easier
    // to double click with small movement of trackball
    bool mouse_pause = mouse_is_down && timer_elapsed(last_mouse_press) < 150;

    if (track_mode != cursor_mode || winswitch_active || tabswitch_active || mouse_pause) {
        // Nerf mouse_report as we're doing something else
        cum_x += mouse_report.x;
        cum_y -= mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    if (track_mode == media_mode) {
        tap_tb(KC_MNXT, KC_MPRV, KC_VOLU, KC_VOLD);
    } else if (track_mode == carret_mode) {
        tap_tb(KC_RIGHT, KC_LEFT, KC_UP, KC_DOWN);
    } else if (winswitch_active || tabswitch_active) {
        tap_switcher();
    }
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Pause mouse report updates for short time after clicking to make it easier
    // to double click with small movement of trackball
    if (keycode == KC_BTN1 || keycode == KC_BTN2 || keycode == KC_BTN3) {
        if (record->event.pressed) {
            mouse_is_down    = true;
            last_mouse_press = timer_read();
        } else {
            mouse_is_down = false;
        }
    }

    // custom keycodes
    switch (keycode) {
        case WINSWITCH:
            if (record->event.pressed) {
                if (!winswitch_active) {
                    winswitch_active = true;
                    register_code(KC_LGUI);
                    register_code(KC_TAB);
                    unregister_code(KC_TAB);
                }
            } else {
                if (winswitch_active) {
                    winswitch_active = false;
                    unregister_code(KC_LGUI);
                }
            }
            return false;

        case TABSWITCH:
            if (record->event.pressed) {
                if (!tabswitch_active) {
                    tabswitch_active = true;
                    register_code(KC_LCTL);
                    // register_code(KC_TAB);
                    // unregister_code(KC_TAB);
                }
            } else {
                if (tabswitch_active) {
                    tabswitch_active = false;
                    unregister_code(KC_LCTL);
                }
            }
            return false;

        case MACSLEEP:
            if (record->event.pressed) {
                register_code(KC_RSFT);
                register_code(KC_RCTL);
                register_code(KC_PWR);
                unregister_code(KC_PWR);
                unregister_code(KC_RCTL);
                unregister_code(KC_RSFT);
            }
            return false;

        default:
            return true;
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_MINS:
        case KC_UNDS:
        case KC_BSPC:
        case KC_DEL:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}
