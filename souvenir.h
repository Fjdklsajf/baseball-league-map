#ifndef SOUVENIR_H
#define SOUVENIR_H

#include <string>
#include <iostream>

class Souvenir {
  public:
    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/
    Souvenir(std::string name = "", double price = 0);
    Souvenir(const Souvenir& copy);

    /**************
     ** MUTATORS **
     **************/
    void setName(std::string name);
    void setPrice(double price);

    /***************
     ** ACCESSORS **
     ***************/
    std::string getName() const;
    double getPrice() const;

    /***********************************
     ** MODIFICATION MEMBER FUNCTIONS **
     ***********************************/
    Souvenir& operator =(const Souvenir& copy);

    /*******************************
     ** CONSTANT MEMBER FUNCTIONS **
     *******************************/
    bool operator <(const Souvenir& s) const;
    bool operator >(const Souvenir& s) const;
    bool operator <=(const Souvenir& s) const;
    bool operator >=(const Souvenir& s) const;
    bool operator ==(const Souvenir& s) const;
    bool operator !=(const Souvenir& s) const;
    std::string getPrint() const;

    std::string _name;
    double _price;

  private:
    friend std::ostream& operator <<(std::ostream& out, const Souvenir& s);

  private:

};
/******************************************************************************
 *  Souvenir Class
 *    Represents a souvenir to be sold. Contains name and price
 ******************************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/******************************************************************************
 *  Souvenir(std::string name = "", double price = 0)
 *    Constructor; Initialize member variables of a souvenir
 *    Parameters: std::string, double
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  Souvenir(const Souvenir& copy)
 *    Copy Constructor; Copy over values of given Souvenir
 *    Parameters: const Souvenir&
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
 *  void setPrice(double price);
 *
 *    Mutator; This method will update the _price attribute to the parameter
 *      _price value
 * ----------------------------------------------------------------------------
 *    Parameters: double
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
 *  double getPrice() const;
 *
 *    Accessor; This method will return _price
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: double
 ******************************************************************************/


/***********************************
 ** MODIFICATION MEMBER FUNCTIONS **
 ***********************************/

/******************************************************************************
 *  Souvenir& operator =(const Souvenir& copy);
 *
 *    Sets values of this souvenir equal to the given vcpy
 * ----------------------------------------------------------------------------
 *    Parameters: const Souvenir&
 * ----------------------------------------------------------------------------
 *    Return: Souvenir&
 ******************************************************************************/


/*******************************
 ** CONSTANT MEMBER FUNCTIONS **
 *******************************/

/******************************************************************************
 *  bool operator <(const Souvenir& s) const;
 *
 *    Check if the name is less than the given souvenir's name
 * ----------------------------------------------------------------------------
 *    Parameters: const Souvenir&
 * ----------------------------------------------------------------------------
 *    Return: bool
 ******************************************************************************/

/******************************************************************************
 *  bool operator >(const Souvenir& s) const;
 *
 *    Check if the name is greater than the given souvenir's name
 * ----------------------------------------------------------------------------
 *    Parameters: const Souvenir&
 * ----------------------------------------------------------------------------
 *    Return: bool
 ******************************************************************************/

/******************************************************************************
 *  bool operator <=(const Souvenir& s) const;
 *
 *    Check if the name is less than or equal to the given souvenir's name
 * ----------------------------------------------------------------------------
 *    Parameters: const Souvenir&
 * ----------------------------------------------------------------------------
 *    Return: bool
 ******************************************************************************/

/******************************************************************************
 *  bool operator >=(const Souvenir& s) const;
 *
 *    Check if the name is greater than or equal to the given souvenir's name
 * ----------------------------------------------------------------------------
 *    Parameters: const Souvenir&
 * ----------------------------------------------------------------------------
 *    Return: bool
 ******************************************************************************/

/******************************************************************************
 *  bool operator ==(const Souvenir& s) const;
 *
 *    Check if the name is equal to the given souvenir's name
 * ----------------------------------------------------------------------------
 *    Parameters: const Souvenir&
 * ----------------------------------------------------------------------------
 *    Return: bool
 ******************************************************************************/

/******************************************************************************
 *  bool operator !=(const Souvenir& s) const;
 *
 *    Check if the name is not equal to the given souvenir's name
 * ----------------------------------------------------------------------------
 *    Parameters: const Souvenir&
 * ----------------------------------------------------------------------------
 *    Return: bool
 ******************************************************************************/

/******************************************************************************
 *  std::string getPrint() const;
 *
 *    Return the souvenir info as a string, in the format of:
 *      cost1 - name1
 *      cost2 - name2
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: std::string
 ******************************************************************************/



/******************************************************************************
 *  friend std::ostream& operator <<(std::ostream& out, const Souvenir& s);
 *
 *    Write the souvenir info to the ostream, in the format of:
 *      cost1 - name1
 *      cost2 - name2
 * ----------------------------------------------------------------------------
 *    Parameters: std::ostream&, const Souvenir&
 * ----------------------------------------------------------------------------
 *    Return: std::ostream&
 ******************************************************************************/
#endif // SOUVENIR_H
