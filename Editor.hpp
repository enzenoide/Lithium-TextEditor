#pragma once
#include "TextBuffer.hpp"
class Editor{
public:
    Editor(TextBuffer &buffer);

    bool Backspace();
    bool Enter();
    bool Space();
    bool Tab();

    bool moveRight();
    bool moveLeft();
    bool moveUp();
    bool moveDown();

    int getRow() const;
    int getCol() const;
private:
    int row,col;
    TextBuffer *text;
};
