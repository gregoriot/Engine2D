#include "Texture.hpp"

Texture::Texture() {
    //Init texture ID as invalid
    id = 0;
}

Texture::~Texture() {
    //Delete texture buffer from video board by ID
    glDeleteTextures( 1, &id);
    
    //Set texture ID as invalid
    id = 0;
}