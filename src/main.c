#include <SDL3/SDL.h>
#include <stdio.h>
#include "engine.h"

int main() {
    Window window = createWindow("hi", 1280, 720);
    if (!validateWindow(window)) return -1;

    SDL_SetRenderVSync(window.renderer, 1);

    Sprite sprite = createSprite(window.renderer, "assets/player.png", 50, 50);
    setSpriteScaleMode(sprite, "nearest");

    bool keepWindowOpen = true;
    float color = 0.09f;

    while (keepWindowOpen) {
        getInput(window.event);
        if (windowQuit(window.event) || isKeyDown(SDL_SCANCODE_ESCAPE)) keepWindowOpen = false;
        SDL_FRect spriteRect = spriteToFRect(sprite);

        if (isKeyDown(SDL_SCANCODE_D)) sprite.x += 3;
        if (isKeyDown(SDL_SCANCODE_A)) sprite.x -= 3;
        if (isKeyDown(SDL_SCANCODE_W)) sprite.y -= 3;
        if (isKeyDown(SDL_SCANCODE_S)) sprite.y += 3;

        SDL_SetRenderDrawColorFloat(window.renderer, color, color, color, 1);
        SDL_RenderClear(window.renderer);
        SDL_RenderTexture(window.renderer, sprite.texture, NULL, &spriteRect);
        SDL_RenderPresent(window.renderer);
    }

    destroySprite(sprite);
    destroyWindow(window);
    return 0;
}