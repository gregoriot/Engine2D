/* 
 * File:   Camera.hpp
 * Author: Gilvanei Gregório
 *
 * Created on 26 de Janeiro de 2014, 22:29
 * 
 * Camera position in world. Help to orientation.
 */

#ifndef CAMERA_HPP
#define	CAMERA_HPP

#include <AL/al.h>
#include <AL/alut.h>

#include "Vector2f.hpp"

class Camera {
public:
    /** Default constructor.*/
    Camera();
    
    /** Default destructor.*/
    virtual ~Camera();
    
    /* 
    * Init camera atributs.
    * 
    * @param float x position
    *    float y position
    */
    void init(float x, float y);
    
    /* 
    * Init camera atributs.
    * 
    * @param Vector2f* position
    */
    void init(Vector2f* position);
    
    /** Position of camera.*/
    Vector2f* position;
    
    // Position of the Listener.
    ALfloat listenerPos[3];

    // Velocity of the Listener.
    ALfloat listenerVel[3];

    // Orientation of the Listener. (first 3 elements are "at", second 3 are "up")
    // Also note that these should be units of '1'.
    ALfloat listenerOri[6];
private:

};

#endif	/* CAMERA_HPP */

