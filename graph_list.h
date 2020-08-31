/*********************************************
 * Authors:  Dacheng Lin
 * Assig #7:   MST & SHORTEST PATH ALOGRITHM
 * Class:    CS 008
 * Section:  MW 9:45-11:10 TTH 9:45-11:50
 * Due Date: 05/01/2020
*********************************************/
#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cassert>
#include <set>
#include <vector>
#include <functional>
#include "location_info.h"
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QSaveFile>
#include <QtDebug>
#include <QDebug>
#include <string>
#include <QFileDialog>
#include <QPainter>
#include <ctime>

using namespace std;

const bool debugging_tool = false;   // Debugging check

template <class Item_Type, class Element>
class Graph_List
{

public:

    //--------STATIC ARRAY STORAGE---------
    const static int STORAGE = 200;

    //--------CONSTURCTOR----------
    Graph_List(int capacity = 100);
    ~Graph_List();

    //---------ACCESSOR---------
    int get_size() const
    {
        return _size;
    }
    Item_Type start_vertex_at(int index) const;
    int vertex_index_of(const Item_Type& target) const;

    //---------MODIFICATIONS----------
    void add_vertex(const int& vertex_index,
                    Item_Type vertex_neighbor);
    void remove_vertex(const int& vertex_index,
                       Item_Type vertex_neighbor);


    //---------OVERLOADING OPERATORS-----------
    List<Item_Type>& operator[](const int index)
    {
        List<Item_Type>* walker = _list;  // Assign a walker

        walker+= index;  // Walk to the assigned position

        return *walker;  // Return the index's list

    }
    const List<Item_Type>& operator[](const int index) const
    {
        List<Item_Type>* walker = _list;  // Assign a walker

        walker+= index;  // Walk to the assigned position

        return *walker;  // Return the index's list
    }

    //---------OVERLOADING OSTREAM OPERATOR-----------
    template<class TYPE>
    friend ostream & operator <<(ostream& outs,
                                 const Graph_List<TYPE,Element> & g)
    {
        List<Item_Type>* walker = g._list;  // Assign walker to walk through
        cout << g.get_size() << endl;

        for(int i = 0; i < g.get_size(); i++,walker++)
        {
            outs << *walker << endl;   // Print the first item
        }

        return outs;
    }


    //--------MST ALOGRITHMS-------
    vector<Item_Type> * Dijkstra_Algorithm(const Item_Type& start,
                                           int & v_size,
                                           int path_costs[]);
    void Prim_Algorithm();
    void Kruskal_Algorithm();



private:
    List<Item_Type> * _list;      // A list of sorted vertex list
    int _mst[STORAGE];            // List of the minimum spanning tree
    int _distance[STORAGE];       // List of shortest cost

    int _size;                    // Size of the list
    int _capacity;                // Capacity for the dynamic space

    void reserve(int new_capacity);  // Reallocation for space

    // Initialize the static array
    void init_1D(int*one_D, int col, int item = -1)
    {
        int* walker = one_D;       // Assign a pointer for 1D space

            for(; walker - one_D < col; walker++)
            {
                *walker = item;    // Initialize all the elements to be
                                   // same as the target item
            }
    }

};




/*************************************************
 * Graph Constructor
 * ----------------------------------------------
 * Precondition: The valid value of the capacity for
 * dynamic space
 * -----------------------------------------------
 * Postcondition: The dynamic spaces for the data
 * will be created with specific capacity.

**************************************************/
template  <class Item_Type,class Element>
Graph_List<Item_Type,Element>::Graph_List(int capacity)
{
    reserve(capacity);    // Reserve space for dynamic space
    init_1D(_distance,capacity,-1);  // Initialize the distance array
    init_1D(_mst,capacity,-1);  // Initialize the distance array
    _size = 0;
}

/*************************************************
 * Graph Destructor
 * ----------------------------------------------
 * Precondition: No parameter needed
 * -----------------------------------------------
 * Postcondition: The dynamic spaces for the data
 * will be released in a 2D-deallocation style.

**************************************************/
template <class Item_Type,class Element>
Graph_List<Item_Type,Element> ::~Graph_List()
{
    List<Item_Type>* walker;     // List walker
    node<Item_Type>* tracker;    // Tracker to help delete each list

    _list += _size -1;    // Go to very last position of
                          // the dyname space

    // Go through the list
    for(;_size > 0; _size--,_list--)
    {
        walker = _list;
        tracker = walker->Begin();

        // Assign the Iterator
        for(;walker->get_size() > 0;tracker = walker->Begin())
        {
            walker->Delete(tracker);
            //  Delete all the items in one list
        }

    }

    _list = nullptr;    // Release the whole list

    _size = 0;
}

