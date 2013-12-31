/* 
 * File:   Vector2f.hpp
 * Author: gregorio
 *
 * Created on 14 de Dezembro de 2013, 20:02
 * 
 * A vector two dimensions.
 */

#ifndef VECTOR2F_HPP
#define	VECTOR2F_HPP

class Vector2f {
public:
    Vector2f();
    Vector2f(float, float);
    Vector2f(Vector2f&);
    virtual ~Vector2f();
    
    Vector2f operator+(Vector2f);
    Vector2f operator-(Vector2f);
    
    float x;
    float y;
private:
};

#endif	/* VECTOR2F_HPP */

