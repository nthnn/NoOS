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