#include "Color.hpp"

Color::Color() {
    red   = 0;
    green = 0;
    blue  = 0;
    alpha = 0;
}

Color::Color(float _red, float _green, float _blue, float _alpha) {
    red   = _red;
    green = _green;
    blue  = _blue;
    alpha = _alpha;
}

Color::Color(Color& color) {
    red   = color.red;
    green = color.green;
    blue  = color.blue;
    alpha = color.alpha;
}


Color::~Color() {
    
}

void Color::parseTo255(){
    red   *= 255;
    green *= 255;
    blue  *= 255;
    alpha *= 255;
}

void Color::parseTo1(){
    red   /= 255.f;
    green /= 255.f;
    blue  /= 255.f;
    alpha /= 255.f;
}