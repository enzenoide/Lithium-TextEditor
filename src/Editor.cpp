#include "Editor.hpp"
#include <iostream>

Editor::Editor(TextBuffer &buffer): posX(0), posY(0), text(&buffer){}

int Editor::getPosX() const{
    return posX;
}
int Editor::getPosY() const{
    return posY;
}
void Editor::insertText(char a){
  if(text -> insertChar(posX,posY,a)){
    posY++;
    std::cout << "michel" << std::endl;
  } 
}
void Editor::Backspace(){
  if(text -> deleteChar(posX,posY - 1)){
    posY--;
    std::cout<<"follen" << std::endl;
  }
}

void Editor::Enter(){
  if(text -> splitLine(posX,posY)){
    posX++;
  }
  else{
    text -> newLine("");
    posX++;
    posY = 0;
  }
}

void Editor::Right(){
  posY++;
}

void Editor::Left(){
  posY--;
}


