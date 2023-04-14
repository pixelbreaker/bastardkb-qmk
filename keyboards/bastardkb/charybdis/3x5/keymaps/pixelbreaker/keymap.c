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

// To generate autcorrect_data.h run:
// qmk generate-autocorrect-data ./keyboards/bastardkb/charybdis/3x5/keymaps/pixelbreaker/autocorrect_dictionary.txt -kb bastardkb/charybdis/3x5/v2/splinky_3 -km pixelbreaker

#include QMK_KEYBOARD_H

enum custom_layers { _BASE = 0, _MEDIA, _NAV, _MOUSE, _CODE, _NUM, _FUN, _ADJUST };
enum custom_keycodes {
    APPSWITCH = QK_USER,
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

// CAGS
#define HRM_A LCTL_T(KC_A)
#define HRM_S LALT_T(KC_S)
#define HRM_D LGUI_T(KC_D)
#define HRM_F LSFT_T(KC_F)

#define HRM_J RSFT_T(KC_J)
#define HRM_K RGUI_T(KC_K)
#define HRM_L LALT_T(KC_L)
#define HRM_QUOT RCTL_T(KC_QUOT)

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
const uint16_t PROGMEM combo_hypr[]    = {SPC_NAV, TAB_CODE, COMBO_END}; // HYPR One shot mod
const uint16_t PROGMEM combo_meh[]     = {SPC_NAV, ESC_MED, COMBO_END};  // MEH One shot mod
const uint16_t PROGMEM combo_symbols[] = {BSP_NUM, ENT_FUN, COMBO_END};  // Shifted Num layer

const uint16_t PROGMEM combo_capsword[] = {LSFT_T(KC_F), RSFT_T(KC_J), COMBO_END}; // Capsword

const uint16_t PROGMEM combo_appswitch[] = {KC_C, KC_V, COMBO_END}; // Gui+tab application switcher with trackball
const uint16_t PROGMEM combo_tabswitch[] = {KC_X, KC_C, COMBO_END}; // Ctrl+tab tab switcher

const uint16_t PROGMEM combo_grv[]  = {KC_O, KC_P, COMBO_END};                    // Grave accent
const uint16_t PROGMEM combo_scln[] = {LALT_T(KC_L), RCTL_T(KC_QUOT), COMBO_END}; // Semi-colon
const uint16_t PROGMEM combo_at[]   = {KC_COMM, KC_DOT, COMBO_END};               // At
const uint16_t PROGMEM combo_hash[] = {KC_M, KC_COMM, COMBO_END};                 // Hash

const uint16_t PROGMEM combo_lchv[] = {KC_T, KC_G, COMBO_END};  // Left chevron
const uint16_t PROGMEM combo_rchv[] = {KC_Y, KC_H, COMBO_END};  // Right chevron
const uint16_t PROGMEM combo_lpar[] = {KC_R, HRM_F, COMBO_END}; // Left parenthesis
const uint16_t PROGMEM combo_rpar[] = {KC_U, HRM_J, COMBO_END}; // Right parenthesis
const uint16_t PROGMEM combo_lbrc[] = {KC_E, HRM_D, COMBO_END}; // Left bracket
const uint16_t PROGMEM combo_rbrc[] = {KC_I, HRM_K, COMBO_END}; // Right bracket
const uint16_t PROGMEM combo_lsqb[] = {KC_W, HRM_S, COMBO_END}; // Left square bracket
const uint16_t PROGMEM combo_rsqb[] = {KC_O, HRM_L, COMBO_END}; // Right square bracket

// clang-format off
enum combos {
    COMBO_HYPR,
    COMBO_MEH,
    COMBO_SYMBOLS,
    COMBO_APPSWITCH,
    COMBO_TABSWITCH,
    COMBO_GRV,
    COMBO_SCLN,
    COMBO_AT,
    COMBO_HASH,
    COMBO_CAPSWORD,
    COMBO_LCHV,
    COMBO_RCHV,
    COMBO_LPAR,
    COMBO_RPAR,
    COMBO_LBRC,
    COMBO_RBRC,
    COMBO_LSQB,
    COMBO_RSQB,
    COMBO_LENGTH
};

// clang-format on
uint16_t COMBO_LEN = COMBO_LENGTH;

combo_t key_combos[] = {
    [COMBO_HYPR]      = COMBO(combo_hypr, OSM(MOD_HYPR)), // KC_HYPR),
    [COMBO_MEH]       = COMBO(combo_meh, OSM(MOD_MEH)),   // KC_MEH),
    [COMBO_SYMBOLS]   = COMBO(combo_symbols, LM(_NUM, MOD_LSFT)),
    [COMBO_APPSWITCH] = COMBO(combo_appswitch, APPSWITCH),
    [COMBO_TABSWITCH] = COMBO(combo_tabswitch, TABSWITCH),
    [COMBO_GRV]       = COMBO(combo_grv, KC_GRV),
    [COMBO_SCLN]      = COMBO(combo_scln, KC_SCLN),
    [COMBO_AT]        = COMBO(combo_at, S(KC_2)),
    [COMBO_HASH]      = COMBO(combo_hash, A(KC_3)),
    [COMBO_CAPSWORD]  = COMBO(combo_capsword, CW_TOGG),
    [COMBO_LCHV]      = COMBO(combo_lchv, S(KC_COMMA)),
    [COMBO_RCHV]      = COMBO(combo_rchv, S(KC_DOT)),
    [COMBO_LPAR]      = COMBO(combo_lpar, S(KC_LBRC)),
    [COMBO_RPAR]      = COMBO(combo_rpar, S(KC_RBRC)),
    [COMBO_LBRC]      = COMBO(combo_lbrc, S(KC_9)),
    [COMBO_RBRC]      = COMBO(combo_rbrc, S(KC_0)),
    [COMBO_LSQB]      = COMBO(combo_lsqb, KC_LBRC),
    [COMBO_RSQB]      = COMBO(combo_rsqb, KC_RBRC),
};

bool get_combo_must_hold(uint16_t index, combo_t *combo) {
    switch (index) {
        // case COMBO_HYPR:
        // case COMBO_MEH:
        case COMBO_APPSWITCH:
        case COMBO_TABSWITCH:
            return true;
    }

    return false;
}
// clang-format off

/** Convenience key shorthands. */
#define U_NA KC_NO // Present but not available for use.
#define U_NU KC_NO // Available but not used.

/** Convenience row shorthands. */
#define __________________RESET_L__________________    QK_BOOT, U_NA,    U_NA,    U_NA,    U_NA
#define __________________RESET_R__________________    U_NA,    U_NA,    U_NA,    U_NA,    QK_BOOT
#define ______________HOME_ROW_CAGS_L______________    KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, U_NA
#define ______________HOME_ROW_CAGS_R______________    U_NA,    KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL
#define ________________COPY_PASTA_________________    USR_UND, USR_CUT, USR_CPY, USR_PST, USR_RDO
#define ________MOUSE_BUTS_______   KC_BTN2, KC_BTN1, KC_BTN3

//////////////
/** Layers. */
//////////////

// Base QWERTY
#define LAYOUT_QWERTY                                                                            \
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
    HRM_A,   HRM_S,   HRM_D,   HRM_F,   KC_G,       KC_H,    HRM_J,   HRM_K,   HRM_L,   HRM_QUOT,\
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
                      ESC_MED, SPC_NAV, TAB_CODE,   BSP_NUM, ENT_FUN

// Media.
#define LAYOUT_MEDIA                                                                             \
    __________________RESET_L__________________,    MACSLEEP,WH_L,    WH_D,    WH_U,    WH_R,    \
    _______, _______, _______, VOL_SML, _______,    KC_CAPS, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, \
    _______, _______, _______, _______, _______,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    \
                         U_NA,    U_NA,    U_NA,    KC_MSTP, KC_MPLY

// Navigation.
#define LAYOUT_NAV                                                                               \
    __________________RESET_L__________________,    DEL_LINE, _______, _______, _______, _______,\
    ______________HOME_ROW_CAGS_L______________,    CW_TOGG, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, \
    ________________COPY_PASTA_________________,    KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  \
                         U_NA,    U_NA,    U_NA,    KC_BSPC, KC_ENT

/*
!, +, *, $, `,
|, -, /, =, ;,
&, _, #, @, \,
*/
// Code.
#define LAYOUT_CODE                                                                              \
    __________________RESET_L__________________,    KC_EXLM, S(KC_EQL),S(KC_8),KC_DLR,  KC_PERC, \
    ______________HOME_ROW_CAGS_L______________,    KC_PIPE, KC_MINS, KC_SLSH, KC_EQL,  KC_SCLN, \
    ________________COPY_PASTA_________________,    KC_AMPR, KC_UNDS, A(KC_3), S(KC_2), KC_BSLS, \
                      U_NA,    U_NA,    U_NA,       KC_DEL, U_NA

/*
#define LAYOUT_CODE                                                                              \
    __________________RESET_L__________________,    KC_EXLM, KC_LBRC, KC_RBRC, KC_DLR,  KC_PERC, \
    ______________HOME_ROW_CAGS_L______________,    KC_PIPE, KC_LCBR, KC_RCBR, KC_EQL,  KC_SCLN, \
    ________________COPY_PASTA_________________,    KC_AMPR, S(KC_9), S(KC_0), S(KC_EQL),KC_BSLS,\
                      U_NA,    U_NA,    U_NA,       KC_DEL, U_NA
*/

// Numerals.
#define LAYOUT_NUM                                                                               \
    KC_LBRC,    KC_7,    KC_8,    KC_9, KC_EQL,     __________________RESET_R__________________, \
    KC_COLN,    KC_4,    KC_5,    KC_6, KC_MINS,    ______________HOME_ROW_CAGS_R______________, \
     KC_GRV,    KC_1,    KC_2,    KC_3, KC_UNDS,    ________________COPY_PASTA_________________, \
                       KC_DOT,    KC_0, KC_MINS,    U_NA,    U_NA


// Function keys.
#define LAYOUT_FUN                                                                               \
     KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,    __________________RESET_R__________________, \
     KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SCRL,    ______________HOME_ROW_CAGS_R______________, \
     KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS,    ________________COPY_PASTA_________________, \
                       KC_APP,  KC_SPC,  KC_TAB,    U_NA,    U_NA

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
// Mouse (Auto)
    #define LAYOUT_MOUSE                                                                         \
    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, \
    _______, SNIPE,   ________MOUSE_BUTS_______,    _______, _______, _______, _______, _______, \
                      _______, _______, _______,    _______, _______
#else
// Mouse (Manual)
    #define LAYOUT_MOUSE                                                                         \
    DPI_MOD, S_D_MOD, _______, _______, _______,    _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, \
    _______, SNIPE,   _______, _______, _______,    _______, _______, _______, _______, _______, \
                      ________MOUSE_BUTS_______,    _______, _______

#endif

// Adjust.
#define LAYOUT_ADJUST                                                                            \
    DPI_MOD, S_D_MOD, _______, _______, _______,    _______, _______, _______, _______, _______, \
    AC_TOGG, _______, _______, _______, _______,    _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, \
                      _______, _______, _______,    _______, _______


// Layer wrappers
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
            R25,        R26,        R27,        R28, ADJUST(R29), \
      __VA_ARGS__
#define MOUSE_MOD(...) _MOUSE_MOD(__VA_ARGS__)

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_wrapper(MOUSE_MOD(LAYOUT_QWERTY)),
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

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_enable(true); // always required before the auto mouse feature will work
}
#endif

