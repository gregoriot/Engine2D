/* 
 * File:   Collision.hpp
 * Author: Gilvanei Gregório
 *
 * Created on 2 de Janeiro de 2014, 20:37
 * 
 * A class with statics functions of collsions.
 */

#ifndef COLLISION_HPP
#define	COLLISION_HPP

#include "Sprite.hpp"

#include <math.h>

class Collision {
public:
    /** Default constructor.*/
    Collision();
    
    /** Default destructor.*/
    virtual ~Collision();
    
    /* 
    * Static function that test if a rect collided 
    * with other rect.
    * 
    * @param float x position of rect 1
    *    float y position of rect 1
    *    float width of rect 1
    *    float height of rect 1
    *    float x position of rect 2
    *    float y position of rect 2
    *    float width of rect 2
    *    float height of rect 2
    * @return bool result of test
    */
    static bool boundingBox(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);
    
    /* 
    * Static function that test if circle collided
    * with other circle.
    * 
    * @param float x position of rect 1
    *    float y position of rect 1
    *    float radius of rect 1
    *    float x position of rect 2
    *    float y position of rect 2
    *    float radius of rect 1
    * @return bool result of test
    */
    static bool circular(float x1, float y1, float r1, float x2, float y2, float r2);
    
    /* 
    * Static function that test if circle collided
    * with other circle.
    * 
    * @param Sprite* sprite1
    *    Sprite* sprite2
    * @return bool result of test
    */
    static bool circular(Sprite* sprite1, Sprite* sprite2);
private:

};

#endif	/* COLLISION_HPP */

