#include <raylib-cpp.hpp>
#include <iostream>

#include "Clicker.h"

void Clicker::Render(void) {
    texture_.Draw(pos_);
}