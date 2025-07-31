#include <SDL3/SDL.h>
#include "input.h"

bool downKeys[SDL_SCANCODE_COUNT];

void getInput(SDL_Event event) {
    SDL_PollEvent(&event);

    if (event.type == SDL_EVENT_KEY_DOWN) {
        downKeys[event.key.scancode] = true;
    }

    if (event.type == SDL_EVENT_KEY_UP) {
        downKeys[event.key.scancode] = false;
    }
}

bool isKeyDown(SDL_Scancode scancode) {
    return downKeys[scancode];
}
