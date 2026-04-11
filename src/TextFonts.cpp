#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <unistd.h>
#include "TextFonts.hpp"
#include <iostream>

TextFonts::TextFonts(const char *fontpath, int fontsize){
    font = TTF_OpenFont(fontpath,fontsize);
    if(font == nullptr){
      std::cout << "error: SDL_ERROR: " << SDL_GetError();
      
  }
}
void TextFonts::render(SDL_Renderer *renderer, const char *message, int x, int y, SDL_Color color){
    if(renderer == nullptr){
        std::cout << "Erro: Renderer recebido eh nulo" << std::endl;
        return;
    }

    if(font == nullptr){
        std::cout << "Erro: Fonte nao carregada!" << std::endl;
        return;
    }

    if(message == nullptr || message[0] == '\0'){
        // evita erro de string vazia
        return;
    }

    SDL_Surface *surface = TTF_RenderText_Blended(font, message, color);
    if(!surface){
        std::cout << "Text render error: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(!texture){
        std::cout << "Texture creation error: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(surface);
        return;
    }

    SDL_Rect rectangle;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = surface->w;
    rectangle.h = surface->h;

    SDL_FreeSurface(surface);

    SDL_RenderCopy(renderer, texture, NULL, &rectangle);
    SDL_DestroyTexture(texture);
}
TTF_Font* TextFonts::getFont()const{
  return font;
}
