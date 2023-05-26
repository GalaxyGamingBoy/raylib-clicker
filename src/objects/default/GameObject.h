#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <raylib-cpp.hpp>

class GameObject {
protected:
    raylib::Vector2 pos_;
    std::string type_ = "GameObject";
public:
    raylib::Vector2 GetPosition() { return pos_; }
    GameObject(void);
    GameObject(std::string type);
    GameObject(float x, float y);
    GameObject(std::string type, float x, float y);
    GameObject(raylib::Vector2 vector);
    GameObject(std::string type, raylib::Vector2 vector);
    virtual void Render(void) {};
    virtual ~GameObject();
    virtual std::string GetType() { return type_; };
};

#endif // !GAMEOBJECT_H