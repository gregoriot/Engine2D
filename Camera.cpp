#include "Camera.hpp"

Camera::Camera() {
    
}

Camera::~Camera() {
    
}

void Camera::init(float x, float y){
    position = new Vector2f(x, y);
    
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
    
void Camera::init(Vector2f* _position){
    position = new Vector2f(*_position);
    
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