// C++ LIBRARIES
#include <fstream>
#include <iostream>

// OTHER LIBRARIES
#include <raylib-cpp.hpp>
#include <json.h>

// CUSTOM
#include "objects/Clicker.h"
#include "scenes/default/Scene.h"
#include "scenes/GameScene.h"

#define LOG(x) std::cout << x << std::endl;

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

nlohmann::json settingsJSON = nlohmann::json::parse(std::ifstream("res/settings.json"));
nlohmann::json windowJSON = nlohmann::json::parse(std::ifstream("res/window.json"));
nlohmann::json texturesJSON = nlohmann::json::parse(std::ifstream("res/textures.json"));
nlohmann::json soundsJSON = nlohmann::json::parse(std::ifstream("res/sounds.json"));
nlohmann::json stringsJSON = nlohmann::json::parse(std::ifstream("res/strings.json"));

Scene* currentScene;
raylib::Window* pWindow;

void updateDrawFrame(void);
void update(void);
void draw(void);

void init(void);
void deinit(void);

int main()
{
    raylib::Window window(windowJSON["width"], windowJSON["height"], windowJSON["title"]);
    pWindow = &window;
    init();

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);
    while (!window.ShouldClose())
    {
        updateDrawFrame();
    }
#endif

    deinit();
    return 0;
}

// Update and Draw Frame
void updateDrawFrame(void)
{
    update();
    draw();
}

// Main Loop Update Function
void update() {
    currentScene->Loop();
}


// Main Loop Draw Function
void draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    currentScene->Render();
    EndDrawing();
}

// Init Function
void init() {
    currentScene = new GameScene{ &texturesJSON, pWindow };
}

// DeInit Function
void deinit() {
}