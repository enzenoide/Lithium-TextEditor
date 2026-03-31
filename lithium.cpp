#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_pixels.h>
#include <iostream>
#include "RenderWindow.hpp"
#include <SDL2/SDL_ttf.h>
#include "TextFonts.hpp"
#include "Editor.hpp"
#include "TextBuffer.hpp"
int main(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
    std::cout << "SDL Could not initialize! SDL ERROR: " << SDL_GetError();
  }
    if(TTF_Init() < 0){
      std::cout << "TTF could not be initialized! SDL ERROR: " << SDL_GetError();
  }
  std::cout << "DEBUG: TENTANDO CRIAR FONTE" << std::endl;
  RenderWindow window("lithium",800,600);
  TextFonts myFont("assets/fonts/fonte.ttf",14);
  SDL_Renderer *renderer = window.Get_Renderer();
  if(renderer == NULL){
      std::cout << "Renderer could not be created! STD ERROR: " << SDL_GetError();
  }
  SDL_Color black = {0,0,0};
  bool running = true;
  SDL_StartTextInput();
  TextBuffer buffer;
  Editor editor(buffer);
  while(running){
      SDL_Event event;
      while(SDL_PollEvent(&event)){
        switch(event.type) {
            case SDL_TEXTINPUT:
              editor.insertText(event.text.text[0]);
              break;
            case SDL_KEYDOWN:
              if(event.key.keysym.sym == SDLK_BACKSPACE){
                editor.Backspace();
              }
              if(event.key.keysym.sym == SDLK_RETURN){
                editor.Enter();
              }
              
              if(event.key.keysym.sym == SDLK_RIGHT){
                editor.Right();
              }
              if(event.key.keysym.sym == SDLK_LEFT){
                editor.Left();
              }
              break;
            case SDL_QUIT:
              running = false;
              break;
      } 
    }
    SDL_SetRenderDrawColor(renderer,169,169,169,1);
    SDL_RenderClear(renderer);
    const auto& lines = buffer.getLines();
    for(int i = 0; i < lines.size();++i){
      myFont.render(renderer,lines[i].c_str(),0,0 + i * 10,black);
    }
    SDL_RenderPresent(renderer);
  }
  SDL_Quit();
  return 0;
}

