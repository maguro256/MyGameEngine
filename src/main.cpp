#include <SDL2/SDL.h>
#include <iostream>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 360;

int main(int argc, char* argv[]) {
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return -1;
    }

    std::cout << "SDL Initialized successfully!" << std::endl;

    SDL_Window* window = SDL_CreateWindow(
        "My Engine - Low Level",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cout << "Failed to create window!" << std::endl;
        return -1;
    }

    // 3秒待ってから閉じる
    SDL_Delay(3000);

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}