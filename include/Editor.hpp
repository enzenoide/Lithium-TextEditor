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
    int getPosY()const;
    int getPosX()const;
private:
    int posX,posY;
    TextBuffer *text;
};
