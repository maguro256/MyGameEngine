#pragma once
#include "IGameApp.h"

class MyShootingGame : public IGameApp {
    float x, y;
public:
    void OnStart() override;
    void OnUpdate(const Uint8* keyState) override;
    void OnDraw(Uint32* buffer, int w, int h) override;
};