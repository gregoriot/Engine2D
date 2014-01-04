/* 
 * File:   TextureLoader.hpp
 * Author: gregorio
 *
 * Created on 2 de Janeiro de 2014, 18:13
 */

#ifndef TEXTURELOADER_HPP
#define	TEXTURELOADER_HPP

#include "SDL/SDL_opengl.h"
#include "SDL/SDL_image.h"
#include "Texture.hpp"

class TextureLoader {
public:
    TextureLoader();
    virtual ~TextureLoader();
    
    static Texture* BMP_16B(const char* filename);
    static Texture* BMP_24B(const char* filename); //Need Fix the colors are inverted.
    static Texture* BMP_32B(const char* filename);
    static Texture* JPG(const char* filename);
    static Texture* PNG(const char* filename);
private:

};

#endif	/* TEXTURELOADER_HPP */

