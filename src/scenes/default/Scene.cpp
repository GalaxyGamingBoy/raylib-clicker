#include "Scene.h"

#include <iostream>
#include <map>

#include "../../objects/default/GameObject.h"

Scene::Scene() {
}

Scene::~Scene() {
    for (std::map<std::string, GameObject*>::iterator it = sceneObjects_.begin(); it != sceneObjects_.end(); ++it) {
        delete it->second;
    }
}

void Scene::Render(void) {
    for (std::map<std::string, GameObject*>::iterator it = sceneObjects_.begin(); it != sceneObjects_.end(); ++it) {
        it->second->Render();
    }
}