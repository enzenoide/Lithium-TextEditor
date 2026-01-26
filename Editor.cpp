#include "Editor.hpp"



Editor::Editor(TextBuffer &buffer): row(0), col(0), text(&buffer){}

int Editor::getCol() const{
    return col;
}
int Editor::getRow() const{
    return row;
}

bool Editor::Enter(){
    if(text -> split_lines(getRow(),getCol())){
      row++;
      col = 0;
      return true;
  }
    return false;
}
bool Editor::Backspace(){
   if(text -> deleter(getRow(),getCol())){
      col--;
      return true;
  }
   else if (col == 0) {
      if(int prevLine = text -> lineLength(row-1)){
          text -> merge_lines(row,col);
          row--;
          col += prevLine;
          return true;
    }
  }
    return false;
}
bool Editor::Space(){
    if(text -> insert(' ',row,col)){
      col++;
      return true;
  }
    return false;
}
bool Editor::Tab(){
   for(int i = 0; i < 8; ++i){
      text -> insert(' ',row,col);
      col++;
  }
    return true;
}
bool Editor::moveRight(){
    if(col <= text -> lineLength(row)){
      col++;
  }
    return true;
}
bool Editor::moveLeft(){
    if(col >= 0){
      col--;
  }
    return true;
}
bool Editor::moveUp(){
  int prevLine = text -> lineLength(row-1);
  int currentLine = text -> lineLength(row);
  if(currentLine < prevLine){
      row--;
      col = prevLine;
      return true;
  }
  row--;
  return true;
}
bool Editor::moveDown(){
  int nextLine = text -> lineLength(row+1);
  int currentLine = text -> lineLength(row);
  if(currentLine > nextLine){
      row++;
      col = nextLine;
      return true;
  }
  row++;
  return true;
}
