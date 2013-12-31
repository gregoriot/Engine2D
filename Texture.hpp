/* 
 * File:   Texture.hpp
 * Author: gregorio
 *
 * Created on 30 de Dezembro de 2013, 12:46
 */

#ifndef TEXTURE_HPP
#define	TEXTURE_HPP

#include "SDL/SDL_opengl.h"
#include "SDL/SDL_image.h"
#include <iostream>

class Texture {
public:
    Texture();
    virtual ~Texture();
    static unsigned int LOAD_BMP(const char* filename);
private:

};

#endif	/* TEXTURE_HPP */

