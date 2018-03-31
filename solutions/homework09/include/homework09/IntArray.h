/***
  Copyright 2018 J. West
 */
#ifndef HOMEWORK09_INCLUDE_HOMEWORK09_INTARRAY_H_
#define HOMEWORK09_INCLUDE_HOMEWORK09_INTARRAY_H_

class IntArray {
  public:
    /*** construct an array with n elements */
    IntArray(unsigned int n);
    /*** destruct and free memeory allocations */
    ~IntArray(void);
    /*** get value at index k
      throws std::out_of_range if k is outside of array bounds 
      */
    int get(unsigned int k);
    /*** put value of <value> at index k
      throws std::out_of_range if k is outside of array bounds 
      */
    void put(unsigned int k, int value);
    /*** return size of the array */
    int size(void);
    /*** allow array indexing into array values
      throws std::out_of_range if k is outside of array bounds 
      */
    int &operator[](unsigned int k);

  private:
    /*** check if k is within array bounds.
      throws std::out_of_range if k is outside of array bounds 
      */
    void checkIndex(unsigned int k);
    /*** pointer to allocated data space */
    int *data_;
    /*** number of elements in allocated data space */
    unsigned int size_;
};

#endif  // HOMEWORK09_INCLUDE_HOMEWORK09_INTARRAY_H_
