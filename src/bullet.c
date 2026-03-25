#include <game/bullet.h>

void update_bullet(Bullet* bullet, float ds, int speed) {
    bullet->y -= speed * ds;
}
