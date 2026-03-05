#include <vector>
#include "TextBuffer.hpp"
TextBuffer::TextBuffer(){
  std::vector<char> first;
  storage.push_back(first);
}
bool TextBuffer::isValidIndex(int row,int col){
    if(row < 0 || row >= storage.size()){
      return false;
  }
    if(col < 0 || col > storage[row].size() - 1){
      return false;
  }
    return true;
}
bool TextBuffer::isValidPosition(int row,int col){
    if(row < 0 || row >= storage.size()){
      return false;
  }
    if(col < 0 || col > storage[row].size()){
      return false;
  }
    return true;
}
bool TextBuffer::insert(char character, int row, int col){
    if(!isValidPosition(row,col)){
      return false; 
  }
    if(col == storage[row].size()){
      storage[row].push_back(character);
      return true;
  }
    else{
      storage[row].insert(storage[row].begin() + col,character);
      return true;
  }
}
bool TextBuffer::deleter(int row,int col){
    if(!isValidIndex(row, col)){
      return false;
  }
    if(col == storage[row].size()){
     return false; 
  }
    storage[row].erase(storage[row].begin() + col);
    return true;
}
bool TextBuffer::split_lines(int row,int col){
    if(!isValidPosition(row,col)){
      return false;
  } 
    std::vector<char> newLine;
    for(int i = col; i < storage[row].size(); ++i){
      newLine.push_back(storage[row][i]);
    }
    storage[row].erase(storage[row].begin() + col, storage[row].end());
    storage.insert(storage.begin() + row + 1, newLine);
    return true;
}
bool TextBuffer::merge_lines(int row){
    if(row >= storage.size()){
      return false;
  }
    for(int i = 0; i < storage[row].size();++i){
      storage[row-1].push_back(storage[row][i]);
  }
    storage.erase(storage.begin() + row);
    return true;
}
size_t TextBuffer::lineLength(int row) const {
   if(row < 0 || row >= storage.size()){
      return 0;
  } 
   return storage[row].size();
}
int TextBuffer::lineCount() const{
    return storage.size();
}
