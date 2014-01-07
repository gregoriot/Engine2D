/* 
 * File:   Font_tff.hpp
 * Author: gregorio
 *
 * Created on 6 de Janeiro de 2014, 13:08
 */

#ifndef FONT_TFF_HPP
#define	FONT_TFF_HPP

#include "Color.hpp"
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_ttf.h>
#include <iostream>

#define FONT_TTF_NORMAL 0
#define FONT_TTF_BOLD 1
#define FONT_TTF_ITALIC 2
#define FONT_TTF_UNDERLINE 4
#define FONT_TTF_STRIKETHROUGH 8

class Font_tff{
public:
    Font_tff();
    virtual ~Font_tff();
    void init(const char*, float);
    void init(const char*, float, int);
    
    void setSize(float);
    void setColor(float, float, float, float);
    void render(const char*, float, float);
    
    float size;
private:
    TTF_Font* font = NULL;
    const char* filename;
    
    Color color;
};

#endif	/* FONT_TFF_HPP */

