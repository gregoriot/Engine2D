/* 
 * File:   Vector2f.hpp
 * Author: Gilvanei Gregório
 *
 * Created on 14 de Dezembro de 2013, 20:02
 * 
 * A vector two dimensions.
 */

#ifndef VECTOR2F_HPP
#define	VECTOR2F_HPP

class Vector2f {
public:
    /** Default constructor.*/
    Vector2f();
    
    /* 
    * Constructor receiving x and y and assigns
    * to object.
    * 
    * @param int x
    *    int y
    */
    Vector2f(float x, float y);
    
    /* 
    * Constructor receiving other vector and assigns
    * to object.
    * 
    * @param Vector2f& vector
    */
    Vector2f(Vector2f& vector);
    
    /** Default destructor.*/
    virtual ~Vector2f();
    
    /* 
    * Overwrites the + operator. Adds two vector.
    * 
    * @param Vector2f vector
    * @return Vector2f vector result
    */
    Vector2f operator+(Vector2f);
    
    /* 
    * Overwrites the - operator. Dcreases two vector.
    * 
    * @param Vector2f vector
    * @return Vector2f vector result
    */
    Vector2f operator-(Vector2f);
    
    /** x position.*/
    float x;
    
    /** y position.*/
    float y;
private:
};

#endif	/* VECTOR2F_HPP */

