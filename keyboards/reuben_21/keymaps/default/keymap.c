#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │Esc│Tab│MO1│Bsp│
     * ├───┼───┼───┼───┤
     * │Num│ / │ * │ - │
     * ├───┼───┼───┼───┤
     * │ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┤ + │
     * │ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │   │
     * ├───┴───┼───┤Ent│
     * │ 0     │ . │   │
     * └───────┴───┴───┘
     */
    [0] = LAYOUT_numpad_6x4(
        KC_CALC,KC_TAB,  MO(1),   KC_BSPC,
        KC_NUM, KC_SLSH, KC_PAST, KC_PMNS,
        KC_7,   KC_8,   KC_9,
        KC_4,   KC_5,   KC_6,   KC_PPLS,
        KC_1,   KC_2,   KC_3, 
        KC_0,          KC_DOT,  KC_ENT
    ),
// TO MAKE KEYBOARD
//   USE MSYS2 MINGW64
//    cd /E/programs/keyboards/qmk_firmware
//    make reuben_21:default

//   USE QMK TOOLBOX

    /*
     * ┌───┐───┬───┬───┐
     * │Rst│RST│MO1│Bsp│
     * └───┘───┼───┼───┤
     * │Num│ / │ * │ - │
     * ┌───┬───┬───┐───┤
     * │Hom│ ↑ │PgU│   │
     * ├───┼───┼───┤ + │
     * │ ← │   │ → │   │
     * ├───┼───┼───┤───┤
     * │End│ ↓ │PgD│   │
     * ├───┴───┼───┤Ent│
     * │Insert │Del│   │
     * └───────┴───┘───┘
     */
    [1] = LAYOUT_numpad_6x4(
        QK_BOOT, QK_BOOT, MO(1),   _______,
        _______, _______, _______, _______,
        KC_HOME, KC_UP,   KC_PGUP,
        KC_LEFT, KC_DOWN, KC_RGHT, _______,
        KC_END,  XXXXXXX, KC_PGDN, 
        KC_INS,           KC_DEL,  KC_ENT
    )
};
