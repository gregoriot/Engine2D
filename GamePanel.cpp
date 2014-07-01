#include "GamePanel.hpp"
#include "MenuScene.hpp"

GamePanel::GamePanel() {
    //Init objects as NULL
    currentScene = NULL;
    screen = NULL;
    al = NULL;
    gl = NULL;
    
    //Init timers as ZERO
    countTimer = 0;
    fps = 0;
    sfps = 0;
}

GamePanel::~GamePanel() {
    gl->~GL();
    al->~AL();
}

void GamePanel::init(int _width, int _height, int _bbp){
    //Init display screen information
    width = _width;
    height = _height;
    bbp = _bbp;
    
    //Create window and init
    initSDL();
    
    //Enable videoBoard functions
    glewInit();
    
    //Init draw screen
    gl = new GL();
    gl->initOpenGL(width, height);
    
    //Init sound system
    al = new AL();
    al->initOpenAL();
    
    //Set initial scene
    currentScene = new MenuScene(this, gl, al);
    
    //Start game
    mainLoop();
}

void GamePanel::initSDL(){
    //Init all functions SDL.
    if(SDL_Init(SDL_INIT_EVERYTHING)<0)
        std::cout<<"ERROR LOAD SDL";
    
    //Init window informations
    flags = SDL_OPENGL;
    flags |= SDL_GL_DOUBLEBUFFER;
    flags |= SDL_HWPALETTE;
    flags |= SDL_RESIZABLE;
    flags |= SDL_SWSURFACE;
    
    //Capture video informations and save informations
    const SDL_VideoInfo* videoInfo = SDL_GetVideoInfo();

	if (!videoInfo) ::exit(1);

	if (videoInfo->hw_available)
        flags |= SDL_HWSURFACE;
	else 
        flags |= SDL_SWSURFACE;

	if (videoInfo->blit_hw) 
        flags |= SDL_HWACCEL;
	
        //Enable double buffer render
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    //Configure keyboard timer
    SDL_EnableKeyRepeat(10, 100);
    
    //Create the window with render options
    screen = SDL_SetVideoMode(width, height, bbp, flags);
}

void GamePanel::mainLoop(){
    //Enable game loop
    run = true;
    
    //Init default game events
    SDL_Event events;
    
    //Init current scene
    currentScene->init();
    
    //Start of game loop
    while (run) {
        lastTime = SDL_GetTicks();
        
        // Update scenes.
        updateScene(events);
        
        // Render scenes.
        renderScene();
        
        currentTime = SDL_GetTicks();
        difTime = currentTime - lastTime;
        countTimer+= difTime;
        
        //Check if passed one second
        if(countTimer>1000){
            countTimer -= 1000;
            fps = sfps;
            sfps = 0;
        }else{
            sfps ++;
        }
    }
    
    //Disables window and close it
    SDL_FreeSurface(screen);
    SDL_Quit();
}

void GamePanel::updateScene(SDL_Event& events){
    // Update input.
    currentScene->input(events);
    
    // Update data
    currentScene->update(difTime);
}

void GamePanel::renderScene(){
    // Clear color buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Reset view matrix
    glLoadIdentity();
    
    // Render scene
    currentScene->render();
    
    // Swap the OpenGL buffers, if double-buffering is supported.
    SDL_GL_SwapBuffers();
}