/*************************************************
 * Helper: Reallocate 1D
 * ----------------------------------------------
 * Precondition: The new capacity for the space
 * -----------------------------------------------
 * Postcondition: The dynamic spaces will be expand
 * or shrink

**************************************************/
template  <class Item_Type,class Element>
void Graph_List<Item_Type,Element> ::reserve(int new_capacity)
{
    //**********ASSERTION
    assert(new_capacity > 0);// Only allows non-negative

    _capacity = new_capacity;

    // Enlarge the dynamic space when needed
    if(_size >= (_capacity) / 2)
        _capacity *= 2;

    _list = new List<Item_Type> [_capacity]; // Reserve that many spaces
                              // to the freestore
}

/*************************************************
 * Start_vertex_at
 * ----------------------------------------------
 * Precondition: The index of that list
 * -----------------------------------------------
 * Postcondition: The start vertex of a list will
 * be returned.

**************************************************/
template <class Item_Type, class Element>
Item_Type Graph_List<Item_Type,Element>::start_vertex_at
                                         (int index) const
{
    List<Item_Type>* walker = _list;  // Assign a walker
    walker+= index;  // Walk to the assigned position

    // Use node finder to find the walker's begin item
    node<Item_Type>* finder = walker->Begin();

    return finder->_item;   // Return the begin item
}

/*************************************************
 * vertex_index_of
 * ----------------------------------------------
 * Precondition: The target item in that list
 * -----------------------------------------------
 * Postcondition: The index of the target vertex

**************************************************/
template <class Item_Type, class Element>
int Graph_List<Item_Type,Element>:: vertex_index_of
                                    (const Item_Type& target) const
{
    List<Item_Type>* finder;
    node<Item_Type>* find_here;

    int i = 0;
    for(; i < get_size(); ++i)
    {
        finder = _list;      // Go through the start vertex of
        finder += i;         // Go through list
        find_here = finder->Begin();  // Each list

        if(find_here->_item == target)  // If the target was found
            return i;
    }

    assert(i != get_size());   // Assert if Not found
    return -1;   // If not found return -1
}

/*************************************************
 * Add_vertex
 * ----------------------------------------------
 * Precondition: The index of that list and the item
 * -----------------------------------------------
 * Postcondition: The item will be inserted into the
 * correct index's list.

**************************************************/
template <class Item_Type, class Element>
void Graph_List<Item_Type,Element> ::add_vertex(const int& vertex_index,
                                        Item_Type vertex_neighbor)
{
    // A list of location list pointer of 2-D pointer
    List<Location_info<Element>>* walker = _list;

    walker += vertex_index;  // Let walker walker to the correct position

    // Insert the sorted information
    walker->InsertSorted(vertex_neighbor);

    if(vertex_index > _size-1)   // Increase size if at a new position
        _size++;

}

/*************************************************
 * remove_vertex
 * ----------------------------------------------
 * Precondition: The index of that list and the item
 * -----------------------------------------------
 * Postcondition: The item will be removed at the
 * correct index's list.

**************************************************/
template <class Item_Type, class Element>
void Graph_List<Item_Type,Element> ::remove_vertex(const int& vertex_index,
                                                   Item_Type vertex_neighbor)
{
    // A list of location list pointer of 2-D pointer
    List<Location_info<Element>>* walker = _list;

    walker += vertex_index;  // Let walker walker to the correct position

    // Find the specific item for the deletion
    node<Item_Type>* finder = walker->Search(vertex_neighbor);

    assert(finder!= nullptr);   // Item should found in the list

    walker->Delete(finder);   // Delete the specific item

    if(walker->get_size() == 0)  // If the list empty
        _size--;
}



