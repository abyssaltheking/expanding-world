#pragma once
#include <SDL3/SDL.h>

typedef struct {
    SDL_Texture* texture;
    float x;
    float y;
    float width;
    float height;
} Sprite;

Sprite createSprite(SDL_Renderer* renderer, char* filename, float width, float height);
SDL_FRect spriteToFRect(Sprite sprite);
void setSpriteScaleMode(Sprite sprite, char* mode);
void destroySprite(Sprite sprite);