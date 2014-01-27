/* 
 * File:   GL.hpp
 * Author: Gilvanei Gregório
 *
 * Created on 20 de Janeiro de 2014, 21:29
 * 
 * Implements functions using openGL for render
 * objects in screen.
 */

#ifndef GL_HPP
#define	GL_HPP

#include<SDL/SDL_opengl.h>

#include "Texture.hpp"

class GL {
public:
    /** Default constructor.*/
    GL();
    
    /** Default destructor.*/
    virtual ~GL();
    
    /* 
    * Init Open GL context, matrixs and load 
    * your Identity, clear color,set depth 
    * and viewport.
    * 
    * @param int width sceen
    *    int height screen
    */
    void initOpenGL(int width, int height);
    
    /** Prepares the context to render on a 
    * camera orthogonal without depth.
    */
    void beginRender2D();
    
    /** Leaves render on a camera orthogonal
    *  without depth. Load again matrixs 
    * projetion and model view.*/
    void endRender2D();
    
    /** Prepares to use textures 2D.*/
    void enableTexture2D();
    
    /** Leaves use textures 2D.*/
    void disableTexture2D();
    
    /* 
    * Draw using opengl(immediate mode) a 
    * texture 2D in a quads, the parameters 
    * position the textures on screen. 
    * 
    * @param Texture* texture
    *    float x1
    *    float y1
    *    float x2
    *    float y2
    */
    void render2D(Texture* texture, float x1, float y1, float x2, float y2);
    
    /* 
    * Draw using opengl(immediate mode) a 
    * texture 2D in a quads, the parameters 
    * position a fraction of textures on screen. 
    * 
    * @param Texture* texture
    *    float source region of image x1
    *    float source region of image y1
    *    float source region of image x2
    *    float source region of image y2
    *    float destination region of sceen x1
    *    float destination region of sceen y1
    *    float destination region of sceen x2
    *    float destination region of sceen y2
    */
    void render2D(Texture* texture, float srcX1, float srcY1, float srcX2, float srcY2, float dstX1, float dstY1, float dstX2, float dstY2);
    
    /* 
    * Draw using opengl(immediate mode) a 
    * texture 2D in a quads, the parameters 
    * position the textures on screen.
    * 
    * @param Texture* texture
    *    float x1
    *    float y1
    *    float x2
    *    float y2
    *    bool flip the image in axis x
    *    bool flip the image in axis y
    */
    void render2D(Texture* texture, float x1, float y1, float x2, float y2, bool flipX, bool flipY);
    
    /* 
    * Draw using opengl(immediate mode) a 
    * texture 2D in a quads, the parameters
    * position a fraction of textures on screen. 
    * 
    * @param Texture* texture
    *    float source region of image x1
    *    float source region of image y1
    *    float source region of image x2
    *    float source region of image y2
    *    float destination region of sceen x1
    *    float destination region of sceen y1
    *    float destination region of sceen x2
    *    float destination region of sceen y2
    *    bool flip the image in axis x
    *    bool flip the image in axis y
    */
    void render2D(Texture* texture, float srcX1, float srcY1, float srcX2, float srcY2, float dstX1, float dstY1, float dstX2, float dstY2, bool flipX, bool flipY);
private:
    /** Width screen in pixels.*/
    int width;
    /** Height screen in pixels.*/
    int height;
    
    /** Ratio screen.*/
    float ratio;
};

#endif	/* GL_HPP */

