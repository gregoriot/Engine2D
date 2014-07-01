/* 
 * File:   TileMap.hpp
 * Author: gustavo
 *
 * Created on May 12, 2014, 10:14 PM
 */

#ifndef TILEMAP_HPP
#define	TILEMAP_HPP

#include <GL/glew.h>
#include <vector>
#include "Texture.hpp"
#include "VertexPos2f.h"

class TileMap {
public:
    /* Buffers */
    GLuint indiceBuffer;
    GLuint vertexBuffer;
    GLuint texCoordBuffer;
    int qtdTiles;

    /* Texture group */
    Texture* tileSet;
    int qtdXTexture;
    int qtdYTexture;

    /* Tile group*/
    std::vector <int**> layers;
    int tileSizeX;
    int tileSizeY;
    int qtdX;
    int qtdY;

    /* TileMap size in pixels */
    int width;
    int height;

    /** Default constructor.*/
    TileMap();

    /** Default destructor.*/
    virtual ~TileMap();

    /* */
    void init();

    /** */
    void initBuffers();

    void render();
    
private:
    
};

#endif	/* TILEMAP_HPP */