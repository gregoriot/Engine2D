/* 
 * File:   Texture.hpp
 * Author: Gilvanei Gregório
 *
 * Created on 30 de Dezembro de 2013, 12:46
 * 
 * Texture, a image which can be draw in screen.
 */

#ifndef TEXTURE_HPP
#define	TEXTURE_HPP

#include "SDL/SDL_opengl.h"
class Texture {
public:
    /** Id of texture in OpenGL context.*/
    unsigned int id;
    
    /** Sprite size in pixels.*/
    int width;
    int height;
    
    /** Texture size in porcents.*/
    float propX;
    float propY;
    
    /** Default constructor.*/
    Texture();
    
    /** Default destructor.*/
    virtual ~Texture();
    
private:
};

#endif	/* TEXTURE_HPP */

