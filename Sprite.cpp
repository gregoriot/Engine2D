/* 
 * File:   Sprite.cpp
 * Author: gustavo
 * 
 * Created on May 27, 2014, 11:44 PM
 */

#include "Sprite.hpp"

Sprite::Sprite() {
    texture = NULL;
}

Sprite::~Sprite() {
    glDeleteBuffers(1, &indiceBuffer);
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteBuffers(1, &texCoordBuffer);
}

void Sprite::init(float x, float y, Texture* _texture){
    position.x = x;
    position.y = y;
    texture = _texture;
}

void Sprite::initBuffers() {
    GLuint indices[6]; //Indices buffer data, 6 == vertices for render 2 triangles
    VertexPos2f vertices[4]; //Vertex buffer data, 4 == vertices for quad
    TextureCoord texCoords[4]; //TexCoord buffer data, 4 == vertices for quad
    
    //Initializing indices vertices
        //First triangle
        indices[0] = 0; //Top-left
        indices[1] = 1; //Top-right
        indices[2] = 2; //Bottom-left
        
        //Second triangle
        indices[3] = 2; //Bottom-left
        indices[4] = 1; //Top-right
        indices[5] = 3; //Bottom-right
    
    //Initializing vertices and textures
        //Top-left
        vertices[0].x = 0;
        vertices[0].y= 0;
        texCoords[0].x = 0;
        texCoords[0].y= 0;
        
        //Top-right
        vertices[1].x = texture->width;
        vertices[1].y= 0;
        texCoords[1].x = texture->prop.x;
        texCoords[1].y= 0;
        
        //Bottom-left
        vertices[2].x = 0;
        vertices[2].y= texture->height;
        texCoords[2].x = 0;
        texCoords[2].y= texture->prop.y;
        
        //Bottom-right
        vertices[3].x = texture->width;
        vertices[3].y= texture->height;
        texCoords[3].x = texture->prop.x;
        texCoords[3].y= texture->prop.y;
    
    //Create IBO
    glGenBuffers(1, &indiceBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indiceBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    //Create TBO
    glGenBuffers(1, &texCoordBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, texCoordBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);
    
    //Create VBO
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    //Unbind buffers
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Sprite::render(){
    // Save matrix
    glPushMatrix();
    
    // Move to object position
    glTranslatef(position.x, position.y, 0);
    
    //Set texture ID
    glBindTexture(GL_TEXTURE_2D, texture->id);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        //Set texture coordinate data
        glBindBuffer(GL_ARRAY_BUFFER, texCoordBuffer);
        glTexCoordPointer(2, GL_FLOAT, 0, NULL);

        //Set vertex data
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glVertexPointer(2, GL_FLOAT, 0, NULL);
        
        //Draw quad using buffers and indices
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indiceBuffer);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    
    //Load previous matrix
    glPopMatrix();
}