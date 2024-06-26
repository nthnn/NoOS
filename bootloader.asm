; This file is part of the NoOS (https://github.com/nthnn/NoOS).
; Copyright (c) 2024 Nathanne Isip.
;
; This program is free software: you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation, version 3.
;
; This program is distributed in the hope that it will be useful, but
; WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
; General Public License for more details.
;
; You should have received a copy of the GNU General Public License
; along with this program. If not, see <http://www.gnu.org/licenses/>.

bits    32

section .text
    align   4
    dd      0x1BADB002
    dd      0x00
    dd      - (0x1BADB002+0x00)

global  start
extern  main

start:
        cli

        xor eax, eax
        xor ebx, ebx
        xor ecx, ecx
        xor edx, edx
        xor esi, esi
        xor edi, edi

        call main
        hlt