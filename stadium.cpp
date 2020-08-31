#include <iostream>
#include <sstream>
#include <string>
#include "stadium.h"

/******************************************************************************
 *
 *  Constructor Stadium
 *_____________________________________________________________________________
 *  Initialize member variables of the Stadium with default values
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    members variables are initialized
 ******************************************************************************/
Stadium::Stadium() {
    _name = _address = _city = _phoneNum = _state = "";
    _zip  = "";
    _seatCap = 0;
    _hasGrass = false;
}

/******************************************************************************
 *
 *  Constructor Stadium
 *_____________________________________________________________________________
 *  Initialize member variables of the Stadium with given
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    members variables are initialized
 ******************************************************************************/
Stadium::Stadium(std::string name, const Team& team, std::string address,
            std::string city, std::string state, string zip, string phoneNum,
            int seatCap, bool hasGrass, const Date& opened) {
    _name = name;
    _team = team;
    _address = address;
    _city = city;
    _state = state;
    _zip = zip;
    _phoneNum = phoneNum;
    _seatCap = seatCap;
    _hasGrass = hasGrass;
    _opened = opened;
}

/******************************************************************************
 *
 *  Copy Constructor Stadium
 *_____________________________________________________________________________
 *  Copy over given Stadium's information
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    members variables are initialized with given Stadium's info
 ******************************************************************************/
Stadium::Stadium(const Stadium& copy) {
    *this = copy;
}

/******************************************************************************
 *
 *  Mutator setName: Class Stadium
 *_____________________________________________________________________________
 *  This method will update the _name attribute to the parameter
 *      name value
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _name is updated
 ******************************************************************************/
void Stadium::setName(std::string name) {
    _name = name;
}

/******************************************************************************
 *
 *  Mutator setTEam: Class Stadium
 *_____________________________________________________________________________
 *  This method will update the _team attribute to the parameter
 *      team value
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _team is updated
 ******************************************************************************/
void Stadium::setTeam(const Team& team) {
    _team = team;
}

/******************************************************************************
 *
 *  Mutator setaddress: Class Stadium
 *_____________________________________________________________________________
 *  This method will update the _address attribute to the parameter
 *      address value
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _address is updated
 ******************************************************************************/
void Stadium::setAddress(std::string address) {
    _address = address;
}

/******************************************************************************
 *
 *  Mutator setAddress: Class Stadium
 *_____________________________________________________________________________
 *  This method will update the _address, _city, _state, and _zip
 *      attributes to the parameter values
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _address, _city, _state, and _zip are updated
 ******************************************************************************/
void Stadium::setAddress(std::string address, std::string city,
                         std::string state, string zip) {
    _address = address;
    _city = city;
    _state = state;
    _zip = zip;
}

/******************************************************************************
 *
 *  Mutator setCity: Class Stadium
 *_____________________________________________________________________________
 *  This method will update the _city attribute to the parameter
 *      city value
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _city is updated
 ******************************************************************************/
void Stadium::setCity(std::string city) {
    _city = city;
}

/******************************************************************************
 *
 *  Mutator setState: Class Stadium
 *_____________________________________________________________________________
 *  This method will update the _state attribute to the parameter
 *      state value
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _state is updated
 ******************************************************************************/
void Stadium::setState(std::string state) {
    _state = state;
}

/******************************************************************************
 *
 *  Mutator setZip: Class Stadium
 *_____________________________________________________________________________
 *  This method will update the _zip attribute to the parameter
 *      zip value
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _zip is updated
 ******************************************************************************/
void Stadium::setZip(string zip) {
    _zip = zip;
}

/******************************************************************************
 *
 *  Mutator setPhoneNum: Class Stadium
 *_____________________________________________________________________________
 *  This method will update the _phoneNum attribute to the parameter
 *      phoneNum value
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _phoneNum is updated
 ******************************************************************************/
void Stadium::setPhoneNum(string phoneNum) {
    _phoneNum = phoneNum;
}

/******************************************************************************
 *
 *  Mutator setSeatCapacity: Class Stadium
 *_____________________________________________________________________________
 *  This method will update the _seatCap attribute to the parameter
 *      seatCap value
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _seatCap is updated
 ******************************************************************************/
