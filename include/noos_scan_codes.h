/*
 * This file is part of the NoOS (https://github.com/nthnn/NoOS).
 * Copyright (c) 2024 Nathanne Isip.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NOOS_SCAN_CODES_H
#define NOOS_SCAN_CODES_H

#include <noos_types.h>

static rune LOWER_CASE_SCAN_CODES[] = {
    0,  // Null
    0,  // Escape

    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b', '\t',
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0, // Control
    
    'a', 's','d', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
    0,  // Left Shift

    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',
    0,  // Right Shift

    '*', 0,  // Alt
    ' ', 0,  // Caps Lock

    // F1- F10
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  // Num Lock
    0,  // Scroll Lock

    // Keypad 7 - 9
    0, 0, 0,
    '-',// Keypad -

    // Keypad 4 - 6
    0, 0, 0,
    '+',// Keypad +

    // Keypad 1 - 0
    0, 0, 0, 0,
    '.',// Keypad .

    0, 0,  // Unused
    0, 0,  // F11 - F12
};

static rune UPPER_CASE_SCAN_CODES[] = {
    0,  // Null
    0,  // Escape

    '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '\b', '\t',
    'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n',
    0, // Control

    'A', 'S','D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '"', '~',
    0,  // Left Shift

    '|', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?',
    0,  // Right Shift

    '*', 0,  // Alt
    ' ', 0,  // Caps Lock

    // F1- F10
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  // Num Lock
    0,  // Scroll Lock

    // Keypad 7 - 9
    0, 0, 0,
    '-',// Keypad -

    // Keypad 4 - 6
    0, 0, 0,
    '+',// Keypad +

    // Keypad 1 - 0
    0, 0, 0, 0,
    '.',// Keypad .

    0, 0,  // Unused
    0, 0,  // F11 - F12
};

#endif