/* 
 * File:   Sound.hpp
 * Author: gregorio
 *
 * Created on 27 de Janeiro de 2014, 10:36
 * 
 * Sound, a sound which can be play using openAL.
 */

#ifndef SOUND_HPP
#define	SOUND_HPP

#include <AL/al.h>
#include <AL/alut.h>

class Sound {
public:
    /** Default constructor.*/
    Sound();
    
    /** Default destructor.*/
    virtual ~Sound();
    
    /** Buffers to hold sound data.*/
    ALuint buffer;

    /** Sources are points of emitting sound.*/
    ALuint source;
    
    // Position of the source sound.
    ALfloat sourcePos[3];

    // Velocity of the source sound.
    ALfloat sourceVel[3];

    ALenum format;
    ALsizei size;
    ALvoid* data;
    ALsizei freq;
    ALboolean loop;
private:
};

#endif	/* SOUND_HPP */

