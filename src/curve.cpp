#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <cmath>
#include <curve.h>

void draw_bezier(SDL_Renderer* r, float points[][2], int width, SDL_Color c) {

    // do bezier

}

float cubic_bezier(float t, float p[4]) {
    return pow((1 - t), 3)*p[0] + 3*pow((1 - t), 2)*t*p[1] + 3*(1 - t)*t*t*p[2] + t*t*t*p[3];
}
