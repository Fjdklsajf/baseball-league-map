#ifndef STADIUM_H
#define STADIUM_H

#include <iostream>
#include <string>
#include "team.h"
#include "date.h"

using namespace std;
class Stadium {
  public:
    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/
    Stadium();
    Stadium(std::string name, const Team& team, std::string address,
            std::string city, std::string state, string zip, string phoneNum,
            int seatCap, bool hasGrass, const Date& opened);
    Stadium(const Stadium& copy);

    /**************
     ** MUTATORS **
     **************/
    void setName(std::string name);
    void setTeam(const Team& team);
    void setAddress(std::string address);
    void setAddress(std::string address, std::string city,
                    std::string state, string zip);
    void setCity(std::string city);
    void setState(std::string state);
    void setZip(string zip);
    void setPhoneNum(string phoneNum);
    void setSeatCapacity(int seatCap);
    void setGrass(bool hasGrass);
    void setOpenedDate(const Date& opened);
    void setLeague(string type){_team.setLeague(type);}

    /***************
     ** ACCESSORS **
     ***************/
    std::string getName() const;
    Team& getTeam();
    std::string getAddress() const;
    std::string getCity() const;
    std::string getState() const;
    string getZip() const;
    string getPhoneNum() const;
    int getSeatCap() const;
    bool hasGrass() const;
    Date getOpenedDate() const;
    bool isAmerican() const;

    /***********************************
     ** MODIFICATION MEMBER FUNCTIONS **
     ***********************************/
    Stadium& operator =(const Stadium& copy);
    void swapTeams(Stadium& other);

    /*******************************
     ** CONSTANT MEMBER FUNCTIONS **
     *******************************/
    bool operator <(const Stadium& s) const;
    bool operator >(const Stadium& s) const;
    bool operator <=(const Stadium& s) const;
    bool operator >=(const Stadium& s) const;
    bool operator ==(const Stadium& s) const;
    bool operator !=(const Stadium& s) const;
    std::string getPrint() const;

  private:
    friend std::ostream& operator <<(std::ostream& out, const Stadium& s);

  private:
    std::string _name, _address, _city, _state,_phoneNum,_zip;
    Team _team;
    int _seatCap;
    bool _hasGrass;
    Date _opened;
};
/******************************************************************************
 *  Stadium Class
 *    A baseball stadium, conatining stadium details and major league team
 ******************************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/******************************************************************************
 *  Stadium()
 *    Constructor; Initialize member variables of the stadium to default values
 *    Parameters: none
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  Stadium(std::string name, const Team& team, std::string address,
 *          std::string city, std::string state, int zip, int phoneNum,
 *          int seatCap, const Date& opened)
 *    Constructor; Initialize member variables of the stadium
 *    Parameters: std::string, const Team&, std::string, std::string,
 *                std::string, int, int, int, const Date&
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  Stadium(const Stadium& copy)
 *    Constructor; Copy over values of the given Stadium
 *    Parameters: Stadium&
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
 *  void setTeam(const Team& team);
 *
 *    Mutator; This method will update the _team attribute to the parameter
 *      team value
 * ----------------------------------------------------------------------------
 *    Parameters: const Team&
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  void setAddress(std::string address);
 *
 *    Mutator; This method will update the _address attribute to the parameter
 *      address value
 * ----------------------------------------------------------------------------
 *    Parameters: std::string
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  void setAddress(std::string address, std::string city,
 *                  std::string state, int zip);
 *
 *    Mutator; This method will update the _address, _city, _state, and _zip
 *      attributes to the parameter values
 * ----------------------------------------------------------------------------
 *    Parameters: std::string, std::string, std::string, int
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  void setCity(std::string city);
 *
 *    Mutator; This method will update the _city attribute to the parameter
 *      city value
 * ----------------------------------------------------------------------------
 *    Parameters: std::string
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  void setState(std::string state);
 *
 *    Mutator; This method will update the _state attribute to the parameter
 *      state value
 * ----------------------------------------------------------------------------
 *    Parameters: std::string
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  void setZip(int zip);
 *
 *    Mutator; This method will update the _zip attribute to the parameter
 *      zip value
 * ----------------------------------------------------------------------------
 *    Parameters: int
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  void setPhoneNum(int phoneNum);
 *
 *    Mutator; This method will update the _phoneNum attribute to the parameter
 *      phoneNum value
 * ----------------------------------------------------------------------------
 *    Parameters: int
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  void setSeatCapacity(int seatCap);
 *
 *    Mutator; This method will update the _seatCap attribute to the parameter
 *      seatCap value
 * ----------------------------------------------------------------------------
 *    Parameters: int
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  void setOpened Date(const Date& opened);
 *
 *    Mutator; This method will update the _opened attribute to the parameter
 *      opened value
 * ----------------------------------------------------------------------------
 *    Parameters: const Date&
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
 *  Team& getTeam() const;
 *
 *    Accessor; This method will return _team
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: Team&
 ******************************************************************************/