/*************************************************
 * Dijkstra_Algorithm
 * ----------------------------------------------
 * Precondition: a non-empty list of edge lists
 * -----------------------------------------------
 * Postcondition: The solution will be outputed
 * after the algorithm is performed

**************************************************/
template <class Item_Type, class Element>
vector<Item_Type>* Graph_List<Item_Type,Element> ::Dijkstra_Algorithm(
                                    const Item_Type& start,
                                    int & v_size,
                                    int path_costs[])
{
    // Define a set of locations as a vector
    vector<Item_Type>* solution = new vector<Item_Type>[STORAGE];

    set<Item_Type> answer_set;    // Item type is location info here
    set<Location_info<Stadium>>::iterator it;
    Item_Type processor_u;

    bool shortest_path_found = false;
    bool Element_exists = false;
    int edge_cost;
    int vertex_index;
    int lowest_cost;
    int lowest_cost_index;

    // If the starting point is differnt swap them
    if(start != start_vertex_at(0))
    {
        cout << start_vertex_at(2)<< endl;
        int index_ = vertex_index_of(start);
        assert(index_!= -1);   // assert if not found

        List<Item_Type> *track = _list;

        track += index_;
        List<Item_Type> new_start =
                *track;

        // Switch the starting point
        *track = *_list;

        *_list = new_start;

        cout << *this << endl;
    }


    // Step 1: Insert the first vertex to the set
    answer_set.insert(start_vertex_at(0));
    _distance[0]= 0;  // Distance at itself is zero as always
    it = answer_set.begin();
    processor_u = *it;    // let the start vertex be the
                                         // start processor

    // Put the start vertex into every solution set
    for(int h = 0; h < get_size(); h++)
    {
        solution[h].push_back(start_vertex_at(0));
    }


    Location_info<Element> next;   // The next vertice of processor

    //------------------------------------------------------
    // Walk through all the vertices in the list
    for(int n = 1; n < get_size()*2; n++)
    {

        // Find the processor u 's index for (u,v)
        vertex_index =
        vertex_index_of(processor_u);

        shortest_path_found = false;   // Reset the bool for element searching

        // Check to see if the next is the set already
        for(int i = 1; i < _list[vertex_index].get_size();i++)
        {

            Element_exists = false;

            // Get the next vertex neighbor in the list.
            next = _list[vertex_index].operator[](i);

            // Check to see if the neighbor vertex is in the set
            for(it = answer_set.begin(); it != answer_set.end();it++)
            {
               if(next == *it)
                   Element_exists = true;  // Element found in set
            }

            if(!Element_exists)       // If element not found in set
            {
                if(!shortest_path_found)
                {
                    // When first time finding the shortest path of u
                    // Update the new processor

                    shortest_path_found = true;
                    processor_u = next;       // Initialize the processor candicate

                }


            }
        }

        // work through the Edge list with walker to update distance
        for(int v = 1; v < _list[vertex_index].get_size();v++)
        {
            next = _list[vertex_index].operator[](v);   // Walk through v for(u,v)

            // Examine the edge cost (processor's cost + current)
            edge_cost = _distance[vertex_index] + next.get_cost();

            // Get the vertex index from the list of edge lists
            int search_index;
            search_index = vertex_index_of(next);


            // If previous cost is infinite or less than current cost
            if(_distance[search_index] == -1 ||
               edge_cost <= _distance[search_index])
            {
                // Find the index of that shortest path
                // Update that path with the processor
                solution[vertex_index_of(next)] = solution[vertex_index];
                solution[vertex_index_of(next)].push_back(next);

                _distance[search_index] = edge_cost;  // Change cost
                                                      // at distance array
            }
        }

        // After updating all the path cost, choose the best processor
        // Use the initialize processor to compare with others
        lowest_cost_index = vertex_index_of(processor_u);
        lowest_cost = _distance[lowest_cost_index];   // Initialize the lowest cost

        // *Debugging purpose
        if(debugging_tool)
            cout << n << "   Pi: " << processor_u  << " "
                 << processor_u .get_cost()<< endl;

        // Go through the entire path cost for each place to select the lowest
        for(int distance_index = 1; distance_index < get_size(); distance_index++)
        {
            Element_exists = false;

            // Lowest path cost is found
            if(_distance[distance_index] != -1 &&
               _distance[distance_index] < lowest_cost)
            {
                Item_Type current_element = start_vertex_at(distance_index);

                // And check to see if the next processor is in the set
                for(it=answer_set.begin();it != answer_set.end();it++)
                {
                    if(current_element == *it)
                        Element_exists = true;

                }


                // set the non-existed element to be a
                // candicate for the procesoor
                if(!Element_exists)
                {
                    lowest_cost_index = distance_index;
                    lowest_cost = _distance[lowest_cost_index];
                }
            }
        }


       // Candicate is finalized at the end with lowest cost
       processor_u = start_vertex_at(lowest_cost_index);

       bool duplicates = false;

       // Check for duplicates for the processor in the
       // answer set, otherwise reset the processor to beginning
       for(it=answer_set.begin();it != answer_set.end();it++)
       {
           if(*it == processor_u)
               duplicates = true;

       }


       //**** Rest position may vary for relatively complicated map
       //     Random assign index will be a better idea
       srand(time(nullptr));

       //***** If there is duplicates, back_track to
       //      previously visited locations to continue mapping
       //      the whole map
       if(duplicates)
       {
           // Get the size of the previously visited locations
           int size_set = static_cast<int>(answer_set.size());

           // Randomly select a index size based on the size
           int rand_select_processor_index = rand() %
                                (size_set);

           set<Location_info<Stadium>> :: iterator check_it;

           check_it = answer_set.begin(); // Assign iterator

           // walk the iterator to that specific index
           for(int y = 0; y <= rand_select_processor_index; y++,check_it++)
           {
               // Reset the processor
               // choose from the answer set
               if(y == rand_select_processor_index)
                   processor_u = *check_it;
           }
       }

        // Reset the path cost with its asociatted path cost
        if(processor_u.get_cost() == 0)
            processor_u.set_cost(_distance[lowest_cost_index]);

        answer_set.insert(processor_u);  // Add the distinct candicate to set

        // *Debugging purposes
        if (debugging_tool)
        {
            cout << n << " Pf: " << processor_u  << " "
                 << processor_u .get_cost()<< endl;

            for(it=answer_set.begin();it != answer_set.end();it++)
            {
                cout << *it << " ";

            }

            cout << endl;
        }


    }

    //------------------------------------------------------

    // Print out the Alogrithm output
    for(int u = 0; u < get_size();u++)
    {
        cout << _distance[u] << " ";

        for(size_t g = 0; g < solution[u].size(); g++)
        {
            cout << solution[u].at(g).get_start() << " ";
        }

        cout << endl;
    }



    cout << endl;

    vector<Item_Type>* walker = solution;   // Assign the solution
    v_size = get_size();


    for(int k = 0; k < v_size; k++)
    {
        path_costs[k] =  _distance[k];
    }

    init_1D(_distance,STORAGE);  // Reset all the distance cost once finished

    return walker;

}

