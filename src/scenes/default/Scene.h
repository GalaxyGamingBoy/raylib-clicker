#ifndef SCENE_H
#define SCENE_H

#include <map>
#include <vector>

#include "../../objects/default/GameObject.h"

class Scene {
protected:
    std::map<std::string, GameObject*> sceneObjects_;
public:
    void AddSceneObject(std::string key, GameObject* object) { sceneObjects_[key] = object; }
    GameObject* GetSceneObject(std::string key) { return sceneObjects_[key]; }
    void SetSceneObject(std::string key, GameObject* object) { sceneObjects_[key] = object; }
    std::map<std::string, GameObject*>* GetSceneObjects(void) { return &sceneObjects_; }
    void SetSceneObjects(std::map<std::string, GameObject*> objects) { sceneObjects_ = objects; }
    virtual void Loop(void) {};
    void Render(void);
    Scene();
    virtual ~Scene();
};

#endif // !SCENE_H