#pragma once
#include <SDL2/SDL.h>

class IGameApp {
public:
    virtual void OnStart() = 0;
    virtual void OnUpdate(const Uint8* keyState) = 0;
    virtual void OnDraw(Uint32* buffer, int width, int height) = 0;
    virtual ~IGameApp() {}
};