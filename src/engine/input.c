#include <SDL3/SDL.h>
#include "input.h"
#include "stdio.h"

int numkeys; 

bool isKeyDown(SDL_Scancode scancode) {
    bool* downKeys = SDL_GetKeyboardState(&numkeys);
    return downKeys[scancode];
}
