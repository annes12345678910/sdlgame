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
    3 = sine movement
    */
    int method; 
} Enemy;

void draw_enemy(Enemy* enemy, SDL_Renderer* ren) {
    draw_image(&enemy->img, enemy->x, enemy->y, ren);
}

void update_enemy(Enemy* enemy, float ds) {

    if (enemy->method == 0)
    {
        enemy->time += ds;
        enemy->x = enemy->ox + sin(enemy->ox + enemy->speed/100+enemy->time)*enemy->speed;
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
