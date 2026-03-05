#pragma once
#include <vector>

class TextBuffer{
  public:
    TextBuffer();
    bool insert(char character, int rol, int col);
    bool deleter(int rol, int col);
    bool split_lines(int row,int col);
    bool merge_lines(int row);
    bool isValidIndex(int row,int col);
    bool isValidPosition(int row, int col);
    size_t lineLength(int row) const;
    int lineCount() const;
    const std::vector<char>& getLine(int row) const;
private:
    std::vector<std::vector<char>> storage;
};

