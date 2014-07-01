/* 
 * File:   GamePlay.hpp
 * Author: Gilvanei Gregório
 *
 * Created on 10 de Janeiro de 2014, 17:22
 *
 * Menu Scene is a scene of main menu game.
 */

#ifndef GAMEPLAY_HPP
#define	GAMEPLAY_HPP

#include <GL/glew.h>
#include <SDL/SDL_events.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string>

#include "Camera.hpp"
#include "Character.hpp"
#include "Font_ttf.hpp"
#include "GamePanel.hpp"
#include "Scene.hpp"
#include "Sprite.hpp"
#include "TextureLoad.hpp"
#include "Tiled.hpp"
#include "TileMap.hpp"
#include "VertexPos2f.h"

class GamePlay : public Scene{
public:
    /** 
    * Constructor of class.
    * 
    * @param GamePanel* 
    *    GL* gl
    */
    GamePlay(GamePanel* _parent, GL* _gl, AL* _al);
    
    /** Default destructor.*/
    virtual ~GamePlay();
    
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
    
    /** Character* character.*/
    Character* character;
    
    /** TileMap* tileMap.*/
    TileMap* tileMap;
    
    Sprite* sprite;
    
    VertexPos2f position;
};

#endif	/* GAMEPLAY_HPP */

