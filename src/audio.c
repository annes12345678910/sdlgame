#include <SDL3/SDL.h>

#include <game/help.h>
#include <game/audio.h>

Audio load_wav(const char* path, SDL_AudioDeviceID dev) {
    SDL_AudioSpec spec;
    Uint8 *wav_data = NULL;
    Uint32 wav_data_len = 0;
    SDL_LoadWAV(getResourcePath(path), &spec, &wav_data, &wav_data_len);
    SDL_AudioStream *stream = SDL_CreateAudioStream(&spec, NULL);
    SDL_BindAudioStreams(dev, &stream, 1);

    Audio meow;
    meow.stream = stream;
    meow.wav_data = wav_data;
    meow.wav_data_len = wav_data_len;
    return meow;
}

void play_audio(Audio audio, SDL_AudioDeviceID dev) {
    SDL_PutAudioStreamData(audio.stream, audio.wav_data, audio.wav_data_len);
}