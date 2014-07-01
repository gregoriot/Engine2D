#include "Sound.hpp"

Sound::Sound() {
    sourcePos[0] = 0.0;
    sourcePos[1] = 0.0;
    sourcePos[2] = 0.0;
          
    sourceVel[0] = 0.0;
    sourceVel[1] = 0.0;
    sourceVel[2] = 0.0;
}

Sound::~Sound() {
    alDeleteBuffers(1, &buffer);
    alDeleteSources(1, &source);
}

