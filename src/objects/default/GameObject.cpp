#include "GameObject.h"
#include <iostream>
#include <raylib-cpp.hpp>

GameObject::GameObject() {
    pos_ = raylib::Vector2(0, 0);
};

GameObject::GameObject(float x, float y) {
    pos_ = raylib::Vector2(x, y);
};

GameObject::GameObject(raylib::Vector2 vector) {
    pos_ = vector;
};

GameObject::GameObject(std::string type) : type_{ type } {
    pos_ = raylib::Vector2(0, 0);
};

GameObject::GameObject(std::string type, float x, float y) : type_{ type } {
    pos_ = raylib::Vector2(x, y);
};

GameObject::GameObject(std::string type, raylib::Vector2 vector) : type_{ type } {
    pos_ = vector;
};

GameObject::~GameObject() {
};