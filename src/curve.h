
void draw_bezier(SDL_Renderer* r, float points[][4], int width, SDL_Color c, int precision=100);
float cubic_bezier(float t, float p[4]);
void draw_curve(SDL_Renderer* r, int points[][2], int n, int width, SDL_Color c);
