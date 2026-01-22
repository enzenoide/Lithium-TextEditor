#include <vector>
#include "TextBuffer.hpp"
void TextBuffer::insert(char character, int row, int col){
    if(col == storage[row].size()){
      storage[row].push_back(character);
  }
    else{
      storage[row].insert(storage[row].begin() + col,character);
  }
}
bool TextBuffer::deleter(char character,int row,int col){
    if(col == storage[row].size()){
     return false; 
  }
    if(row >= storage.size()){
      return false;
  }
    storage[row].erase(storage[row].begin() + col);
    return true;
}
