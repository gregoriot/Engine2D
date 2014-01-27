/* 
 * File:   Color.hpp
 * Author: Gilvanei Gregório
 *
 * Created on 6 de Janeiro de 2014, 13:19
 * 
 * Color is a representation of a color in rgba, with
 * your red component, green component, blue component
 * and alpha component.
 */

#ifndef COLOR_HPP
#define	COLOR_HPP

class Color {
public:
    /** Default constructor.*/
    Color();
    
    /* 
    * Constructor receiving a 4 components of
    * RGBA and assigns to object.
    * 
    * @param float red
    *    float blue
    *    float green
    *    float alpha
    */
    Color(float red, float blue, float green, float alpha);
    
    /* 
    * Constructor receiving other color and 
    * assigns to object.
    * 
    * @param Color& color
    */
    Color(Color& color);
    
    /** Default destructor.*/
    virtual ~Color();
    
    /** Parse the components to 255.*/
    void parseTo255(); // Need refactor this.
    
    /** Parse the components to 1.*/
    void parseTo1();   // Need refactor this.
    
    /** Red component.*/
    float red;
    
    /** Green component.*/
    float green;
    
    /** Blue component.*/
    float blue;
    
    /** Alpha component.*/
    float alpha;
private:

};

#endif	/* COLOR_HPP */

