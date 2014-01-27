#include "AL.hpp"

AL::AL() {
    
}

AL::~AL() {
    alutExit();
}

void AL::initOpenAL(){
	alutInit(NULL, 0);
	alGetError();
}

void AL::play(float source){
    alSourcePlay(source);
}

void AL::stop(float source){
    alSourcePause(source);
}

void AL::pause(float source){
    alSourceStop(source);
}