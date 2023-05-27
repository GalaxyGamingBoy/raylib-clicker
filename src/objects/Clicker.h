#ifndef CLICKER_H
#define CLICKER_H

#include <raylib-cpp.hpp>
#include <map>

#include "../../lib/json.h"

#include "default/GameObject.h"
#include "../utils/Utils.h"

class Clicker : public GameObject {
    std::map<std::string, raylib::Texture*> textures_;
    raylib::Texture* texture_;
    raylib::Rectangle rect_;
    nlohmann::json* textureJSON_;
public:
    ~Clicker();
    void Render(void) override;
    void SetTexture(std::string texture) { texture_ = textures_[texture]; }
    raylib::Texture* GetTexture() { return texture_; }
    raylib::Rectangle* GetRect() { return &rect_; }
    void LoadTextures() {
        nlohmann::json tmp = *textureJSON_;
        textures_["default"] = new raylib::Texture(raylib::Image(tmp["clicker"]["file"]).Resize(tmp["clicker"]["width"], tmp["clicker"]["width"]));
        textures_["clicked"] = new raylib::Texture(raylib::Image(tmp["clickerClicked"]["file"]).Resize(tmp["clickerClicked"]["width"], tmp["clickerClicked"]["width"]));

        texture_ = textures_["default"];
        rect_ = raylib::Rectangle(GetPosition(), raylib::Vector2(texture_->GetWidth(), texture_->GetHeight()));
    };
    Clicker(float x, float y, nlohmann::json* textureJSON) : GameObject{ "Clicker", x, y } {
        textureJSON_ = textureJSON;
        LoadTextures();
    };
};

#endif // !CLICKER_H