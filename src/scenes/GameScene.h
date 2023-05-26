#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <iostream>
#include <raylib-cpp.hpp>

#include "../../lib/json.h"
#include "default/Scene.h"
#include "../objects/Clicker.h"
#include "../objects/default/GameObject.h"

class GameScene : public Scene {
public:
    GameScene(nlohmann::json* textureJSON, raylib::Window* window) : Scene() {
        AddSceneObject("player", new Clicker{ float(window->GetWidth() / 2.0 - 64.0), float(window->GetHeight() / 2.0 - 64.0), textureJSON });
    }
    void Loop() override {}
    ~GameScene() {}
};

#endif // !GAMESCENE_H