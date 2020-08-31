/*********************************************
 * Authors:  Dacheng Lin
 * Assig #7:   MST & SHORTEST PATH ALOGRITHM
 * Class:    CS 008
 * Section:  MW 9:45-11:10 TTH 9:45-11:50
 * Due Date: 05/01/2020
*********************************************/
#ifndef LINKED_FUNCTIONS_H
#define LINKED_FUNCTIONS_H

#include <iostream>
#include <cassert>

#include "node_struct.h"

using namespace std;

// Author: Dacheng Lin (Link)
// LInked FUnctions  EDITTED on Dec 1, 2019 Link

template <typename ITEM_TYPE>
void _Print_my_nodes ( node<ITEM_TYPE> * head,
                     ostream & outs = cout);
//Post-condition: Print the items in the list

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _Insert_head(node<ITEM_TYPE> *& head,
                             ITEM_TYPE insert_this );
//Post-condition: Insert the item at the beginning of the list

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _Insert_after(node<ITEM_TYPE> *& head,
                              node<ITEM_TYPE> *& after_this,
                              ITEM_TYPE insert_this);
//Post-condition: Insert the item after the mark pointer.

template <typename ITEM_TYPE>
ITEM_TYPE _Remove_head(node<ITEM_TYPE> *& head);
//Post-condition: Remove the item at the beginning.

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _Search_my_list(node<ITEM_TYPE> * head,
                                 ITEM_TYPE find_me);
//Post-condition: Find the target in the list, return head if
//                not found.

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _Insert_before(node<ITEM_TYPE>* & head,
                                node<ITEM_TYPE>* & before_this,
                                ITEM_TYPE insert_this);
//Post-condition: Insert the item before the mark pointer.

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _Previous_Node(node<ITEM_TYPE>* & head,
                                node<ITEM_TYPE>* mark);
//Post-condition: Return the pointer that points before the
//                mark pointer.

template <typename ITEM_TYPE>
ITEM_TYPE _Delete_Node(node<ITEM_TYPE> *& head,
                       node<ITEM_TYPE> * delete_this);
//Post-condition: Delete the note at this marked position.

template <typename ITEM_TYPE>
node <ITEM_TYPE>* _Copy_List(node<ITEM_TYPE>* head);
//Post-condition: Duplicate the list that's led by the head.

template <typename ITEM_TYPE>
void _ClearList(node<ITEM_TYPE>* & head);
//Post-condition: Clear all the nodes in the list.

template <typename ITEM_TYPE>
ITEM_TYPE & At(node<ITEM_TYPE>* head, int pos);
//Post-condition: Return the item at certain position.

template <typename ITEM_TYPE>
void _Print_nodes_Backwards(node <ITEM_TYPE> * head,
                            ostream & outs = cout);
//Post-condition: Print the list starting from the back.

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _RightAfter_Item(node<ITEM_TYPE>* & head,
                                  ITEM_TYPE item,
                                  bool ascending = true);

template <class ITEM_TYPE>
node<ITEM_TYPE>*  _InsertSorted(node<ITEM_TYPE>* & head,ITEM_TYPE item,
                                bool ascending, bool uniqueness, int& size);

template <class ITEM_TYPE>
int _Size(node<ITEM_TYPE>* head);

//******************************************** PRINT
template <typename ITEM_TYPE>
void _Print_my_nodes ( node<ITEM_TYPE> * head,
                       ostream & outs)
{
    node <ITEM_TYPE> * walker = head;

    while (walker != nullptr)         // While the current/next ptr
                                      // pointer is not null
    {
        outs <<  *walker;             // Print the items

        walker = walker -> next;
    }

    outs << "||| \n";


}

//******************************************** INSERT HEAD
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _Insert_head(node<ITEM_TYPE> *& head,
                              ITEM_TYPE insert_this )
{
    node <ITEM_TYPE> * leader = new node<ITEM_TYPE>();
                               // Create the new box for
                               // the head and keep the item
    leader -> next = head;
                               // After the walker the next
                               // will be pointing to the
                               // same position that head points
    head = leader;             // Change the head walker at
                               // the end

    leader -> _item = insert_this;

    return leader;

}

//******************************************** INSERT AFTER
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _Insert_after(node<ITEM_TYPE> *& head,
                               node<ITEM_TYPE> *& after_this,
                               ITEM_TYPE insert_this)
{
    if (head == nullptr || after_this == nullptr)// Insert head if empty
        return _Insert_head(head,insert_this);

    node <ITEM_TYPE> * add_here = new node<ITEM_TYPE>(insert_this);
                                            // Create the box

    add_here -> next = after_this -> next;  // let this new box holder
                                            // 's next destination to be
                                            // the same as the another
    after_this -> next = add_here;          // Change that one's next
                                            // to this new box

//    head = after_this; ??

    return add_here;



}

