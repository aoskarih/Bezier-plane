

// Basic
#include <stdio.h>
#include <stdlib.h>
#include <misc.h>
#include <ctime>
#include <string>
#include <cmath>
#include <vector>
#include <mandelbrot.h>

// Graphics
#define GLEW_STATIC
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>


// Globals
SDL_Window* window = NULL;
SDL_Surface* window_surf;
SDL_Renderer* renderer = NULL;
SDL_Texture* texture;

bool screen = true;
bool fullscreen = false;

double s = 4.0;


bool init() {
    bool success = true;

    //SDL init
    if(!screen) return success;
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize");
        success = false;
    } else {

        if(!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			printf("Warning: Linear texture filtering not enabled!");
		}

        if(fullscreen) {
            SDL_DisplayMode DM;
            SDL_GetCurrentDisplayMode(0, &DM);
            SCREEN_WIDTH = DM.w;
            SCREEN_HEIGHT = DM.h;
        }

        window = SDL_CreateWindow("Mandelbrot",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SCREEN_WIDTH,
                                    SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN);
        if(window == NULL) {
            printf("Can't create window");
            success = false;
        } else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if(renderer == NULL) {
				printf("Renderer could not be created");
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
    return success;
}

void close() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = NULL;
    window = NULL;

    SDL_Quit();
}


void render(double dt) {
    SDL_Texture* texture = SDL_CreateTexture (
        renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        SCREEN_WIDTH, SCREEN_HEIGHT
    );

    std::vector<unsigned char> pixels( SCREEN_WIDTH * SCREEN_HEIGHT * 4, 0 );

    SDL_SetRenderDrawColor( renderer, 0, 0, 0, SDL_ALPHA_OPAQUE );
    SDL_RenderClear( renderer );

    pixels = calc_pixels(-0.743643134, 0.131827966, s);
    s *= 0.9;

    SDL_UpdateTexture(
        texture,
        NULL,
        &pixels[0],
        SCREEN_WIDTH * 4
    );
    SDL_RenderCopy( renderer, texture, NULL, NULL );
    SDL_RenderPresent( renderer );

}

void update(double dt) {
    //p.x += 60*dt;
    //p.y += 60*dt;
}

int main() {
    if(!init()) {
        printf("failed init \n");
    } else {
        printf("init success \n");
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
