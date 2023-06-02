#include <iostream>
#include <raylib-cpp.hpp>

#include "GameScene.h"

#include "../objects/Clicker.h"
#include "../objects/Score.h"
#include "../objects/Hand.h"

void GameScene::Loop() {
    // Get Objects
    Clicker* clicker = dynamic_cast<Clicker*>(GetSceneObject("clicker"));
    Score* score = dynamic_cast<Score*>(GetSceneObject("score"));
    Hand* hand = dynamic_cast<Hand*>(GetSceneObject("hand"));

    // Functions
    std::function<void(void)> click = [score, clicker]() {
        score->IncrementScore();
        clicker->SetTexture("clicked");
    };

    // Tick
    hand->Tick();

    // Reset Textures
    clicker->SetTexture("default");

    if (hand->GetTick() == 0) {
        hand->SetTexture("extended");
        click();
    }
    else if (hand->GetTick() == hand->GetMaxTick() / 2) {
        hand->SetTexture("default");
    }

    // Check if button clicked
    if (clicker->GetRect()->CheckCollision(raylib::Mouse::GetPosition()) && raylib::Mouse::IsButtonPressed(MOUSE_LEFT_BUTTON)) {
        click();
    }
};