//********************************************** REMOVE HEAD
template <typename ITEM_TYPE>
ITEM_TYPE _Remove_head(node<ITEM_TYPE> *& head)
{
    assert(head != nullptr);     // If head points to null space

    node <ITEM_TYPE>* walker = head;
    ITEM_TYPE deleted_item = head -> _item; // Keep the last node's item

    head = head -> next;   // Head ptr is now skipping 1 box


    delete walker;    // Remove the box by the copied label

    return deleted_item;      // Return the item


}

//************************************************ SEARCH ITEM
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _Search_my_list(node<ITEM_TYPE> * head,
                                 ITEM_TYPE find_me)
{
    node <ITEM_TYPE> * finder = head;   // Create the copy of the head
                                        // label
    while (finder != nullptr)   // while is not end of the list
    {
        if (finder -> _item == find_me) // Match the item
        {
            return finder;              // Return the founded label
        }

        finder = finder -> next;        // Ready to go to the next box
    }

//    assert(finder != nullptr);
    return finder;
}

//************************************************* INSERT BEFORE
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _Insert_before(node<ITEM_TYPE>* & head,
                                node<ITEM_TYPE>* & before_this,
                                ITEM_TYPE insert_this)
{
    if(before_this == head || head == nullptr)  // if before this is headptr
        return _Insert_head(head,insert_this);  // Insert head


    node <ITEM_TYPE>* walker = _Previous_Node(head,before_this);
                                    //  Find the address of the previous
                                    //  box

    node <ITEM_TYPE>* add_here = new node <ITEM_TYPE>(insert_this);
                                    //  Create a new box with the item

    add_here -> next = before_this; // Insert the box in front of the before


    walker -> next = add_here;     // Change previous box 's next to
                                   // the new box instead of before this

    return add_here;
}


//*************************************************** PREVI NODE
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _Previous_Node(node<ITEM_TYPE>* & head,
                                node<ITEM_TYPE>* mark)
{
//    assert(head != nullptr);

    if(mark == nullptr || head == nullptr)   // Return nullptr if the prev is head
        return head;

    node <ITEM_TYPE>* walker = head;


    while( walker != nullptr)      // Before it reaches the end
    {
        if(walker -> next == mark) // ITEM FOUND
            return walker;

        walker = walker -> next;   // Walk through the list
                                   // until the walker's next place
                                   // hits before this
    }

//    assert(walker != nullptr);     // If reach the end and the mark
                                   // is not in the list (assert)
    return head;
}

//**************************************************** DELETE THIS
template <typename ITEM_TYPE>
ITEM_TYPE _Delete_Node(node<ITEM_TYPE> *& head,
                       node<ITEM_TYPE> * delete_this)
{
    assert(delete_this != nullptr);  // Assert if the list already
                                     //

    if (delete_this == head)
        return _Remove_head(head);         // Return the only item

    node <ITEM_TYPE>* walker = head;
    ITEM_TYPE deleted_item = delete_this ->_item;

    walker = _Previous_Node(head,delete_this);
    // Walker points at the node before delete

    walker -> next = delete_this -> next;

    delete delete_this;
    // Set next of this node to be the next of delete this(skip delete)
    // right now walker's next is delete this
    return deleted_item;

}

//************************************************* COPY LIST
template <typename ITEM_TYPE>
node <ITEM_TYPE>* _Copy_List(node<ITEM_TYPE>*& dest_head,
                             node<ITEM_TYPE>* src_head)
{
    assert(dest_head == nullptr);  // Make sure dest_head
                                   // is always nullptr before copying

    if (src_head == nullptr)   // Return nullprt if empty
    {
        dest_head = nullptr;
        return nullptr;
    }

    node <ITEM_TYPE>* src_walker = src_head;  // Assign a src walker

    node <ITEM_TYPE>* dest_walker =     // Assign a dest walker
                    _Insert_head(dest_head,src_head-> _item);

    node <ITEM_TYPE>* tail = dest_head;    // Declare a pointer for tail

    src_walker = src_walker -> next;    // Move the walker to the next

    // Keep walking until hitting the head
    for(; src_walker != nullptr; src_walker = src_walker -> next)
    {
        // Keep inserting after the last node
        // and return the new created node position to lhs
         dest_walker =_Insert_after(dest_head,dest_walker,
                                      src_walker->_item);

        if(src_walker -> next == nullptr)
            tail = dest_walker;          // Set the tail when it's about
                                        // to the nullptr
    }

   // dest_walker -> next = nullptr;      // Set the nullptr for the dest

    return tail;     // Return the last node of the dest


}
//************************************************* CLEAR LIST
template <typename ITEM_TYPE>
void _ClearList(node<ITEM_TYPE>* & head)
{
    assert(head != nullptr);     // Prevent delete from null space
    node <ITEM_TYPE>* walker = head;    // Assign the walker

    while (walker -> next != nullptr)  // While walker's next box
                                       // is not empty
    {
        node <ITEM_TYPE>* remover = walker; // Assign the remover

        walker = walker -> next;           // walker skips one box
        head = walker;                     // Redirect the head pointer


        delete remover;
    }


    head = walker -> next;   // Head points to null

    delete walker;
}

