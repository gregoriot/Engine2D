#include "TileMap.hpp"
#include <istream>

#ifndef TILEMAPMANAGER_HPP
#define	TILEMAPMANAGER_HPP

class TileMapManager {
public:
    /** Default constructor.*/
    TileMapManager();
        
    /** Default destructor.*/
    virtual ~TileMapManager();
    
    static TileMap* load(const char* filePath, Texture* texture);
    
    static void loadHeader(TileMap* tileMap, std::ifstream &file);
    static void loadLayer(TileMap* tileMap, std::ifstream &file);
};

#endif	/* TILEMAPMANAGER_HPP */

