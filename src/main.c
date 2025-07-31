#include <SDL3/SDL.h>
#include <stdio.h>
#include "engine/window.h"
#include "engine/input.h"

int main() {
    Window window = createWindow("hi", 800, 600);
    if (!validateWindow(window)) return -1;

    SDL_SetWindowSurfaceVSync(window.sdlWindow, 1);

    bool keepWindowOpen = true;
    float color = 1;
    float colorChange = 0.01;

    while (keepWindowOpen) {
        getInput(window.event);
        if (windowQuit(window.event) || isKeyDown(SDL_SCANCODE_ESCAPE)) keepWindowOpen = false;

        if (isKeyDown(SDL_SCANCODE_SPACE)) color -= colorChange;
        
        if (color < 0 || color > 1) {
            colorChange *= -1;
        }
        printf("%f\n", color);

        SDL_SetRenderDrawColorFloat(window.renderer, color, color, color, 1);
        SDL_RenderClear(window.renderer);
        SDL_RenderPresent(window.renderer);
    }

    destroyWindow(window);
    return 0;
}