//*************************************************  AT POSITION
template <typename ITEM_TYPE>
ITEM_TYPE & At(node<ITEM_TYPE>* head, int pos)
{
    int start_pos = 0;
    node <ITEM_TYPE>* walker = head;

    if(start_pos == pos)
        return walker -> _item;    // Return current item if
                                   // position 0

    while (start_pos != pos)       // Keep finding until matches
    {
        walker = walker -> next;

        start_pos++;               // Increase the counter

        assert(walker != nullptr);  // Break when out of space
    }

    return walker-> _item;         // Return item at that pos

}

//************************************************ PRINT BACKWARD
template <typename ITEM_TYPE>
void _Print_nodes_Backwards(node <ITEM_TYPE> * head,
                            ostream & outs)
{
    if (head == nullptr)       // Won't print if empty list
        return;

    if(head -> next == nullptr)  // Print the only node
    {
        cout << *head;
        return;
    }

    node <ITEM_TYPE>* walker = head;

    while (walker -> next != nullptr)
    {
        walker = walker -> next;
    }

    outs << *walker;    // Print the last one

    node <ITEM_TYPE> * print_before = _Previous_Node(head, walker);


    while (print_before != head)
    {
       outs << *print_before;    // Cout the previous item

       walker = _Previous_Node(head,print_before);
                                 // Let the walker find the next
                                 // previous node
       print_before = walker;    // Move the print to where walker
                                 // holds to
    }

    outs << *print_before;       // Print the very first item
    outs << endl;
}

//*************************************************** LAST NODE
template <typename ITEM_TYPE>
node<ITEM_TYPE> * _Last_Node(node<ITEM_TYPE>* head)
{
    assert(head != nullptr);

    node <ITEM_TYPE>* walker = head;

    while(walker ->next != nullptr)
    {
        walker = walker -> next;  // Return the last node
    }

    return walker;


}

//*************************************************** SIZE
template <class ITEM_TYPE>
int _Size(node<ITEM_TYPE>* head)
{
    if(head == nullptr)  // If it's empty list
        return -1;

    int list_size = 0;   // Set a counter for the size
    node<ITEM_TYPE>* walker = head;

    // Keep walking until read the end
    for(; walker != nullptr; walker = walker-> next)
    {
        list_size++;   // Keep counting also
    }

    return list_size;


}

//*************************************************** RIGHT AFTER
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _RightAfter_Item(node<ITEM_TYPE>* & head,
                                  ITEM_TYPE item,
                                  bool ascending )
{
    if (head == nullptr) // If there is a empty list
        return nullptr;

    node <ITEM_TYPE>* leader = head;   // Assign Leader and follower
    node <ITEM_TYPE>* follower = head;

    if (ascending)    // If the order is from smallest to greatest
    {
        // If the the item is smaller than the very first
        if(item < head -> _item)
            return nullptr;


        leader = leader -> next;  // Advance Lead first

        // Process until follower is about reach the end
        while (follower -> next != nullptr)
        {
            if (leader -> _item > item ||
                follower -> _item == item) // If the next item is bigger
                return follower;

            if (leader != nullptr)       // Only advance leader only if
                leader = leader -> next; // it's not nullpter

            follower = follower -> next; // Advance the follower

        }

        return follower;  // Return the follower
    }

    else       // Reverse Version of the Ascending
    {
        // If the the item is smaller than the very first
        if(item > head -> _item)
            return nullptr;


        leader = leader -> next;  // Advance Lead first

        // Process until follower is about reach the end
        while (follower -> next != nullptr)
        {
            if (leader -> _item < item ||
                follower -> _item == item) // If the next item is bigger
                return follower;

            if (leader != nullptr)       // Only advance leader only if
                leader = leader -> next; // it's not nullpter

            follower = follower -> next; // Advance the follower

        }

        return follower;  // Return the follower
    }

}

//*********************************************** INSERT SORTED
template <class ITEM_TYPE>
node<ITEM_TYPE>*  _InsertSorted(node<ITEM_TYPE>* & head,ITEM_TYPE item,
                                bool ascending, bool uniqueness, int& size)
{
    if (head == nullptr)     // If empty, just insert in the front
    {
        size++;              // Increase size if inserting
        return _Insert_head(head,item);
    }
    node<ITEM_TYPE> * insert_here = _RightAfter_Item(head,item,ascending);

    // If there is duplicated one
    if (insert_here != nullptr &&insert_here -> _item == item
                               && uniqueness)
    {
        insert_here -> _item = item;    // Rewrite the item

        return insert_here;             // Return here
    }

    size++;              // Increase size if inserting
    return _Insert_after(head,insert_here,item); // Insert after here


}

#endif // LINKED_FUNCTIONS_H
