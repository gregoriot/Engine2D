/* 
 * File:   Color.hpp
 * Author: gregorio
 *
 * Created on 6 de Janeiro de 2014, 13:19
 */

#ifndef COLOR_HPP
#define	COLOR_HPP

class Color {
public:
    Color();
    Color(float, float, float, float);
    Color(Color&);
    virtual ~Color();
    
    void parseTo255(); // Need refactor this.
    void parseTo1();
    
    float red;
    float green;
    float blue;
    float alpha;
private:

};

#endif	/* COLOR_HPP */

