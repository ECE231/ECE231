/***
  Copyright 2018 J. West
 */
#ifndef HOMEWORK10_INCLUDE_HOMEWORK10_EDITOR_BUFFER_H_
#define HOMEWORK10_INCLUDE_HOMEWORK10_EDITOR_BUFFER_H_
#include <string>
#include <iostream>
struct Element {
  char val;
  Element *prev;
  Element *next;
};
std::ostream &operator<<(std::ostream &os, const Element &e);

class EditorBuffer {
  public:
    EditorBuffer(void);
    ~EditorBuffer(void);
    void moveCursorForward();
    void moveCursorBackward();
    void moveCursorToStart();
    void moveCursorToEnd();
    void insertCharacter(char);
    void deleteCharacter();
    std::string getText() const;
    int getCursor() const;
    friend std::ostream &operator<<(std::ostream &os, const EditorBuffer &e);
  private:
    Element *start_;
    Element *cursor_;
};
std::ostream &operator<<(std::ostream &os, const EditorBuffer &e);

#endif  // HOMEWORK10_INCLUDE_HOMEWORK10_EDITOR_BUFFER_H_
