/* 
 * File:   ResourceLoader.hpp
 * Author: Gilvanei Gregório
 *
 * Created on 26 de Janeiro de 2014, 19:53
 * 
 * A class with statics functions that abstracts the 
 * resource loading for the game.
 */

#ifndef SOUNDLOAD_HPP
#define	SOUNDLOAD_HPP

#include <AL/al.h>
#include <AL/alut.h>
#include <iostream>
#include "Sound.hpp"

class SoundLoad {
public:
    
    /** Default constructor.*/
    SoundLoad();
        
    /** Default destructor.*/
    virtual ~SoundLoad();
    
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

#endif	/* SOUNDLOAD_HPP */

