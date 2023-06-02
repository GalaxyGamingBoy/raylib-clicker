#ifndef HAND_H
#define HAND_H

#include <raylib-cpp.hpp>
#include <map>

#include "../../lib/json.h"

#include "default/GameObject.h"
#include "../utils/Utils.h"

class Hand : public GameObject {
    std::map<std::string, raylib::Texture*> textures_;
    raylib::Texture* texture_;
    raylib::Rectangle rect_;
    nlohmann::json* textureJSON_;
    int tick_;
    int tickMax_;
public:
    ~Hand();
    void Render(void) override;
    void SetTexture(std::string texture) { texture_ = textures_[texture]; }
    raylib::Texture* GetTexture() { return texture_; }
    raylib::Rectangle* GetRect() { return &rect_; }
    void LoadTextures() {
        nlohmann::json tmp = *textureJSON_;
        textures_["default"] = new raylib::Texture(raylib::Image(tmp["hand"]["file"]).Resize(tmp["hand"]["width"], tmp["hand"]["height"]));
        textures_["extended"] = new raylib::Texture(raylib::Image(tmp["handExtended"]["file"]).Resize(tmp["handExtended"]["width"], tmp["handExtended"]["height"]));

        texture_ = textures_["default"];
        rect_ = raylib::Rectangle(GetPosition(), raylib::Vector2(texture_->GetWidth(), texture_->GetHeight()));
    };
    int GetTick() { return tick_; }
    int GetMaxTick() { return tickMax_; }
    void SetTickMax(int maxTick) { tickMax_ = maxTick; }
    void Tick() { tick_ = (tick_ == tickMax_) ? 0 : tick_ + 1; }
    Hand(int maxTick, float x, float y, nlohmann::json* textureJSON) : GameObject{ "Hand", x, y }, tick_(0), tickMax_(maxTick) {
        textureJSON_ = textureJSON;
        LoadTextures();
    };
};

#endif // !HAND_H