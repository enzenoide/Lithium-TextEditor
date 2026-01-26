#pragma once
#include <vector>

class TextBuffer{
  public:
    bool insert(char character, int rol, int col);
    bool deleter(char character,int rol, int col);
    bool split_lines(int row,int col);
    bool merge_lines(int row,int col);
    bool isValid(int row,int col);
private:
    std::vector<std::vector<char>> storage;
};
