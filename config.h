#pragma once

// Lets you roll mod-tap keys
#define IGNORE_MOD_TAP_INTERRUPT
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
//define TAPPING_FORCE_HOLD
#define PERMISSIVE_HOLD
#define TAPPING_TERM 280
#define COMBO_TERM 15
// This is for LTO, but I think it's all deprecated now?
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// For MX lock key, I don't have them, so no need for them
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define COMBO_VARIABLE_LEN
#define NO_MUSIC_MODE
#define EXTRA_SHORT_COMBOS
#define ONESHOT_TAP_TOGGLE 5  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
/* #define HOMEROW */
