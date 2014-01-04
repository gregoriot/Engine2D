/* 
 * File:   Rect.cpp
 * Author: gregorio
 * 
 * Created on 2 de Janeiro de 2014, 20:53
 */

#include "Rect.hpp"

Rect::Rect() {
    
}

Rect::~Rect() {
    
}

void Rect::init(){
    x = 0;
    y = 0;
    width = 0;
    height = 0;
}

void Rect::init(float _x, float _y, float _width, float _height){
    x = _x;
    y = _x;
    width = _width;
    height = _height;
}

bool Rect::contains(float _x, float _y){
    if(_x < x)
        return false;
    if(_x > x+width)
        return false;
    if(_y < y)
        return false;
    if(_y > y+height)
        return false;
    
    return true;
}

bool Rect::contains(Rect* rect){
    if(rect->x < x)
        return false;
    if(rect->x+rect->width > x+width)
        return false;
    if(rect->y < y)
        return false;
    if(rect->y+rect->height > y+height)
        return false;
    
    return true;
}

const float Rect::centerX(){
    return x + width/2;
}

const float Rect::centerY(){
    return y + height/2;
}