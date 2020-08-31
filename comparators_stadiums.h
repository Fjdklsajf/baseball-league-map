#ifndef COMPARATORS_STADIUMS_H
#define COMPARATORS_STADIUMS_H

#include <iostream>
#include <string>
#include <set>
#include <functional>
#include "stadium.h"
#include <string>

using namespace std;

/*****************************************
 * Comparators
 * ------------------------------
 * Pre-condition: None
 * -------------------------------
 * Post-condtion: Comparison for the
 ****************************************/
class CompareDate {
public:
    bool operator()(Stadium& t1, Stadium& t2)
    {
       if (t1.getOpenedDate() < t2.getOpenedDate()) return true;

       return false;
    }
};


class CompareStadium_Alph {
public:
    bool operator()(Stadium& t1, Stadium& t2)
    {
       if (t1.getName() < t2.getName()) return true;
       if (t1.getName() <= t2.getName()) return true;

       return false;
    }
};



class CompareTeam_Alph {
public:
    bool operator()(Stadium& t1, Stadium& t2)
    {
       if (t1.getTeam() < t2.getTeam()) return true;
       if (t1.getTeam() <= t2.getTeam()) return true;

       return false;
    }
};









#endif // COMPARATORS_STADIUMS_H
