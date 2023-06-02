#include <raylib-cpp.hpp>
#include <iostream>

#include "Hand.h"

Hand::~Hand() {
    delete textureJSON_;
    delete texture_;
    for (std::map<std::string, raylib::Texture*>::iterator it = textures_.begin(); it != textures_.end(); ++it) {
        delete it->second;
    }
}

void Hand::Render(void) {
    texture_->Draw(pos_);
}