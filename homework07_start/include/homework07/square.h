/***
  Copyright 2018 J. West
 */
#ifndef HOMEWORK07_INCLUDE_HOMEWORK07_SQUARE_H_
#define HOMEWORK07_INCLUDE_HOMEWORK07_SQUARE_H_

typedef enum {N, E, S, W} Direction;
typedef enum {OCCUPIED, EMPTY, START, MARKED} State;

class Square {
  public:
    Square(void);
    void set_state(State s) {state_ = s;}
    State state(void) const {return state_;}
  private:
    State state_;
};

#endif  // HOMEWORK07_INCLUDE_HOMEWORK07_SQUARE_H_
