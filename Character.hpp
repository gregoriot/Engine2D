/* 
 * File:   Character.hpp
 * Author: gregorio
 *
 * Created on 31 de Dezembro de 2013, 11:43
 */

#ifndef CHARACTER_HPP
#define	CHARACTER_HPP

#include "Sprite.hpp"
#include "SDL/SDL_opengl.h"
#include "Texture.hpp"
#include "Rect.hpp"

class Character : public Sprite {
public:
    Character();
    virtual ~Character();
    void init(float, float, int, int, Texture*);
    void update(long);
    void render();
    
    Rect collisionBox;
private:
    int currentFrame;
    int numberFrames;
    int frameTimer;
    int timeBetweenFrames;

    int currentAnimation;
    int numberAnimations;
    
    float frameProp;
    float animationProp;
};

#endif	/* CHARACTER_HPP */

