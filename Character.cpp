#include "Character.hpp"

Character::Character() {
    texture = NULL;
    sound = NULL;
    al = NULL;
}

Character::~Character() {
    glDeleteBuffers(1, &indiceBuffer);
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteBuffers(1, &texCoordBuffer);
}

void Character::init(float x, float y, int _numberAnimations, int _numberFrames, Texture* _texture, AL* _al){
    position.x = x;
    position.y = y;
    
    currentFrame = 0;
    numberFrames = _numberFrames;
    frameTimer = 0;
    timeBetweenFrames = 60;

    currentAnimation = 0;
    numberAnimations = _numberAnimations;
    
    texture = _texture;
        
    texture->width  /= numberFrames;
    texture->height /= numberAnimations;
    
    texture->prop.x /= numberFrames;
    texture->prop.y /= numberAnimations;
    
    al = _al;
    sound = SoundLoad::WAV("Assets/test.wav");
    
    active = true;
    
    initBuffers();
}

void Character::initBuffers(){
    GLuint indices[6]; //Indices buffer data, 6 == vertices for render 2 triangles
    VertexPos2f vertices[4]; //Vertex buffer data, 4 == vertices for quad
    TextureCoord texCoords[4*numberAnimations*numberFrames]; //TexCoord buffer data, 4 == vertices for quad
    
    //Initializing indices vertices
        //First triangle
        indices[0] = 0; //Top-left
        indices[1] = 1; //Top-right
        indices[2] = 2; //Bottom-left
        
        //Second triangle
        indices[3] = 2; //Bottom-left
        indices[4] = 1; //Top-right
        indices[5] = 3; //Bottom-right
    
    //Initializing vertices
        //Top-left
        vertices[0].x = 0;
        vertices[0].y= 0;
        
        //Top-right
        vertices[1].x = texture->width;
        vertices[1].y= 0;
        
        //Bottom-left
        vertices[2].x = 0;
        vertices[2].y= texture->height;
        
        //Bottom-right
        vertices[3].x = texture->width;
        vertices[3].y= texture->height;
    
    int offset = 0; //Offset current texCoords group
    for(int i=0; i<numberAnimations; i++){
        for(int j=0; j<numberFrames; j++){
            offset = 4*(i*numberFrames+j); //4 == vertices for quad
            
            //Top-left
            texCoords[offset].x = j*texture->prop.x;
            texCoords[offset].y = i*texture->prop.y;

            //Top-right
            texCoords[offset+1].x = j*texture->prop.x + texture->prop.x;
            texCoords[offset+1].y = i*texture->prop.y;
            
            //Bottom-left
            texCoords[offset+2].x = j*texture->prop.x;
            texCoords[offset+2].y = i*texture->prop.y + texture->prop.y;

            //Bottom-right
            texCoords[offset+3].x = j*texture->prop.x + texture->prop.x;
            texCoords[offset+3].y = i*texture->prop.y + texture->prop.y;
        }
    }
    
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

void Character::update(long difTime){
     frameTimer += difTime;
     currentFrame = (frameTimer/timeBetweenFrames)%numberFrames;
//     alSourcePlay(sound->source);
}

void Character::render(){
    // Save matrix
    glPushMatrix();
    
    // Move to object position
    glTranslatef(position.x, position.y, 0);
    
    //Set texture ID
    glBindTexture(GL_TEXTURE_2D, texture->id);
    
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
        //Set vertex data
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glVertexPointer(2, GL_FLOAT, 0, NULL);
    
        //Set texture coordinate data
        glBindBuffer(GL_ARRAY_BUFFER, texCoordBuffer);
        glTexCoordPointer(2, GL_FLOAT, 0,
                (GLvoid*)((currentAnimation*numberFrames+currentFrame)*4*sizeof(TextureCoord))); //4 == vertices for quad
        
        //Draw quad using vertex data and index data
        glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, indiceBuffer);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); //6 == Total vertices of two triangles
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    
    // Load previous matrix
    glPopMatrix();
}