/* 
 * File:   Character.hpp
 * Author: Gilvanei Gregório
 *
 * Created on 31 de Dezembro de 2013, 11:43
 */

#ifndef CHARACTER_HPP
#define	CHARACTER_HPP

#include <GL/glew.h>
#include "AL.hpp"
#include "GL.hpp"
#include "Sound.hpp"
#include "Sprite.hpp"
#include "Texture.hpp"
#include "SoundLoad.hpp"

class Character : public Sprite {
public:
    /** Sound* sound.*/
    Sound* sound;
    
    /** Current frame of sprite.*/
    int currentFrame;
    
    /** Number frame of sprite.*/
    int numberFrames;
    
    /** Current animation of sprite.*/
    int currentAnimation;
    
    /** Number animation of sprite.*/
    int numberAnimations;
    
    /** Default constructor.*/
    Character();
    
    /** Default destructor.*/
    virtual ~Character();
    
    /* Init global position, animated info and
     * texture image.
     * 
     * @param float x position
     *    float y position
     *    int number of animations
     *    int number of frames
     *    Texture* texture
     */
    void init(float x, float y, int numberAnimations, int numberFrames, Texture* texture, AL* al);
    
    /** Init buffers for rendering */
    void initBuffers();
    
    /** 
    * Update the states of character.
    * 
    * @param long difTime, time difference between the bonds of the game
    */
    void update(long difTime);
    
    /** Render the character in your position.*/
    void render();
    
private:
    /** AL* al.*/
    AL* al;
    
    /** Frame timer.*/
    int frameTimer;
    
    /** Time between frames*/
    int timeBetweenFrames;
};

#endif	/* CHARACTER_HPP */

