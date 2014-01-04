/* 
 * File:   Collision.cpp
 * Author: gregorio
 * 
 * Created on 2 de Janeiro de 2014, 20:37
 */

#include "Collision.hpp"

Collision::Collision() {
    
}

Collision::~Collision() {
    
}

bool Collision::boundingBox(Rect rectA, Rect rectB){
     if(rectA.x > rectB.x+rectB.width)
        return false;
    if(rectA.x+rectA.width < rectB.x)
        return false;
    if(rectA.y > rectB.y+rectB.height)
        return false;
    if(rectA.y+rectA.height < rectB.y)
        return false;
    
    return true;
}

bool Collision::circular(float x1, float y1, float r1, float x2, float y2, float r2){
    if(sqrt(pow(x1-x2, 2) + pow(y1-y2, 2)) <= (r1 + r2))
			return true;
		
		return false;
    
    return false;
}

bool Collision::circular(Sprite* s1 , Sprite* s2){
    if(sqrt(pow(s1->x-s2->x, 2) + pow(s1->y-s2->y, 2)) <= (s1->radius + s2->radius))
			return true;
		
		return false;
    
    return false;
}