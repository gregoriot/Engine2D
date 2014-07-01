#include "Tiled.hpp"

Tiled::Tiled(){

}

Tiled::~Tiled(){

}

bool Tiled::load(const char* filePath, Texture* texture){
    tileMap = new TileMap();
    tileMap->tileSet = texture;
    
    tiledFile.open(filePath);
    
    if(!tiledFile)
        return false;
    
    while(std::getline(tiledFile, line)){
        if(line[0] == '#')
            continue;
        
        if(line[0] == ' ')
            continue;
        
        if(line[0] == '['){
            if(line[1] == 'h'){
                Tiled::loadHeader();
            }
            
            if(line[1] == 'l'){
                Tiled::loadLayer();
            }
        }
        
    }
    
    tiledFile.close();
    return true;
}

void Tiled::loadHeader(){
    std::getline(tiledFile, line);
    subString = StringSplit::split(line, '=');
    tileMap->qtdX = atoi(subString[1].c_str());

    std::getline(tiledFile, line);
    subString = StringSplit::split(line, '=');
    tileMap->qtdY = atoi(subString[1].c_str());

    std::getline(tiledFile, line);
    subString = StringSplit::split(line, '=');
    tileMap->tileSizeX = atoi(subString[1].c_str());

    std::getline(tiledFile, line);
    subString = StringSplit::split(line, '=');
    tileMap->tileSizeY = atoi(subString[1].c_str());

    tileMap->init();
}

void Tiled::loadLayer(){
    std::getline(tiledFile, line);
    std::getline(tiledFile, line);

    int** tempLayer = new int*[tileMap->qtdY];
    for(int i=0; i<tileMap->qtdY; i++){
        tempLayer[i] = new int[tileMap->qtdX];
        std::getline(tiledFile, line);
        subString = StringSplit::split(line, ',');

        for(int j=0; j<tileMap->qtdX; j++){
            int value = atoi(subString[j].c_str())-1;
            tempLayer[i][j] = value<0?0:value;
        }
    }


    tileMap->layers.push_back(tempLayer);
}