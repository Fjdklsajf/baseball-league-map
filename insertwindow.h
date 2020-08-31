#ifndef INSERTWINDOW_H
#define INSERTWINDOW_H

#include <QDialog>
#include <string>
#include "ui_insertwindow.h"


using namespace std;

namespace Ui {
class InsertWindow;
}

class InsertWindow : public QDialog
{
    Q_OBJECT

public:
    /********************************
    *          CONSTRUCTOR          *
    ********************************/
    explicit InsertWindow(QWidget *parent = nullptr,    //Parent window
                          const QString name = "",
                          bool selecting = false);    //Checks if we display
                                                        //the date input

    /********************************
    *          DESTRUCTOR           *
    ********************************/
    ~InsertWindow();


    /********************************
    *          ACCESSORS            *
    ********************************/
    string get_input();
    string get_input2();
    int get_type() {return _options_type;}
    bool is_valid();

private slots:

    /********************************
    *             SLOTS             *
    ********************************/
    void on_WordInput_textEdited(const QString &arg1);
    //String that is entered

    //User presses the "Ok" button
    bool on_buttonBox_accepted();

    //User presses the "Cancel" button
    void on_buttonBox_rejected();

    //User presses the X button at the top
    void on_InsertWindow_rejected();


private:

    //-------------------CHECKERS--------------------
    Ui::InsertWindow *ui;
    string input;     //String that stores the information entered
    string input2;    //String that stores the information entered
    bool validated = true;
    bool _selections = false;

    int _options_type = 0;
    //  0-5 types for the sorting part of stadiums

};

#endif // INSERTWINDOW_H

/********************************
*    CONSTRUCTOR/DESTRUCTOR     *
********************************/
/*****************************************************************
* InsertWindow
*
*     Constructor; Initalizes class attributes
*     Parameters: parent(*QWidget): parent window
*                 name(QString): Title text at the top of the window
*                 displayDate(bool): Checks if the user inputs a date
*     Return: none
***************************************************************/

/*****************************************************************
* ~InsertWindow
*
*     Destructor; Deallocates all dynamically allocated memory
*     Parameters: none
*     Return: none
***************************************************************/

/********************************
*           ACCESSORS           *
********************************/

/*****************************************************************
* string get_input()
*
*     Accessor; Returns the data entered into the text edit
*     Parameters: none
*     Return: string
***************************************************************/

/*****************************************************************
* string get_input2()
*
*     Accessor; Returns the data entered into the second text edit
*     Parameters: none
*     Return: string
***************************************************************/

/*****************************************************************
* string INVALID()
*
*     Accessor; Returns INV (used for input validation)
*     Parameters: none
*     Return: string
***************************************************************/



/********************************
*             SLOTS             *
********************************/

/*****************************************************************
* void on_WordInput_textEdited
*
*     Slot; Determines what the class does when the user enters data
*           into the text edit
*     Parameters: arg1(QString): data in the text edit
*     Return: none
***************************************************************/

/*****************************************************************
* bool on_buttonBox_accepted();
*
*     Slot; Determines what the class does when the user presses the "ok" button
*     Parameters: none
*     Return: bool
***************************************************************/

/*****************************************************************
* bool on_buttonBox_rejected();
*
*     Slot; Determines what the class does when the user presses the
*           cancel button
*     Parameters: none
*     Return: bool
***************************************************************/

/*****************************************************************
* bool on_InsertWindow_rejected();
*
*     Slot; Determines what the class does when the user presses the
*           X button at the top of the window
*     Parameters: none
*     Return: bool
***************************************************************/
