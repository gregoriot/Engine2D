/* 
 * File:   Character.cpp
 * Author: gregorio
 * 
 * Created on 31 de Dezembro de 2013, 11:43
 */

#include "Character.hpp"

Character::Character() {
    
}

Character::~Character() {
    
}

void Character::init(float _x, float _y, Texture* texture){
    x = _x;
    y = _y;
    
    width = texture->width;
    height = texture->height;
    
    textureId = texture->id;
    
    active = true;
}

void Character::update(long){

}

void Character::render(){
    glBindTexture(GL_TEXTURE_2D, textureId); //inicia o uso da texturo com o id gerado
    
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);
        glVertex2f(x, y);

        glTexCoord2f(1, 0);
        glVertex2f(width, y);

        glTexCoord2f(1, 1);
        glVertex2f(width, height);	 

        glTexCoord2f(0, 1);
        glVertex2f(x, height);
    glEnd();
}