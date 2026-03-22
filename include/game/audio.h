#include <SDL3/SDL.h>
#include <game/help.h>
#pragma once

typedef struct 
{
    SDL_AudioStream* stream;
    Uint8 *wav_data;
    Uint32 wav_data_len;
} Audio;

Audio load_wav(const char* path, SDL_AudioDeviceID dev);

void play_audio(Audio audio, SDL_AudioDeviceID dev);
