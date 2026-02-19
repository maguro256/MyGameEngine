#include "Engine.h"
#include <cstring> // memset用

MyEngine::MyEngine(int w, int h) : width(w), height(h), window(nullptr), renderer(nullptr), texture(nullptr), buffer(nullptr), isRunning(false) {}

MyEngine::~MyEngine() {
    if (buffer) delete[] buffer;
    if (texture) SDL_DestroyTexture(texture);
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
}

bool MyEngine::Init(const char* title) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return false;
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!window) return false;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height);
    buffer = new Uint32[width * height];
    return true;
}

void MyEngine::Run(IGameApp* app) {
    isRunning = true;
    SDL_Event event;

    app->OnStart();

    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) isRunning = false;
        }

        const Uint8* keyState = SDL_GetKeyboardState(NULL);
        app->OnUpdate(keyState);

        memset(buffer, 0, width * height * sizeof(Uint32)); // 画面クリア
        app->OnDraw(buffer, width, height);

        SDL_UpdateTexture(texture, NULL, buffer, width * sizeof(Uint32));
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
}