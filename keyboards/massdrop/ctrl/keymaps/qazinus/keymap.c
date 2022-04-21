#include QMK_KEYBOARD_H

// #include "keymap.h"

// static uint16_t idle_timer;             // Idle LED timeout timer
// static uint8_t idle_second_counter;     // Idle LED seconds counter, counts seconds not milliseconds
// static uint8_t key_event_counter;       // This counter is used to check if any keys are being held


enum ctrl_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
};

// static const char * sendstring_commands[] = {
//     "git init ",
//     "git clone ",
//     "git config --global ",
//     "git add ",
//     "git diff ",
//     "git reset ",
//     "git rebase ",
//     "git branch -b \"",
//     "git checkout ",
//     "git merge ",
//     "git remote add ",
//     "git fetch ",
//     "git pull ",
//     "git push ",
//     "git commit ",
//     "git status ",
//     "git log ",
// };

// //Associate our tap dance key with its functionality
// qk_tap_dance_action_t tap_dance_actions[] = {
//     [TD_LGUI_ML] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LGUI, _ML),
//     [TD_APP_YL] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_APP, _YL),
//     [TD_CTRL_TERM] = ACTION_TAP_DANCE_DOUBLE(KC_LCTRL, LCA(KC_T)),
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                              KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(1),   KC_APP,  KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            KC_MUTE, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_MPLY, KC_MSTP, KC_VOLU,
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, _______, _______, _______, _______,   KC_MPRV, KC_MNXT, KC_VOLD,
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______, _______,
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, NK_TOGG, _______, _______, _______, _______, _______,                              _______,
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______,                              _______,
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______
    ),
    */
};

// #ifdef _______
// #undef _______
// #define _______ {0, 0, 0}

// const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
//     [_FL] = {
//         _______, CORAL,   CORAL,   _______, _______, CORAL,   CORAL,   _______, _______, CORAL,   _______, YELLOW,  YELLOW,           TEAL,    GOLD,   GOLD,
//         _______, _______, PINK,    PINK,    PINK,    PINK,    _______, _______, _______, GREEN,   GREEN,   GREEN,   GREEN,   _______, TEAL,    TEAL,   TEAL,
//         ORANGE,  ORANGE,  ORANGE,  ORANGE,  ORANGE,  ORANGE,  _______, AZURE,   AZURE,   _______, _______, _______, _______, _______, TEAL,    TEAL,   TEAL,
//         _______, ORANGE,  ORANGE,  ORANGE,  ORANGE,  ORANGE,  _______, _______, _______, _______, _______, _______, _______,
//         _______, ORANGE,  _______, CORAL,   _______, AZURE,   AZURE,   _______, _______, _______, _______, AZURE,                              SPRING,
//         _______, _______, _______,                   _______,                            _______, PINK,    _______, AZURE,            _______, SPRING, _______
//     },
//     [_ML] = {
//         _______, GOLD,    GOLD,    GOLD,   _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
//         _______, MAGENT,  MAGENT,  MAGENT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//         _______, MAGENT,  GOLD,    MAGENT, GOLD,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//         _______, GOLD,    GOLD,    GOLD,   GOLD,    _______, _______, _______, _______, _______, _______, _______, _______,
//         _______, _______, _______, CORAL,  _______, _______, _______, _______, _______, _______, _______, _______,                            GOLD,
//         _______, PINK,    _______,                  _______,                                     _______, PINK,    _______, _______, GOLD,    GOLD,    GOLD
//     },
//     [_GL] = {
//         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
//         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//         _______, _______, _______, _______, BLUE,    AZURE,   AZURE,   _______, CYAN,    _______, TURQ,    PURPLE,  _______, _______, _______, _______, _______,
//         _______, CORAL,   GREEN,   GREEN,   TURQ,    _______, _______, _______, _______, GREEN,   _______, _______, _______,
//         _______, CYAN,    CHART,   TURQ,    ORANGE,  CHART,   _______, CHART,   _______, _______, _______, _______,                            _______,
//         _______, _______, _______,                   _______,                            _______, PINK,    _______, _______,          _______, _______, _______
//     },
//     [_VL] = {
//         PURPLE,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
//         _______, _______, _______, TURQ,    _______, _______, _______, _______, TURQ,    _______, _______, _______, _______, _______, _______, _______, _______,
//         _______, AZURE,   AZURE,   AZURE,   PURPLE,  _______, BLUE,    PURPLE,  PURPLE,  PURPLE,  BLUE,    _______, _______, _______, _______, _______, _______,
//         _______, PURPLE,  _______, BLUE,    _______, GOLD,    GOLDEN,  GOLDEN,  GOLDEN,  GOLDEN,  _______, _______, _______,
//         _______, _______, BLUE,    BLUE,    _______, _______, TURQ,    _______, _______, _______, TURQ,    _______,                            _______,
//         _______, _______, _______,                   _______,                            _______, PINK,    _______, _______,          _______, _______, _______
//     },
//     [_YL] = {
//         RED,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
//         CHART,   BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    _______, _______, _______, _______, PURPLE,  PURPLE,
//         _______, RED,     _______, BLUE,    _______, GOLD,    _______, _______, GREEN,   _______, MAGENT,  _______, GOLD,    GOLD,    _______, PURPLE,  PURPLE,
//         _______, BLUE,    _______, BLUE,    _______, MAGENT,  _______, GREEN,   GREEN,   GREEN,   MAGENT,  _______, _______,
//         _______, ORANGE,  ORANGE,  _______, _______, _______, _______, RED,     MAGENT,  MAGENT,  _______, _______,                            GREEN,
//         _______, _______, _______,                   _______,                   _______, PINK,    _______, _______,                   BLUE,    GREEN,   BLUE
//     },
// };

