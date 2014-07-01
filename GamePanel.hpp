/* 
 * File:   GamePanel.hpp
 * Author: Gilvanei Gregório
 *
 * Created on 11 de Dezembro de 2013, 09:19
 * 
 * The GamePanel is a manager class all game.
 * Handles the scenes like them all. 
 */

#ifndef GAMEPANEL_HPP
#define	GAMEPANEL_HPP

#include <GL/glew.h>
#include <SDL/SDL.h>
#include "AL.hpp"
#include "GL.hpp"
#include "Scene.hpp"
#include "Sound.hpp"

class GamePanel {
public:
    /** Default constructor.*/
    GamePanel();
    
    /** Default destructor.*/
    virtual ~GamePanel();
    
    /**Init all functions of class.*/ 
    void init(int _width, int _height, int _bpp);
    
    /**Init all functions SDL.*/
    void initSDL();
    
    /**
    * Main loop of game, like draws, update
    * and treats inputs of scenes.
    */
    void mainLoop();
    
    /**
    * Default render for all scenes.
    */
    void renderScene();
    
    /**
    * Default update for all scenes.
    */
    void updateScene(SDL_Event& events);

    /**Width Screen.*/
    int width;
    
    /**Height Screen.*/
    int height;
     
    /**Variable that control game is running.*/
    bool run;
    
    /**Frames per seconds.*/
    int fps;
    
    /**Current scene running.*/
    Scene* currentScene;
    
    /**GL object.*/
    GL* gl;
    
    /**AL object.*/
    AL* al;
private:
    /**Sceen object.*/
    SDL_Surface* screen;

    /**Bailey Borwein Plouffe.*/
    int bbp;
    
    /**Flags of screen.*/
    int flags;
    
    /**Last time of system.*/
    int lastTime;
    
    /**Current time of system.*/
    int currentTime;
    
    /**Dif time of system.*/
    int difTime;
    
    /**Count timer of system.*/
    int countTimer;
    
    /**Count of frames per seconds.*/
    int sfps;
};

#endif	/* GAMEPANEL_HPP */

