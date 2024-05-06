#include <noos_sys.h>
#include <noos_term.h>

using namespace NoOS;

void setup() {
    Term::init();
}

void loop() {
    Term::print(F("Enter your name: "));

    rune buf[30];
    Term::readLine(buf, 30);

    Term::print(F("Hello, "));
    Term::println(buf);
}