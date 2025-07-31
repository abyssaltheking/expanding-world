#include <SDL3/SDL.h>
#include <stdio.h>
#include "window.h"

Window createWindow(char* title, unsigned int width, unsigned int height) {
    Window window;
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* sdlWindow = SDL_CreateWindow(title, width, height, 0);
    if (sdlWindow == NULL) {
        printf("ERROR: couldn't create window: %s", SDL_GetError());
        SDL_Quit();
    }
    window.sdlWindow = sdlWindow;

    SDL_Renderer* renderer = SDL_CreateRenderer(window.sdlWindow, NULL);
    if (renderer == NULL) {
        printf("ERROR: couldn't create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window.sdlWindow);
        SDL_Quit();
    }
    window.renderer = renderer;

    SDL_Event event;
    window.event = event;

    return window;
}

bool validateWindow(Window window) {
    return (window.sdlWindow != NULL && window.renderer != NULL);
}

bool windowQuit(SDL_Event event) {
    SDL_PollEvent(&event);

    if (event.type == SDL_EVENT_QUIT) return true;
    else return false;
}

void destroyWindow(Window window) {
    SDL_DestroyWindow(window.sdlWindow);
    SDL_DestroyRenderer(window.renderer);
    SDL_Quit();
}

