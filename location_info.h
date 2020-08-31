/*********************************************
 * Authors:  Dacheng Lin
 * Assig #7:   MST & SHORTEST PATH ALOGRITHM
 * Class:    CS 008
 * Section:  MW 9:45-11:10 TTH 9:45-11:50
 * Due Date: 05/01/2020
*********************************************/
#ifndef LOCATION_INFO_H
#define LOCATION_INFO_H

#include <iostream>
#include <cassert>
#include <string>
#include <cstdlib>
#include "stadium.h"
#include "Sorted_List_class.h"
using namespace std;

template <class Item_Type>
class Location_info
{

public:

        // --------CONSTRUCTORS-------------
        Location_info()
        {
            _cost = 0;

        }
        Location_info(Item_Type u, int cost = 0)
        {
            _start_u = u;
            _cost = cost;

        }

        Location_info(Item_Type u, Item_Type v, int cost =0)
        {
            _start_u = u;
            _end_v = v;
            _cost = cost;
        }

        // --------ACCESSOR-------------
        Item_Type get_start() const {return  _start_u;}
        Item_Type get_end() const {return _end_v;}
        int get_cost() const {return  _cost;}

        // --------MUTATORS-------------
        // Pre-condtion:  Get the name and the cost
        // Post-condtion:  Set the private values to
        // the assigned values
        // -----------------------------
        void set_start(Item_Type u )  {_start_u = u; }
        void set_end(Item_Type v) {_end_v = v;}
        void set_cost(int cost )  {_cost = cost; }


        // --------OSTREAM OPERATOR----------
        friend ostream& operator <<(ostream& outs,
                                    const Location_info& l)
        {
            // Case 1: Ending vertex is empty
            if(l.get_cost() == 0)
                outs << l.get_start();

            // Case 2: (u,v) is ready to be presented
            else
            {
                outs << "(" << l.get_start() << ", "
                     << l.get_end() << ") ";
            }

//            if(l.get_cost() != 0)
//                outs << " " << l.get_cost();

            return outs;
        }

        // --------COMPARISION OPERATORS------------
        // Pre-condtion:  Get two Location objects
        // Post-condtion:  compare the cost of traveling
        // to determine the equalness
        // -----------------------------------------
        friend bool operator <(const Location_info& l,
                               const Location_info & r)
        {
            // Cost can be same sometimes in the map
            return (l.get_cost() <= r.get_cost());
        }

        friend bool operator >(const Location_info& l,
                               const Location_info & r)
        {
            return (l.get_cost() >= r.get_cost());
        }

        friend bool operator <=(const Location_info& l,
                               const Location_info & r)
        {
            return (l.get_cost() <= r.get_cost()
                   );
        }

        friend bool operator >=(const Location_info& l,
                               const Location_info & r)
        {
            return (l.get_cost() >= r.get_cost()
                   );
        }

        friend bool operator ==(const Location_info& l,
                               const Location_info & r)
        {
            return (l.get_start() == r.get_start());
        }

        friend bool operator !=(const Location_info& l,
                               const Location_info & r)
        {
            return (l.get_start() != r.get_start() ||
                    l.get_end() != r.get_end());
        }

        bool is_duplicated(const Location_info& l) const
        {
            return ( (l.get_start() == get_start()) ||
                     (l.get_end() == get_end())     ||
                     get_start() == l.get_end()     ||
                     get_end() == l.get_start());
        }


private:
       Item_Type _start_u;        // Start vertice u
       Item_Type _end_v;          // Ending vertice v
       int _cost;           // Edge cost for (u,v)
};



#endif // LOCATION_INFO_H
