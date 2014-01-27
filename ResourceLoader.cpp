#include "ResourceLoader.hpp"

ResourceLoader::ResourceLoader() {
    
}

ResourceLoader::~ResourceLoader() {
    
}

Texture* ResourceLoader::BMP_16B(const char* filePath){
    Texture* texture = new Texture();

    SDL_Surface* surface = SDL_LoadBMP(filePath); //Load the bmp 16 bits file.
    texture->width = surface->w;
    texture->height = surface->h;

    glGenTextures(1, &texture->id); //Generate opengl id for the texture.
    glBindTexture(GL_TEXTURE_2D, texture->id); //Use the texture, we have just generated.
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //If the texture is smaller, than the image, we get the average of the pixels next to it
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //Same if the image bigger
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP); //We repeat the pixels in the edge of the texture.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP); //It for vertically and horizontally.

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, surface->pixels); //Make the texture in opengl context.
    SDL_FreeSurface(surface); //Delete the image, we don't need it anymore.

    return texture; //Return Texture.
}

Texture* ResourceLoader::BMP_24B(const char* filePath){
    Texture* texture = new Texture();

    SDL_Surface* surface = SDL_LoadBMP(filePath); //Load the bmp 16 bits file.
    texture->width = surface->w;
    texture->height = surface->h;

    glGenTextures(1, &texture->id); //Generate opengl id for the texture.
    glBindTexture(GL_TEXTURE_2D, texture->id); //Use the texture, we have just generated.
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //If the texture is smaller, than the image, we get the average of the pixels next to it
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //Same if the image bigger
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP); //We repeat the pixels in the edge of the texture.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP); //It for vertically and horizontally.
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB, GL_UNSIGNED_BYTE, surface->pixels); //Make the texture in opengl context.
    SDL_FreeSurface(surface); //Delete the image, we don't need it anymore.

    return texture; //Return Texture.
}

Texture* ResourceLoader::BMP_32B(const char* filePath){
    Texture* texture = new Texture();

    SDL_Surface* surface = SDL_LoadBMP(filePath); //Load the bmp 16 bits file.
    texture->width = surface->w;
    texture->height = surface->h;

    glGenTextures(1, &texture->id); //Generate opengl id for the texture.
    glBindTexture(GL_TEXTURE_2D, texture->id); //Use the texture, we have just generated.
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //If the texture is smaller, than the image, we get the average of the pixels next to it
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //Same if the image bigger
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP); //We repeat the pixels in the edge of the texture.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP); //It for vertically and horizontally.

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, surface->pixels); //Make the texture in opengl context.
    SDL_FreeSurface(surface); //Delete the image, we don't need it anymore.

    return texture; //Return Texture.
}

Texture* ResourceLoader::JPG(const char* filePath) {
    Texture* texture = new Texture();

    SDL_Surface* surface = IMG_Load(filePath);  //Load the png file.
    texture->width = surface->w;
    texture->height = surface->h;
    
    glGenTextures(1, &texture->id); //Generate opengl id for the texture.
    glBindTexture(GL_TEXTURE_2D, texture->id); //Use the texture, we have just generated.
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //If the texture is smaller, than the image, we get the average of the pixels next to it
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //Same if the image bigger
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP); //We repeat the pixels in the edge of the texture.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP); //It for vertically and horizontally.
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB, GL_UNSIGNED_BYTE, surface->pixels);  //Make the texture in opengl context.
    SDL_FreeSurface(surface);   //Delete the image, we don't need it anymore.
    
    return texture; //Return Texture.
}

Texture* ResourceLoader::PNG(const char* filePath) {
    Texture* texture = new Texture();

    SDL_Surface* surface = IMG_Load(filePath);  //Load the png file.
    texture->width = surface->w;
    texture->height = surface->h;
    
    glGenTextures(1, &texture->id); //Generate opengl id for the texture.
    glBindTexture(GL_TEXTURE_2D, texture->id); //Use the texture, we have just generated.
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //If the texture is smaller, than the image, we get the average of the pixels next to it
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //Same if the image bigger
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP); //We repeat the pixels in the edge of the texture.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP); //It for vertically and horizontally.
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);  //Make the texture in opengl context.
    SDL_FreeSurface(surface);   //Delete the image, we don't need it anymore.
    
    return texture; //Return Texture.
}

Sound* ResourceLoader::WAV(const char* filePath){
    Sound* sound = new Sound();

	// Load wav data into a buffer.
	alGenBuffers(1, &sound->buffer);

	if(alGetError() != AL_NO_ERROR)
		std::cout<<"ERROR GEN BUFFER";

    //Load wav file with alut.
	alutLoadWAVFile((ALbyte*)filePath, &sound->format, &sound->data, &sound->size, &sound->freq, &sound->loop);
	alBufferData(sound->buffer, sound->format, sound->data, sound->size, sound->freq);
	alutUnloadWAV(sound->format, sound->data, sound->size, sound->freq);

	// Bind the buffer with the source.
	alGenSources(1, &sound->source);

	if(alGetError() != AL_NO_ERROR)
		std::cout<<"ERROR GEN SOURCE";

	alSourcei (sound->source, AL_BUFFER,   sound->buffer);
	alSourcef (sound->source, AL_PITCH,    1.0      );
	alSourcef (sound->source, AL_GAIN,     1.0      );
	alSourcefv(sound->source, AL_POSITION, sound->sourcePos);
	alSourcefv(sound->source, AL_VELOCITY, sound->sourceVel);
	alSourcei (sound->source, AL_LOOPING,  sound->loop);

	// Do another error check and return.
	if(alGetError() == AL_NO_ERROR)
		std::cout<<"ERROR LOAD WAV";
    
    return sound;
}