#ifndef UTILS_H
#define UTILS_H

#include <raylib-cpp.hpp>

class Utils {
public:
    static raylib::Rectangle Texture2Rect(raylib::Texture texture, raylib::Vector2 pos) {
        return raylib::Rectangle(pos, texture.GetSize());
    }
    static raylib::Rectangle Image2Rect(raylib::Image image, raylib::Vector2 pos) {
        return raylib::Rectangle(pos, image.GetSize());
    }
};

#endif // !UTILS_H