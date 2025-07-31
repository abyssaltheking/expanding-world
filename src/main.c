#include <SDL3/SDL.h>
#include "engine/window.h"

int main() {
    Window window = createWindow("hi", 800, 600);
    if (!validateWindow(window)) return -1;

    SDL_SetWindowSurfaceVSync(window.sdlWindow, 1);

    bool keepWindowOpen = true;

    while (keepWindowOpen) {
        if (windowQuit(window.event)) keepWindowOpen = false;

        SDL_SetRenderDrawColorFloat(window.renderer, 0.2f, 0.3f, 0.3f, 255);
        SDL_RenderClear(window.renderer);
        SDL_RenderPresent(window.renderer);
    }

    destroyWindow(window);
    return 0;
}