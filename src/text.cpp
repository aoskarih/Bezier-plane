
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

void render_text(SDL_Renderer* r, TTF_Font* f, int x, int y, std::string text, SDL_Color text_c, SDL_Color back_c, bool center) {
    SDL_Surface* mess_surf;
    SDL_Texture* mess;
    SDL_Rect mess_rect;

    mess_surf = TTF_RenderText_Shaded(f, text.c_str(), text_c, back_c);
    mess = SDL_CreateTextureFromSurface(r, mess_surf);
    if(center) {
        mess_rect = {x-(mess_surf->w/2), y-(mess_surf->h/2), mess_surf->w, mess_surf->h};
    } else {
        mess_rect = {x, y, mess_surf->w, mess_surf->h};
    }

    SDL_SetRenderDrawColor(r, back_c.r, back_c.g, back_c.b, back_c.a);
    SDL_RenderFillRect(r, &mess_rect);

    SDL_RenderCopy(r, mess, NULL, &mess_rect);

    SDL_FreeSurface(mess_surf);
    SDL_DestroyTexture(mess);
}

void render_text_box(SDL_Renderer* r,
                     TTF_Font* f,
                     int x,
                     int y,
                     std::string text,
                     SDL_Color text_c,
                     SDL_Color back_c,
                     int outline,
                     SDL_Color line_c,
                     bool center)
{
    SDL_Surface* mess_surf;
    SDL_Texture* mess;
    SDL_Rect mess_rect;
    SDL_Rect out_rect;

    mess_surf = TTF_RenderText_Shaded(f, text.c_str(), text_c, back_c);
    mess = SDL_CreateTextureFromSurface(r, mess_surf);
    if(center) {
        mess_rect = {x-(mess_surf->w/2), y-(mess_surf->h/2), mess_surf->w, mess_surf->h};
    } else {
        mess_rect = {x, y, mess_surf->w, mess_surf->h};
    }

    out_rect.x = mess_rect.x-outline;
    out_rect.y = mess_rect.y-outline;
    out_rect.h = mess_rect.h+2*outline;
    out_rect.w = mess_rect.w+2*outline;
    SDL_SetRenderDrawColor(r, line_c.r, line_c.g, line_c.b, line_c.a);
    SDL_RenderFillRect(r, &out_rect);

    SDL_SetRenderDrawColor(r, back_c.r, back_c.g, back_c.b, back_c.a);
    SDL_RenderFillRect(r, &mess_rect);

    SDL_RenderCopy(r, mess, NULL, &mess_rect);

    SDL_FreeSurface(mess_surf);
    SDL_DestroyTexture(mess);

}
