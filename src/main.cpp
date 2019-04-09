/*
Arttu Hyvönen 4/2019
TODO:
Code
*/

#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <ctime>
#include <string>
#include <map>
#include <Player.h>
#include <text.h>
#include <curve.h>
#include <misc.h>

using std::cout;
using std::cin;
using std::endl;

//SDL stuff
SDL_Window* window = NULL;
SDL_Surface* window_surf;
SDL_Renderer* renderer = NULL;
TTF_Font* sans = NULL;

bool screen = true;
bool fullscreen = true;

int SCREEN_WIDTH = 1280;
int SCREEN_HEIGHT = 720;


color c[16];
std::map<std::string, color> col;

//Game variables
Player p (0, 0);


bool init() {
    bool success = true;

    //Game init
    c[0].r = 29;    c[0].g = 43;    c[0].b = 83;    c[0].a = 255;
    c[1].r = 126;   c[1].g = 37;    c[1].b = 83;    c[1].a = 255;
    c[2].r = 0;     c[2].g = 135;   c[2].b = 81;    c[2].a = 255;
    c[3].r = 171;   c[3].g = 82;    c[3].b = 54;    c[3].a = 255;
    c[4].r = 95;    c[4].g = 87;    c[4].b = 79;    c[4].a = 255;
    c[5].r = 194;   c[5].g = 195;   c[5].b = 199;   c[5].a = 255;
    c[6].r = 255;   c[6].g = 251;   c[6].b = 242;   c[6].a = 255;
    c[7].r = 255;   c[7].g = 0;     c[7].b = 77;    c[7].a = 255;
    c[8].r = 255;   c[8].g = 163;   c[8].b = 0;     c[8].a = 255;
    c[9].r = 255;   c[9].g = 236;   c[9].b = 39;    c[9].a = 255;
    c[10].r = 0;    c[10].g = 228;  c[10].b = 54;   c[10].a = 255;
    c[11].r = 41;   c[11].g = 173;  c[11].b = 255;  c[11].a = 255;
    c[12].r = 131;  c[12].g = 118;  c[12].b = 156;  c[12].a = 255;
    c[13].r = 255;  c[13].g = 119;  c[13].b = 168;  c[13].a = 255;
    c[14].r = 255;  c[14].g = 204;  c[14].b = 170;  c[14].a = 255;
    c[15].r = 0;    c[15].g = 0;    c[15].b = 0;    c[15].a = 255;

    col["dark blue"] = c[0];
    col["purple"] = c[1];
    col["dark green"] = c[2];
    col["brown"] = c[3];
    col["dark grey"] = c[4];
    col["grey"] = c[5];
    col["white"] = c[6];
    col["red"] = c[7];
    col["orange"] = c[8];
    col["yellow"] = c[9];
    col["green"] = c[10];
    col["blue"] = c[11];
    col["spale"] = c[12];
    col["pink"] = c[13];
    col["peach"] = c[14];
    col["black"] = c[15];

    //SDL init
    if(!screen) return success;
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL could not initialize";
        success = false;
    } else {

        if(!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			cout << "Warning: Linear texture filtering not enabled!";
		}

        if(fullscreen) {
            SDL_DisplayMode DM;
            SDL_GetCurrentDisplayMode(0, &DM);
            SCREEN_WIDTH = DM.w;
            SCREEN_HEIGHT = DM.h;
        }

        window = SDL_CreateWindow("N-Body Simulation",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SCREEN_WIDTH,
                                    SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN);
        if(window == NULL) {
            cout << "Can't create window";
            success = false;
        } else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if(renderer == NULL) {
				cout << "Renderer could not be created";
				success = false;
			}
			else {
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}
        }
        if(fullscreen) {
            SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
        }

    }

    //SDL TTF init
    if(TTF_Init() < 0) {
        cout << "TTF not initializing" << endl;
    }
    sans = TTF_OpenFont("../data/noto-sans/NotoSans-Regular.ttf", 20);
    return success;
}

void close() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = NULL;
    window = NULL;
    TTF_CloseFont(sans);

    SDL_Quit();
    TTF_Quit();
}

void render(double dt) {
    //Clear screen
    SDL_SetRenderDrawColor(renderer, col["white"].r, col["white"].g, col["white"].b, col["white"].a);
    SDL_RenderClear(renderer);

    //Text objects
    SDL_Color Red = {255, 0, 0};
    SDL_Color Black = {0, 0, 0};
    SDL_Color White = {255, 255, 255};

    //Grid
    for(int i = -10; i < 12; i++) {
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
        int lx = i*100-fmod(p.x,100)+SCREEN_WIDTH/2;
        int ly = i*100-fmod(p.y,100)+SCREEN_HEIGHT/2;

        int gx = int(p.x/100)+i;
        int gy = -(int(p.y/100)+i);

        std::string ax = std::to_string(gx);
        std::string ay = std::to_string(gy);
        if(gx == 0) {
            color c = col["red"];
            thickLineRGBA(renderer, lx, 0, lx, SCREEN_HEIGHT, 3, c.r, c.g, c.b, c.a);
        } else if(gx%10 == 0) {
            color c = col["dark blue"];
            thickLineRGBA(renderer, lx, 0, lx, SCREEN_HEIGHT, 2, c.r, c.g, c.b, c.a);
        } else {
            color c = col["dark grey"];
            thickLineRGBA(renderer, lx, 0, lx, SCREEN_HEIGHT, 1, c.r, c.g, c.b, c.a);
        }

        if(gy == 0) {
            color c = col["red"];
            thickLineRGBA(renderer, 0, ly, SCREEN_WIDTH, ly, 3, c.r, c.g, c.b, c.a);
        } else if(gy%10 == 0) {
            color c = col["dark blue"];
            thickLineRGBA(renderer, 0, ly, SCREEN_WIDTH, ly, 2, c.r, c.g, c.b, c.a);
        } else {
            color c = col["dark grey"];
            thickLineRGBA(renderer, 0, ly, SCREEN_WIDTH, ly, 1, c.r, c.g, c.b, c.a);
        }

        render_text_box(renderer, sans, lx, 20, ax, color_to_SDL(col["black"]), color_to_SDL(col["white"]), 1, color_to_SDL(col["black"]), true);
        render_text_box(renderer, sans, 20, ly, ay, color_to_SDL(col["black"]), color_to_SDL(col["white"]), 1, color_to_SDL(col["black"]), true);
    }

    //Position


    //UI

    //fps


    std::string fps_str = std::to_string(int(1.0/dt));
    render_text(renderer, sans, SCREEN_WIDTH-100, 20, fps_str, Red, White);

    SDL_RenderPresent(renderer);
}

void update(double dt) {
    p.x += 60*dt;
    p.y += 60*dt;
}

int main() {
    if(!init()) {
        cout << "failed init";
    } else {
        cout << "init success" << endl;
        SDL_Event e;
        bool quit = false;
        bool pause = false;
        clock_t t = clock();
        double dt;
        while(!quit) {

            //input
            while(SDL_PollEvent(&e) != 0) {
                if(e.type == SDL_QUIT) quit = true;
                if(e.type == SDL_KEYDOWN) {
                    switch(e.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            quit = true;
                            break;
                    }
                }
            }

            dt = (float(clock()-t))/(CLOCKS_PER_SEC);
            t = clock();
            update(dt);
            render(dt);

        }
    }

    close();

    return 0;
}
