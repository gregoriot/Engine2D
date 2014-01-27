#include "Collision.hpp"

Collision::Collision() {
    
}

Collision::~Collision() {
    
}

bool Collision::boundingBox(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2){
     if(x1 > x2+w2)
        return false;
    if(x1+w1 < x2)
        return false;
    if(y1 > y2+h2)
        return false;
    if(y1+h1 < y2)
        return false;
    
    return true;
}

bool Collision::circular(float x1, float y1, float r1, float x2, float y2, float r2){
    if(sqrt(pow(x1-x2, 2) + pow(y1-y2, 2)) <= (r1 + r2))
			return true;
		
		return false;
    
    return false;
}

bool Collision::circular(Sprite* sprite1 , Sprite* sprite2){
    if(sqrt(pow(sprite1->x-sprite2->x, 2) + pow(sprite1->y-sprite2->y, 2)) <= (sprite1->radius + sprite2->radius))
			return true;
		
		return false;
    
    return false;
}