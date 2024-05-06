#ifndef NOOS_SYS_H
#define NOOS_SYS_H

#include <noos_types.h>

namespace NoOS {

class Sys final {
public:
    static void halt();
    static void reboot();

    static void delay(u16 milliseconds);
};

}

#endif