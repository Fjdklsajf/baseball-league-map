#ifndef YES_NO_WINDOW_H
#define YES_NO_WINDOW_H

#include <QDialog>
#include "ui_yes_no_window.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <QMessageBox>

using namespace std;


namespace Ui {
class Yes_No_Window;
}

class Yes_No_Window : public QDialog
{
    Q_OBJECT

public:
    /********************************
    *          CONSTRUCTOR          *
    ********************************/
    explicit Yes_No_Window(QWidget *parent = nullptr,
                           QString title = "",
                           bool file = true,
                           bool stadium = false,
                           bool souvenir = false);

    /********************************
    *          DESTRUCTOR           *
    ********************************/
    ~Yes_No_Window();

    /********************************
    *          ACCESSORS            *
    ********************************/
    int get_answer();
    string get_stadium() {return _stadium_name;}
    string get_team() {return _team_name;}
    string get_phone() {return _phone_num;}
    string get_capacity() {return _capacity;}
    string get_item() {return _item_name;}
    string get_price() {return _item_price;}


private slots:
    /********************************
    *             SLOTS             *
    ********************************/
    void on_Yes_clicked();

    void on_No_clicked();



    void on_Yes_No_Window_rejected()
    {close();}


    void on_Yes_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::Yes_No_Window *ui;
    int yesno = 0;     //Checks if the user clicks the types

    // 0: map    1: stadiums
    // 2: teams  3: souvenirs list

    //----------------INPUTS------------------
    bool _stadium_inputs = false;
    bool _souvenir_inputs = false;

    string _stadium_name = "";
    string _capacity = "";
    string _phone_num = "";
    string _team_name = "";
    string _item_name = "";
    string _item_price = "";
};

#endif // YES_NO_WINDOW_H

/********************************
*    CONSTRUCTOR/DESTRUCTOR     *
********************************/
/*****************************************************************
* Yes_No_Window
*
*     Constructor; Initalizes class attributes
*     Parameters: parent(*QWidget): parent window
*                 title(QString): title of the window
*
*     Return: none
***************************************************************/

/*****************************************************************
* ~Yes_No_Window
*
*     Destructor; Deallocates all dynamically allocated memory
*     Parameters: none
*     Return: none
***************************************************************/

/********************************
*           ACCESSORS           *
********************************/

/*****************************************************************
* int get_answer();
*
*     Accessor; Returns the choice that the user specifies
*     Parameters: none
*     Return: int
***************************************************************/

/********************************
*             SLOTS             *
********************************/

/*****************************************************************
* void on_Yes_clicked();
*
*     Slot; Sets answer to 1 and closes the window
*     Parameters: none
*     Return: none
***************************************************************/

/*****************************************************************
* void on_No_clicked();
*
*     Slot; Sets answer to 2 and closes the window
*     Parameters: none
*     Return: none
***************************************************************/
