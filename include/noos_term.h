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

#ifndef NOOS_TERM_H
#define NOOS_TERM_H

#include <noos_types.h>

namespace NoOS {

class Term final {
public:
    static void init();
    static void scrollUp(u8 num);

    static void print(rune ch);
    static void print(string str);

    static void println();
    static void println(rune ch);
    static void println(string str);

    static bool isKeyboardBufferEmpty();
    static rune readRune();
    static void readLine(string buf, u16 len);

    static void setCursorPosition(u16 x, u16 y);

    static void setX(u16 x);
    static void setY(u16 y);

    static u16 getX();
    static u16 getY();
};

}

#endif