#include "Graphics.h"

/// @brief 四角を描画
/// @param buffer 描画バッファ
/// @param screenW ウィンドウの横幅
/// @param screenH ウィンドウの縦幅
/// @param x 四角の横幅
/// @param y 四角の縦幅
/// @param size 大きさの倍率
/// @param color 色
void Graphics::DrawRect(Uint32* buffer, int screenW, int screenH, int x, int y, int size, Uint32 color) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int dx = x + i;
            int dy = y + j;
            if (dx >= 0 && dx < screenW && dy >= 0 && dy < screenH) {
                buffer[dy * screenW + dx] = color;
            }
        }
    }
}