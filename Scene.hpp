/* 
 * File:   Scene.hpp
 * Author: Gilvanei Gregório
 *
 * Created on 12 de Dezembro de 2013, 21:18
 * 
 * Abstract class scene, draws, update and manager
 * inputs of Scene.
 */

#ifndef SCENE_HPP
#define	SCENE_HPP

#include <SDL/SDL_events.h>
#include "AL.hpp"
#include "GL.hpp"

class Scene {
public:
    /** Default constructor.*/
    Scene();
    
    /** Default destructor.*/
    virtual ~Scene();
    
    /** Abstract method. Init atributs of scenes.*/
    virtual void init() = 0;
    
     /** 
     * Get current scene of game.
     * 
     * @return Scene* scene, current scene of game.
     */
     Scene* getScene();
    
    /** 
    * Change current scene of game.
    * 
    * @param Scene* scene, new scene to use.
    */
    void setScene(Scene* scene);
    
    /** 
    * Abstract method. Manager input of game.
    * @param SDL_Event events, object contain information of inputs
    */
    virtual void input(SDL_Event& events) = 0;
    
    /** 
    * Abstract method. Update the states of game.
    * @param long difTime, time difference between the bonds of the game
    */
    virtual void update(long difTime) = 0;
    
    /** Abstract method. Render the game in screen.*/
    virtual void render() = 0;
    
protected:
    /** Screen size in pixels.*/
    int width;
    int height;

    /** Object responsible for OpenGL.*/
    GL* gl;
    
    /** Object responsible for OpenAL.*/
    AL* al;
    
private:
};

#endif	/* SCENE_HPP */

