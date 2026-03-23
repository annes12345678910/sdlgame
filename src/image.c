#include <game/image.h>

Image load_image(const char* path, SDL_Renderer* ren) {
    SDL_Surface* wowimg = SDL_LoadBMP(getResourcePath(path));
    SDL_Texture* wow = SDL_CreateTextureFromSurface(ren, wowimg);
    SDL_SetTextureScaleMode(wow, SDL_SCALEMODE_NEAREST);
    Image e;
    e.tex = wow;
    return e;
}

void draw_image(Image* img, int x, int y, SDL_Renderer* ren) {
    SDL_FRect dest = {x, y, img->tex->w * 10, img->tex->h * 10};
    SDL_RenderTexture(ren, img->tex, NULL, &dest);
}
