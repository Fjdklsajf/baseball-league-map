/*********************************************
 * Authors:  Dacheng Lin
 * Assig #7:   MST & SHORTEST PATH ALOGRITHM
 * Class:    CS 008
 * Section:  MW 9:45-11:10 TTH 9:45-11:50
 * Due Date: 05/01/2020
*********************************************/
#ifndef LINKLIST_CLASS_H
#define LINKLIST_CLASS_H

#include <iostream>
#include <cassert>
#include "linked_functions.h"

using namespace std;


template <class ITEM_TYPE>
class List
{
public:
    //* Iterator
    class Iterator
    {
    public:
        friend class List;
        Iterator() {_ptr = nullptr;}
        Iterator(node<ITEM_TYPE>* p)
        {
            _ptr = p;
        }

        //* Dereference Operator
        ITEM_TYPE operator*()
        {
            assert(_ptr);
            return _ptr -> _item;
        }

        node<ITEM_TYPE>* operator ->()  //
        {
            assert(_ptr);
            return _ptr;
        }
        //* Check Emptyness
        bool is_null()
        {
            if(_ptr)
                return false;
            return true;
        }

        //* Comparision Operators
        friend bool operator != (const Iterator & lhs,
                                 const Iterator & rhs)
        {
            return (lhs._ptr != rhs._ptr);
            // Compare two node pointers
        }
        friend bool operator == (const Iterator & lhs,
                                 const Iterator & rhs)
        {
            return (lhs._ptr  == rhs._ptr );
            // Compare two node pointers
        }

        //* Implement Operations
        friend Iterator operator++ (Iterator & It,
                                    int unused)
        {
            unused++;      // Unused
            Iterator Hold;
            Hold = It;
            ++It;

            return Hold;
        }

        Iterator & operator ++ ()
        {
            _ptr = _ptr -> next;
            return *this;
        }

    private:
        node<ITEM_TYPE>* _ptr;
    };

    // Default construtor
    List(bool order = true, bool unique = false);

    //* BIG THREE
    ~List();
    List(const List<ITEM_TYPE> & copy_me);
    List & operator =(const List<ITEM_TYPE> & rhs);

    //* Accessor
    int get_size() const;

    //* Command Functions
    node<ITEM_TYPE>* Search(const ITEM_TYPE & key);
    node<ITEM_TYPE>* Previ(node<ITEM_TYPE>* iMarker);
    node<ITEM_TYPE>* Begin() const;
    node<ITEM_TYPE>* End() const;
    ITEM_TYPE Delete(node<ITEM_TYPE>* iMarker);


    //* Insert Sorted
    node<ITEM_TYPE>* InsertSorted(ITEM_TYPE item);
    node<ITEM_TYPE>* Insert_After(ITEM_TYPE i,
                                  node<ITEM_TYPE>* iMarker);

    //* Operators
    ITEM_TYPE & at_index(int index) {return At(_head,index);}
    ITEM_TYPE & operator [](int index);
    const ITEM_TYPE & operator[](ITEM_TYPE index) const;

    //* I/O stream
    template<class T>
    friend ostream& operator <<(ostream& outs, const List<T> & l);

 private:
    node<ITEM_TYPE>* _head;
    int _size;
    bool _order;
    bool _unique;

};

template <class ITEM_TYPE>
List<ITEM_TYPE>:: List(bool order, bool unique) : _head(nullptr),
                  _size(0),_order(order), _unique(unique)
{

}

//******************************************** BIG THREE-DESTRU
/* Pre-condition: none
 * Post-condition: The dynamic space will be released in the freestore
 */
template <class ITEM_TYPE>
List<ITEM_TYPE> :: ~List()
{
    delete _head;
    _head = nullptr;

}

//******************************************** BIG THREE-COPY
/* Pre-condition: Receive a list object
 * Post-condition: The dynamic space will be copied
 */
template<class ITEM_TYPE>
List<ITEM_TYPE> :: List (const List <ITEM_TYPE> & me)
{
    _head = nullptr;  // Assing head to nullptr

    _Copy_List(_head,me._head);
    _order = me._order;
    _unique = me._unique;
    _size = me._size;
}

//******************************************** BIG THREE-ASSIGN
/* Pre-condition: Receive a list object
 * Post-condition: The dynamic space will be reassigned
 */
template <class ITEM_TYPE>
List<ITEM_TYPE> & List<ITEM_TYPE> :: operator =(const List<ITEM_TYPE> & rhs)
{
    if(this != &rhs)
    {
        _ClearList(_head);   //  Clear the list before constructing
        _Copy_List(_head,rhs._head);
        _order = rhs._order;
        _unique = rhs._unique;
        _size = rhs._size;
    }


    return *this;

}

//******************************************** ACCESSOR
/* Pre-condition: none
 * Post-condition: return the size of the list
 */
template <class ITEM_TYPE>
int List<ITEM_TYPE> :: get_size() const
{
    return _size;
}

//**********************************************  INSERT AFTER
/* Pre-condition: The node pointer that points at target item
 * Post-condition: The element will be inserted after the target
 */
template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>:: Insert_After(ITEM_TYPE i,
                                           node<ITEM_TYPE>* iMarker)
{
    return _Insert_after(_head,iMarker,i);
}


//*********************************************** INSERT SORTED
/* Pre-condition: The item needs to be inserted
 * Post-condition: The element will be inserted sorted
 */
template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE> :: InsertSorted(ITEM_TYPE item)
{
    return _InsertSorted(_head,item,_order,_unique,_size);

}
//*********************************************** SEARCH
/* Pre-condition: The item that needs to be search
 * Post-condition: The node ptr of that target will be returned
 */
template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE> :: Search(const ITEM_TYPE & key)
{
    return _Search_my_list(_head,key);
}

//*********************************************** PREVIOUS
/* Pre-condition: The node pointer that points at target item
 * Post-condition: The node ptr before that target will be inserted
 */
template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE> :: Previ(node<ITEM_TYPE>* iMarker)
{
    return _Previous_Node(_head,iMarker);
}

//*********************************************** AT BEGIN
/* Pre-condition: None
 * Post-condition: The head ptr of the list will be returned
 */
template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE> :: Begin() const
{
    return _head;         // Get the head of the list
}

//*********************************************** AT END
/* Pre-condition: None
 * Post-condition: The End ptr of the list will be returned
 */
template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE> :: End() const
{
    return _Last_Node(_head);   // Get the last element
}

//*********************************************** DELETE
/* Pre-condition: The node prt at the delete item
 * Post-condition: The item was deleted will be returned
 */
template <class ITEM_TYPE>
ITEM_TYPE List<ITEM_TYPE> :: Delete(node<ITEM_TYPE>* iMarker)
{
    if(_size > 0)
        _size--;
    return _Delete_Node(_head,iMarker);
}

//************************************************ BRACKET OPERA
/* Pre-condition: The valid index
 * Post-condition: The element at that index in the list
 */
template <class ITEM_TYPE>
ITEM_TYPE & List<ITEM_TYPE> :: operator [](int index)
{
    return At(_head,index);   // Return the element at the index
}

template <class ITEM_TYPE>
const ITEM_TYPE & List<ITEM_TYPE> :: operator[](ITEM_TYPE index) const
{
    return At(_head,index);  // Return the element at the index
}


//************************************************ << OPERA
template<class T>
ostream& operator <<(ostream& outs, const List<T> & l)
{
    _Print_my_nodes(l._head,outs);    // Print out the elements


    return outs;
}


#endif // LINKLIST_CLASS_H
