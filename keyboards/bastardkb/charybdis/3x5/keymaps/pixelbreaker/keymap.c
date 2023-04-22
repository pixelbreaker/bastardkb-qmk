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
    BI_MEMARR,
    BI_ARRFN,
    SNIP_ARRFN,
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
// #define CHARYDIS_AUTO_SNIPING_ON_LAYER _MOUSE

#ifdef CHARYBDIS_DRAGSCROLL_DPI
#    undef CHARYBDIS_DRAGSCROLL_DPI
#endif
#define CHARYBDIS_DRAGSCROLL_DPI 40

#ifndef MEDIA_TAP_TERM
#    define MEDIA_TAP_TERM 500
#endif
#ifndef MEDIA_TAP_THRESHOLD
#    define MEDIA_TAP_THRESHOLD 100
#endif

#ifndef CARRET_TIMEOUT_MS
#    define CARRET_TIMEOUT_MS 250
#endif

#define ESC_MED LT(_MEDIA, KC_ESC)
#define SPC_NAV LT(_NAV, KC_SPC)
#define TAB_CODE LT(_CODE, KC_TAB)
#define BSP_NUM LT(_NUM, KC_BSPC)
#define ENT_FUN LT(_FUN, KC_ENT)

#define OSM_HYPR OSM(MOD_HYPR)
#define OSM_MEH OSM(MOD_MEH)

#define MO_Z LT(_MOUSE, KC_Z)
#define ADJ_SLSH LT(_ADJUST, KC_SLSH)

#define USR_RDO G(S(KC_Z))
#define USR_PST G(KC_V)
#define USR_CPY G(KC_C)
#define USR_CUT G(KC_X)
#define USR_UND G(KC_Z)
#define VOL_SML A(KC_LSFT)
#define MACSLEEP RCS(KC_KB_POWER)

// CAGS (Qwerty)
#define HRM_A LCTL_T(KC_A)
#define HRM_S LALT_T(KC_S)
#define HRM_D LGUI_T(KC_D)
#define HRM_F LSFT_T(KC_F)

#define HRM_J RSFT_T(KC_J)
#define HRM_K RGUI_T(KC_K)
#define HRM_L LALT_T(KC_L)
#define HRM_QUOT RCTL_T(KC_QUOT)

#define GB_HASH A(KC_3)
#define GB_AT S(KC_2)

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
const uint16_t PROGMEM combo_hypr[]   = {SPC_NAV, TAB_CODE, COMBO_END}; // HYPR One shot mod
const uint16_t PROGMEM combo_meh[]    = {SPC_NAV, ESC_MED, COMBO_END};  // MEH One shot mod
const uint16_t PROGMEM combo_delete[] = {BSP_NUM, ENT_FUN, COMBO_END};  // Shifted Num layer

const uint16_t PROGMEM combo_capsword[] = {HRM_F, HRM_J, COMBO_END}; // Capsword

const uint16_t PROGMEM combo_appswitch[] = {KC_C, KC_V, COMBO_END}; // Gui+tab application switcher with trackball
const uint16_t PROGMEM combo_tabswitch[] = {KC_X, KC_C, COMBO_END}; // Ctrl+tab tab switcher

