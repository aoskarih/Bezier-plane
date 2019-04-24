#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <cmath>
#include <map>
#include <string>
#include <curve.h>
#include <misc.h>


void draw_bezier(SDL_Renderer* r, float points[][4], int width, SDL_Color c, int precision) {
    int line[precision][2];
    for(int i = 0; i < precision; i++) {
        line[i][0] = int(100*cubic_bezier(float(i)/float(precision-1), points[0]))+SCREEN_WIDTH/2;
        line[i][1] = -int(100*cubic_bezier(float(i)/float(precision-1), points[1]))+SCREEN_HEIGHT/2;
        //printf((std::to_string(line[i][0]) + " " + std::to_string(line[i][1]) + "\n").c_str());
    }
    draw_curve(r, line, precision, width, c);
}

float cubic_bezier(float t, float p[4]) {
    float v = pow((1.0 - t), 3)*p[0] + 3*pow((1.0 - t), 2)*t*p[1] + 3*(1.0 - t)*t*t*p[2] + t*t*t*p[3];
    return v;
}


void draw_curve(SDL_Renderer* r, int points[][2], int n, int width, SDL_Color c) {
    for(int i = 1; i < n; i++) {
        thickLineRGBA(r, points[i-1][0], points[i-1][1], points[i][0], points[i][1], width, c.r, c.g, c.b, c.a);
    }
}
