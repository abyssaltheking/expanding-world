#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <stdio.h>
#include "sprite.h"

Sprite createSprite(
    SDL_Renderer* renderer, 
    char* filename, 
    float width, 
    float height) 
{
    Sprite sprite;

    sprite.texture = IMG_LoadTexture(renderer, filename);
    sprite.texture->w = width;
    sprite.texture->h = height;
    sprite.width = width;
    sprite.height = height;
    sprite.x = 0;
    sprite.y = 0;

    return sprite;
}

void setSpriteScaleMode(Sprite sprite, char* mode) {
    if (strcmp(mode, "nearest") == 0) {
        SDL_SetTextureScaleMode(sprite.texture, SDL_SCALEMODE_NEAREST);
    } else if (strcmp(mode, "linear") == 0) {
        SDL_SetTextureScaleMode(sprite.texture, SDL_SCALEMODE_LINEAR);
    } else {
        printf("WARN: invalid scale mode: \"%s\", only valid input being \"nearest\" and \"linear\"\n", mode);
    }
}

SDL_FRect spriteToFRect(Sprite sprite) {
    return (SDL_FRect){
        sprite.x,
        sprite.y,
        sprite.width,
        sprite.height,
    };
}

void destroySprite(Sprite sprite) {
    SDL_DestroyTexture(sprite.texture);
}