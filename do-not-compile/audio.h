#pragma once

#include <SDL3/SDL.h>
#include "../../libs/miniaudio.h"

typedef struct {
    ma_engine engine;
    SDL_AudioDeviceID deviceId;
} AudioEngine;

AudioEngine initAudio();
void destroyAudio(AudioEngine engine);