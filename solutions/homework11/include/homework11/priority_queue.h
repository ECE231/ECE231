/***
  Copyright 2018 J. West
 */
#ifndef HOMEWORK11_INCLUDE_HOMEWORK11_PRIORITY_QUEUE_H_
#define HOMEWORK11_INCLUDE_HOMEWORK11_PRIORITY_QUEUE_H_
#include <string>
#include <iostream>

template <typename ValueType>
class PriorityQueue {
  public:
    PriorityQueue(void);
    ~PriorityQueue(void);
    int size() const;
    bool isEmpty() const;
    void clear();
    void enqueue(ValueType value, double priority);
    ValueType dequeue();
    ValueType peek() const;
    PriorityQueue(const PriorityQueue<ValueType> &src);
    PriorityQueue<ValueType> &operator=(const PriorityQueue<ValueType> &src);

  private:
    struct Cell {
      ValueType data;
      double priority;
      Cell *link;
    };
    Cell *head;
    Cell *tail;
    int count;
    void deepCopy(const PriorityQueue<ValueType> &src);
};

template <typename ValueType>
PriorityQueue<ValueType>::PriorityQueue() {
  head = tail = NULL;
  count= 0;
}

template <typename ValueType>
PriorityQueue<ValueType>::~PriorityQueue() {
  clear();
}

template <typename ValueType>
int PriorityQueue<ValueType>::size() const {
  return count;
}

template <typename ValueType>
bool PriorityQueue<ValueType>::isEmpty() const {
  return count == 0;
}

template <typename ValueType>
void PriorityQueue<ValueType>::clear() {
  while (!isEmpty()) dequeue();
}

template <typename ValueType>
void PriorityQueue<ValueType>::enqueue(ValueType value, double priority) {
  Cell *newCell = new Cell;
  newCell->data = value;
  newCell->priority = priority;
  // if empty then add this one.
  if (head == NULL) {
    head = tail = newCell;
    newCell->link = NULL;
  // if higher priority than head then make it the new head
  } else if (head->priority > priority) {
    newCell->link = head;
    head = newCell;
  // see if it higher than others
  } else {
    Cell *cp;
    for (cp = head ; cp->link != NULL ; cp = cp->link) {
      if (cp->link->priority > priority) {
        newCell->link = cp->link;
        cp->link = newCell;
        count++;
        return;
      }
    }
    // if lowest priority then add to tail
    newCell->link = NULL;
    tail->link = newCell;
  }
  count++;
}

template <typename ValueType>
ValueType PriorityQueue<ValueType>::dequeue() {
  if (isEmpty()) throw std::runtime_error("tried to dequeue when empty");
  Cell *cp = head;
  ValueType result = cp->data;
  head = cp->link;
  if (head == NULL) tail = NULL;
  delete cp;
  count--;
  return result;
}

template <typename ValueType>
ValueType PriorityQueue<ValueType>::peek() const {
  if (isEmpty()) throw std::runtime_error("tried to peek when empty");
  return head->data;
}

template <typename ValueType>
PriorityQueue<ValueType>::PriorityQueue(const PriorityQueue<ValueType> &src) {
  deepCopy(src);
}

template <typename ValueType>
PriorityQueue<ValueType> &PriorityQueue<ValueType>::operator=(
  const PriorityQueue<ValueType> &src) {
  if (this != &src) {
    clear();
    deepCopy(src);
  }
  return *this;
}

template <typename ValueType>
void PriorityQueue<ValueType>::deepCopy(const PriorityQueue<ValueType> &src) {
  head = tail = NULL;
  count = 0;
  for (Cell *cp = src.head ; cp != NULL ; cp = cp->link) {
    enqueue(cp->data, cp->priority);
  }
}
#endif  // HOMEWORK11_INCLUDE_HOMEWORK11_PRIORITY_QUEUE
