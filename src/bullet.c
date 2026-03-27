#include <game/bullet.h>

void update_bullet(Bullet* bullet, float ds, int speed) {
    bullet->y -= speed * ds;
}

void draw_bullet(Bullet* bullet, SDL_Renderer* ren) {
    draw_image(bullet->img, bullet->x, bullet->y, ren);
}
