#include "TileMap.hpp"

TileMap::TileMap(){
    tileSet = NULL;
    qtdTiles = 0;
}

TileMap::~TileMap(){
    glDeleteBuffers(1, &indiceBuffer);
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteBuffers(1, &texCoordBuffer);
}

void TileMap::init(){
    this->width = this->tileSizeX*this->qtdX;
    this->height = this->tileSizeY*this->qtdY;
    
    this->qtdXTexture = this->tileSet->width/this->tileSizeX;
    this->qtdYTexture = this->tileSet->height/this->tileSizeY;
    
    this->tileSet->prop.x /= qtdXTexture;
    this->tileSet->prop.y /= qtdYTexture;
}

void TileMap::initBuffers(){
    GLuint indices[layers.size()*qtdX*qtdY*6]; //Indices buffer data, 6 == vertices for render 2 triangles
    VertexPos2f vertices[layers.size()*qtdX*qtdY*4]; //Vertex buffer data, 4 == vertices for quad
    TextureCoord texCoords[layers.size()*qtdX*qtdY*4]; //TexCoord buffer data, 4 == vertices for quad
    
    int vx;
    int vy;
    float tx;
    float ty;
    int offsetIndices; //Offset current indices group
    int offsetVertices; //Offset current vertices group
    
    for(int l=0; l<layers.size(); l++){
        for(int i=0; i<qtdY; i++){
            for(int j=0; j<qtdX; j++){
                if(layers[l][i][j] == 0)
                    continue;
                
                qtdTiles++;
                
                //Initializing vertices and textures
                    offsetVertices = 4*qtdTiles; //4 == vertices for quad

                    vx = j*tileSizeX;
                    vy = i*tileSizeY;
                    tx = layers[l][i][j]%qtdXTexture*tileSet->prop.x;
                    ty = layers[l][i][j]/qtdXTexture*tileSet->prop.y;

                    //Top-left
                    vertices[offsetVertices].x = vx;
                    vertices[offsetVertices].y = vy;
                    texCoords[offsetVertices].x = tx;
                    texCoords[offsetVertices].y = ty;

                    //Top-right
                    vertices[offsetVertices+1].x = vx + tileSizeX;
                    vertices[offsetVertices+1].y = vy;
                    texCoords[offsetVertices+1].x = tx + tileSet->prop.x;
                    texCoords[offsetVertices+1].y = ty;

                    //Bottom-left
                    vertices[offsetVertices+2].x = vx;
                    vertices[offsetVertices+2].y = vy + tileSizeY;
                    texCoords[offsetVertices+2].x = tx;
                    texCoords[offsetVertices+2].y = ty + tileSet->prop.y;

                    //Bottom-right
                    vertices[offsetVertices+3].x = vx + tileSizeX;
                    vertices[offsetVertices+3].y = vy + tileSizeY;
                    texCoords[offsetVertices+3].x = tx + tileSet->prop.x;
                    texCoords[offsetVertices+3].y = ty + tileSet->prop.y;

                //Initializing indices vertices
                    offsetIndices = 6*qtdTiles; //6 == vertices for render 2 triangles

                    //First triangle
                    indices[offsetIndices] = offsetVertices; //Top-left
                    indices[offsetIndices+1] = offsetVertices + 1; //Top-right
                    indices[offsetIndices+2] = offsetVertices + 2; //Bottom-left

                    //Second triangle
                    indices[offsetIndices+3] = offsetVertices + 2; //Bottom-left
                    indices[offsetIndices+4] = offsetVertices + 1; //Top-right
                    indices[offsetIndices+5] = offsetVertices + 3; //Bottom-right
            }
        }
    }
    
    //Create IBO
    glGenBuffers(1, &indiceBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indiceBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*6*qtdTiles, indices, GL_STATIC_DRAW);
    
    //Create TBO
    glGenBuffers(1, &texCoordBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, texCoordBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(TextureCoord)*4*qtdTiles, texCoords, GL_STATIC_DRAW);
    
    //Create VBO
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(VertexPos2f)*4*qtdTiles, vertices, GL_STATIC_DRAW);
    
    //Unbind buffers
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void TileMap::render(){
    // Save matrix
    glPushMatrix();
    
    //Set texture ID
    glBindTexture(GL_TEXTURE_2D, tileSet->id);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        //Set texture coordinate data
        glBindBuffer(GL_ARRAY_BUFFER, texCoordBuffer);
        glTexCoordPointer(2, GL_FLOAT, 0, NULL);

        //Set vertex data
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glVertexPointer(2, GL_FLOAT, 0, NULL);
        
        //Draw quad using vertex data and index data
        glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, indiceBuffer);
        glDrawElements( GL_TRIANGLES, 6*qtdTiles, GL_UNSIGNED_INT, NULL); //6 == Total vertices of two triangles
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    
    // Load previous matrix
    glPopMatrix();
}