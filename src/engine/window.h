#pragma once
#include <SDL3/SDL.h>

typedef struct {
    SDL_Window* sdlWindow;
    SDL_Renderer* renderer;
    SDL_Event event;
} Window;

Window createWindow(char* title, unsigned int width, unsigned int height, bool vsync);
bool validateWindow(Window window);
bool windowQuit(SDL_Event event);
void destroyWindow(Window window);