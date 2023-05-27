#include <raylib-cpp.hpp>
#include <iostream>

#include "Clicker.h"

Clicker::~Clicker() {
    delete textureJSON_;
    delete texture_;
    for (std::map<std::string, raylib::Texture*>::iterator it = textures_.begin(); it != textures_.end(); ++it) {
        delete it->second;
    }
}

void Clicker::Render(void) {
    texture_->Draw(pos_);
}