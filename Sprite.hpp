/* 
 * File:   Sprite.hpp
 * Author: Gilvanei Gregório
 *
 * Created on 31 de Dezembro de 2013, 17:34
 * 
 * Class sprite, draws, update.
 */

#ifndef SPRITE_HPP
#define	SPRITE_HPP

#include <GL/glew.h>
#include "Texture.hpp"
#include "VertexPos2f.h"

class Sprite {
public:
    GLuint indiceBuffer;
    GLuint vertexBuffer;
    GLuint texCoordBuffer;
    
    /** Position in world.*/
    VertexPos2f position;
    
    /** Texture of sprite. */
    Texture* texture;
    
    /** Sprite size in pixels.*/
    float radius;
    
    /** Reports the states of sprite.*/
    bool active;
    
    /** Default constructor.*/
    Sprite();
    
    /** Default destructor.*/
    virtual ~Sprite();
    
    /* Init global position and texture image.
     * 
     * @param float x position
     *    float y position
     *    Texture* texture
     */
    void init(float x, float y, Texture* _texture);
    
    /** Init buffers for rendering */
    void initBuffers();
    
    /** 
     * Update the states of game.
     * 
     * @param long difTime, time difference between the bonds of the game
     */
    void update(long difTime);
    
    /** Render the game in screen.*/
    void render();
protected:
private:
};

#endif	/* SPRITE_HPP */