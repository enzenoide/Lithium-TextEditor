#include "Editor.hpp"



Editor::Editor(TextBuffer &buffer): row(0), col(0), text(&buffer){}

int Editor::getCol() const{
    return col;
}
int Editor::getRow() const{
    return row;
}

bool Editor::Enter(){
    if(text -> split_lines(row,col)){
      row++;
      col = 0;
      return true;
  }
    return false;
}
