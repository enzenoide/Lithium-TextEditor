#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_pixels.h>
#include <iostream>
#include "RenderWindow.hpp"
#include <SDL2/SDL_ttf.h>
#include "TextFonts.hpp"
int main(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
    std::cout << "SDL Could not initialize! SDL ERROR: " << SDL_GetError();
  }
    if(TTF_Init() < 0){
      std::cout << "TTF could not be initialized! SDL ERROR: " << SDL_GetError();
  }
  std::cout << "DEBUG: TENTANDO CRIAR FONTE" << std::endl;
  RenderWindow window("lithium",800,600);
  TextFonts myFont("assets/fonts/fonte.ttf",28);
  SDL_Renderer *renderer = window.Get_Renderer();
  if(renderer == NULL){
      std::cout << "Renderer could not be created! STD ERROR: " << SDL_GetError();
  }

  bool running = true;
  while(running){
      SDL_Event event;
      while(SDL_PollEvent(&event) != 0){
        if(event.type == SDL_QUIT){
          running = false;
      }
    }
    SDL_SetRenderDrawColor(renderer,169,169,169,1);
    SDL_RenderClear(renderer);
    SDL_Color black = {0,0,0};
    myFont.render(renderer,"a b c d e f g h i j k l m n o p q r s t u v w x y z",800,250,black);
    SDL_RenderPresent(renderer);
  }
  SDL_Quit();
  return 0;
}

