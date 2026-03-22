#include <SDL3/SDL.h>
#include <game/help.h>

SDL_AudioStream* load_wav(const char* path, SDL_AudioDeviceID dev) {
    SDL_AudioSpec spec;
    Uint8 *wav_data = NULL;
    Uint32 wav_data_len = 0;
    SDL_LoadWAV(getResourcePath(path), &spec, &wav_data, &wav_data_len);
    SDL_AudioStream *stream = SDL_CreateAudioStream(&spec, NULL);
    SDL_BindAudioStreams(dev, &stream, 1);

    SDL_PutAudioStreamData(stream, wav_data, wav_data_len);
}