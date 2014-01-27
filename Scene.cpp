#include "Scene.hpp"

Scene::Scene() {

}

Scene::~Scene() {
    
}

Scene* Scene::getScene(){
    return currentScene;
}
    
void Scene::setScene(Scene* _scene){
    if(currentScene != NULL)
        currentScene->~Scene();
    
    currentScene = _scene;
    currentScene->init();
}