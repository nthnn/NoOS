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

#include <noos_io.h>

void NoOS::IO::out8(u32 addr, u8 value) {
    __asm__(
        "outb %%al, %%dx" ::
        "d" (addr),
        "a" (value)
    );
}

void NoOS::IO::out16(u32 addr, u16 value) {
    __asm__(
        "outw %%ax, %%dx" ::
        "d" (addr),
        "a" (value)
    );
}

void NoOS::IO::out32(u32 addr, u32 value) {
    __asm__(
        "outl %%eax, %%dx" ::
        "d" (addr),
        "a" (value)
    );
}

u8 NoOS::IO::in8(u32 addr) {
    u8 value;
    __asm__(
        "inb %%dx, %%al" :
        "=a" (value) :
        "d" (addr)
    );

    return value;
}

u16 NoOS::IO::in16(u32 addr) {
    u16 value;
    __asm__(
        "inw %%dx, %%ax" :
        "=a" (value) :
        "d" (addr)
    );

    return value;
}

u32 NoOS::IO::in32(u32 addr) {
    u32 value;
    __asm__(
        "inl %%dx, %%eax" :
        "=a" (value) :
        "d" (addr)
    );

    return value;
}
