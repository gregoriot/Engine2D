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
    
    /** Position x in world.*/
    float x;
    /** Position y in world.*/
    float y;
    
    /** Width sprite in pixel.*/
    float width;
    /** Height sprite in pixel.*/
    float height;
    /** Radius sprite in pixel.*/
    float radius;
    
    /** Reports the states od sprite.*/
    bool active;
protected:
private:
};

#endif	/* SPRITE_HPP */

