/* 
 * File:   Character.hpp
 * Author: Gilvanei Gregório
 *
 * Created on 31 de Dezembro de 2013, 11:43
 */

#ifndef CHARACTER_HPP
#define	CHARACTER_HPP

#include "SDL/SDL_opengl.h"

#include "Sprite.hpp"
#include "Texture.hpp"
#include "Sound.hpp"
#include "GL.hpp"
#include "AL.hpp"

#include <iostream>

class Character : public Sprite {
public:
    /** Default constructor.*/
    Character();
    
    /** Default destructor.*/
    virtual ~Character();
    
    /* Init atributs of class.
    * 
    * @param float x position
    *    float y position
    *    int number of animations
    *    int number of frames
    *    Texture* texture
    */
    void init(float x, float y, int numberAnimations, int numberFrames, Texture* texture, GL* gl, AL* al);
    
    /** 
    * Update the states of character.
    * 
    * @param long difTime, time difference between the bonds of the game
    */
    void update(long difTime);
    
    /** Render the character in your position.*/
    void render();
    
    /** Texture* texture.*/
    Texture* texture;
    
    /** Sound* sound.*/
    Sound* sound;
private:
    /** GL* gl;.*/
    GL* gl;
    
    /** AL* al.*/
    AL* al;
    
    /** Current frame of sprite.*/
    int currentFrame;
    
    /** 
     * Number frame of sprite.*/
    int numberFrames;
    
    /** Frame timer.*/
    int frameTimer;
    
    /** Time between frames*/
    int timeBetweenFrames;

    /** Current animation of sprite.*/
    int currentAnimation;
    
    /** Number animation of sprite.*/
    int numberAnimations;
    
    /** proportion of this sprite, relative of frames.*/
    float frameProp;
    
    /** proportion of this sprite, relative of Animations.*/
    float animationProp;
};

#endif	/* CHARACTER_HPP */

