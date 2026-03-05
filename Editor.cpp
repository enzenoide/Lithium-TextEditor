#include "Editor.hpp"



Editor::Editor(TextBuffer &buffer): row(0), col(0), text(&buffer){}

int Editor::getCol() const{
    return col;
}
int Editor::getRow() const{
    return row;
}
bool Editor::insertChar(char a){
  if(a){
    if(text -> insert(a,row,col))
      return true;
    return false;
  }
  return false;
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
   if(col > 0){
    if(text -> deleter(row,col - 1)){
      col--;
      return true;
    }
    return false;
  }
    if(row > 0){
        int prevLine = text -> lineLength(row-1);
          if(text -> merge_lines(row)){
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
      if(!text -> insert(' ',row,col))
        return false;
      col++;
  }
    return true;
}
bool Editor::moveRight(){
    if(col < text -> lineLength(row)){
      col++;
      return true;
  }
    return false;
}
bool Editor::moveLeft(){
    if(col > 0){
      col--;
      return true;
  }
    return false;
}
bool Editor::moveUp(){
  if(row > 0){
    row--;
    int newLineLength = text ->  lineLength(row);
    if(col > newLineLength)
      col = newLineLength;
    return true;
  }
  return false;
}
bool Editor::moveDown(){
  if(row + 1 < text->lineCount()){
    row++;
    int newLineLength = text -> lineLength(row);
    if(col > newLineLength)
      col = newLineLength;
    return true;
  }
  return false;
}
