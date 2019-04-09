#include <SDL2/SDL.h>

#include <misc.h>

SDL_Color color_to_SDL(int r, int g, int b, int a) {
    SDL_Color col = {r, g, b, a};
    return col;
}

SDL_Color color_to_SDL(struct color c) {
    SDL_Color col = {c.r, c.g, c.b, c.a};
    return col;
}
