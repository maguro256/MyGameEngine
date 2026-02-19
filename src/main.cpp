#include "Engine.h"
#include "UserGame.h"

int main(int argc, char* argv[]) {
    MyEngine engine(640, 360);
    if (!engine.Init("Multi-File Engine Test")) return -1;
    
    MyShootingGame game;
    engine.Run(&game);
    
    return 0;
}