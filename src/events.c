#include <SDL3/SDL.h>

bool is_key_down(SDL_Scancode code, const bool *state) {
    return state[code];
}