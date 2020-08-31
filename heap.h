#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include "comparators_stadiums.h"
#include <algorithm>

template <typename E, typename C>           // element and comparator

class Heap {                           		// heap interface
  public:
    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
    ******************************/
    Heap();                                	// default constructor
    Heap(const Heap<E, C>& source);     	// copy constructor
    ~Heap();                               	// destructor

    /***********************************
     ** MODIFICATION MEMBER FUNCTIONS **
    ***********************************/
    Heap<E, C>& operator=(const Heap<E, C>& source);    // overloaded assignment operator
    void insert(const E& value);       		// insert new data
    E remove();              				// remove root data
    std::vector<E>& sortedList();

    /*******************************
     ** CONSTANT MEMBER FUNCTIONS **
    *******************************/
    int size() const;
    bool empty() const;
    E peek() const;
    Heap<E, C>& heapify(E *elements, int size) const;
    void preOrderDisplay(int root = 0) const;

  private:									//place any private member functions
    void expand();							//resize the array
    void swap(int i1, int i2);              // swap the two elements

  private:									//private member variables
    E *array;
    int _size;
    int _allocated;
};
/******************************************************************************
 *  Heap Class
 *    Array implementation of heap
 ******************************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/******************************************************************************
 *  Heap()
 *    Constructor; initailze the empty heap with 20 spaces
 *    Parameters: none
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  Heap()
 *    Copy Constructor; Copies over the values from the given heap
 *    Parameters: const heap&
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  ~Heap()
 *    Destructor; Destroy all values in the heap
 *    Parameters: none
 *    Return: void
 ******************************************************************************/


/***********************************
 ** MODIFICATION MEMBER FUNCTIONS **
 ***********************************/

/******************************************************************************
 *  Heap<E, C>& operator =(const Heap& source);
 *
 *    delete values in the current heap and copy over values
 * ----------------------------------------------------------------------------
 *    Parameters: const Heap<E, C>
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  void insert(const E& value);
 *
 *    insert the new data into the heap
 * ----------------------------------------------------------------------------
 *    Parameters: const E&
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  E remove();
 *
 *    Remove the root value and returns it
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/


/*******************************
 ** CONSTANT MEMBER FUNCTIONS **
 *******************************/

/******************************************************************************
 *  int size() const;
 *
 *    Returns the size of the heap
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: int
 ******************************************************************************/

/******************************************************************************
 *  bool empty() const;
 *
 *    Determines if heap is empty
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: bool
 ******************************************************************************/

/******************************************************************************
 *  E peek() const;
 *
 *    Returns the root of the heap
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: E
 ******************************************************************************/

/******************************************************************************
 *  Heap<E, C>& heapify(E *elements, int size) const;
 *
 *    Convert back to a heap
 * ----------------------------------------------------------------------------
 *    Parameters: E *, int
 * ----------------------------------------------------------------------------
 *    Return: Heap<E, C>&
 ******************************************************************************/

/******************************************************************************
 *  void preOrderDisplay(int root = 0) const;
 *
 *    Display the preORderDisplay
 * ----------------------------------------------------------------------------
 *    Parameters:
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/


/******************************************************************************
 *  void expand() const;
 *
 *    Alloocate more memory for the heap
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  void swap(int i1, int2) const;
 *
 *    Wap the two elements at given indexes
 * ----------------------------------------------------------------------------
 *    Parameters: int, int
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

template <typename E, typename C>
Heap<E, C>::Heap() {
    _size = 0;
    _allocated = 20;
    array = new E[_allocated];
}

template <typename E, typename C>
Heap<E, C>::Heap(const Heap& source) {
    _size = 0;
    *this = source;
}

template <typename E, typename C>
Heap<E, C>::~Heap() {
    delete[] array;
}

template <typename E, typename C>
Heap<E, C>& Heap<E, C>::operator =(const Heap<E, C>& source) {
    if(this == &source) {
        return *this;
    }

    delete[] array;
    _size = source._size;
    _allocated = source._allocated;

    array = new E[_allocated];
    for(int i = 0; i < source._size; i++) {
        array[i] = source.array[i];
    }
}

template <typename E, typename C>
void Heap<E, C>::insert(const E& value) {
    int parent, current;
    //E temp;

    if(_size == _allocated) {
        expand();
    }

    array[_size] = value;
    parent = (_size - 1) / 2;
    current = _size;

    while(parent >= 0 && C()(array[current], array[parent])) {
        if(current == parent) {
            break;
        }
        swap(current, parent);

        current = parent;
        parent = (parent - 1) / 2;
    }
    _size++;
}

template <typename E, typename C>
E Heap<E, C>::remove() {
    int rChild, lChild, current;

    //swap root and last element remove the initial root
    swap(0, --_size);

    current = 0;
    rChild = 2;
    lChild = 1;
    //restore heap-order property
    while (lChild < _size) {         //until no more children
        if(rChild >= _size) {        //only left child
            if(C()(array[lChild], array[current])) {
                //swap with left
                swap(current, lChild);
            }

            break;                  //reached end of heap
        }

        //at least 1 or 2 children can be swapped
        if(C()(array[lChild], array[current]) || C()(array[rChild], array[current])) {
            if(C()(array[lChild], array[rChild])) {   //swap left
                swap(current, lChild);
                current = lChild;
            } else {                                //swap right
                swap(current, rChild);
                current = rChild;
            }
        } else {
            break;
        }

        rChild = current*2 + 2;
        lChild = current*2 + 1;
    }

    return array[_size];
}

template <typename E, typename C>
std::vector<E>& Heap<E, C>::sortedList() {

    // Need a dynamic Sorting vector
    std::vector<E>* sorted = new vector<E>;
    Heap<E, C> temp;

    for(int i = 0; i < _size; i++) {
        temp.insert(array[i]);
    }

    while(!temp.empty()) {
        sorted->push_back(temp.remove());
    }

    // Use the sorting alogrithm for the vector
    sort(sorted->begin(),sorted->end(),C());

    return *sorted;
}

template <typename E, typename C>
E Heap<E, C>::peek() const {
    return empty() ? nullptr : array[0];
}

template <typename E, typename C>
int Heap<E, C>::size() const {
    return _size;
}

template <typename E, typename C>
bool Heap<E, C>::empty() const {
    return size() <= 0;
}

template <typename E, typename C>
Heap<E, C>& Heap<E, C>::heapify(E *elements, int size) const {
    Heap<E, C> result;

    for(int i = 0; i < size; i++) {
        result.insert(elements[i]);
    }

    return result;
}

template <typename E, typename C>
void Heap<E, C>::expand() {
    _allocated *= 2;
    E *temp = new E[_allocated];

    for(int i = 0; i < _size; i++) {
        temp[i] = array[i];
    }

    delete[] array;
    array = temp;
}

template <typename E, typename C>
void Heap<E, C>::swap(int i1, int i2) {
    E temp = array[i1];
    array[i1] = array[i2];
    array[i2] = temp;
}

template <typename E, typename C>
void Heap<E, C>::preOrderDisplay(int root) const {
    if (root >= _size)
        return;

    std::cout << array[root] << " ";

    preOrderDisplay(2*root + 1);
    preOrderDisplay(2*root + 2);
}


#endif // HEAP_H
