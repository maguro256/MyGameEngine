#include "UserGame.h"
#include "Graphics.h" // 道具箱を使う
#include <iostream>

void MyShootingGame::OnStart() {
    x = 100; y = 100;
    std::cout << "Game Started in Separate Files!" << std::endl;
}

void MyShootingGame::OnUpdate(const Uint8* keyState) {
    if (keyState[SDL_SCANCODE_RIGHT]) x += 5.0f;
    if (keyState[SDL_SCANCODE_LEFT])  x -= 5.0f;
    if (keyState[SDL_SCANCODE_DOWN])  y += 5.0f;
    if (keyState[SDL_SCANCODE_UP])    y -= 5.0f;
}

void MyShootingGame::OnDraw(Uint32* buffer, int w, int h) {
    Graphics::DrawRect(buffer, w, h, (int)x, (int)y, 30, 0xFF00FF00);
}