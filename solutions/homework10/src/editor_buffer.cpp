/***
  Copyright 2018 J. West
 */
#include <stdlib.h>
#include <string>
#include "homework10/editor_buffer.h"

std::ostream &operator<<(std::ostream &os, const Element &e) {
  return os << "(" << e.val << "," << e.prev << "," << e.next << ")";
}

EditorBuffer::EditorBuffer(void) {
  cursor_ = start_ = new Element();
  start_->prev = start_->next = start_;
}

EditorBuffer::~EditorBuffer(void) {
  Element *e = start_->next;
  Element *tmp;
  while (e != start_) {
    tmp = e->next;
    delete e;
    e = tmp;
  }
  delete start_;
}
void EditorBuffer::moveCursorForward() {
  if (cursor_->next != start_) {
    cursor_ = cursor_->next;
  } else {
    std::cout << "tried to move past end of buffer\n";
  }
}
void EditorBuffer::moveCursorBackward() {
  if (cursor_->prev != start_) {
    cursor_ = cursor_->prev;
  } else {
    std::cout << "tried to move past start of buffer\n";
  }
}
void EditorBuffer::moveCursorToStart() {
  cursor_ = start_;
}
void EditorBuffer::moveCursorToEnd() {
  cursor_ = start_->prev;
}
void EditorBuffer::insertCharacter(char c) {
  Element *e = new Element();
  e->val = c;
  e->prev = cursor_;
  e->next = cursor_->next;
  cursor_->next->prev = e;
  cursor_->next = e;
  cursor_ = e;
}
void EditorBuffer::deleteCharacter() {
  if (cursor_->next == start_) {
    std::cout << "Can't delete past end of buffer\n";
    return;
  }
  Element *tmp = cursor_->next;
  cursor_->next->prev = cursor_;
  cursor_->next = cursor_->next->next;
  delete tmp;
}
std::string EditorBuffer::getText() const {
  Element *e = start_->next;
  std::string s;
  while (e != start_) {
    s.push_back(e->val);
    e = e->next;
  }
  return s;
}
int EditorBuffer::getCursor() const {
  Element *e = start_;
  int count = 0;
  while (e != cursor_) {
    count++;
    e = e->next;
  }
  return count;
}
std::ostream &operator<<(std::ostream &os, const EditorBuffer &eb) {
  Element *e = eb.start_->next;
  os << "Start = " << eb.start_ << " Cursor=" << eb.cursor_ << std::endl;
  while (e != eb.start_) {
    os << e << "->" << *e << std::endl;
    e = e->next;
  }
  return os;
}

