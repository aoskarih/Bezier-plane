

void render_text(SDL_Renderer* r,
                 TTF_Font* f,
                 int x,
                 int y,
                 std::string text,
                 SDL_Color text_c,
                 SDL_Color back_c,
                 bool center=false);

void render_text_box(SDL_Renderer* r,
                      TTF_Font* f,
                      int x,
                      int y,
                      std::string text,
                      SDL_Color text_c,
                      SDL_Color back_c,
                      int outline,
                      SDL_Color line_c,
                      bool center=false);
