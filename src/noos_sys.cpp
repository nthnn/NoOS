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
#include <noos_sys.h>
#include <noos_types.h>

void NoOS::Sys::halt() {
    __asm__("cli");
    __asm__("hlt");
}

void NoOS::Sys::reboot() {
    u8 sig = 0x02;
    while((sig & 0x02) != 0)
        sig = NoOS::IO::in8(0x64);

    NoOS::IO::out8(0x64, 0xFE);
}

void NoOS::Sys::delay(u16 milliseconds) {
    u32 iterations = milliseconds * 100000;
    for(u32 i = 0; i < iterations; i++)
        __asm__("nop");
}