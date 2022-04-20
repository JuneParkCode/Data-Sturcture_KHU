#include "DoubleLinkedList.hpp"

/*
    header, trailer의 위치가 DLL에 저장되어있으므로 항상 O(1)으로
    goToTop(), goToBottom이 수행.
*/
class TextEditor
{
private:
    DoubleLinkedList<char *>    *lst;
public:
    TextEditor();
    ~TextEditor();
    void    goToTop();
    void    goToBottom();
    void    insertLine(char newLine[]);
    char    *getNextLine();
    char    *getPrevLine();
};

TextEditor::TextEditor()
{
    this->lst = new DoubleLinkedList<char *>();
    this->lst->setHeader("---Top of file---");
    this->lst->setHeader("---Bottom of file---");
}

TextEditor::~TextEditor()
{
    delete this->lst;
}

void    TextEditor::goToTop()
{
    this->lst->goToHead();
}

void    TextEditor::goToBottom()
{
    this->lst->goToRear();
}

void    TextEditor::insertLine(char newLine[])
{
    this->lst->insertItem(newLine);
}

char    *TextEditor::getNextLine()
{
    char    *item;

    this->lst->getNextItem(item);
    return (item);
}

char    *TextEditor::getPrevLine()
{
    char    *item;

    this->lst->getPrevItem(item);
    return (item);
}