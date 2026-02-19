#pragma once
#include <SDL2/SDL.h>
#include "IGameApp.h"

class MyEngine {
private:
    int width, height;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    Uint32* buffer;
    bool isRunning;

public:
    MyEngine(int w, int h);
    ~MyEngine();
    
    bool Init(const char* title);
    void Run(IGameApp* app);
};