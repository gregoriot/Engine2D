/* 
 * File:   Sprite.hpp
 * Author: Gilvanei Gregório
 *
 * Created on 31 de Dezembro de 2013, 17:34
 * 
 * Abstract class sprite, draws, update.
 */

#ifndef SPRITE_HPP
#define	SPRITE_HPP

#include "Texture.hpp"


class Sprite {
public:
    /** Position in world.*/
    float x;
    float y;
    
    /** Sprite size in pixels.*/
    float width;
    float height;
    float radius;
    
    /** Reports the states od sprite.*/
    bool active;
    
    
    /** Default constructor.*/
    Sprite();
    
    /** Default destructor.*/
    virtual ~Sprite();
    
    /** 
     * Abstract method. Update the states of game.
     * @param: long difTime, time difference between the bonds of the game
     */
    virtual void update(long difTime) = 0;
    
    /** Abstract method. Render the game in screen.*/
    virtual void render() = 0;
protected:
private:
};

#endif	/* SPRITE_HPP */

