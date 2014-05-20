#include "TileMapManager.hpp"
#include "StringSplit.hpp"
#include <fstream>
#include <stdlib.h>

TileMapManager::TileMapManager(){

}

TileMapManager::~TileMapManager(){

}

TileMap* TileMapManager::load(const char* filePath, Texture* texture){
    TileMap* tileMap = new TileMap();
    tileMap->tileSet = texture;
    
    std::string line;
    std::vector<std::string> subString;
    
    std::ifstream file(filePath);
    
    if(!file)
        return NULL;
    
    while(std::getline(file, line)){
        if(line[0] == '#')
            continue;
        
        if(line[0] == ' ')
            continue;
        
        if(line[0] == '['){
            if(line[1] == 'h'){
                TileMapManager::loadHeader(tileMap, file);
            }
            
            if(line[1] == 'l'){
                TileMapManager::loadLayer(tileMap, file);
            }
        }
        
    }
    
    file.close();
    
    return tileMap;
}

void TileMapManager::loadHeader(TileMap* tileMap, std::ifstream &file){
    std::string line;
    std::vector<std::string> subString;
    
    std::getline(file, line);
    subString = StringSplit::split(line, '=');
    tileMap->qtdX = atoi(subString[1].c_str());

    std::getline(file, line);
    subString = StringSplit::split(line, '=');
    tileMap->qtdY = atoi(subString[1].c_str());

    std::getline(file, line);
    subString = StringSplit::split(line, '=');
    tileMap->tileSizeX = atoi(subString[1].c_str());

    std::getline(file, line);
    subString = StringSplit::split(line, '=');
    tileMap->tileSizeY = atoi(subString[1].c_str());

    tileMap->init();
}

void TileMapManager::loadLayer(TileMap* tileMap, std::ifstream &file){
    std::string line;
    std::vector<std::string> subString;
    
    std::getline(file, line);
    std::getline(file, line);

    int** tempLayer = new int*[tileMap->qtdY];
    for(int i=0; i<tileMap->qtdY; i++){
        tempLayer[i] = new int[tileMap->qtdX];
        std::getline(file, line);
        subString = StringSplit::split(line, ',');

        for(int j=0; j<tileMap->qtdX; j++){
            int value = atoi(subString[j].c_str())-1;
            tempLayer[i][j] = value<0?0:value;
        }
    }


    tileMap->layers.push_back(tempLayer);
}