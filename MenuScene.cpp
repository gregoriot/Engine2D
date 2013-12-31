#include "MenuScene.hpp"
#include "Texture.hpp"

MenuScene::MenuScene(GamePanel& _parent) {
    parent = &_parent;
    
    character = new Character();
}

MenuScene::~MenuScene() {
    
}

void MenuScene::init(){
   character->init(0, 0, Texture::LOAD_BMP("back.bmp"));
}

void MenuScene::input(SDL_Event& e){
    while (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_QUIT:
                parent->run = false;
                break;
            case SDL_KEYDOWN:
                switch (e.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        parent->run = false;
                    default:
                        break;
                }
                break;
        }
    }
}

void MenuScene::update(long difTime){
    character->update(difTime);
}

void MenuScene::render(){
    //Clear color buffer
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, parent->width, parent->height, 0.0, -1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_CULL_FACE);
    glClear(GL_DEPTH_BUFFER_BIT);
    glColor3f(1.f, 1.f, 1.f);
        
    glEnable(GL_TEXTURE_2D);
    
    character->render();

    glDisable(GL_TEXTURE_2D);
    glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_MODELVIEW); 

    //Update screen
    SDL_GL_SwapBuffers();
}