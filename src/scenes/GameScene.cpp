#include <iostream>
#include <raylib-cpp.hpp>

#include "GameScene.h"

#include "../objects/Clicker.h"
#include "../objects/Score.h"

void GameScene::Loop() {
    // Get Objects
    Clicker* clicker = dynamic_cast<Clicker*>(GetSceneObject("clicker"));
    Score* score = dynamic_cast<Score*>(GetSceneObject("score"));

    // Reset Textures
    clicker->SetTexture("default");

    // Check if button clicked
    if (clicker->GetRect()->CheckCollision(raylib::Mouse::GetPosition()) && raylib::Mouse::IsButtonPressed(MOUSE_LEFT_BUTTON)) {
        clicker->SetTexture("clicked");
        score->IncrementScore();
    }
};