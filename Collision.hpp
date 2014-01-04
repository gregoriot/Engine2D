/* 
 * File:   Collision.hpp
 * Author: gregorio
 *
 * Created on 2 de Janeiro de 2014, 20:37
 */

#ifndef COLLISION_HPP
#define	COLLISION_HPP

#include "Rect.hpp"
#include "Sprite.hpp"
#include <math.h>

class Collision {
public:
    Collision();
    virtual ~Collision();
    
    static bool boundingBox(Rect rectA, Rect rectB);
    static bool circular(float, float, float, float, float, float);
    static bool circular(Sprite*, Sprite*);
private:

};

#endif	/* COLLISION_HPP */

