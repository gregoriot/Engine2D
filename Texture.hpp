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


#include <GL/glew.h>
#include <GL/gl.h>
#include "TextureCoord.h"

class Texture {
public:
    /** Id of texture in OpenGL context.*/
    GLuint id;
    
    /** Texture size in pixels.*/
    GLuint width;
    GLuint height;
    
    /** Texture size in percents.*/
    TextureCoord prop;
    
    /** Default constructor.*/
    Texture();
    
    /** Default destructor.*/
    virtual ~Texture();
    
private:
    
};

#endif	/* TEXTURE_HPP */

