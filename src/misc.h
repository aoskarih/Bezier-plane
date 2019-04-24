
struct color {
    int r;
    int g;
    int b;
    int a;
};


extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

extern color c[16];
extern std::map<std::string, color> col;

SDL_Color color_to_SDL(int r, int g, int b, int a=255);
SDL_Color color_to_SDL(struct color c);
