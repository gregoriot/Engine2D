/* 
 * File:   Rect.hpp
 * Author: gregorio
 *
 * Created on 2 de Janeiro de 2014, 20:53
 */

#ifndef RECT_HPP
#define	RECT_HPP

class Rect {
public:
    Rect();
    virtual ~Rect();
    void init();
    void init(float, float, float, float);
    bool contains(float, float);
    bool contains(Rect*);
    const float centerX();
    const float centerY();
    
    float x;
    float y;
    float width;
    float height;
private:

};

#endif	/* RECT_HPP */

