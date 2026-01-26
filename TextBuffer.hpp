#pragma once
#include <vector>

class TextBuffer{
  public:
    bool insert(char character, int rol, int col);
    bool deleter(int rol, int col);
    bool split_lines(int row,int col);
    bool merge_lines(int row,int col);
    bool isValid(int row,int col);
    bool lineLength(int row);
private:
    std::vector<std::vector<char>> storage;
};