/*************************************************
 * Prim_Algorithm
 * ----------------------------------------------
 * Precondition: a non-empty list of edge lists
 * -----------------------------------------------
 * Postcondition: The solution will be outputed
 * after the algorithm is performed

**************************************************/
template <class Item_Type, class Element>
void Graph_List<Item_Type,Element>::Prim_Algorithm()
{
    // Define a set of locations as a vector
    vector<Location_info<string>> answer_set;
    bool item_found = false;
    int vertex_index;


    int lowest_edge_cost;
    int start_vertex;

    //------------------------------------------------------
    List<Item_Type>* walker = _list;
    node<Item_Type>* finder = walker->Begin() +1;

    // Initialize the lowerset cost from the sorted edge list
    lowest_edge_cost = finder->_item.get_cost();

    // Go through the list to find the best starting place
    for(int i =0; i < get_size(); i++,walker++ )
    {
        finder = walker->Begin() +1;

        // Swap the value if find the smaller start cost
        if(finder->_item.get_cost() <= lowest_edge_cost)
        {
            // Get the lower cost
           lowest_edge_cost = finder->_item.get_cost();

            // Find the index of that place
           start_vertex = vertex_index_of(finder->_item);
        }
    }

    // Push back the initial starting cost first
    answer_set.push_back(start_vertex_at(start_vertex));

    Location_info<string> next;   // The next vertice of processor

    // Walk through the entir list of Edge list to finish spanning
    for(int n = 0; n < get_size(); n++)
    {
        walker = _list;  // Assign walker at the front

        // Find the processor u 's index for (u,v)
        vertex_index =
        vertex_index_of(answer_set[answer_set.size()-1]);
        walker += (vertex_index);      // Walk to processor vertex index


        // Check to see if the next is the set already
        for(int i = 1; i < walker->get_size();i++)
        {
            item_found = false;     // Reset the bool for element searching

            // Get the next vertex neighbor in the list.
            next = walker->operator[](i);

            // Search the neighbor in the set
            for(size_t j = 0; j < answer_set.size(); j++)
            {
                if(next == answer_set[j])
                    item_found = true;   // Set true if found
            }

            if(!item_found)  // If neighbor vertex not in the set
            {
                answer_set.push_back(next);  // Insert the vertex into set
                break;                       // Break the for loop
            }
        }
    }
    //------------------------------------------------------

    node<Item_Type>* searcher;
    int search_index;

    // Print out the Alogrithm output
    for(size_t t = 0 ; t < answer_set.size(); t++)
    {
        walker = _list;

        if(t != answer_set.size()-1)
        {
            cout << "(";
            cout << answer_set[t] << ", " << answer_set[t+1]
                 << ") ";

            search_index = vertex_index_of(answer_set[t]); // Find processor
            walker += search_index;          // Assign walker to here

            searcher = walker->Search(answer_set[t+1]);  // Find the second item
                                             // of the list

            cout << searcher->_item.get_cost();

        }

        cout << endl;


    }



}

