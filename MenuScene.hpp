/* 
 * File:   MenuScene.hpp
 * Author: gregorio
 *
 * Created on 12 de Dezembro de 2013, 21:23
 * 
 * Menu Scene is a scene of main menu game.
 */

#ifndef MENUSCENE_HPP
#define	MENUSCENE_HPP

#include "GamePanel.hpp"
#include "Scene.hpp"
#include "Vector2f.hpp"
#include "Character.hpp"
#include <SDL/SDL_events.h>
#include <SDL/SDL_image.h>
#include <string>

class MenuScene : public Scene {
public:
    MenuScene(GamePanel&);
    virtual ~MenuScene();
    void init();
    void input(SDL_Event&);
    void update(long);
    void render();
private:
    GamePanel* parent;
    Vector2f camera;
    
    Character* character;
};

#endif	/* MENUSCENE_HPP */

