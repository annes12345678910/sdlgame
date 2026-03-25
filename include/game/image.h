#include <SDL3/SDL.h>

#include <game/help.h>
#pragma once
typedef struct
{
    SDL_Texture* tex;
    int w;
    int h;
} Image;

Image load_image(const char* path, SDL_Renderer* ren);

void draw_image(Image* img, int x, int y, SDL_Renderer* ren);