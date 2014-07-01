#include "Camera.hpp"

Camera::Camera() {
    position = new VertexPos2f();
}

Camera::~Camera() {
    
}

void Camera::init(float x, float y){
    position->x = x;
    position->y = y;
    
    listenerPos[0] = 0.0;
    listenerPos[1] = 0.0;
    listenerPos[2] = 0.0;

    listenerVel[0] = 0.0;
    listenerVel[1] = 0.0;
    listenerVel[2] = 0.0;

    listenerOri[0] = 0.0;
    listenerOri[1] = 0.0;
    listenerOri[2] = -1.0;
    listenerOri[3] = 0.0;
    listenerOri[4] = 1.0;
    listenerOri[5] = 0.0;
    
    alListenerfv(AL_POSITION,    listenerPos);
    alListenerfv(AL_VELOCITY,    listenerVel);
    alListenerfv(AL_ORIENTATION, listenerOri);
}
    
void Camera::init(VertexPos2f* position){
    init(position->x, position->y);
}