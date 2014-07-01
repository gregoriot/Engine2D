#include "GL.hpp"

GL::GL() {
    
}

GL::~GL() {
    
}


void GL::initOpenGL(int _width, int _height){
    width = _width;
    height = _height;
    ratio = ((float) width / (float) height);
    
    //Init Projection Matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.0, 10.0);

    //Init ModelView Matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Init clear color
    glClearColor(0.f, 0.f, 0.f, 0.f);
}

void GL::beginRender2D(){
    
}

void GL::endRender2D(){
    
}

void GL::enableTexture2D(){
    //Enable transparency and translucency.
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glEnable(GL_TEXTURE_2D);
}

void GL::disableTexture2D(){
    glDisable(GL_BLEND);
    
    glDisable(GL_TEXTURE_2D);
}

void GL::render2D(Texture* texture, float x1, float y1, float x2, float y2){
    glBindTexture(GL_TEXTURE_2D, texture->id);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex2f(x1, y1);
        glTexCoord2f(1, 0); glVertex2f(x2, y1);
        glTexCoord2f(1, 1); glVertex2f(x2, y2);	 
        glTexCoord2f(0, 1); glVertex2f(x1,y2);
    glEnd();
}

void GL::render2D(Texture* texture, float srcX1, float srcY1, float srcX2, float srcY2, float dstX1, float dstY1, float dstX2, float dstY2){
    float texCoordX1 = srcX1/texture->width;
    float texCoordX2 = srcX2/texture->width;
    float texCoordY1 = srcY1/texture->height;
    float texCoordY2 = srcY2/texture->height;
    
    glBindTexture(GL_TEXTURE_2D, texture->id);
    glBegin(GL_QUADS);
        glTexCoord2f(texCoordX1, texCoordY1); glVertex2f(dstX1, dstY1);
        glTexCoord2f(texCoordX2, texCoordY1); glVertex2f(dstX2, dstY1);
        glTexCoord2f(texCoordX2, texCoordY2); glVertex2f(dstX2, dstY2);	 
        glTexCoord2f(texCoordX1, texCoordY2); glVertex2f(dstX1,dstY2);
    glEnd();
}

void GL::render2D(Texture* texture, float x1, float y1, float x2, float y2, bool flipX, bool flipY){
    float texCoordX1 = flipX?1:0;
    float texCoordX2 = flipX?0:1;
    float texCoordY1 = flipY?1:0;
    float texCoordY2 = flipY?0:1;
    
    glBindTexture(GL_TEXTURE_2D, texture->id);
    glBegin(GL_QUADS);
        glTexCoord2f(texCoordX1, texCoordY1); glVertex2f(x1, y1);
        glTexCoord2f(texCoordX2, texCoordY1); glVertex2f(x2, y1);
        glTexCoord2f(texCoordX2, texCoordY2); glVertex2f(x2, y2);	 
        glTexCoord2f(texCoordX1, texCoordY2); glVertex2f(x1,y2);
    glEnd();
}

void GL::render2D(Texture* texture, float srcX1, float srcY1, float srcX2, float srcY2, float dstX1, float dstY1, float dstX2, float dstY2, bool flipX, bool flipY){
    float texCoordX1 = srcX1/texture->width;
    float texCoordX2 = srcX2/texture->width;
    float texCoordY1 = srcY1/texture->height;
    float texCoordY2 = srcY2/texture->height;
    
    glBindTexture(GL_TEXTURE_2D, texture->id);
    glBegin(GL_QUADS);
        glTexCoord2f(texCoordX1, texCoordY1); glVertex2f(dstX1, dstY1);
        glTexCoord2f(texCoordX2, texCoordY1); glVertex2f(dstX2, dstY1);
        glTexCoord2f(texCoordX2, texCoordY2); glVertex2f(dstX2, dstY2);	 
        glTexCoord2f(texCoordX1, texCoordY2); glVertex2f(dstX1,dstY2);
    glEnd();
}