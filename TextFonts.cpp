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
void TextFonts::render(SDL_Renderer *renderer, const char *message, int x, int y,SDL_Color color){
    if(renderer == nullptr){
      std::cout << "Erro: Renderer recebido eh nulo" << std::endl;
      return;
  }
    SDL_Surface *surface = TTF_RenderText_Solid(font,message,color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
    SDL_Rect rectangle;
    rectangle.x = 0;
    rectangle.y = 0;
    rectangle.w = 600;
    rectangle.h = 64;
    SDL_RenderCopy(renderer, texture, NULL, &rectangle);
    SDL_DestroyTexture(texture); // Libera a memória para não dar leak


    
    
}

