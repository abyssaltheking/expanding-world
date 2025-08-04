#define MA_IMPLEMENTATION
#define MA_NO_ENGINE_IO
#define SDL_MAIN_HANDLED
#define CHANNELS 2
#define SAMPLE_RATE 48000

#include "audio.h"
#include <SDL3/SDL.h>
#include <stdio.h>
#include "../../libs/miniaudio.h"

static ma_engine initEngine;

void dataCallback(void* userData, ma_uint8* buffer, int bufferSizeInBytes) {
    (void)userData;

    ma_uint32 bufferSizeInFrames = (ma_uint32)bufferSizeInBytes / ma_get_bytes_per_frame(ma_format_f32, CHANNELS);
    ma_engine_read_pcm_frames(&initEngine, userData, bufferSizeInFrames, NULL);
}

AudioEngine initAudio() {
    bool failed = false;

    ma_result result;
    ma_engine_config engineConfig;
    ma_engine engine;

    SDL_AudioSpec desiredSpec;
    SDL_AudioSpec obtainedSpec;
    SDL_AudioDeviceID deviceId;
    
    if (SDL_InitSubSystem(SDL_INIT_AUDIO) != 0) printf("ERR: sdl audio init failed: %s", SDL_GetError());
    
    engineConfig = ma_engine_config_init();
    engineConfig.noDevice = MA_TRUE;
    engineConfig.channels = CHANNELS;
    engineConfig.sampleRate = SAMPLE_RATE;

    result = ma_engine_init(&engineConfig, &engine);
    if (result != MA_SUCCESS) printf("ERR: couldnt init miniaudio");
    
    initEngine = engine;

    MA_ZERO_OBJECT(&desiredSpec);
    desiredSpec.freq = ma_engine_get_sample_rate(&engine);
    desiredSpec.format = SDL_AUDIO_F32;
    desiredSpec.channels = ma_engine_get_channels(&engine);

    deviceId = SDL_OpenAudioDevice(deviceId, &desiredSpec);
    if (deviceId == 0) printf("ERR: failed to open audio device: %s", SDL_GetError());

    SDL_PauseAudioDevice(deviceId);

    return (AudioEngine) {
        engine,
        deviceId
    };
}

// TODO: make audio type and make it playable

void destroyAudio(AudioEngine engine) {
    ma_engine_uninit(&engine.engine);
    SDL_CloseAudioDevice(engine.deviceId);
    SDL_QuitSubSystem(SDL_INIT_AUDIO);
}
