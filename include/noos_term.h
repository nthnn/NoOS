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