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

void draw_enemy(Enemy* enemy, SDL_Renderer* ren) {
    draw_image(&enemy->img, enemy->x, enemy->y, ren);
}

void update_enemy(Enemy* enemy, float ds) {
    #define RADIUS 100
    enemy->time += ds;
    if (enemy->method == 0)
    {
        enemy->x = enemy->ox + sin(enemy->ox + enemy->speed/100+enemy->time)*enemy->speed;
    }
    if (enemy->method == 2)
    {
        enemy->x = enemy->ox + cos(enemy->time) * RADIUS;
        enemy->y = enemy->oy + sin(enemy->time) * RADIUS;
    }
    
}

SDL_Rect get_enemy_box(Enemy* enemy) {
    return (SDL_Rect){
        .x = enemy->x,
        .y = enemy->y,
        .w = enemy->img.tex->w,
        .h = enemy->img.tex->h
    };
}
