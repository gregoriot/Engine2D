/* 
 * File:   Texture.cpp
 * Author: gregorio
 *
 * Created on 30 de Dezembro de 2013, 13:08
 */

#include "Texture.hpp"

Texture::Texture() {

}

Texture::~Texture() {
    
}

unsigned int Texture::LOAD_BMP(const char* filename){
        unsigned int id; //Id for the texture.
        glGenTextures(1, &id); //Generate opengl id for the texture.
        
        SDL_Surface* img = SDL_LoadBMP(filename); //Load the bmp image.
        
        glBindTexture(GL_TEXTURE_2D, id); //Use the texture, we have just generated.
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //If the texture is smaller, than the image, we get the average of the pixels next to it
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //Same if the image bigger
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP); //We repeat the pixels in the edge of the texture.
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP); //It for vertically and horizontally.
        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, img->pixels); //Make the texture in opengl context.
        SDL_FreeSurface(img); //Delete the image, we don't need it anymore.
        
        return id; //Return only the id.
}


