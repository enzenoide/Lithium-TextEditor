#include <vector>
#include "TextBuffer.hpp"
bool TextBuffer::isValid(int row,int col){
    if(row > storage.size() || row < storage.size()){
      return false;
  }
    if(col > storage[row].size()){
      return false;
  }
    return true;
}
bool TextBuffer::insert(char character, int row, int col){
    if(!isValid(row,col)){
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
    if(!isValid(row, col)){
      return false;
  }
    if(col == storage[row].size()){
     return false; 
  }
    if(row >= storage.size()){
      return false;
  }
    storage[row].erase(storage[row].begin() + col);
    return true;
}
bool TextBuffer::split_lines(int row,int col){
    if(!isValid(row,col)){
      return false;
  } 
    std::vector<char> newLine;
    for(int i = col + 1; i < storage[row].size(); ++i){
      newLine.push_back(storage[row][i]);
    }
    storage[row].erase(storage[row].begin() + col, storage[row].end());
    storage.insert(storage.begin() + row + 1, newLine);
    return true;
}
bool TextBuffer::merge_lines(int row, int col){
    if(!isValid(row,col)){
      return false;
  }
    if(row >= storage.size()){
      return false;
  }
    for(int i = 0; i < storage[row].size();++i){
      storage[row-1].push_back(storage[row][i]);
  }
    storage[row].erase(storage[row].begin(), storage[row].end());
    return true;
}
bool TextBuffer::lineLength(int row){
   if(row < storage.size()){
      return false;
  } 
   return storage[row].size();
}
