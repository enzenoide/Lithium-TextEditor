#include "TextBuffer.hpp"
#include <string>
#include <vector>
TextBuffer::TextBuffer(){
  lines.push_back("");
}
  
bool TextBuffer::insertChar(int row,int col,char c){
  if(row < 0 || row > lines.size())
    return false;
  if(col > lines[row].size())
    col = lines[row].size();
  lines[row].insert(col,1,c);
  return true;
}
deleteResult TextBuffer::deleteChar(int row,int col){
    
  if(row >= lines.size())
    return deleteResult::Fail;
  if(col > 0){
    lines[row].erase(col - 1, 1);
    return deleteResult::Success;
  }
  if(col == 0 && row > 0){
    lines[row - 1] += lines[row];
    lines.erase(lines.begin() + row);
    return deleteResult::MergeWithPrevious;
  }
  return deleteResult::Fail;
}
bool TextBuffer::newLine(std::string row){
  lines.push_back(row);
  return true;
}
bool TextBuffer::splitLine(int row, int col){
  if(col < lines[row].size() && col > 0){
    std::string left = lines[row].substr(0,col);
    std::string right = lines[row].substr(col);

    lines[row] = left;

    lines.insert(lines.begin() + row + 1,right);
    return true;
  }
  return false;
}
const std::vector<std::string>& TextBuffer::getLines()const{
  return lines;
}

