#include <noos_sys.h>
#include <noos_term.h>

using namespace NoOS;

void setup() {
    Term::init();
    Term::setCursorPosition(0, 0);

    Term::println(F("Hello, world!"));
}

void loop() {
    Sys::halt();
}