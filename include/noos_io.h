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

#ifndef NOOS_IO_H
#define NOOS_IO_H

#include <noos_types.h>

namespace NoOS {

class IO final {
public:
    static void out8(u32 addr, u8 value);
    static void out16(u32 addr, u16 value);
    static void out32(u32 addr, u32 value);

    static u8 in8(u32 addr);
    static u16 in16(u32 addr);
    static u32 in32(u32 addr);
};

}

#endif