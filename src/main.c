#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <game/help.h>
#include <game/image.h>
#include <game/player.h>
#include <game/events.h>
#include <game/audio.h>

#define TARGET_FPS 60
#define fps_ms (1000 / TARGET_FPS)

int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    bool quit = false;
    SDL_Event event;
    SDL_AudioDeviceID device;

    int winw;
    int winh;
    const bool* key_states;

    // Initialize SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        return 2;
    }
    if (!SDL_Init(SDL_INIT_AUDIO))
    {
        return 6;
    }
    
    
    // Create Window and Renderer
    if (!SDL_CreateWindowAndRenderer("game", 800, 600, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        return 4;
    }

    device = SDL_OpenAudioDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, NULL);

    Player player;
    player.img = load_image("player.bmp", renderer);
    player.x = 0;
    player.ammo = 10;
    player.hp = 5;
    player.speed = 200;
    load_wav("boss.wav", device);
    Uint32 last_frame;
    // Main Loop
    while (!quit) {
        Uint32 start_frame = SDL_GetTicks();
        Uint32 delta_time = start_frame - last_frame;
        int seconds_passed = start_frame / 1000;
        int fps = 1.0f / (delta_time / 1000.0f);

        SDL_GetWindowSize(window, &winw, &winh);
        //printf("winw %i winh %i\n", winw, winh);
        //printf("%i\n", fps);
        //fflush(stdout);
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
        key_states = SDL_GetKeyboardState(NULL);
        if (is_key_down(SDL_SCANCODE_A, key_states))
        {
            player.x -= player.speed * delta_time / 1000.0f;
        }
        if (is_key_down(SDL_SCANCODE_D, key_states))
        {
            player.x += player.speed * delta_time / 1000.0f;
        }
        

        // --- DRAWING ---
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        draw_player(&player, winh - 90, renderer);

        // Present the backbuffer
        SDL_RenderPresent(renderer);

        Uint32 frame_time = SDL_GetTicks() - start_frame;
        if (frame_time < fps_ms)
        {
            SDL_Delay(fps_ms - frame_time);
        }
        last_frame = start_frame;
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
