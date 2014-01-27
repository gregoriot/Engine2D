#include "GamePanel.hpp"
#include "MenuScene.hpp"

GamePanel::GamePanel() {
    currentScene = NULL;
}

GamePanel::~GamePanel() {
    gl->~GL();
    al->~AL();
}

void GamePanel::init(){
    run = true;
    width = 800;
    height = 600;
    bbp = 16;
    
    countTimer = 0;
    fps = 0;
    sfps = 0;
    
    initSDL();
    gl = new GL();
    gl->initOpenGL(width, height);
    
    al = new AL();
    al->initOpenAL();
    
    currentScene = new MenuScene(this, gl, al);
    mainLoop();
}

void GamePanel::initSDL(){
    //Init all functions SDL.
    if(SDL_Init(SDL_INIT_EVERYTHING)<0)
        std::cout<<"ERROR LOAD SDL";
    
    flags = SDL_OPENGL;
    flags |= SDL_GL_DOUBLEBUFFER;
    flags |= SDL_HWPALETTE;
    flags |= SDL_RESIZABLE;
    flags |= SDL_SWSURFACE;
    
    const SDL_VideoInfo* videoInfo = SDL_GetVideoInfo();

	if (!videoInfo) ::exit(1);

	if (videoInfo->hw_available)
        flags |= SDL_HWSURFACE;
	else 
        flags |= SDL_SWSURFACE;

	if (videoInfo->blit_hw) 
        flags |= SDL_HWACCEL;
	
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    SDL_EnableKeyRepeat(10, 100);
    screen = SDL_SetVideoMode(width, height, bbp, flags);
}

void GamePanel::mainLoop(){
    SDL_Event events;
    currentScene->init();
    
    while (run) {
        lastTime = SDL_GetTicks();
             
        currentScene->input(events);
        currentScene->update(difTime);
        currentScene->render();
        
        currentTime = SDL_GetTicks();
        difTime = currentTime - lastTime;
        countTimer+= difTime;
        if(countTimer>1000){
            countTimer -= 1000;
            sfps = 0;
            fps = sfps;
        }else{
            sfps ++;
        }
    }
     
    SDL_FreeSurface(screen);
    SDL_Quit();
}