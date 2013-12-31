/* 
 * File:   Sprite.hpp
 * Author: gregorio
 *
 * Created on 31 de Dezembro de 2013, 17:34
 */

#ifndef SPRITE_HPP
#define	SPRITE_HPP

class Sprite {
public:
    Sprite();
    virtual ~Sprite();
    virtual void update(long) = 0;
    virtual void render() = 0;
    
    float x;
    float y;
    
    float width;
    float height;
    
    bool active;
protected:
    unsigned int textureId;
private:
};

#endif	/* SPRITE_HPP */

