/* 
 * File:   Texture.hpp
 * Author: gregorio
 *
 * Created on 30 de Dezembro de 2013, 12:46
 */

#ifndef TEXTURE_HPP
#define	TEXTURE_HPP

#include "SDL/SDL_opengl.h"
class Texture {
public:
    Texture();
    virtual ~Texture();
    
    unsigned int id;
    float width;
    float height;
private:
};

#endif	/* TEXTURE_HPP */

