#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <iostream>
#include "souvenir.h"
#include "tree.h"
#include <set>
#include <functional>

using namespace std;

class Team {
  public:
    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/
    Team(std::string name = "", std::string league = "AL");
    Team(const Team& copy);

    /**************
     ** MUTATORS **
     **************/
    void setName(std::string name);
    void setSouvenirs(const Tree<Souvenir>& souvenirs);
    void setLeague(std::string league);

    /***************
     ** ACCESSORS **
     ***************/
    std::string getName() const;
    Tree<Souvenir> getSouvenirs() const;
    std::string getLeague() const;
    bool isAmericanLeague() const;

    set<Souvenir>& getSV()
    {return _sv;}

    /***********************************
     ** MODIFICATION MEMBER FUNCTIONS **
     ***********************************/
    void addSouvenir(const Souvenir& souvenir);
    void addSouvenir(std::string name, double price);
    bool deleteSouvenir(std::string name);
    bool changeSouvenirInfo(std::string oldName, std::string newName, double price);
    Team& operator =(const Team& copy);
    void swapLeague();

    void adding(const Souvenir& souvenir)
    {
        _sv.insert(souvenir);
    }

    /*******************************
     ** CONSTANT MEMBER FUNCTIONS **
     *******************************/
    bool operator <(const Team& team) const;
    bool operator >(const Team& team) const;
    bool operator <=(const Team& team) const;
    bool operator >=(const Team& team) const;
    bool operator ==(const Team& team) const;
    bool operator !=(const Team& team) const;
    std::string getPrint() const;

  private:
    friend std::ostream& operator <<(std::ostream& out, const Team& team);

  private:
    std::string _name, _league;
    Tree<Souvenir> _souvenirs;    //replace with user defined tree
    set<Souvenir> _sv;
};
/******************************************************************************
 *  Team Class
 *    A baseball team, containing its name, league and list of souvenirs
 ******************************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/******************************************************************************
 *  Team(std::string name = "", std::string league = "")
 *    Constructor; Initialize member variables of the team
 *    Parameters: std::string, std::string
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  Team(const Team& copy)
 *    Constructor; Copy over values of given Team
 *    Parameters: const Team&
 *    Return: void
 ******************************************************************************/


/**************
 ** MUTATORS **
 **************/

/******************************************************************************
 *  void setName(std::string name);
 *
 *    Mutator; This method will update the _name attribute to the parameter
 *      name value
 * ----------------------------------------------------------------------------
 *    Parameters: std::string
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  void setSouvenirs(const Tree<Souvenir>& souvenirs);
 *
 *    Mutator; This method will update the _souvenirs attribute to the parameter
 *      souvenirs value
 * ----------------------------------------------------------------------------
 *    Parameters: const Tree<Souvenir>&
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  void setLeague(std::string league);
 *
 *    Mutator; This method will update the _league attribute to the parameter
 *      league value
 * ----------------------------------------------------------------------------
 *    Parameters: std::string
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/


/***************
 ** ACCESSORS **
 ***************/

/******************************************************************************
 *  std::string getName() const;
 *
 *    Accessor; This method will return _name
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: std::string
 ******************************************************************************/

/******************************************************************************
 *  Tree<Souvenir> getSouvenirs() const;
 *
 *    Accessor; This method will return _souvenirs
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: Tree<Souvenir>
 ******************************************************************************/

/******************************************************************************
 *  std::string getLeague() const;
 *
 *    Accessor; This method will return _league
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: std::string
 ******************************************************************************/


/***********************************
 ** MODIFICATION MEMBER FUNCTIONS **
 ***********************************/

/******************************************************************************
 *  void addSouvenir(const Souvenir& souvenir);
 *
 *    Add a souvenir to the list of souvenirs
 * ----------------------------------------------------------------------------
 *    Parameters: const Souvenir&
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  void addSouvenir(std::string name, double price);
 *
 *    Create a new souvenir and add it to the list of souvenirs
 * ----------------------------------------------------------------------------
 *    Parameters: std::string, double
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  bool deleteSouvenir(std::string name);
 *
 *    delete a souvenir with the given name. Return false if oldName is not found
 * ----------------------------------------------------------------------------
 *    Parameters: std::string
 * ----------------------------------------------------------------------------
 *    Return: bool
 ******************************************************************************/

/******************************************************************************
 *  bool changeSouvenirInfo(std::string oldName, std::string newName, double price);
 *
 *    update a souvenir's info. Return false if oldName is not found
 * ----------------------------------------------------------------------------
 *    Parameters: std::string, std::string, double
 * ----------------------------------------------------------------------------
 *    Return: bool
 ******************************************************************************/

/******************************************************************************
 *  Team& operator =(const Team& copy);
 *
 *    Sets values of this team equal to the given Team copy
 * ----------------------------------------------------------------------------
 *    Parameters: const Team&
 * ----------------------------------------------------------------------------
 *    Return: Team&
 ******************************************************************************/


/*******************************
 ** CONSTANT MEMBER FUNCTIONS **
 *******************************/

/******************************************************************************
 *  bool operator <(const Team& team) const;
 *
 *    Compare if the name is less than other team's name
 * ----------------------------------------------------------------------------
 *    Parameters: const Team& team
 * ----------------------------------------------------------------------------
 *    Return: bool
 ******************************************************************************/

/******************************************************************************
 *  bool operator >(const Team& team) const;
 *
 *    Compare if the name is greater than other team's name
 * ----------------------------------------------------------------------------
 *    Parameters: const Team& team
 * ----------------------------------------------------------------------------
 *    Return: bool
 ******************************************************************************/

/******************************************************************************
 *  bool operator <=(const Team& team) const;
 *
 *    Compare if the name is less than or equal to other team's name
 * ----------------------------------------------------------------------------
 *    Parameters: const Team& team
 * ----------------------------------------------------------------------------
 *    Return: bool
 ******************************************************************************/

/******************************************************************************
 *  bool operator >=(const Team& team) const;
 *
 *    Compare if the name is greater than or equal to other team's name
 * ----------------------------------------------------------------------------
 *    Parameters: const Team& team
 * ----------------------------------------------------------------------------
 *    Return: bool
 ******************************************************************************/

/******************************************************************************
 *  bool operator ==(const Team& team) const;
 *
 *    Compare if the name is equal to other team's name
 * ----------------------------------------------------------------------------
 *    Parameters: const Team& team
 * ----------------------------------------------------------------------------
 *    Return: bool
 ******************************************************************************/

/******************************************************************************
 *  bool operator !=(const Team& team) const;
 *
 *    Compare if the name is not equal to other team's name
 * ----------------------------------------------------------------------------
 *    Parameters: const Team& team
 * ----------------------------------------------------------------------------
 *    Return: bool
 ******************************************************************************/

/******************************************************************************
 *  std::string getPrint() const;
 *
 *    return information of the team including its merchandise as a string
 *      in the format of:
 *      Team name
 *      League: AL/NL
 *      ---Souvenirs---
 *      souvenir1 info
 *      souvenir2 info...
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/



/******************************************************************************
 *  friend std::ostream& operator <<(std::ostream& out, const Team& team);
 *
 *    return information of the team including its merchandise as a ostream
 *      in the format of:
 *      Team name
 *      League: AL/NL
 *      ---Souvenirs---
 *      souvenir1 info
 *      souvenir2 info...
 * ----------------------------------------------------------------------------
 *    Parameters: std::ostream&, const Team&
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/
#endif // TEAM_H
