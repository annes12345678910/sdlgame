#include <game/image.h>
#include <game/array.h>
#pragma once
typedef struct
{
    Image img;
    float x;
    int hp;
    int ammo;
    int speed;
} Player;

void draw_player(Player* player, int y, SDL_Renderer* ren);

void update_player(Player* player, float ds, const bool* key_states, Array* ar, SDL_Renderer* ren);