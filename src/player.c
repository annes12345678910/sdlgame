#include <game/image.h>
#include <game/player.h>

void draw_player(Player* player, int y, SDL_Renderer* ren) {
    draw_image(&player->img, player->x, y, ren);
}
