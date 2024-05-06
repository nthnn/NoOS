#include <noos_io.h>
#include <noos_term.h>

#define KBD_STATUS_REGISTER 0x64
#define KBD_DATA_REGISTER   0x60

volatile rune* vga_buffer = (volatile rune*) 0xB8000;
static u16 x = 0, y = 26;

static rune scanCodes[] = {
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

void NoOS::Term::init() {
    for(u16 i = 0; i < 4000; i++)
        vga_buffer[i] = 0;

    NoOS::Term::setCursorPosition(x, y);
    NoOS::Term::print((rune) 0x00);

    x--;
}

void NoOS::Term::scrollUp(u8 num) {
    u8* tmp;
    for(
        vga_buffer = (volatile rune*) 0xB8000;
        vga_buffer < (volatile rune*) (0xB8000 + 4000);
        vga_buffer += 2
    ) {
        tmp = (u8*)(vga_buffer + num * 160);

        if(tmp < (u8*) (0xB8000 + 4000)) {
            *vga_buffer = *tmp;
            *(vga_buffer + 1) = *(tmp + 1);
        }
        else {
            *vga_buffer = 0;
            *(vga_buffer + 1) = 0x07;
        }
    }

    y -= num;
    NoOS::Term::setCursorPosition(x, y);
}

void NoOS::Term::print(rune ch) {
    vga_buffer = (volatile rune*) (0xB8000 + 2 * x + 160 * y);
    switch(ch) {
        case 10:
            x = 0;
            y++;
            break;

        case 8:
            if(x) {
                *(vga_buffer + 1) = 0x00;
                x--;
            }
            break;

        case 9:
            x = x + 8 - (x % 8);
            break;

        case 13:
            x = 0;
            break;

        default:
            *vga_buffer = ch;
            *(vga_buffer + 1) = 0x07;

            x++;
            if(x > 79) {
                x = 0;
                y++;
            }
    }

    if(y > 24)
        NoOS::Term::scrollUp(y - 24);
    NoOS::Term::setCursorPosition(x, y);
}

void NoOS::Term::print(string str) {
    while(*str)
        NoOS::Term::print(*str++);
    NoOS::Term::setCursorPosition(x, y);
}

void NoOS::Term::println() {
    NoOS::Term::print(F("\r\n"));
}

void NoOS::Term::println(rune ch) {
    NoOS::Term::print(ch);
    NoOS::Term::println();
}

void NoOS::Term::println(string str) {
    NoOS::Term::print(str);
    NoOS::Term::println();
}

bool NoOS::Term::isKeyboardBufferEmpty() {
    return (NoOS::IO::in8(KBD_STATUS_REGISTER) & 0x01) == 0;
}

rune NoOS::Term::readRune() {
    rune ch = 0;
    bool isShifted = false;

    read:
    while(NoOS::Term::isKeyboardBufferEmpty());
    ch = NoOS::IO::in8(KBD_DATA_REGISTER);

    if(ch == 0x2A || ch == 0x36) {
        while(NoOS::Term::isKeyboardBufferEmpty());
        ch = NoOS::IO::in8(KBD_DATA_REGISTER);

        isShifted = true;
    }

    while(!NoOS::Term::isKeyboardBufferEmpty())
        (void) NoOS::IO::in8(KBD_DATA_REGISTER);

    if((u32) ch < sizeof(scanCodes))
        ch = scanCodes[(u32) ch] & 0xff;
    else goto read;

    if(isShifted && ch >= 'a' && ch <= 'z')
        ch = ch - ('a' - 'A');
    return ch;
}

void NoOS::Term::readLine(string buf, u16 len) {
    u16 idx = 0,
        size = 0,
        startX = x;
    rune key;

    while(1) {
        if(size == len)
            break;

        key = NoOS::Term::readRune();
        switch(key) {
            case '\b':
                if(idx > 0) {
                    idx--, size--;
                    buf[idx] = '\0';

                    NoOS::Term::print(F("\b \b"));
                    if(idx == 0)
                        NoOS::Term::setCursorPosition(startX, y);
                }
                break;

            case '\n':
                buf[idx] = '\0';
                NoOS::Term::println();

                return;

            default:
                if(idx < len - 1 && key >= 32) {
                    buf[idx++] = key;
                    size++;

                    NoOS::Term::print(key);
                }
                break;
        }
    }
}

void NoOS::Term::setCursorPosition(u16 newX, u16 newY) {
    u16 pos = newY * 80 + newX;

    NoOS::IO::out8(0x3D4, 0x0E);
    NoOS::IO::out8(0x3D5, (pos >> 8) & 0xFF);

    NoOS::IO::out8(0x3D4, 0x0F);
    NoOS::IO::out8(0x3D5, pos & 0xFF);

    x = newX;
    y = newY;
}

void NoOS::Term::setX(u16 newX) {
    x = newX;
}

void NoOS::Term::setY(u16 newY) {
    y = newY;
}

u16 NoOS::Term::getX() {
    return x;
}

u16 NoOS::Term::getY() {
    return y;
}