#include "GamePanel.hpp"
#include "MenuScene.hpp"

GamePanel::GamePanel() {

}

GamePanel::~GamePanel() {
    
}

void GamePanel::init(){
    width = 800;
    height = 600;
    bbp = 16;
    
    currentScene = new MenuScene(*this);
    
    countTimer = 0;
    fps = 0;
    sfps = 0;
    
    initSDL();
    initOpenGL();
    
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

void GamePanel::initOpenGL(){
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClearDepth(1.f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    
    //Set View
    float ratio = ((float) width / (float) height);

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.f, ratio, .1f, 100.f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
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