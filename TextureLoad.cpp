#include "TextureLoad.hpp"

TextureLoad::TextureLoad() {
    
}

TextureLoad::~TextureLoad() {
    
}

Texture* TextureLoad::BMP_16B(const char* filePath){
    SDL_Surface* surface = SDL_LoadBMP(filePath); //Load the bmp 16 bits file.
    
    Texture* texture = TextureLoad::prepare(surface);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, surface->pixels); //Make the texture in opengl context.
    SDL_FreeSurface(surface); //Delete the image, we don't need it anymore.

    return texture; //Return Texture.
}

Texture* TextureLoad::BMP_24B(const char* filePath){
    SDL_Surface* surface = SDL_LoadBMP(filePath); //Load the bmp 16 bits file.
    
    Texture* texture = TextureLoad::prepare(surface);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB, GL_UNSIGNED_BYTE, surface->pixels); //Make the texture in opengl context.
    SDL_FreeSurface(surface); //Delete the image, we don't need it anymore.

    return texture; //Return Texture.
}

Texture* TextureLoad::BMP_32B(const char* filePath){
    SDL_Surface* surface = SDL_LoadBMP(filePath); //Load the bmp 16 bits file.
    
    Texture* texture = TextureLoad::prepare(surface);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, surface->pixels); //Make the texture in opengl context.
    SDL_FreeSurface(surface); //Delete the image, we don't need it anymore.

    return texture; //Return Texture.
}

Texture* TextureLoad::JPG(const char* filePath) {
    SDL_Surface* surface = IMG_Load(filePath);  //Load the png file.
    
    Texture* texture = TextureLoad::prepare(surface);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB, GL_UNSIGNED_BYTE, surface->pixels);  //Make the texture in opengl context.
    SDL_FreeSurface(surface);   //Delete the image, we don't need it anymore.
    
    return texture; //Return Texture.
}

Texture* TextureLoad::PNG(const char* filePath) {
    SDL_Surface* surface = IMG_Load(filePath);  //Load the png file.
    
    Texture* texture = TextureLoad::prepare(surface);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);  //Make the texture in opengl context.
    SDL_FreeSurface(surface);   //Delete the image, we don't need it anymore.
    
    return texture; //Return Texture.
}

Texture* TextureLoad::prepare(SDL_Surface* surface){
    Texture* texture = new Texture();
    
    texture->width = surface->w;
    texture->height = surface->h;
    
    texture->prop.x = 1;
    texture->prop.y = 1;
    
    glGenTextures(1, &texture->id); //Generate opengl id for the texture.
    glBindTexture(GL_TEXTURE_2D, texture->id); //Use the texture, we have just generated.
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //If the texture is smaller, than the image, we get the average of the pixels next to it
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //Same if the image bigger
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP); //We repeat the pixels in the edge of the texture.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP); //It for vertically and horizontally.
    
    return texture;
}