#include "Editor.hpp"
#include "TextBuffer.hpp"
#include <iostream>

Editor::Editor(TextBuffer &buffer): row(0), col(0), text(&buffer){}

int Editor::getRow() const{
    return row;
}
int Editor::getCol() const{
    return col;
}
void Editor::insertText(char character){
  if(text -> insertChar(row,col,character)){
    col++;
  } 
}
void Editor::Backspace(){
  deleteResult result = text -> deleteChar(row,col);
  if(result == deleteResult::Success){
    col--;
  }
  else if(result == deleteResult::MergeWithPrevious){
    row--;
    col = text -> getLines()[row].size();
  }
}

void Editor::Enter(){
  if(row == 30)
    return;
  if(text -> splitLine(row,col)){
    row++;
  }
  else{
    text -> newLine("");
    row++;
    col = 0;
  }
}

void Editor::Right(){
  col++;
}

void Editor::Left(){
  col--;
}


