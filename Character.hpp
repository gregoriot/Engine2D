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

class Character : public Sprite {
public:
    Character();
    virtual ~Character();
    void init(int, int, unsigned int);
    void update(long);
    void render();
private:

};

#endif	/* CHARACTER_HPP */

