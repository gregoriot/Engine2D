/* 
 * File:   ResourceLoader.hpp
 * Author: Gilvanei Gregório
 *
 * Created on 26 de Janeiro de 2014, 19:53
 * 
 * A class with statics functions that abstracts the 
 * resource loading for the game.
 */

#ifndef RESOURCELOADER_HPP
#define	RESOURCELOADER_HPP

#include <SDL/SDL_opengl.h>
#include <SDL/SDL_image.h>
#include <AL/al.h>
#include <AL/alut.h>

#include "Texture.hpp"
#include "Sound.hpp"

#include <iostream>

class ResourceLoader {
public:
    /** Default constructor.*/
    ResourceLoader();
        
    /** Default destructor.*/
    virtual ~ResourceLoader();
    
    /* 
    * Static function that load a image 
    * .BMP 16 bits em return a texture. 
    * 
    * @param const char* filePath
    * @return Texture* texture  
    */
    static Texture* BMP_16B(const char* filePath);
    
    /* 
    * Static function that load a image 
    * .BMP 24 bits em return a texture. 
    * 
    * @param const char* filePath
    * @return Texture* texture  
    */
    static Texture* BMP_24B(const char* filePath); //Need Fix the colors are inverted.
    
    /* 
    * Static function that load a image 
    * .BMP 32 bits em return a texture. 
    * 
    * @param const char* filePath
    * @return Texture* texture  
    */
    static Texture* BMP_32B(const char* filePath);
    
    /* 
    * Static function that load a image 
    * .JPG bits em return a texture. 
    * 
    * @param const char* filePath
    * @return Texture* texture  
    */
    static Texture* JPG(const char* filePath);
    
    /* 
    * Static function that load a image 
    * .PNG em return a texture. 
    * 
    * @param const char* filePath
    * @return Texture* texture  
    */
    static Texture* PNG(const char* filePath);
    
    /* 
    * Static function that load a sound 
    * .WAV em return a Sound. 
    * 
    * @param const char* filePath
    * @return Sound* sound  
    */
    static Sound* WAV(const char* filePath);
private:

};

#endif	/* RESOURCELOADER_HPP */