/******************************************************************************
 *  std::string getAddress() const;
 *
 *    Accessor; This method will return _address
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: std::string
 ******************************************************************************/

/******************************************************************************
 *  std::string getCity() const;
 *
 *    Accessor; This method will return _city
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: std::string
 ******************************************************************************/

/******************************************************************************
 *  std::string getState() const;
 *
 *    Accessor; This method will return _state
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: std::string
 ******************************************************************************/

/******************************************************************************
 *  int getZip() const;
 *
 *    Accessor; This method will return _zip
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: int
 ******************************************************************************/

/******************************************************************************
 *  int getPhoneNum() const;
 *
 *    Accessor; This method will return _zip
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: int
 ******************************************************************************/

/******************************************************************************
 *  int getSeatCap() const;
 *
 *    Accessor; This method will return _seatCap
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: int
 ******************************************************************************/

/******************************************************************************
 *  Date getOpenedDate() const;
 *
 *    Accessor; This method will return _opened
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: int
 ******************************************************************************/


/***********************************
 ** MODIFICATION MEMBER FUNCTIONS **
 ***********************************/

/******************************************************************************
 *  Stadium& operator =(const Stadium& copy);
 *
 *    Copy values over from the given Stadium
 * ----------------------------------------------------------------------------
 *    Parameters: const Stadium&
 * ----------------------------------------------------------------------------
 *    Return: Stadium&
 ******************************************************************************/

/******************************************************************************
 *  void swapTeams(Stadium& other);
 *
 *    Swap the teams of two stadiums
 * ----------------------------------------------------------------------------
 *    Parameters: Stadium&
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/


/*******************************
 ** CONSTANT MEMBER FUNCTIONS **
 *******************************/

/******************************************************************************
 *  bool operator <(const Stadium& s) const;
 *
 *    Compare if the name is less than other stadium's name
 * ----------------------------------------------------------------------------
 *    Parameters: const Stadium&
 * ----------------------------------------------------------------------------
 *    Return: bool
 ******************************************************************************/

/******************************************************************************
 *  bool operator >(const Stadium& s) const;
 *
 *    Compare if the name is greater than other stadium's name
 * ----------------------------------------------------------------------------
 *    Parameters: const Stadium&
 * ----------------------------------------------------------------------------
 *    Return: bool
 ******************************************************************************/

/******************************************************************************
 *  bool operator <=(const Stadium& s) const;
 *
 *    Compare if the name is less than or equal to other stadium's name
 * ----------------------------------------------------------------------------
 *    Parameters: const Stadium&
 * ----------------------------------------------------------------------------
 *    Return: bool
 ******************************************************************************/

/******************************************************************************
 *  bool operator >=(const Stadium& s) const;
 *
 *    Compare if the name is great than or equal to other stadium's name
 * ----------------------------------------------------------------------------
 *    Parameters: const Stadium&
 * ----------------------------------------------------------------------------
 *    Return: bool
 ******************************************************************************/

/******************************************************************************
 *  bool operator ==(const Stadium& s) const;
 *
 *    Compare if the name is equal to other stadium's name
 * ----------------------------------------------------------------------------
 *    Parameters: const Stadium&
 * ----------------------------------------------------------------------------
 *    Return: bool
 ******************************************************************************/

/******************************************************************************
 *  bool operator !=(const Stadium& s) const;
 *
 *    Compare if the name is not equal to other stadium's name
 * ----------------------------------------------------------------------------
 *    Parameters: const Stadium&
 * ----------------------------------------------------------------------------
 *    Return: bool
 ******************************************************************************/

/******************************************************************************
 *  std::string getPrint() const;
 *
 *    Return the stadium's information as a string, in the format:
 *      Stadium name
 *      Address
 *      Phone number
 *      Date opened
 *      Capacity
 *      Team info...
 *      Souvenir info...
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: std::string
 ******************************************************************************/



/******************************************************************************
 *  friend std::ostream& operator <<(std::ostream& out, const Stadium& s);
 *
 *    Return the stadium's information as a ostream, in the format:
 *      Stadium name
 *      Address
 *      Phone number
 *      Date opened
 *      Capacity
 *      Team info...
 *      Souvenir info...
 * ----------------------------------------------------------------------------
 *    Parameters:
 * ----------------------------------------------------------------------------
 *    Return: ostream
 ******************************************************************************/
#endif // STADIUM_H
