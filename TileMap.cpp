#include "TileMap.hpp"
#include <iostream>

TileMap::TileMap(){
    
}

TileMap::~TileMap(){
    
}

void TileMap::init(){
    this->width = this->tileSizeX*this->qtdX;
    this->height = this->tileSizeY*this->qtdY;
    
    this->qtdXTexture = this->tileSet->width/this->tileSizeX;
    this->qtdYTexture = this->tileSet->height/this->tileSizeY;
    
    this->tileSet->propX /= qtdXTexture;
    this->tileSet->propY /= qtdYTexture;
}

void TileMap::render(){
    glBindTexture(GL_TEXTURE_2D, tileSet->id); //inicia o uso da texturo com o id gerado
    
    for(int i=0; i<qtdX; i++){
        for(int j=0; j<qtdY; j++){

            int dx = j*tileSizeX;
            int dy = i*tileSizeY;

            for (int l=0; l<layers.size(); l++) {
                if(layers[l][i][j] > 0){
                    float sx = tileSet->propX*(layers[l][i][j]%qtdXTexture);
                    float sy = tileSet->propY*(layers[l][i][j]/qtdYTexture);
                    
                    glBegin(GL_QUADS);
                        glTexCoord2f(sx, sy);
                        glVertex2f(dx, dy);

                        glTexCoord2f(sx+tileSet->propX, sy);
                        glVertex2f(dx+tileSizeX, dy);

                        glTexCoord2f(sx+tileSet->propX, sy+tileSet->propY);
                        glVertex2f(dx+tileSizeX, dy+tileSizeY);	 

                        glTexCoord2f(sx, sy+tileSet->propY);
                        glVertex2f(dx, dy+tileSizeY);
                    glEnd();
                }
            }
        }
    }
}