/* 
 * File:   AL.hpp
 * Author: Gilvanei Gregório
 *
 * Created on 22 de Janeiro de 2014, 10:12
 */

#ifndef AL_HPP
#define	AL_HPP

#include <AL/al.h>
#include <AL/alut.h>
#include <stddef.h>

class AL {
public:
    AL();
    virtual ~AL();
    void initOpenAL();
    void play(float source);
    void stop(float source);
    void pause(float source);
private:

};

#endif	/* AL_HPP */

