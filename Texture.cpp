#include "Texture.hpp"

Texture::Texture() {

}

Texture::~Texture() {
    glDeleteTextures( 1, &id);
    id = 0;
}

