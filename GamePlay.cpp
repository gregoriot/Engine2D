#include "GamePlay.hpp"

GamePlay::GamePlay(GamePanel* _parent, GL* _gl, AL* _al) {
    parent = _parent;
    gl = _gl;
    al =_al;
    
    width = parent->width;
    height = parent->height;
    
    camera = new Camera();
    camera->init(0,0);
}

GamePlay::~GamePlay() {
    
}

void GamePlay::init(){
   character = new Character();
   character->init(0,0, 2, 8, ResourceLoader::PNG("Assets/youKnowHow.png"), gl, al);
   font.init("Fonts/iwantv2.ttf", 36, FONT_TTF_NORMAL);
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
//            character->x = e.button.x;
//            character->y = e.button.y;
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
                    break;
                case SDLK_RIGHT:
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
    gl->beginRender2D();
    gl->enableTexture2D();
    
    character->render();
    
    font.color = new Color(1,0,0,1);
    font.render("jhk", width * 0.14f, height *0.17f);

    gl->disableTexture2D();
    gl->endRender2D();

    //Update screen
    SDL_GL_SwapBuffers();
}

