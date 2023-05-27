#ifndef CLICKER_H
#define CLICKER_H

#include <raylib-cpp.hpp>
#include "../../lib/json.h"

#include "default/GameObject.h"
#include "../utils/Utils.h"

class Clicker : public GameObject {
    raylib::Texture texture_;
    raylib::Rectangle rect_;
    nlohmann::json* textureJSON_;
public:
    ~Clicker();
    void Render(void) override;
    raylib::Texture* GetTexture() { return &texture_; }
    raylib::Rectangle* GetRect() { return &rect_; }
    void LoadTexture(std::string path) {
        nlohmann::json tmp = *textureJSON_;
        texture_ = raylib::Image(path).Resize(tmp["clicker"]["width"], tmp["clicker"]["width"]);
        rect_ = Utils::Image2Rect(texture_, GetPosition());
    };
    Clicker(float x, float y, nlohmann::json* textureJSON) : GameObject{ "Clicker", x, y } {
        textureJSON_ = textureJSON;
        nlohmann::json tmp = *textureJSON;
        LoadTexture(tmp["clicker"]["file"]);
    };
};

#endif // !CLICKER_H