/* 
 * File:   GamePanel.hpp
 * Author: gregorio
 *
 * Created on 11 de Dezembro de 2013, 09:19
 * 
 * The GamePanel is a manager class all game.
 * Handles the scenes like them all. 
 */

#ifndef GAMEPANEL_HPP
#define	GAMEPANEL_HPP

#include <iostream>
#include <GL/gl.h> //always after include glew, never before.
#include <GL/glu.h>
#include "SDL/SDL.h"
#include "Scene.hpp"

class GamePanel {
public:
    GamePanel();
    virtual ~GamePanel();
    
    //Init all functions of class. 
    void init();
    //Init all functions SDL.
    void initSDL();
    //Init all functions SDL.
    void initOpenGL();
    
    /*Main loop of game, like draws, update and treats 
    inputs of scenes.*/
    void mainLoop();
    
    int width;  //Width Screen.
    int height; //Height Screen.
     
    bool run;   //Variable that control game is running.
private:
    SDL_Surface* screen;
    int bbp;
    int flags;
    
    Scene* currentScene;
    
    int lastTime;
    int currentTime;
    int difTime;
    int countTimer;
    
    int fps;
    int sfps;
};

#endif	/* GAMEPANEL_HPP */

