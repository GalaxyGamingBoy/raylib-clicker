#ifndef CLICKER_H
#define CLICKER_H

#include <raylib-cpp.hpp>
#include "../../lib/json.h"

#include "default/GameObject.h"

class Clicker : public GameObject {
    raylib::Texture texture_;
public:
    void Render(void) override;
    void LoadTexture(std::string path) {
        texture_ = raylib::Image(path);
    }
    Clicker(float x, float y, nlohmann::json* textureJSON) : GameObject{ "Clicker", x, y } {
        nlohmann::json tmp = *textureJSON;
        LoadTexture(tmp["clicker"]);
    };
};

#endif // !CLICKER_H