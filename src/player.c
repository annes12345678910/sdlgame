#include <game/image.h>
#include <game/player.h>
#include <game/events.h>
#include <game/array.h>
#include <game/bullet.h>
#include <game/images.h>

void draw_player(Player* player, int y, SDL_Renderer* ren) {
    draw_image(&player->img, player->x, y, ren);
}

void update_player(Player* player, float ds, const bool* key_states, Array* ar, SDL_Renderer* ren) {
    if (is_key_down(SDL_SCANCODE_A, key_states) || is_key_down(SDL_SCANCODE_LEFT, key_states))
    {
        player->x -= player->speed * ds;
    }
    if (is_key_down(SDL_SCANCODE_D, key_states) || is_key_down(SDL_SCANCODE_RIGHT, key_states))
    {
        player->x += player->speed * ds;
    }
    if (is_key_down(SDL_SCANCODE_SPACE, key_states))
    {
        resize_array(ar, 1, sizeof(Bullet));

        Bullet* bullets = (Bullet*)ar->data;
        Bullet* bul = &bullets[ar->len - 1];

        bul->img = &img_bullet;
        bul->x = player->x;
        bul->y = 300;
    }
    
}