// #undef _______
// #define _______ KC_TRNS
// #endif

// // Runs just one time when the keyboard initializes.
// void matrix_init_user(void) {
//     // Enable or disable debugging
//     debug_enable=true;
//     debug_matrix=true;
//     debug_keyboard=true;
//     debug_mouse=true;

//     idle_second_counter = 0;                            // Counter for number of seconds keyboard has been idle.
//     key_event_counter = 0;                              // Counter to determine if keys are being held, neutral at 0.
//     rgb_time_out_seconds = RGB_DEFAULT_TIME_OUT;        // RGB timeout initialized to its default configure in keymap.h
//     rgb_time_out_enable = false;                        // Disable RGB timeout by default. Enable using toggle key.
//     rgb_time_out_user_value = false;                    // Has to have the same initial value as rgb_time_out_enable.
//     rgb_enabled_flag = true;                            // Initially, keyboard RGB is enabled. Change to false config.h initializes RGB disabled.
//     rgb_time_out_fast_mode_enabled = false;             // RGB timeout fast mode disabled initially.
//     rgb_time_out_saved_flag = rgb_matrix_get_flags();   // Save RGB matrix state for when keyboard comes back from ide.
// };

// void keyboard_post_init_user(void) {
//     rgb_matrix_enable();
// }

// Runs constantly in the background, in a loop.
// void matrix_scan_user(void) {
//     if(rgb_time_out_enable && rgb_enabled_flag) {
//         // If the key event counter is not zero then some key was pressed down but not released, thus reset the timeout counter.
//         if (key_event_counter) {
//             idle_second_counter = 0;
//         } else if (timer_elapsed(idle_timer) > MILLISECONDS_IN_SECOND) {
//             idle_second_counter++;
//             idle_timer = timer_read();
//         }

//         if (idle_second_counter >= rgb_time_out_seconds) {
//             rgb_time_out_saved_flag = rgb_matrix_get_flags();
//             rgb_matrix_set_flags(LED_FLAG_NONE);
//             rgb_matrix_disable_noeeprom();
//             rgb_enabled_flag = false;
//             idle_second_counter = 0;
//         }
//     }
// };

#define MODS_SHIFT  (get_mods() & MOD_MASK_SHIFT)
#define MODS_CTRL   (get_mods() & MOD_MASK_CTRL)
#define MODS_ALT    (get_mods() & MOD_MASK_ALT)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR): {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        // case FOO:
        //     if (record->event.pressed) {
        //         // Do something when pressed
        //     } else {
        //         // Do something else when release
        //     }
        //     return false; // Skip all further processing of this key
        // case KC_ENTER:
        //     // Play a tone when enter is pressed
        //     if (record->event.pressed) {
        //         PLAY_SONG(tone_qwerty);
        //     }
        //     return true; // Let QMK send the enter press/release eventsv
        default:
            return true; //Process all other keycodes normally
    }

    //   // If console is enabled, it will print the matrix position and status of each key pressed
    // #ifdef CONSOLE_ENABLE
    //     uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    // #endif
    // return true;
}

// void set_layer_color(int layer) {
//     if (layer == 0) { return; }
//     for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
//         HSV hsv = {
//             .h = pgm_read_byte(&ledmap[layer][i][0]),
//             .s = pgm_read_byte(&ledmap[layer][i][1]),
//             .v = pgm_read_byte(&ledmap[layer][i][2]),
//         };
//         if (hsv.h || hsv.s || hsv.v) {
//             RGB rgb = hsv_to_rgb(hsv);
//             float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
//             rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
//         } else if (layer != 1) {
//             // Only deactivate non-defined key LEDs at layers other than FN. Because at FN we have RGB adjustments and need to see them live.
//             // If the values are all false then it's a transparent key and deactivate LED at this layer
//             rgb_matrix_set_color(i, 0, 0, 0);
//         }
//     }
// }

// void rgb_matrix_indicators_user(void) {
//     if (disable_layer_color ||
//         rgb_matrix_get_flags() == LED_FLAG_NONE ||
//         rgb_matrix_get_flags() == LED_FLAG_UNDERGLOW) {
//             return;
//         }
//     set_layer_color(get_highest_layer(layer_state));
// }


static uint16_t last_animation_change;

void matrix_scan_user(void) {
    if (last_animation_change == 0)
        last_animation_change = timer_read();

    if (timer_elapsed(last_animation_change) >  5 * 1000) {
        last_animation_change = timer_read();
        rgb_matrix_step();
    }
}

