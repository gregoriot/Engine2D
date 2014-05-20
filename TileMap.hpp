#include "Texture.hpp"
#include <vector>

/* 
 * File:   TileMap.hpp
 * Author: gustavo
 *
 * Created on May 12, 2014, 10:14 PM
 */

#ifndef TILEMAP_HPP
#define	TILEMAP_HPP

class TileMap {
    public:
        
        /* Texture group */
        Texture* tileSet;
        unsigned int qtdXTexture;
        unsigned int qtdYTexture;
        
        /* Tile group*/
        std::vector <int**> layers;
        unsigned int tileSizeX;
        unsigned int tileSizeY;
        unsigned int qtdX;
        unsigned int qtdY;
        
        /* */
        unsigned int width;
        unsigned int height;
        
        /* */
        unsigned int bufferId;
        
        /** Default constructor.*/
        TileMap();

        /** Default destructor.*/
        virtual ~TileMap();
        
        /* */
        void init();
        
        void render();
        
    private:
};

#endif	/* TILEMAP_HPP */