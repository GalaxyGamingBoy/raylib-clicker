#include <raylib-cpp.hpp>

#include "Score.h"

void Score::Render(void) {
    raylib::Text::Draw("Points: " + std::to_string(GetScore()), GetPosition(), 32, raylib::Color::Red());
}