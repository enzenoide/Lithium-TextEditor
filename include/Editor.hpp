#pragma once
#include "TextBuffer.hpp"
class Editor{
public:
    Editor(TextBuffer &buffer);

    void Backspace();
    void insertText(char a);
    void Enter();
    void Right();
    void Left();
    int getRow()const;
    int getCol()const;
private:
    int row,col;
    TextBuffer *text;
};
