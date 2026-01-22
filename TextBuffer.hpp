#pragma once
#include <vector>

class TextBuffer{
  public:
    void insert(char character, int rol, int col);
    bool deleter(char character,int rol, int col);
    void split_lines(int row,int col);
    void merge_lines(int row,int col);
private:
    std::vector<std::vector<char>> storage;
};
