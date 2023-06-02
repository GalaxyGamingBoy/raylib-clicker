#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <iostream>
#include <raylib-cpp.hpp>

#include "../../lib/json.h"
#include "default/Scene.h"
#include "../objects/default/GameObject.h"
#include "../utils/Utils.h"

#include "../objects/Clicker.h"
#include "../objects/Score.h"
#include "../objects/Hand.h"

class GameScene : public Scene {
public:
    GameScene(nlohmann::json* textureJSON, raylib::Window* window) : Scene() {
        nlohmann::json tmp = *textureJSON;
        AddSceneObject("clicker", new Clicker{ float(window->GetWidth() / 2.0 - (double)tmp["clicker"]["width"] / 2), float(window->GetHeight() / 2.0 - (double)tmp["clicker"]["height"] / 2), textureJSON });
        AddSceneObject("score", new Score{ 0, float(window->GetWidth() / 2.0 - (double)tmp["clicker"]["width"] / 2 - 16), float(window->GetHeight() / 2.0 + (double)tmp["clicker"]["height"] / 2) });
        AddSceneObject("hand", new Hand{ 256, float(window->GetWidth() / 2.0 - (double)tmp["hand"]["width"] / 2), float(window->GetHeight() / 2.0 - (double)tmp["hand"]["height"] - 64.0), textureJSON });
    }
    void Loop() override;
    ~GameScene() {}
};

#endif // !GAMESCENE_H