#include <game/image.h>
#pragma once

typedef struct
{
    Image img;
    float x;
    float y;
} Bullet;

void update_bullet(Bullet* bullet, float ds, int speed);
