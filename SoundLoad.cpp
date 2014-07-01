#include "SoundLoad.hpp"

SoundLoad::SoundLoad() {
    
}

SoundLoad::~SoundLoad() {
    
}

Sound* SoundLoad::WAV(const char* filePath){
    Sound* sound = new Sound();

	// Load wav data into a buffer.
	alGenBuffers(1, &sound->buffer);

	if(alGetError() != AL_NO_ERROR)
            std::cout<<"ERROR GEN BUFFER";

    //Load wav file with alut.
	alutLoadWAVFile((ALbyte*)filePath, &sound->format, &sound->data, &sound->size, &sound->freq, &sound->loop);
	alBufferData(sound->buffer, sound->format, sound->data, sound->size, sound->freq);
	alutUnloadWAV(sound->format, sound->data, sound->size, sound->freq);

	// Bind the buffer with the source.
	alGenSources(1, &sound->source);

	if(alGetError() != AL_NO_ERROR)
            std::cout<<"ERROR GEN SOURCE";

	alSourcei (sound->source, AL_BUFFER,   sound->buffer);
	alSourcef (sound->source, AL_PITCH,    1.0      );
	alSourcef (sound->source, AL_GAIN,     1.0      );
	alSourcefv(sound->source, AL_POSITION, sound->sourcePos);
	alSourcefv(sound->source, AL_VELOCITY, sound->sourceVel);
	alSourcei (sound->source, AL_LOOPING,  sound->loop);

	// Do another error check and return.
	if(alGetError() == AL_NO_ERROR)
            std::cout<<"ERROR LOAD WAV";
    
    return sound;
}