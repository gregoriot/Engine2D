/* 
 * File:   MenuScene.hpp
 * Author: Gilvanei Gregório
 *
 * Created on 12 de Dezembro de 2013, 21:23
 * 
 * Menu Scene is a scene of main menu game.
 */

#ifndef MENUSCENE_HPP
#define	MENUSCENE_HPP

#include <SDL/SDL_events.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "GamePanel.hpp"
#include "Scene.hpp"
#include "Vector2f.hpp"
#include "Font_ttf.hpp"
#include "Texture.hpp"
#include "Texture.hpp"
#include "Collision.hpp"
#include "TextureManager.hpp"
#include "GamePlay.hpp"

#include <string>

class MenuScene : public Scene {
public:
    /** 
    * Constructor of class.
    * 
    * @param GamePanel* 
    *    GL* gl
    */
    MenuScene(GamePanel* _parent, GL* _gl, AL* _al);
    
    /** Default destructor.*/
    virtual ~MenuScene();
    
    /** Init atributs of scenes.*/
    void init();
    
    /** 
    * Abstract method. Manager input of game.
    * 
    * @param SDL_Event events, object contain information of inputs
    */
    void input(SDL_Event& event);
    
    /** 
    * Update the states of game.
    * 
    * @param long difTime, time difference between the bonds of the game
    */
    void update(long difTime);
    
    /** Render the game in screen.*/
    void render();
private:
    /** GamePanel* parent, pointer to main game panel.*/
    GamePanel* parent;
    
    /** Camera* camera.*/
    Camera* camera;
    
    /** Font_ttf font.*/
    Font_ttf font;
    
    /** Texture* mainMenuTex.*/
    Texture* mainMenuTex;
};
#endif	/* MENUSCENE_HPP */

