/*********************************************
 * Authors:  Dacheng Lin
 * Assig #7:   MST & SHORTEST PATH ALOGRITHM
 * Class:    CS 008
 * Section:  MW 9:45-11:10 TTH 9:45-11:50
 * Due Date: 05/01/2020
*********************************************/
#ifndef NODE_STRUCT_H
#define NODE_STRUCT_H

#include <iostream>
#include <cassert>

using namespace std;

template<typename ITEM_TYPE>
struct node
{
public:
    node(ITEM_TYPE item = ITEM_TYPE ());

    template <typename T>
    friend ostream & operator <<(ostream & outs,
                                 const node<T> &print_this );

    ITEM_TYPE _item;
    node* next;


};

/* Pre-condition: None
 * Post-condition: The private variables will be initialized
 */
template <typename ITEM_TYPE>
node<ITEM_TYPE> :: node(ITEM_TYPE item) :
        _item (item), next (nullptr)
{
     // Initilizations

}


template <typename T>
ostream & operator <<(ostream & outs,
                     const node<T> &print_this )
{
    outs << "[" << print_this._item << "]";


    return outs;

}




#endif // NODE_STRUCT_H
