#include <game/image.h>

Image load_image(const char* path, SDL_Renderer* ren) {
    SDL_Surface* wowimg = SDL_LoadBMP(getResourcePath(path));
    SDL_Texture* wow = SDL_CreateTextureFromSurface(ren, wowimg);
    SDL_SetTextureScaleMode(wow, SDL_SCALEMODE_NEAREST);
    Image e;
    e.tex = wow;
    e.w = 0;
    e.h = 0;
    return e;
}

void draw_image(Image* img, int x, int y, SDL_Renderer* ren) {
    if (!img || !img->tex)
    {
        fprintf(stderr, "Failed to draw image, %p tex %p", img, img->tex);
        return;
    }
    
    SDL_FRect dest = {
        x, y, 
        img->w != 0 ? img->w:img->tex->w * 10, 
        img->h != 0 ? img->h:img->tex->h * 10
    };
    SDL_RenderTexture(ren, img->tex, NULL, &dest);
}
