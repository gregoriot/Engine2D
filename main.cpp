/* 
 * File:   main.cpp
 * Author: Gilvanei Gregório
 *
 * Created on 11 de Dezembro de 2013, 09:24
 * 
 * Main.
 */

#include "GamePanel.hpp"

int main() {
    
    //Create and init game system
    GamePanel gamePanel;
    gamePanel.init(800, 600, 16);
    
    return 0;
}

