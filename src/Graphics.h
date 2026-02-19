#pragma once 
#include <SDL2/SDL.h>

class Graphics {
public:
    static void DrawRect(Uint32* buffer, int screenW, int screenH, int x, int y, int size, Uint32 color);
};