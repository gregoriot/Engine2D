#ifndef TILED_HPP
#define	TILED_HPP

#include <fstream>
#include <istream>
#include <stdlib.h>
#include "StringSplit.hpp"
#include "TileMap.hpp"

class Tiled {
public:
    /**Default constructor.*/
    Tiled();
        
    /**Default destructor.*/
    virtual ~Tiled();
    
    /**Load tiled map from file .txt.*/
    bool load(const char* filePath, Texture* texture);
    
    /**TileMap instance.*/
    TileMap* tileMap;
    
    /**TileMap file.*/
    std::ifstream tiledFile;
    
    /**Current line.*/
    std::string line;
    
    /**Current subString of line.*/
    std::vector<std::string> subString;
private:
    /**Load only the header from file .txt.*/
    void loadHeader();
    
    /**Load only the layers from file .txt.*/
    void loadLayer();
};

#endif	/* TILED_HPP */

