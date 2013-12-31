/* 
 * File:   Scene.hpp
 * Author: gregorio
 *
 * Created on 12 de Dezembro de 2013, 21:18
 * 
 * Abstract class scene, draws, update and treats
 * inputs of Scene.
 */

#ifndef SCENE_HPP
#define	SCENE_HPP

#include <SDL/SDL_events.h>

class Scene {
public:
    Scene();
    virtual ~Scene();
    virtual void init() = 0;
    virtual void input(SDL_Event&) = 0;
    virtual void update(long) = 0;
    virtual void render() = 0;
private:
};

#endif	/* SCENE_HPP */

