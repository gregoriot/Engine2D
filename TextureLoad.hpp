/* 
 * File:   TextureManager.hpp
 * Author: Gilvanei Gregório
 *
 * Created on 26 de Janeiro de 2014, 19:53
 * 
 * A class with statics functions that abstracts the 
 * texture management for the game.
 */

#ifndef TEXTUREMANAGER_HPP
#define	TEXTUREMANAGER_HPP

#include <SDL/SDL_image.h>
#include "Texture.hpp"

class TextureLoad {
public:
    
    /** Default constructor.*/
    TextureLoad();
        
    /** Default destructor.*/
    virtual ~TextureLoad();
    
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
    
    
private:
    
    /* 
    * Static sub-function that create
    * generic texture configuration
    * 
    * @param const char* filePath
    * @return Texture* texture  
    */
    static Texture* prepare(SDL_Surface* surface);
};

#endif	/* TEXTUREMANAGER_HPP */

