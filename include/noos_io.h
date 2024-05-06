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