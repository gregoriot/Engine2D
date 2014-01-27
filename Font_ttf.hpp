/* 
 * File:   Font_ttf.hpp
 * Author: Gilvanei Gregório
 *
 * Created on 6 de Janeiro de 2014, 13:08
 * 
 * Font TTF for render text in screen using 
 * openGL context. 
 */

#ifndef FONT_TTF_HPP
#define	FONT_TTF_HPP

#include <SDL/SDL_opengl.h>
#include <SDL/SDL_ttf.h>

#include "Color.hpp"

#include <iostream>

#define FONT_TTF_NORMAL 0
#define FONT_TTF_BOLD 1
#define FONT_TTF_ITALIC 2
#define FONT_TTF_UNDERLINE 4
#define FONT_TTF_STRIKETHROUGH 8

class Font_ttf{
public:
    /** Default constructor.*/
    Font_ttf();
    
    /** Default destructor.*/
    virtual ~Font_ttf();
    
    /* 
    * Init Font tff, loaded with SDL 
    * and late use with openGL.
    * 
    * @param const char* file path
    *    float size letters
    */
    void init(const char* filePath, float size);
    
    /* 
    * Init Font tff, loaded with SDL 
    * and late use with openGL.
    * 
    * @param const char* file path
    *    float size letters
    *    int style(defined in the class itself) 
    */
    void init(const char* filePath, float size , int style);
    
    /* 
    * Render font ttf in screen, using openGl.
    * 
    * @param const char* text
    *    int x position
    *    iny y position
    */
    void render(const char* text, float x, float y);
    
    /** Size of font.*/
    float size;
    /** Color of font.*/
    Color* color;
private:
    /** Font in SDL context.*/
    TTF_Font* font = NULL;
    /** File Path of font.*/
    const char* filePath;
};

#endif	/* FONT_TTF_HPP */

