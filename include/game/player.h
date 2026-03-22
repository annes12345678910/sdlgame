#include <game/image.h>

typedef struct
{
    Image img;
    float x;
    int hp;
    int ammo;
    int speed;
} Player;

void draw_player(Player* player, int y, SDL_Renderer* ren);

void update_player(Player* player, float ds, const bool* key_states);
