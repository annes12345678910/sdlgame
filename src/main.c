#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <game/help.h>
#include <game/image.h>
#include <game/images.h>
#include <game/player.h>
#include <game/events.h>
#include <game/audio.h>
#include <game/bullet.h>

#include <game/enemy.h>
#include <game/array.h>

#include <SDL3_gfx/SDL3_gfxPrimitives.h>

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
    player.img.h = 0;
    player.img.w = 0;
    
    Enemy ene;
    
    ene.x = 0;
    ene.hp = 1;
    ene.ox = 400;
    ene.speed = 200;
    ene.y = 100;
    ene.method = 2;
    ene.img = load_image("bossidle.bmp", renderer);
    ene.time = 0;
    ene.img.h = 0;
    ene.img.w = 0;

    Audio e = load_wav("boss.wav", device);
    Uint32 last_frame;
    play_audio(e, device);

    Array bullets = create_heap_array(sizeof(Bullet), 0);

    img_bullet = load_image("bullet.bmp", renderer);
    
    // Main Loop
    while (!quit) {
        Uint32 start_frame = SDL_GetTicks();
        Uint32 delta_time = start_frame - last_frame;
        float delta_sec = delta_time / 1000.0f;
        int seconds_passed = start_frame / 1000;
        int fps = 1.0f / (delta_time / 1000.0f);

        SDL_GetWindowSize(window, &winw, &winh);
        ene.ox = winw / 2.0f;
        ene.oy = 100;
        //printf("winw %i winh %i\n", winw, winh);
        //printf("%i\n", fps);
        //fflush(stdout);
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
        key_states = SDL_GetKeyboardState(NULL);
        update_player(&player, delta_sec, key_states, &bullets, renderer);
        update_enemy(&ene, delta_sec);
        ene.x -= 80;
        

        // --- DRAWING ---
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for (size_t i = 0; i < bullets.len; i++)
        {
            update_bullet(&((Bullet*)bullets.data)[i], delta_sec, 200);
            draw_bullet(&((Bullet*)bullets.data)[i], renderer);
            if (((Bullet*)bullets.data)[i].y < -100)
            {
                for (size_t j = i; j < bullets.len - 1; j++) {
                    ((Bullet*)bullets.data)[j] = ((Bullet*)bullets.data)[j + 1];
                }
                #ifdef DEBUG
                printf("Freed %p\n", &((Bullet*)bullets.data)[i]);
                #endif
                bullets.len--;
            }
            
        }

        draw_player(&player, winh - 90, renderer);


        //filledCircleRGBA(renderer, ene.ox, ene.oy, 100, 255, 0, 0, 255);

        draw_enemy(&ene, renderer);

        // Present the backbuffer
        SDL_RenderPresent(renderer);

        Uint32 frame_time = SDL_GetTicks() - start_frame;
        if (frame_time < fps_ms)
        {
            SDL_Delay(fps_ms - frame_time);
        }
        last_frame = start_frame;

        fflush(stdout);
        fflush(stderr);
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
