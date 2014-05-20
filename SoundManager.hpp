/* 
 * File:   ResourceLoader.hpp
 * Author: Gilvanei Gregório
 *
 * Created on 26 de Janeiro de 2014, 19:53
 * 
 * A class with statics functions that abstracts the 
 * resource loading for the game.
 */

#ifndef SOUNDMANAGER_HPP
#define	SOUNDMANAGER_HPP

#include <AL/al.h>
#include <AL/alut.h>

#include "Sound.hpp"

#include <iostream>

class SoundManager {
public:
    
    /** Default constructor.*/
    SoundManager();
        
    /** Default destructor.*/
    virtual ~SoundManager();
    
    /* 
    * Static function that load a sound 
    * .WAV em return a Sound. 
    * 
    * @param const char* filePath
    * @return Sound* sound  
    */
    static Sound* loadWAV(const char* filePath);
    
    
private:
};

#endif	/* SOUNDMANAGER_HPP */