void Stadium::setSeatCapacity(int seatCap) {
    _seatCap = seatCap;
}

/******************************************************************************
 *
 *  Mutator setGrass: Class Stadium
 *_____________________________________________________________________________
 *  This method will update the _hasGrass attribute to the parameter
 *      hasGrass value
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _hasGrass is updated
 ******************************************************************************/
void Stadium::setGrass(bool hasGrass) {
    _hasGrass = hasGrass;
}

/******************************************************************************
 *
 *  Mutator setOpenedDate: Class Stadium
 *_____________________________________________________________________________
 *  This method will update the _opened attribute to the parameter
 *      opened value
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _opened is updated
 ******************************************************************************/
void Stadium::setOpenedDate(const Date& opened) {
    _opened = opened;
}

/******************************************************************************
 *
 *  Accessor getName: Class Stadium
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
std::string Stadium::getName() const {
    return _name;
}

/******************************************************************************
 *
 *  Accessor getTeam: Class Stadium
 *_____________________________________________________________________________
 *  This method will return _team
 *  - returns Team&
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _team is returned
 ******************************************************************************/
Team& Stadium::getTeam() {
    return _team;
}

/******************************************************************************
 *
 *  Accessor getAddress: Class Stadium
 *_____________________________________________________________________________
 *  This method will return _address
 *  - returns std::string
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    std::string
 *
 *  POST-CONDITIONS
 *    _address is returned
 ******************************************************************************/
std::string Stadium::getAddress() const {
    return _address;
}

/******************************************************************************
 *
 *  Accessor getCity: Class Stadium
 *_____________________________________________________________________________
 *  This method will return _city
 *  - returns std::string
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _city is returned
 ******************************************************************************/
std::string Stadium::getCity() const {
    return _city;
}

/******************************************************************************
 *
 *  Accessor getState: Class Stadium
 *_____________________________________________________________________________
 *  This method will return _state
 *  - returns std::string
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _state is returned
 ******************************************************************************/
std::string Stadium::getState() const {
    return _state;
}

/******************************************************************************
 *
 *  Accessor getZip: Class Stadium
 *_____________________________________________________________________________
 *  This method will return _zip
 *  - returns int
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _zip is returned
 ******************************************************************************/
string Stadium::getZip() const {
    return _zip;
}

/******************************************************************************
 *
 *  Accessor getPhoneNum: Class Stadium
 *_____________________________________________________________________________
 *  This method will return _phoneNum
 *  - returns int
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _phoneNum is returned
 ******************************************************************************/
string Stadium::getPhoneNum() const {
    return _phoneNum;
}

/******************************************************************************
 *
 *  Accessor getSeatCap: Class Stadium
 *_____________________________________________________________________________
 *  This method will return _seatCap
 *  - returns int
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _seatCap is returned
 ******************************************************************************/
int Stadium::getSeatCap() const {
    return _seatCap;
}

/******************************************************************************
 *
 *  Accessor hasGrass: Class Stadium
 *_____________________________________________________________________________
 *  This method will return _hasGrass
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _hasGrass is returned
 ******************************************************************************/
bool Stadium::hasGrass() const {
    return _hasGrass;
}

/******************************************************************************
 *
 *  Accessor getOpenedDate: Class Stadium
 *_____________________________________________________________________________
 *  This method will return _opened
 *  - returns Date
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _opened is returned
 ******************************************************************************/
Date Stadium::getOpenedDate() const {
    return _opened;
}

/******************************************************************************
 *
 *  Accessor isAmericanLeague: Class Stadium
 *_____________________________________________________________________________
 *  This method will return true if stadium is in american league
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _team.isAmericanLeague() is returned
 ******************************************************************************/
bool Stadium::isAmerican() const {
    return _team.isAmericanLeague();
}

/******************************************************************************
 *
 *  Overalod operator =: Class Stadium
 *_____________________________________________________________________________
 *  Copy values over from the given Stadium
 *  - returns Stadium&
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    member variables are updated to copy's values
 ******************************************************************************/
Stadium& Stadium::operator =(const Stadium& copy) {
    if(this != &copy) {
        _name = copy._name;
        _team = copy._team;
        _address = copy._address;
        _city = copy._city;
        _state = copy._state;
        _zip = copy._zip;
        _phoneNum = copy._phoneNum;
        _seatCap = copy._seatCap;
        _opened = copy._opened;
        _hasGrass = copy._hasGrass;
    }
    return *this;
}

