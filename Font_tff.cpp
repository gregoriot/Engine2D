/* 
 * File:   Font_tff.cpp
 * Author: gregorio
 * 
 * Created on 6 de Janeiro de 2014, 13:08
 */

#include "Font_tff.hpp"

Font_tff::Font_tff() {
    
}

Font_tff::~Font_tff() {
    TTF_CloseFont( font );
    TTF_Quit();
}

void Font_tff::init(const char* _filename, float _size){
    if( TTF_Init() == -1 ){
        std::cout<<"error load font ttf";
    }
        
    filename = _filename;
    size = _size;
    font = TTF_OpenFont(filename, size);
}

void Font_tff::init(const char* _filename, float _size, int style){
    if( TTF_Init() == -1 ){
        std::cout<<"error load font ttf";
    }
        
    filename = _filename;
    size = _size;
    font = TTF_OpenFont(filename, size);
    TTF_SetFontStyle(font, style);
}

void Font_tff::setSize(float _size){
    size = _size;
    
    TTF_CloseFont(font);
    font = TTF_OpenFont(filename, size);
}

void Font_tff::setColor(float _red, float _green, float _blue, float _alpha){
    color.red = _red;
    color.green = _green;
    color.blue = _blue;
    color.alpha = _alpha;
}

void Font_tff::render(const char* text, float x, float y){
	//Init colors and surfaces menssage.
    color.parseTo255();
	SDL_Color Color = {color.red, color.green, color.blue};
	SDL_Surface *messageSurface = TTF_RenderText_Blended(const_cast<TTF_Font*>(font), text, Color);
	
    //Generate an OpenGL texture.
    unsigned int Texture = 0;
	glGenTextures(1, &Texture);
	glBindTexture(GL_TEXTURE_2D, Texture);
 
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 
    //Make the texture in opengl context.
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, messageSurface->w, messageSurface->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, messageSurface->pixels);
 
	//Draw the texture in screen.
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
        glVertex2f(x, y);
        
		glTexCoord2f(1, 0);
        glVertex2f(x+messageSurface->w, y);
        
		glTexCoord2f(1, 1); 
        glVertex2f(x+messageSurface->w, y+messageSurface->h);
        
		glTexCoord2f(0, 1); 
        glVertex2f(x, y+messageSurface->h);
	glEnd();
 
	//Deallocate memory.
	glDeleteTextures(1, &Texture);
	SDL_FreeSurface(messageSurface);
}