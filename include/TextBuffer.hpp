#pragma once
#include <vector>
#include <string>
class TextBuffer{
  public:
    TextBuffer();
    bool insertChar(int row,int col,char a);
    bool deleteChar(int row, int col);
    bool newLine(std::string row);
    bool splitLine(int row,int col);
    const std::vector<std::string>& getLines() const;
private:
    std::vector<std::string> lines;
};