/******************************************************************************
 *
 *  Method swapTeams: Class Stadium
 *_____________________________________________________________________________
 *  Swap the teams of two stadiums
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    team and other's team are swapped
 ******************************************************************************/
void Stadium::swapTeams(Stadium& other) {
    if(this != &other) {
        Team temp = _team;
        _team = other._team;
        other._team = temp;
    }
}

/******************************************************************************
 *
 *  Overalod operator <: Class Stadium
 *_____________________________________________________________________________
 *  Compare if the name is less than other stadium's name
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    return true if name is less than other stadium's name
 ******************************************************************************/
bool Stadium::operator <(const Stadium& s) const {
    return _name < s._name;
}

/******************************************************************************
 *
 *  Overalod operator >: Class Stadium
 *_____________________________________________________________________________
 *  Compare if the name is greater than other stadium's name
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    return true if name is greater than other stadium's name
 ******************************************************************************/
bool Stadium::operator >(const Stadium& s) const {
    return _name > s._name;
}

/******************************************************************************
 *
 *  Overalod operator <=: Class Stadium
 *_____________________________________________________________________________
 *  Compare if the name is less than or equal to other stadium's name
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    return true if name is less than or equal to other stadium's name
 ******************************************************************************/
bool Stadium::operator <=(const Stadium& s) const {
    return _name <= s._name;
}

/******************************************************************************
 *
 *  Overalod operator >=: Class Stadium
 *_____________________________________________________________________________
 *  Compare if the name is great than or equal to other stadium's name
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    return true if name is great than or equal to other stadium's name
 ******************************************************************************/
bool Stadium::operator >=(const Stadium& s) const {
    return _name >= s._name;
}

/******************************************************************************
 *
 *  Overalod operator ==: Class Stadium
 *_____________________________________________________________________________
 *  Compare if the name is equal to other stadium's name
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    return true if name is equal to other stadium's name
 ******************************************************************************/
bool Stadium::operator ==(const Stadium& s) const {
    return _name == s._name;
}

/******************************************************************************
 *
 *  Overalod operator !=: Class Stadium
 *_____________________________________________________________________________
 *  Compare if the name is not equal to other stadium's name
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    return true if name is not equal to other stadium's name
 ******************************************************************************/
bool Stadium::operator !=(const Stadium& s) const {
    return _name != s._name;
}

/******************************************************************************
 *
 *  Method getPrint: Class Stadium
 *_____________________________________________________________________________
 *  Return the stadium's information as a string, in the format:
 *      Stadium name
 *      Address
 *      Phone number
 *      Date opened
 *      Capacity
 *      Team info...
 *      Souvenir info...
 *  - returns std::string
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    Stadium's info are returned as a string
 ******************************************************************************/
std::string Stadium::getPrint() const {
    std::stringstream ss;
    ss << *this;
    return ss.str();
}

/******************************************************************************
 *
 *  Overload operator <<: Class Stadium
 *_____________________________________________________________________________
 *  Return the stadium's information as a ostream, in the format:
 *      Stadium name
 *      Address
 *      Phone number
 *      Date opened
 *      Capacity
 *      Team info...
 *      Souvenir info...
 *  - returns ostream&
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    Stadium's info are returned as a ostream
 ******************************************************************************/
std::ostream& operator <<(std::ostream& out, const Stadium& s) {
    out << s._name << " ";
//        << s._address << ",\n"
//        << s._city << ", " << s._state << ' ' << s._zip << "\n";

//    std::string num = std::to_string(s._phoneNum);
//    out << '(' << num.substr(0, 3) << ')' << num.substr(3, 3)
//        << '-' << num.substr(6) << '\n';
//    out << "Opened - " << s._opened << '\n';

//    int temp = s._seatCap, count = 1;
//    num = "";
//    while(temp != 0) {
//        num = std::to_string(temp % 10) + num;
//        temp /= 10;
//        if(count++%3 == 0 && temp != 0) {
//            num = "," + num;
//        }
//    }
//    out << "Capactiy - " << num << '\n';

//    out << "Team info:\n" << s._team;

    return out;
}

