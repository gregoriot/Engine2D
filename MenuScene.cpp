#include "MenuScene.hpp"
#include "Texture.hpp"
#include "TextureLoader.hpp"

MenuScene::MenuScene(GamePanel& _parent) {
    parent = &_parent;
    
    character = new Character();
}

MenuScene::~MenuScene() {
    
}

void MenuScene::init(){
   font.init("Fonts/iwantv2.ttf", 80, FONT_TTF_UNDERLINE);
   
   character->init(0.f, 0.f, 2, 8, TextureLoader::PNG("Assets/youKnowHow.png"));
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
            character->x = e.button.x;
            character->y = e.button.y;
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
            ;
        }
        
        //Keyboard key down.
        if(e.type == SDL_KEYDOWN){
            switch (e.key.keysym.sym) {
                case SDLK_ESCAPE:
                    parent->run = false;
                    break;
                case SDLK_LEFT:
                    character->x -= 2;
                    break;
                case SDLK_RIGHT:
                    character->x += 2;
                    break;
                case SDLK_UP:
                    character->y -= 2;
                    break;
                case SDLK_DOWN:
                    character->y += 2;
                    break;
                default:
                    break;
            }
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
    
    //Disable depth.
    glDisable(GL_CULL_FACE);
    glClear(GL_DEPTH_BUFFER_BIT);
        
    //Enable transparency and translucency.
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor3f(0.2f,1,0.7f);
    glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(800, 0);
        glVertex2f(800, 600);	 
        glVertex2f(0,600);
    glEnd();
    glColor4f(1,1,1,1);
    
    glEnable(GL_TEXTURE_2D);
    character->render();
    
    font.setColor(1,0,0,1);
    font.render("texto", 300, 300);
    glDisable(GL_TEXTURE_2D);
    
    
    glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_MODELVIEW); 

    //Update screen
    SDL_GL_SwapBuffers();
}