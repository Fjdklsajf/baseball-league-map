#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "stadium.h"

/******************************************************************************
 *
 *  Constructor Souvenir
 *_____________________________________________________________________________
 *  Initialize member variables of a souvenir
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _name and _price are initialized
 ******************************************************************************/
Souvenir::Souvenir(std::string name, double price) : _name(name), _price(price){
}

/******************************************************************************
 *
 *  Copy Constructor Souvenir
 *_____________________________________________________________________________
 *  Copy over values of given Souvenir
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _name and _price are initialized with copy's values
 ******************************************************************************/
Souvenir::Souvenir(const Souvenir& copy) {
    *this = copy;
}

/******************************************************************************
 *
 *  Mutator setName: Class Souvenir
 *_____________________________________________________________________________
 *  This method will update the _name attribute to the parameter
 *      name value
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _name is changed
 ******************************************************************************/
void Souvenir::setName(std::string name) {
    _name = name;
}

/******************************************************************************
 *
 *  Mutator setPrice: Class Souvenir
 *_____________________________________________________________________________
 *  This method will update the _price attribute to the parameter
 *      price value
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _price is changed
 ******************************************************************************/
void Souvenir::setPrice(double price) {
    _price = price;
}

/******************************************************************************
 *
 *  Accessor getName: Class Souvenir
 *_____________________________________________________________________________
 *  This method will return _name
 *  - returns std::string
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _name is returned
 ******************************************************************************/
std::string Souvenir::getName() const {
    return _name;
}

/******************************************************************************
 *
 *  Accessor getPrice: Class Souvenir
 *_____________________________________________________________________________
 *  This method will return _price
 *  - returns double
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _price is returned
 ******************************************************************************/
double Souvenir::getPrice() const {
    return _price;
}

/******************************************************************************
 *
 *  Overload operator =: Class Souvenir
 *_____________________________________________________________________________
 *  Sets values of this souvenir equal to the given copy
 *  - returns Souvenir&
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _name and _price and updated to the copy's values
 ******************************************************************************/
Souvenir& Souvenir::operator =(const Souvenir& copy) {
    if(this != &copy) {
        _name = copy._name;
        _price = copy._price;
    }
    return *this;
}

/******************************************************************************
 *
 *  Overload operator <: Class Souvenir
 *_____________________________________________________________________________
 *  Check if the name is less than the given souvenir's name
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    Returnt true if name comes first
 ******************************************************************************/
bool Souvenir::operator <(const Souvenir& s) const {
    return _name < s._name;
}

/******************************************************************************
 *
 *  Overload operator >: Class Souvenir
 *_____________________________________________________________________________
 *  Check if the name is greater than the given souvenir's name
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    Returnt true if name comes after
 ******************************************************************************/
bool Souvenir::operator >(const Souvenir& s) const {
    return _name > s._name;
}

/******************************************************************************
 *
 *  Overload operator <=: Class Souvenir
 *_____________________________________________________________________________
 *  Check if the name is less than or equal to the given souvenir's name
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    Returnt true if name comes first or equal
 ******************************************************************************/
bool Souvenir::operator <=(const Souvenir& s) const {
    return _name <= s._name;
}

/******************************************************************************
 *
 *  Overload operator >=: Class Souvenir
 *_____________________________________________________________________________
 *  Check if the name is greater than or equal to the given souvenir's name
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    Returnt true if name comes after or equal
 ******************************************************************************/
bool Souvenir::operator >=(const Souvenir& s) const {
    return _name >= s._name;
}

/******************************************************************************
 *
 *  Overload operator =: Class Souvenir
 *_____________________________________________________________________________
 *  Check if the name is equal to the given souvenir's name
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    Returnt true if name is equal
 ******************************************************************************/
bool Souvenir::operator ==(const Souvenir& s) const {
    return _name == s._name;
}

/******************************************************************************
 *
 *  Overload operator !=: Class Souvenir
 *_____________________________________________________________________________
 *  Check if the name is not equal to the given souvenir's name
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    Returnt true if name is not equal
 ******************************************************************************/
bool Souvenir::operator !=(const Souvenir& s) const {
    return _name != s._name;
}

/******************************************************************************
 *
 *  Method getPrint: Class Souvenir
 *_____________________________________________________________________________
 *  Return the souvenir info as a string, in the format of:
 *      cost1 - name1
 *      cost2 - name2
 *  - returns std::string
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    souvenir info are returned
 ******************************************************************************/
std::string Souvenir::getPrint() const {
    std::stringstream ss;
    ss << *this;
    return ss.str();
}

/******************************************************************************
 *
 *  Overload operator <<: Class Souvenir
 *_____________________________________________________________________________
 *  Write the souvenir info to the ostream, in the format of:
 *      cost1 - name1
 *      cost2 - name2
 *  - returns std::ostream&
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    souvenir info are returned
 ******************************************************************************/
std::ostream& operator <<(std::ostream& out, const Souvenir& s) {
    std::string money = "";
    int price = static_cast<int>(s._price) * 100;
    money += '$' + std::to_string(price/100) + '.';
    if(price % 100 < 10) {
        money += '0';
    }
    money += std::to_string(price%100);
    out << std::left << std::setw(10) << money << "- " << s._name;

    return out;
}
