#include "GamePlay.hpp"

GamePlay::GamePlay(GamePanel* _parent, GL* _gl, AL* _al) {
    parent = _parent;
    gl = _gl;
    al =_al;
    
    width = parent->width;
    height = parent->height;
    
    camera = new Camera();
    camera->init(0,0);
    
    gl->beginRender2D();
    gl->enableTexture2D();
}

GamePlay::~GamePlay() {
    gl->endRender2D();
    gl->disableTexture2D();
}

void GamePlay::init(){
    sprite = new Sprite();
    sprite->init(200, 200, TextureLoad::PNG("Assets/tileset.png"));
    sprite->initBuffers();
    
    character = new Character();
    character->init(200, 200, 2, 8, TextureLoad::PNG("Assets/youKnowHow.png"), al);
    font.init("Fonts/iwantv2.ttf", 36, FONT_TTF_NORMAL);
   
    Tiled* tiled = new Tiled();
    tiled->load("Assets/tilemap.txt", TextureLoad::PNG("Assets/tileset.png"));
    tileMap = tiled->tileMap;
    tileMap->initBuffers();
}

void GamePlay::input(SDL_Event& e){
    while (SDL_PollEvent(&e)) {
        //Windowns Close Button.
        if(e.type == SDL_QUIT){
            parent->run = false;
            break;
        }

        //Mouse motion.
        if(e.type == SDL_MOUSEMOTION ) {
            character->position.x = e.button.x;
            character->position.y = e.button.y;
        }
        
        //Mouse button was pressed.
        if(e.type == SDL_MOUSEBUTTONDOWN ){
            //Left mouse button was pressed.
            if(e.button.button == SDL_BUTTON_LEFT ){
                ;
            }
        }
        
        //Mouse button was release.
        if(e.type == SDL_MOUSEBUTTONUP){
            if(e.button.button == SDL_BUTTON_LEFT ){
                ;
            }
        }
        
        //Keyboard key down.
        if(e.type == SDL_KEYDOWN){
            switch (e.key.keysym.sym) {
                case SDLK_ESCAPE:
                    parent->run = false;
                    break;
                case SDLK_LEFT:
                    character->currentAnimation = 1;
                    break;
                case SDLK_RIGHT:
                    character->currentAnimation = 0;
                    break;
                case SDLK_UP:
                    break;
                case SDLK_DOWN:
                    break;
                default:
                    break;
            }
        }
    }
}

void GamePlay::update(long difTime){
    character->update(difTime);
}

void GamePlay::render(){
    tileMap->render();
    
//    sprite->render();
    
    character->render();
    
    char buff[10];
    sprintf(buff, "%d", parent->fps);
    font.color = new Color(1,0,0,1);
    font.render(buff, width * 0.14f, height *0.17f);
}

