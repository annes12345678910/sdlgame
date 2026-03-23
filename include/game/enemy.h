#include <game/image.h>
#include <game/audio.h>

#include <math.h>

#pragma once

typedef struct
{
    float x;
    float y;
    float ox;
    float oy;
    Image img;
    int hp;
    int speed;
    float time;
    /*
    0 = bouncing left and right
    1 = staying still
    2 = circling
    */
    int method; 
} Enemy;

void draw_enemy(Enemy* enemy, SDL_Renderer* ren);

void update_enemy(Enemy* enemy, float ds);

SDL_Rect get_enemy_box(Enemy* enemy);