const uint16_t PROGMEM combo_l11[]       = {KC_Q, HRM_A, COMBO_END};
const uint16_t PROGMEM combo_l12[]       = {KC_W, HRM_S, COMBO_END};
const uint16_t PROGMEM combo_l13[]       = {KC_E, HRM_D, COMBO_END};
const uint16_t PROGMEM combo_l14[]       = {KC_R, HRM_F, COMBO_END};
const uint16_t PROGMEM combo_l15[]       = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM combo_l21[]       = {HRM_A, MO_Z, COMBO_END};
const uint16_t PROGMEM combo_l22[]       = {HRM_S, KC_X, COMBO_END};
const uint16_t PROGMEM combo_l23[]       = {HRM_D, KC_C, COMBO_END};
const uint16_t PROGMEM combo_l24[]       = {HRM_F, KC_V, COMBO_END};
const uint16_t PROGMEM combo_l25[]       = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM combo_r11[]       = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM combo_r12[]       = {KC_U, HRM_J, COMBO_END};
const uint16_t PROGMEM combo_r13[]       = {KC_I, HRM_K, COMBO_END};
const uint16_t PROGMEM combo_r14[]       = {KC_O, HRM_L, COMBO_END};
const uint16_t PROGMEM combo_r15[]       = {KC_P, HRM_QUOT, COMBO_END};
const uint16_t PROGMEM combo_r21[]       = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM combo_r22[]       = {HRM_J, KC_M, COMBO_END};
const uint16_t PROGMEM combo_r23[]       = {HRM_K, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_r24[]       = {HRM_L, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_r25[]       = {HRM_QUOT, ADJ_SLSH, COMBO_END};
const uint16_t PROGMEM combo_memarr[]    = {KC_H, KC_N, COMBO_END};  // ->
const uint16_t PROGMEM combo_arrfn[]     = {HRM_J, KC_M, COMBO_END}; // =>
const uint16_t PROGMEM combo_fullarrfn[] = {HRM_A, MO_Z, COMBO_END}; // () => {}

// clang-format off
enum combos {
    COMBO_HYPR,
    COMBO_MEH,
    COMBO_DELETE,
    COMBO_APPSWITCH,
    COMBO_TABSWITCH,
    COMBO_CAPSWORD,
    COMBO_L11,
    COMBO_L12,
    COMBO_L13,
    COMBO_L14,
    COMBO_L15,
    COMBO_L21,
    COMBO_L22,
    COMBO_L23,
    COMBO_L24,
    COMBO_L25,
    COMBO_R11,
    COMBO_R12,
    COMBO_R13,
    COMBO_R14,
    COMBO_R15,
    COMBO_R21,
    COMBO_R22,
    COMBO_R23,
    COMBO_R24,
    COMBO_R25,
    COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

combo_t key_combos[] = {
    [COMBO_HYPR]        = COMBO(combo_hypr, OSM_HYPR),
    [COMBO_MEH]         = COMBO(combo_meh, OSM_MEH),
    [COMBO_DELETE]      = COMBO(combo_delete, KC_DEL),

    [COMBO_APPSWITCH]   = COMBO(combo_appswitch, APPSWITCH),
    [COMBO_TABSWITCH]   = COMBO(combo_tabswitch, TABSWITCH),
    [COMBO_CAPSWORD]    = COMBO(combo_capsword, CW_TOGG),

    [COMBO_L11]       = COMBO(combo_l11, KC_TILD),
    [COMBO_L12]       = COMBO(combo_l12, KC_LBRC),
    [COMBO_L13]       = COMBO(combo_l13, KC_LPRN),
    [COMBO_L14]       = COMBO(combo_l14, KC_LCBR),
    [COMBO_L15]       = COMBO(combo_l15, KC_LT),
    [COMBO_L21]       = COMBO(combo_l21, SNIP_ARRFN),
    [COMBO_L22]       = COMBO(combo_l22, KC_NO),
    [COMBO_L23]       = COMBO(combo_l23, KC_BTN2),
    [COMBO_L24]       = COMBO(combo_l24, KC_BTN1),
    [COMBO_L25]       = COMBO(combo_l25, KC_BTN3),

    [COMBO_R11]       = COMBO(combo_r11, KC_GT),
    [COMBO_R12]       = COMBO(combo_r12, KC_RCBR),
    [COMBO_R13]       = COMBO(combo_r13, KC_RPRN),
    [COMBO_R14]       = COMBO(combo_r14, KC_RBRC),
    [COMBO_R15]       = COMBO(combo_r15, KC_GRV),
    [COMBO_R21]       = COMBO(combo_r21, BI_MEMARR), // ->
    [COMBO_R22]       = COMBO(combo_r22, BI_ARRFN), // =>
    [COMBO_R23]       = COMBO(combo_r23, GB_HASH), // #
    [COMBO_R24]       = COMBO(combo_r24, GB_AT), // @
    [COMBO_R25]       = COMBO(combo_r25, KC_SCLN),
};

/** Convenience key shorthands. */
#define U_NA KC_NO // Present but not available for use.
#define U_NU KC_NO // Available but not used.

/** Convenience row shorthands. */
#define __________________RESET_L__________________    QK_BOOT, U_NA,    U_NA,    U_NA,    U_NA
#define __________________RESET_R__________________    U_NA,    U_NA,    U_NA,    U_NA,    QK_BOOT
#define ______________HOME_ROW_CAGS_L______________    KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, U_NA
#define ______________HOME_ROW_CAGS_R______________    U_NA,    KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL
#define ________________COPY_PASTA_________________    USR_UND, USR_CUT, USR_CPY, USR_PST, USR_RDO
#define ________MOUSE_BUTS_______                      KC_BTN2, KC_BTN1, KC_BTN3

//////////////
/** Layers. */
//////////////

// Base QWERTY
#define LAYOUT_QWERTY                                                                            \
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
    HRM_A,   HRM_S,   HRM_D,   HRM_F,   KC_G,       KC_H,    HRM_J,   HRM_K,   HRM_L,   HRM_QUOT,\
    MO_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  ADJ_SLSH, \
                      ESC_MED, SPC_NAV, TAB_CODE,   BSP_NUM, ENT_FUN

// Media.
#define LAYOUT_MEDIA                                                                             \
    __________________RESET_L__________________,    MACSLEEP,WH_L,    WH_D,    WH_U,    WH_R,    \
    _______, _______, _______, VOL_SML, _______,    KC_CAPS, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, \
    _______, _______, _______, _______, _______,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    \
                         U_NA,    U_NA,    U_NA,    KC_MSTP, KC_MPLY

// Navigation.
#define LAYOUT_NAV                                                                               \
    __________________RESET_L__________________,    CW_TOGG, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______,    DEL_LINE,KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, \
    ________________COPY_PASTA_________________,    KC_INS, KC_HOME, KC_PGDN,  KC_PGUP, KC_END,  \
                         U_NA,    U_NA,    U_NA,    KC_BSPC, KC_ENT

/*
!, +, *, $, `,
|, -, /, =, :,
&, _, #, @, \,
*/

// Code.
#define LAYOUT_CODE                                                                              \
     _______,_______,KC_LBRC, KC_RBRC, _______,     KC_EXLM, KC_PLUS, KC_ASTR, KC_DLR,  KC_GRV,  \
     _______,KC_LT,  KC_LPRN, KC_RPRN, KC_GT,       KC_PIPE, KC_MINS, KC_SLSH, KC_EQL,  KC_COLN, \
     _______,_______,KC_LCBR, KC_RCBR, _______,     KC_AMPR, KC_UNDS, GB_HASH, GB_AT,   KC_BSLS, \
                      U_NA,   _______, U_NA,        _______, _______

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
    ______________HOME_ROW_CAGS_L______________,    _______, _______, _______, _______, _______, \
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
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_wrapper(LAYOUT_QWERTY),
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

bool     mouse_is_down           = false;
uint16_t last_mouse_press        = 0;
uint16_t last_media_nav          = 0;
uint16_t switch_track_mode_timer = 0;

void tap_code_fast(uint8_t code) {
    register_code(code);
    unregister_code(code);
}

void tap_tb(uint8_t keycode0, uint8_t keycode1, uint8_t keycode2, uint8_t keycode3) {
    if (abs(cum_x) + abs(cum_y) >= tap_factor) {
        if (abs(cum_x) * 0.4 > abs(cum_y)) {
            for (int8_t i = 0; i <= (abs(cum_x) + abs(cum_y)) / tap_factor; i++) {
                if (cum_x > 0) {
                    tap_code_fast(keycode0);
                    cum_x = max(cum_x - tap_factor, 0);
                } else {
                    tap_code_fast(keycode1);
                    cum_x = min(cum_x + tap_factor, 0);
                }
            }
            cum_y = 0;
        } else {
            for (int8_t i = 0; i <= (abs(cum_x) + abs(cum_y)) / tap_factor; i++) {
                if (cum_y > 0) {
                    tap_code_fast(keycode2);
                    cum_y = max(cum_y - tap_factor, 0);
                } else {
                    tap_code_fast(keycode3);
                    cum_y = min(cum_y + tap_factor, 0);
                }
            }
            cum_x = 0;
        }
    }
}

void tap_media(void) {
    if (abs(cum_x) + abs(cum_y) >= tap_factor) {
        if (abs(cum_x) > abs(cum_y)) {
            for (int8_t i = 0; i <= (abs(cum_x) + abs(cum_y)) / tap_factor; i++) {
                if (cum_x > 0) {
                    if (cum_x > MEDIA_TAP_THRESHOLD && timer_elapsed(last_media_nav) > MEDIA_TAP_TERM) {
                        tap_code_fast(KC_MNXT);
                        last_media_nav = timer_read();
                    }
                    cum_x = max(cum_x - tap_factor, 0);
                } else {
                    if (cum_x < -MEDIA_TAP_THRESHOLD && timer_elapsed(last_media_nav) > MEDIA_TAP_TERM) {
                        tap_code_fast(KC_MPRV);
                        last_media_nav = timer_read();
                    }
                    cum_x = max(cum_x + tap_factor, 0);
                }
            }
            cum_y = 0;
        } else {
            for (int8_t i = 0; i <= (abs(cum_x) + abs(cum_y)) / tap_factor; i++) {
                if (cum_y > 0) {
                    tap_code_fast(KC_VOLU);
                    cum_y = max(cum_y - tap_factor, 0);
                } else {
                    tap_code_fast(KC_VOLD);
                    cum_y = min(cum_y + tap_factor, 0);
                }
            }
            cum_x = 0;
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

bool appswitch_active = false;
bool tabswitch_active = false;

static deferred_token activate_carret_token = INVALID_DEFERRED_TOKEN;

uint32_t activate_carret_mode(uint32_t trigger_time, void *cb_arg) {
    track_mode = CARRET;
    return 0;
}

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
        tap_media();
    } else if (track_mode == CARRET) {
        tap_tb(KC_RIGHT, KC_LEFT, KC_UP, KC_DOWN);
    } else if (appswitch_active || tabswitch_active) {
        tap_switcher();
    }
    return mouse_report;
}

bool return_or_achordion(bool default_return, uint16_t keycode, keyrecord_t *record) {
#if !defined(POINTING_DEVICE_AUTO_MOUSE_ENABLE) && defined(ACHORDION_ENABLE)
    return process_achordion(keycode, record);
#else
    return default_return;
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // if thumb cluster keys are pressed, turn off the mouse layer
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    if (record->event.key.row % (MATRIX_ROWS / 2) >= 3 && record->event.pressed) {
        layer_off(_MOUSE);
    }
#endif

    // custom keycodes
    switch (keycode) {
        // set trackball modes...
        case SPC_NAV:
            charybdis_set_pointer_dragscroll_enabled(record->event.pressed);
            return return_or_achordion(true, keycode, record);
        case ESC_MED:
            track_mode = record->event.pressed ? MEDIA : CURSOR;
            return return_or_achordion(true, keycode, record);
        case TAB_CODE:
            if (record->event.pressed) {
                if (!extend_deferred_exec(activate_carret_token, CARRET_TIMEOUT_MS)) {
                    activate_carret_token = defer_exec(CARRET_TIMEOUT_MS, activate_carret_mode, NULL);
                }
            } else {
                cancel_deferred_exec(activate_carret_token);
                track_mode = CURSOR;
            }
            return return_or_achordion(true, keycode, record);

        case OSM_HYPR:
        case OSM_MEH:
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
            if (record->event.pressed) {
                layer_off(_MOUSE);
            }
#endif
            return true;

        // Pause mouse report updates for short time after clicking to make it easier
        // to double click with small movement of trackball
        case KC_BTN1 ... KC_BTN3:
            if (record->event.pressed) {
                mouse_is_down    = true;
                last_mouse_press = timer_read();
            } else {
                mouse_is_down = false;
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

        // COMPLEX combos
        case BI_MEMARR: // ->
            if (record->event.pressed) {
                tap_code16(KC_MINS);
                tap_code16(KC_GT);
            }
            return false;

        case BI_ARRFN: // =>
            if (record->event.pressed) {
                tap_code16(KC_EQL);
                tap_code16(KC_GT);
            }
            return false;

        case SNIP_ARRFN: // Full arrow function
            if (record->event.pressed) {
                SEND_STRING("() =>\n{\n\n}");
                tap_code16(KC_UP);
            }
            return false;

        default:
#if !defined(POINTING_DEVICE_AUTO_MOUSE_ENABLE) && defined(ACHORDION_ENABLE)
            return process_achordion(keycode, record);
#else
            return true;
#endif
    }
}

/*
    ACHORDION config
*/
#if !defined(POINTING_DEVICE_AUTO_MOUSE_ENABLE) && defined(ACHORDION_ENABLE)

void matrix_scan_user(void) {
    achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    // Exceptionally consider the following chords as holds, even though they
    // are on the same hand.
    switch (tap_hold_keycode) {
        case HRM_D: // D + S.
            if (other_keycode == HRM_S) {
                return true;
            }
            break;
    }
    // Also allow same-hand hol ds when the other key is in the rows below the
    // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
    // if (tap_hold_record->event.key.row % (MATRIX_ROWS / 2) >= 3 || other_record->event.key.row % (MATRIX_ROWS / 2) >= 3) {
    //     return true;
    // }

    // Otherwise, follow the opposite hands rule.
    return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case ESC_MED:
        case TAB_CODE:
        case BSP_NUM:
        case ENT_FUN:
        case SPC_NAV:
            return 0;

        case MO_Z:
            return 150;

        default:
            return 800;
    }

    return 800;
}

bool achordion_eager_mod(uint8_t mod) {
    switch (mod) {
        // case MOD_LSFT:
        // case MOD_RSFT:
        // case MOD_LCTL:
        // case MOD_RCTL:
        case MOD_HYPR:
        case MOD_MEH:
            return true; // Eagerly apply Shift and Ctrl mods.

        default:
            return false;
    }
}

#endif

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

// Combos
bool get_combo_must_hold(uint16_t index, combo_t *combo) {
    switch (index) {
        case COMBO_APPSWITCH:
        case COMBO_TABSWITCH:
            return true;
    }

    return false;
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        // thumbs combos tend to be super slow
        case COMBO_HYPR:
        case COMBO_MEH:
            return COMBO_TERM + 100;

        case COMBO_DELETE:
            return COMBO_TERM + 50;

        // some combos are slooow
        case COMBO_L21:
        case COMBO_L23:
        case COMBO_L24:
        case COMBO_L25:
        case COMBO_R25:
            return COMBO_TERM + 40;
    }

    return COMBO_TERM;
}

// reset CPI after wake
void suspend_wakeup_init_user(void) {
    keyboard_post_init_kb();
}
