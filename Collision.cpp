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
}

bool Collision::circular(Sprite* s1 , Sprite* s2){
    if(sqrt(pow(s1->position.x-s2->position.x, 2) + pow(s1->position.y-s2->position.y, 2)) <= (s1->radius + s2->radius))
        return true;
    
    return false;
}