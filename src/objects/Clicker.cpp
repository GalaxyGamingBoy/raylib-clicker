#include <raylib-cpp.hpp>
#include <iostream>

#include "Clicker.h"

Clicker::~Clicker() {
    delete textureJSON_;
}

void Clicker::Render(void) {
    texture_.Draw(pos_);
}