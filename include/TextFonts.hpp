#pragma once
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>

class TextFonts{
public:
    TextFonts(const char *file,int ptsize);
    void render(SDL_Renderer* renderer,const char* message, int x, int y, SDL_Color color);
    TTF_Font* getFont()const;
private:
    TTF_Font *font;
};
