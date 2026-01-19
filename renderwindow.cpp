#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include "RenderWindow.hpp"
RenderWindow::RenderWindow(const char* title,int width, int height) : window(NULL), renderer(NULL){
  window = SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_SHOWN);
  if(window == NULL){
    std::cout << "SDL Could not create window! SDL_ERROR: " << SDL_GetError();
  }
  renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
  if(renderer == NULL){
      std::cout << "SDL Could not create renderer! SDL ERROR: " << SDL_GetError();
  }
}
  SDL_Renderer *RenderWindow::Get_Renderer(){
      return renderer;
  }
  void RenderWindow::close(){
      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
      renderer = NULL;
      window = NULL;  
}
 
