#include <string>
#include <iostream>
#include <sstream>
#include "stadium.h"

/******************************************************************************
 *
 *  Constructor Team
 *_____________________________________________________________________________
 *  Initialize member variables of the team
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _name and _league are initialized
 ******************************************************************************/
Team::Team(std::string name, std::string league) : _name(name), _league(league) {
    if(league != "AL" && league != "NL") {
        _league = "AL";
    }
}

/******************************************************************************
 *
 *  Copy Constructor Team
 *_____________________________________________________________________________
 *  Copy over values of given Team
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _name and _league are initialized with copy's values
 ******************************************************************************/
Team::Team(const Team& copy) {
    *this = copy;
}

/******************************************************************************
 *
 *  Mutator setName: Class Team
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
void Team::setName(std::string name) {
    _name = name;
}

/******************************************************************************
 *
 *  Mutator setSouvenirs: Class Team
 *_____________________________________________________________________________
 *  This method will update the _souvenirs attribute to the parameter
 *      souvenirs value
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _souvenirs is updated
 ******************************************************************************/
void Team::setSouvenirs(const Tree<Souvenir>& souvenirs) {
    _souvenirs = souvenirs;
}

/******************************************************************************
 *
 *  Mutator setLeague: Class Team
 *_____________________________________________________________________________
 *  This method will update the _league attribute to the parameter
 *      league value
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _league is updated
 ******************************************************************************/
void Team::setLeague(std::string league) {
    if(league == "AL" || league == "NL") {
         _league = league;
     }
}

/******************************************************************************
 *
 *  Accessor getName: Class Team
 *_____________________________________________________________________________
 *  This method will return _name
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _name is returned
 ******************************************************************************/
std::string Team::getName() const {
    return _name;
}

/******************************************************************************
 *
 *  Accessor getSouvenirs: Class Team
 *_____________________________________________________________________________
 *  This method will return _souvenirs
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _souvenirs is returned
 ******************************************************************************/
Tree<Souvenir> Team::getSouvenirs() const {
    return _souvenirs;
}

/******************************************************************************
 *
 *  Accessor getLeague: Class Team
 *_____________________________________________________________________________
 *  This method will return _league
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _league is returned
 ******************************************************************************/
std::string Team::getLeague() const {
    return _league;
}

/******************************************************************************
 *
 *  Accessor isAmericanLeague: Class Team
 *_____________________________________________________________________________
 *  This method will league type
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    return true if is american league
 ******************************************************************************/
bool Team::isAmericanLeague() const {
    return _league == "AL";
}

/******************************************************************************
 *
 *  Method addSouvenir: Class Team
 *_____________________________________________________________________________
 *  Add a souvenir to the list of souvenirs
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    a souvenir is added
 ******************************************************************************/
void Team::addSouvenir(const Souvenir& souvenir) {
    _souvenirs.insert(souvenir);
}

/******************************************************************************
 *
 *  Method addSouvenir: Class Team
 *_____________________________________________________________________________
 *  Create a new souvenir and add it to the list of souvenirs
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    a souvenir is added
 ******************************************************************************/
void Team::addSouvenir(std::string name, double price) {
    _souvenirs.insert(Souvenir(name, price));
}

/******************************************************************************
 *
 *  Method deleteSouvenir: Class Team
 *_____________________________________________________________________________
 *  delete a souvenir with the given name. Return false if oldName is not found
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    return true is souvenir with given name is deleted
 ******************************************************************************/
bool Team::deleteSouvenir(std::string name) {
    return _souvenirs.remove(Souvenir(name));
}

/******************************************************************************
 *
 *  Method changeSouvenirInfo: Class Team
 *_____________________________________________________________________________
 *  update a souvenir's info. Return false if oldName is not found
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    return true is souvenir with given name is updated
 ******************************************************************************/
bool Team::changeSouvenirInfo(std::string oldName, std::string newName, double price) {
    Souvenir temp(oldName, price);
    if(!_souvenirs.find(temp)) {
        return false;
    }
    _souvenirs.remove(temp);
    temp.setName(newName);
    _souvenirs.insert(temp);
    return true;
}

