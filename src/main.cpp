#include <SDL2/SDL.h>
#include <iostream>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 360;

struct Player{
    float x,y;
    int size;
    Uint32 color;
};

void draw_rect(Uint32* buffer, int screen_width, int screen_height, int x, int y, int size, Uint32 color){
    for(int i = 0;i < size;i++){
        for(int j = 0;j < size;j++){
            int draw_x = x+1;
            int draw_y = y+j;

            if(draw_x >= 0 && draw_x < screen_width && draw_y >= 0 && draw_y < screen_height ){
                int index = draw_y * screen_width + draw_x;
                buffer[index] = color;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    // SDL初期化
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return -1;

    SDL_Window* window = SDL_CreateWindow("My Engine - Input Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WINDOW_WIDTH, WINDOW_HEIGHT);
    
    // バッファ確保
    Uint32* buffer = new Uint32[WINDOW_WIDTH * WINDOW_HEIGHT];

    Player player;
    player.x = 100;
    player.y = 100;
    player.size = 30;
    player.color = 0xFF00FF00; // 緑

    bool isRunning = true;
    SDL_Event event;

    while (isRunning) {
        // --- A. イベント処理 ---
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) isRunning = false;
        }

        // --- B. 入力と更新 (Input & Update) ---
        
        // 【3】 キーボードの状態配列へのポインタを取得
        // OSが管理している「今どのキーが押されているかリスト」の先頭アドレスをもらう
        const Uint8* keyState = SDL_GetKeyboardState(NULL);

        // 配列の中身をチェック (1なら押されている)
        // SDL_SCANCODE_RIGHT などは配列のインデックス（番号）
        if (keyState[SDL_SCANCODE_RIGHT]) {
            player.x += 2.0f; // 右へ
        }
        if (keyState[SDL_SCANCODE_LEFT]) {
            player.x -= 2.0f; // 左へ
        }
        if (keyState[SDL_SCANCODE_UP]) {
            player.y -= 2.0f; // 上へ (Y座標は上が0)
        }
        if (keyState[SDL_SCANCODE_DOWN]) {
            player.y += 2.0f; // 下へ
        }

        // 1. 画面をリセット（背景を黒で塗りつぶす）
        for (int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; ++i) buffer[i] = 0xFF000000;

        // 2. プレイヤーを描画
        // float座標をintにキャストして渡す
        draw_rect(buffer, WINDOW_WIDTH, WINDOW_HEIGHT,(int)player.x, (int)player.y, player.size, player.color);

        // 3. GPUへ転送して表示
        SDL_UpdateTexture(texture, NULL, buffer, WINDOW_WIDTH * sizeof(Uint32));
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    delete[] buffer;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}