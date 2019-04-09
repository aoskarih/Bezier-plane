
struct color {
    int r;
    int g;
    int b;
    int a;
};

SDL_Color color_to_SDL(int r, int g, int b, int a=255);
SDL_Color color_to_SDL(struct color c);
