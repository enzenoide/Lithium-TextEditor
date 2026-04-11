#pragma once
#include <vector>
#include <string>
enum class deleteResult {
    Success,
    MergeWithPrevious,
    Fail
};
class TextBuffer{
  public:
    TextBuffer();
    bool insertChar(int row,int col,char a);
    deleteResult deleteChar(int row, int col);
    bool newLine(std::string row);
    bool splitLine(int row,int col);
    const std::vector<std::string>& getLines() const;
private:
    std::vector<std::string> lines;
};