enum trackball_modes {
    CURSOR = 0,
    CARRET,
    MEDIA,
};
uint8_t track_mode = CURSOR;

int16_t cum_x         = 0;
int16_t cum_y         = 0;
int16_t tap_factor    = 100;
int16_t switch_factor = 250;

bool     mouse_is_down    = false;
uint16_t last_mouse_press = 0;
uint16_t last_media_nav   = 0;

void tap_code_fast(uint8_t code) {
    register_code(code);
    unregister_code(code);
}

void tap_tb(uint8_t keycode0, uint8_t keycode1, uint8_t keycode2, uint8_t keycode3) {
    if (abs(cum_x) + abs(cum_y) >= tap_factor) {
        if (abs(cum_x) * 0.4 > abs(cum_y)) {
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

void tap_media(void) {
    if (abs(cum_x) + abs(cum_y) >= tap_factor) {
        if (abs(cum_x) > abs(cum_y)) {
            if (cum_x > 0) {
                if (cum_x > 80 && timer_elapsed(last_media_nav) > 500) {
                    tap_code_fast(KC_MNXT);
                    last_media_nav = timer_read();
                }
                cum_x = max(cum_x - tap_factor, 0);
                cum_y = 0;
            } else {
                if (cum_x < -80 && timer_elapsed(last_media_nav) > 500) {
                    tap_code_fast(KC_MPRV);
                    last_media_nav = timer_read();
                }
                cum_x = min(cum_x + tap_factor, 0);
                cum_y = 0;
            }
        } else {
            if (cum_y > 0) {
                for (int8_t i = 0; i <= (abs(cum_x) + abs(cum_y)) / tap_factor; i++) {
                    tap_code_fast(KC_VOLU);
                    cum_y = max(cum_y - tap_factor, 0);
                }
                cum_x = 0;
            } else {
                for (int8_t i = 0; i <= (abs(cum_x) + abs(cum_y)) / tap_factor; i++) {
                    tap_code_fast(KC_VOLD);
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
    charybdis_set_pointer_dragscroll_enabled(layer_state_cmp(state, _NAV));

    // other trackball modes
    if (layer_state_cmp(state, _MEDIA)) {
        track_mode = MEDIA;
    } else if (layer_state_cmp(state, _CODE)) {
        track_mode = CARRET;
    } else {
        track_mode = CURSOR;
    }
    return state;
}

bool appswitch_active = false;
bool tabswitch_active = false;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // Pause mouse report updates for short time after clicking to make it easier
    // to double click with small movement of trackball
    bool mouse_pause = mouse_is_down && timer_elapsed(last_mouse_press) < 150;

    if (track_mode != CURSOR || appswitch_active || tabswitch_active || mouse_pause) {
        // Nerf mouse_report as we're doing something else
        cum_x += mouse_report.x;
        cum_y -= mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    if (track_mode == MEDIA) {
        // tap_tb(KC_NO, KC_NO, KC_VOLU, KC_VOLD);
        tap_media();
    } else if (track_mode == CARRET) {
        tap_tb(KC_RIGHT, KC_LEFT, KC_UP, KC_DOWN);
    } else if (appswitch_active || tabswitch_active) {
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
        // cancel auto mouse if using thumb cluster
        case ESC_MED:
        case SPC_NAV:
        case TAB_CODE:
        case BSP_NUM:
        case ENT_FUN:
        case OSM(MOD_HYPR):
            if (record->event.pressed) {
                layer_off(_MOUSE);
            }
            return true;

        case APPSWITCH:
            if (record->event.pressed) {
                if (!appswitch_active) {
                    register_code(KC_LGUI);
                    register_code(KC_TAB);
                    unregister_code(KC_TAB);
                }
            } else {
                if (appswitch_active) {
                    unregister_code(KC_LGUI);
                }
            }
            appswitch_active = record->event.pressed;
            return false;

        case TABSWITCH:
            if (record->event.pressed) {
                if (!tabswitch_active) {
                    register_code(KC_LCTL);
                }
            } else {
                if (tabswitch_active) {
                    unregister_code(KC_LCTL);
                }
            }
            tabswitch_active = record->event.pressed;
            return false;

        case MACSLEEP:
            if (record->event.pressed) {
                register_code(KC_RSFT);
                register_code(KC_RCTL);
                register_code(KC_SYSTEM_POWER);
                unregister_code(KC_SYSTEM_POWER);
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

// reset CPI after wake
void suspend_wakeup_init_user(void) {
    keyboard_post_init_kb();
}
