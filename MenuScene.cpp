#include "MenuScene.hpp"

MenuScene::MenuScene(GamePanel* _parent, GL* _gl, AL* _al) {
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

MenuScene::~MenuScene() {
    gl->endRender2D();
    gl->disableTexture2D();
}

void MenuScene::init(){
    font = Font_ttf();
    font.init("Fonts/iwantv2.ttf", 36, FONT_TTF_NORMAL);
    mainMenuTex = TextureLoad::JPG("Assets/main_menu.jpg");
}
    
void MenuScene::input(SDL_Event& e){
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
                if(Collision::boundingBox(width*0.09f, height*0.15f, width*0.32f, height*0.25f, e.button.x, e.button.y, 1, 1)){
                    parent->currentScene = new GamePlay(parent, gl, al);
                    parent->currentScene->init();                
                }
                if(Collision::boundingBox(width*0.09f, height*0.8f, width*0.32f, height*0.9f, e.button.x, e.button.y, 1, 1))
                    parent->run = false;
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

void MenuScene::update(long difTime){

}

void MenuScene::render(){
    gl->render2D(mainMenuTex, 0, 0, width, height);
    
    font.color = new Color(1,0,0,1);
    font.render("Start", width * 0.14f, height *0.17f);
    font.render("Exit", width * 0.14f, height *0.825f);
}