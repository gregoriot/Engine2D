/* 
 * File:   TextureCoord.h
 * Author: gustavo
 *
 * Created on May 27, 2014, 10:19 PM
 * The TextureCoord is the texture data of one vertex.
 */

#ifndef TEXTURECOORD_H
#define	TEXTURECOORD_H

#include <GL/gl.h>

struct TextureCoord {

    /**Texture coordinate X in percent*/
    GLfloat x;
    
    /**Texture coordinate Y in percent*/
    GLfloat y;
    
};

#endif	/* TEXTURECOORD_H */