/******************************************************************************
 *
 *  Overalod operator =: Class Team
 *_____________________________________________________________________________
 *  Sets values of this team equal to the given Team copy
 *  - returns Team&
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _name, _souvenirs and _league are cahnged to copy's values
 ******************************************************************************/
Team& Team::operator =(const Team& copy) {
    if(this != &copy) {
        _name = copy._name;
        _souvenirs = copy._souvenirs;
        _league = copy._league;
    }
    return *this;
}

/******************************************************************************
 *
 *  Method swapLeague: Class Team
 *_____________________________________________________________________________
 *  Swap the league of the team between AL and NL
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _league is swapped
 ******************************************************************************/
void Team::swapLeague() {
    if(_league == "AL")
    {
        _league = "NL";
    }
    else {
        _league = "AL";
    }
}

/******************************************************************************
 *
 *  Overalod operator <: Class Team
 *_____________________________________________________________________________
 *  Compare if the name is less than other team's name
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    return true if name is less
 ******************************************************************************/
bool Team::operator <(const Team& team) const {
    return _name < team._name;
}

/******************************************************************************
 *
 *  Overalod operator >: Class Team
 *_____________________________________________________________________________
 *  Compare if the name is greater than other team's name
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    return true if name is greater
 ******************************************************************************/
bool Team::operator >(const Team& team) const {
    return _name > team._name;
}

/******************************************************************************
 *
 *  Overalod operator <=: Class Team
 *_____________________________________________________________________________
 *  Compare if the name is less than or equal to other team's name
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    return true if name is less or equal to other team's name
 ******************************************************************************/
bool Team::operator <=(const Team& team) const {
    return _name <= team._name;
}

/******************************************************************************
 *
 *  Overalod operator >=: Class Team
 *_____________________________________________________________________________
 *  Compare if the name is greater than or equal to other team's name
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    return true if name is greater than or equal to other team's name
 ******************************************************************************/
bool Team::operator >=(const Team& team) const {
    return _name >= team._name;
}

/******************************************************************************
 *
 *  Overalod operator ==: Class Team
 *_____________________________________________________________________________
 *  Compare if the name is equal to other team's name
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    return true if name is equal to other team's name
 ******************************************************************************/
bool Team::operator ==(const Team& team) const {
    return _name == team._name;
}

/******************************************************************************
 *
 *  Overalod operator !=: Class Team
 *_____________________________________________________________________________
 *  Compare if the name is lnot equal to other team's name
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    return true if name is not equal to other team's name
 ******************************************************************************/
bool Team::operator !=(const Team& team) const {
    return _name != team._name;
}

/******************************************************************************
 *
 *  Method getPrint: Class Team
 *_____________________________________________________________________________
 *  return information of the team including its merchandise as a string
 *      in the format of:
 *      Team name
 *      League: AL/NL
 *      ---Souvenirs---
 *      souvenir1 info
 *      souvenir2 info...
 *  - returns std::string
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    team info are returned as a string
 ******************************************************************************/
std::string Team::getPrint() const {
    std::stringstream temp;
    temp << *this;
    return temp.str();
}

/******************************************************************************
 *
 *  Overload operator <<: Class Team
 *_____________________________________________________________________________
 *  return information of the team including its merchandise as a string
 *      in the format of:
 *      Team name
 *      League: AL/NL
 *      ---Souvenirs---
 *      souvenir1 info
 *      souvenir2 info...
 *  - returns ostream&
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    team info are returned as a ostream
 ******************************************************************************/
std::ostream& operator <<(std::ostream& out, const Team& team) {
    Tree<Souvenir> souvenirs = team.getSouvenirs();

    out << team._name << std::endl;
    out << "League: ";
    if(team._league == "AL") {
        out << "American League\n";
    } else if (team._league == "NL") {
        out << "National League\n";
    } else {
        out << "None\n";
    }
    if(!souvenirs.empty()) {
        out << "--- Souvenirs ---\n";
        souvenirs.getPrint(out);
    }
    return out;
}

