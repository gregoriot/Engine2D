#include "Vector2f.hpp"

Vector2f::Vector2f() {
    x = 0;
    y = 0;
}

 Vector2f::Vector2f(float _x, float _y){
     x = _x;
     y = _y;
 }
 
 Vector2f::Vector2f(Vector2f& vector2f){
     x = vector2f.x;
     y = vector2f.y;
 }
    
Vector2f::~Vector2f() {
    
}

Vector2f Vector2f::operator+(Vector2f vector2f){
    Vector2f result;
    result.x = this->x + vector2f.x;
    result.y = this->y + vector2f.y;
    
    return result;
}

Vector2f Vector2f::operator-(Vector2f vector2f){
    Vector2f result;
    result.x = this->x - vector2f.x;
    result.y = this->y - vector2f.y;
    
    return result;
}