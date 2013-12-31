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

void Character::init(int _x, int _y, unsigned int _textureId){
    x = _x;
    y = _y;
    textureId = _textureId;
    
    active = true;
}

void Character::update(long){

}

void Character::render(){
    glBindTexture(GL_TEXTURE_2D, textureId); //inicia o uso da texturo com o id gerado
    
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);
        glVertex2f(0.0f, 0.0f);

        glTexCoord2f(1, 0);
        glVertex2f(500, 0.0f);

        glTexCoord2f(1, 1);
        glVertex2f(500, 500);	 

        glTexCoord2f(0, 1);
        glVertex2f(0, 500);
    glEnd();
}