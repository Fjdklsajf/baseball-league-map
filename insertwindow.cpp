#include "insertwindow.h"

#include <QMessageBox>
#include <QPainter>
#include <QPen>

using namespace std;

/***********************************************************
*
* InsertWindow: Class InsertWindow
*_________________________________________________________
*  This function allows the user to insert information
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* parent(QWidget*): parent window
* name(QString): tells the user what to insert
* displayDate(bool): checks if we display the date
*
* POST-CONDITIONS
*     This function returns the string put into the text edit
***********************************************************/
InsertWindow::InsertWindow(QWidget *parent,     //Parent window
                           const QString name,
                           bool selecting):   //Checks if we display the date

    QDialog(parent),
    ui(new Ui::InsertWindow)
{
    ui->setupUi(this);
    this->ui->TypeLabel->setText(name);
    QFont font = ui->TypeLabel->font();
    font.setPointSize(16);
    ui->TypeLabel->setAlignment(Qt::AlignHCenter);
    ui->TypeLabel->setFont(font);

    // Turn on the switch for the selection
    if(selecting)
    {
        ui->comboBox->setVisible(true);
        _selections = true;
        ui->WordInput->setVisible(false);
    }

    else
    {
        ui->comboBox->setVisible(false);
         ui->WordInput->setVisible(true);

    }

//    ui->DateLabel->setHidden(!displayDate);
//    ui->DateInput->setHidden(!displayDate);


}

/***********************************************************
*
* ~InsertWindow: Class InsertWindow
*_________________________________________________________
*  This function destructs the window
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* none
*
* POST-CONDITIONS
*     This function deallocates all dynamically allocated memory
***********************************************************/
InsertWindow::~InsertWindow()
{
    delete ui;
}



/***********************************************************
*
* Method get_input: Class InsertWindow
*_________________________________________________________
*  This function receives nothing
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* input: Word that is entered into the text edit
*
* POST-CONDITIONS
*     This function returns the string put into the text edit
***********************************************************/
string InsertWindow::get_input()
{
    return input;
}

/***********************************************************
*
* Method get_input2: Class InsertWindow
*_________________________________________________________
*  This function receives nothing
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* input2: Date that is entered into the text edit
*
* POST-CONDITIONS
*     This function returns the date put into the text edit
***********************************************************/
string InsertWindow::get_input2()
{
    return input2;
}
/***********************************************************
*
* Method INVALID: Class InsertWindow
*_________________________________________________________
*  This function receives nothing
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* none
*
* POST-CONDITIONS
*     This function returns the invalid string to signify
*     that it was not valid
***********************************************************/
bool InsertWindow::is_valid()
{
    return validated;
}

/***********************************************************
*
* Slot on_WordInput_textEdited: Class InsertWindow
*_________________________________________________________
*  This function receives a QString
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* arg1(const QString&)
*
* POST-CONDITIONS
*     This function changes input to arg1 provided the user
*     accepts the dialogue box
***********************************************************/
void InsertWindow::on_WordInput_textEdited(const QString &arg1)
{
    if(on_buttonBox_accepted())
        input = arg1.toStdString();
}

/***********************************************************
*
* Slot on_buttonBox_accepted: Class InsertWindow
*_________________________________________________________
*  This function receives nothing
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* none
*
* POST-CONDITIONS
*     This function returns true. This is simply a way to tell
*     the program that the user accepted the text input
***********************************************************/
bool InsertWindow::on_buttonBox_accepted()
{
    if(_selections)
    {
        // Confirmm the selections
        _options_type =
        ui->comboBox->currentIndex();


        _selections = false;

    }
    return true;
}

/***********************************************************
*
* Slot on_buttonBox_rejected: Class InsertWindow
*_________________________________________________________
*  This function receives nothing
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* none
*
* POST-CONDITIONS
*     This function sets input to the invalid string
***********************************************************/
void InsertWindow::on_buttonBox_rejected()
{
    input = "";
    validated = false;  // Reset the validation
    close();
}

/***********************************************************
*
* Slot on_InsertWindow_rejected: Class InsertWindow
*_________________________________________________________
*  This function receives nothing
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* none
*
* POST-CONDITIONS
*     This function sets input to the invalid string
***********************************************************/
void InsertWindow::on_InsertWindow_rejected()
{
    input = "";
    validated = false;   // Reset the validation
    close();
}
