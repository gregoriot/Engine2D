#include "Font_ttf.hpp"

Font_ttf::Font_ttf() {
    font = NULL;
    color = new Color();
}

Font_ttf::~Font_ttf() {
    TTF_CloseFont(font);
    TTF_Quit();
}

void Font_ttf::init(const char* _filePath, float _size){
    if( TTF_Init() == -1 ){
        std::cout<<"error load font ttf";
    }
        
    filePath = _filePath;
    size = _size;
    font = TTF_OpenFont(filePath, size);
}

void Font_ttf::init(const char* _filePath, float _size, int style){
    if( TTF_Init() == -1 ){
        std::cout<<"error load font ttf";
    }
        
    filePath = _filePath;
    size = _size;
    font = TTF_OpenFont(filePath, size);
    TTF_SetFontStyle(font, style);
}

void Font_ttf::render(const char* text, float x, float y){
	//Init colors and surfaces menssage.
    color->parseTo255();
	SDL_Color Color = {color->red, color->green, color->blue};
    color->parseTo1();
	SDL_Surface *messageSurface = TTF_RenderText_Blended(const_cast<TTF_Font*>(font), text, Color);
	
    //Generate an OpenGL texture.
    GLuint Texture = 0;
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