/*************************************************
 * Kruskal_Algorithm
 * ----------------------------------------------
 * Precondition: a non-empty list of edge lists
 * -----------------------------------------------
 * Postcondition: The solution will be outputed
 * after the algorithm is performed

**************************************************/
template <class Item_Type, class Element>
void Graph_List<Item_Type,Element>::Kruskal_Algorithm()
{

    // Define a set of Edges with locations as a vector
    vector<Location_info<string>> answer_set;
    List<Location_info<string>> _pair_vertices_;

    List<Location_info<string>>::Iterator it;

    bool item_duplicated = false;
    List<Item_Type>* walker = _list;
    node<Item_Type>* vertex_u = walker->Begin();
    node<Item_Type>* vertex_v = walker->Begin() +1;


    int lowest_edge_cost = vertex_v->_item.get_cost();
    int lowest_start_vertex;
    Item_Type lowest_Item_start;
    Element lowest_end_name;

    int start_vertex;      // Index of start vertex u
    Item_Type Item_start_index;
    Element end_vertex_name;

    //------------------------------------------------------

    // Find the least costly edge to and add it to the answer set
    for(int p = 0; p < _size;p++,walker++)
    {
        vertex_u = walker->Begin();
        vertex_v = walker->Begin() + 1;

        // Find the lowest edge cost in the list to start
        if(vertex_v->_item.get_cost() < lowest_edge_cost)
        {
            lowest_edge_cost = vertex_v->_item.get_cost();
            lowest_start_vertex = vertex_index_of(vertex_u->_item);
            lowest_end_name  = vertex_v->_item.get_start();
        }

    }

    // Define the Edge the with start and ending location
    Item_start_index = start_vertex_at(lowest_start_vertex);
    Item_start_index.set_end(lowest_end_name);
    Item_start_index.set_cost(lowest_edge_cost);

    // Add the lowest cost edge to the list
    answer_set.push_back(Item_start_index);
    _pair_vertices_.InsertSorted(Item_start_index);


    walker = _list;
    // Go through the list to sort all the edge info to list
    for(int i =0; i < _size; i++,walker++ )
    {
        vertex_u = walker->Begin();  // Start vertex

        // Walk throught each edge list
        for( int k = 1; k < walker->get_size(); k++)
        {
            vertex_v = walker->Begin() + k;

            start_vertex = vertex_index_of(vertex_u->_item);

            // Define the Edge the with start and ending location
            Item_start_index = start_vertex_at(start_vertex);
            Item_start_index.set_end(vertex_v->_item.get_start());
            Item_start_index.set_cost(vertex_v->_item.get_cost());

            // Insert the Edge info as sorted into the list
            _pair_vertices_.InsertSorted(Item_start_index);

        }

    }


   int allowed_repeats = 0;
   size_t max_size = static_cast<size_t>(_size -2);

//   cout << _pair_vertices_.get_size() << " eeeee\n";

   // Walker through the edge info in the list to fill the answer set
   for(it = _pair_vertices_.Begin();
       answer_set.size() != max_size  &&  it != _pair_vertices_.End();it++)
   {

       item_duplicated = false;

       for(size_t h = 0; h < answer_set.size(); h++)
       {
           // If the Edge info is not duplicated in the set
           if( it->_item.get_start() == answer_set[h].get_start() ||
               (it->_item.get_start() == answer_set[h].get_start() &&
              it->_item.get_end() == answer_set[h].get_end() ) ||
              (it->_item.get_start() == answer_set[h].get_end() &&
               it->_item.get_end() == answer_set[h].get_start() ) ||
              it->_item.get_end() == answer_set[0].get_start() ||
              it->_item.get_cost() == answer_set[h].get_cost())
           {
               // Only allowed the starting vertex to repeat
               if((it->_item.get_start() == answer_set[h].get_start() &&
                   it->_item.get_end() != answer_set[h].get_end() )
                       )
                   allowed_repeats++;
               else
                item_duplicated = true;
           }


       }

//       cout << *it << " ";  // Debug
       // If not duplicated add into the solution
       if(!item_duplicated)

           answer_set.push_back(*it);

   }


//   cout << "----------------------------------------\n";
    for(size_t y =0;y < answer_set.size(); y++)
    {
        cout << "(" << answer_set[y].get_start()
             << ", " << answer_set[y].get_end() << ")"
             << " "  << answer_set[y].get_cost() << endl;
    }




}







#endif // MY_GRAPH_H
