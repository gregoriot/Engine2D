/* 
 * File:   Character.cpp
 * Author: gregorio
 * 
 * Created on 31 de Dezembro de 2013, 11:43
 */

#include <iostream>

#include "Character.hpp"

Character::Character() {
    
}

Character::~Character() {
    
}

void Character::init(float _x, float _y, int _numberAnimations, int _numberFrames, Texture* texture){
    x = _x;
    y = _y;
    
    width = texture->width / _numberFrames;
    height = texture->height / _numberAnimations;
    
    textureId = texture->id;
    
    active = true;
    
    currentFrame = 0;
    numberFrames = _numberFrames;
    frameTimer = 0;
    timeBetweenFrames = 60;

    currentAnimation = 0;
    numberAnimations = _numberAnimations;
    
    frameProp = 1.f/numberFrames;
    animationProp = 1.f/numberAnimations;
    
    collisionBox.init(x, y, height, width);
}

void Character::update(long difTime){
     frameTimer += difTime;
      currentFrame = (frameTimer/timeBetweenFrames)%numberFrames;
}

void Character::render(){
    glBindTexture(GL_TEXTURE_2D, textureId); //inicia o uso da texturo com o id gerado
    
    float beginCoordX = currentFrame*frameProp;
    float beginCoordY = currentAnimation*animationProp;
    float endCoordX = currentFrame*frameProp+frameProp;
    float endCoordY = currentAnimation*animationProp+animationProp;
    
    glBegin(GL_QUADS);
        glTexCoord2f(beginCoordX, beginCoordY);
        glVertex2f(x, y);

        glTexCoord2f(endCoordX, beginCoordY);
        glVertex2f(x+width, y);

        glTexCoord2f(endCoordX, endCoordY);
        glVertex2f(x+width, y+height);	 

        glTexCoord2f(beginCoordX, endCoordY);
        glVertex2f(x, y+height);
    glEnd();
}