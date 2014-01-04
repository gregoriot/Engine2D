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
    glDeleteTextures( 1, &id);
    id = 0;
}

