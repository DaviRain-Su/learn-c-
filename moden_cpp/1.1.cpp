//1.1.cpp
#include "foo.h"
#include <iostream>
#include <functional>

int main() {
    // set -std=c++2a
    [ out = std::ref (std::cout << "Result from C code: " << add(1, 2) ) ]  () {
        out.get() << ".\n";
    }();
    return 0;
}
