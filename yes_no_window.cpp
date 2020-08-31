#include "yes_no_window.h"
#include <QDebug>


/***********************************************************
*
* Yes_No_Window: Class Yes_No_Window
*-------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*       parent(*QWidget): parent window
*       title(QString): title of the window
*
* POST-CONDITIONS
*     This function constructs the window
***********************************************************/
Yes_No_Window::Yes_No_Window(QWidget *parent,   //Parent window
                             QString title,
                             bool file,
                             bool stadium,
                             bool souvenir) :   //Title of the window
    QDialog(parent),
    ui(new Ui::Yes_No_Window)
{
    ui->setupUi(this);
    ui->label->setText(title);
    QFont font = ui->label->font();
    font.setPointSize(14);
    ui->label->setFont(font);


    // Mode : File
    if(file)
    {
        this->setWindowTitle("Files");
        // Hide the text editing and labels
        ui->lineEdit->setVisible(false);
        ui->lineEdit_2->setVisible(false);
        ui->lineEdit_3->setVisible(false);
        ui->lineEdit_4->setVisible(false);

        ui->Stadium_label->setVisible(false);
        ui->Team_label->setVisible(false);
        ui->phone_label->setVisible(false);
        ui->phone_label_2->setVisible(false);

        ui->pushButton->setVisible(false);
    }

    // Mode : Stadium
    else if(stadium)
    {

        this->setWindowTitle("Stadiums");

        // Decide the editing mode
        _stadium_inputs = true;


        ui->Yes->setVisible(false);
        ui->No->setVisible(false);
        ui->Yes_3->setVisible(false);
        ui->pushButton->setVisible(true);

        // Adjust the visibility of the editings
        ui->lineEdit->setVisible(true);
        ui->lineEdit_2->setVisible(true);
        ui->lineEdit_3->setVisible(true);
        ui->lineEdit_4->setVisible(true);

        ui->Stadium_label->setText("Enter New Stadium Name:");
        ui->Team_label->setText("Enter New Team Name: ");
        ui->phone_label->setText("Enter New Phone#: ");
        ui->phone_label_2->setText("Enter New Capacity: ");

        ui->Stadium_label->setVisible(true);
        ui->Team_label->setVisible(true);
        ui->phone_label->setVisible(true);
        ui->phone_label_2->setVisible(true);


    }

    // Mode : Souvenir
    else if(souvenir)
    {
        this->setWindowTitle("Sovenirs");

        // Decide the editing mode
        _stadium_inputs = false;
        _souvenir_inputs = true;

        ui->Yes->setVisible(false);
        ui->No->setVisible(false);
        ui->Yes_3->setVisible(false);
        ui->pushButton->setVisible(true);

        // Only need the first two
        ui->lineEdit->setVisible(true);
        ui->lineEdit_2->setVisible(true);
        ui->lineEdit_3->setVisible(false);
        ui->lineEdit_4->setVisible(false);

        ui->Stadium_label->setText("Enter New Item Name:");
        ui->Team_label->setText("Enter New Item Price: ");


        // Set the labels
        ui->Stadium_label->setVisible(true);
        ui->Team_label->setVisible(true);
        ui->phone_label->setVisible(false);
        ui->phone_label_2->setVisible(false);


    }

    // Only display message
    else
    {
        ui->Yes->setVisible(false);
        ui->No->setVisible(false);
        ui->Yes_3->setVisible(false);
        ui->pushButton->setVisible(false);

        // Only need the first two
        ui->lineEdit->setVisible(false);
        ui->lineEdit_2->setVisible(false);
        ui->lineEdit_3->setVisible(false);
        ui->lineEdit_4->setVisible(false);


        // Set the labels
        ui->Stadium_label->setVisible(false);
        ui->Team_label->setVisible(false);
        ui->phone_label->setVisible(false);
        ui->phone_label_2->setVisible(false);
    }
}

/***********************************************************
*
* ~Yes_No_Window: Class Yes_No_Window
*_________________________________________________________
*  This function destructs the window
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*       none
*
* POST-CONDITIONS
*     This function deallocates all dynamically allocated memory
***********************************************************/
Yes_No_Window::~Yes_No_Window()
{
    delete ui;
}

/***********************************************************
*
* slot on_Yes_clicked: Class MainWindow
*_________________________________________________________
*  This function receives nothing
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*       none
*
* POST-CONDITIONS
*     This function changes yesno to 1
***********************************************************/
void Yes_No_Window::on_Yes_clicked()
{
    yesno = 0;
    close();
}

/***********************************************************
*
* slot on_No_clicked: Class MainWindow
*_________________________________________________________
*  This function receives nothing
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*       none
*
* POST-CONDITIONS
*     This function changes yesno to 0
***********************************************************/
void Yes_No_Window::on_No_clicked()
{
    yesno = 1;   // stadiumss
    close();
}

void Yes_No_Window::on_Yes_3_clicked()
{
    yesno = 3;  // Souvenirs
    close();
}


/***********************************************************
*
* slot on_Yes_No_Window_rejected: Class MainWindow
*_________________________________________________________
*  This function receives nothing
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*       none
*
* POST-CONDITIONS
*     This function changes yesno to -1, indicating failure
***********************************************************/


/***********************************************************
*
* function get_answer: Class MainWindow
*_________________________________________________________
*  This function receives nothing
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*       none
*
* POST-CONDITIONS
*     This function returns what the user selected
***********************************************************/
int Yes_No_Window::get_answer()
{
    return yesno;
}




void Yes_No_Window::on_pushButton_clicked()
{
    // Validate inputs for stadium
    if(_stadium_inputs == true)
    {
        _stadium_name = ui->lineEdit->text().toStdString();
        _team_name = ui->lineEdit_2->text().toStdString();

        _phone_num = ui->lineEdit_3->text().toStdString();
        _capacity = ui->lineEdit_4->text().toStdString();

        if(_phone_num != "")
        {
            // Verify every character to check
            for(size_t j = 0; j < _phone_num.length();j++)
            {
                if(!isdigit(_phone_num[j]))
                {
                    // If it's not valid
                    _phone_num = "";
                    QMessageBox::information(this,"Error",
                                             "Invalid Phone#.");
                    break;
                }
            }

        }

        // Capacity will need to be verified
        if(_capacity != " ")
        {
            // Verify every character to check
            for(size_t k = 0; k < _capacity.length();k++)
            {
                if(!isdigit(_capacity[k]))
                {
                    // If it's not valid
                    _capacity = "";
                    QMessageBox::information(this,"Error",
                                             "Invalid Capacity.");
                    break;
                }
            }
        }

        _stadium_inputs = false;

        ui->lineEdit->clear();
        ui->lineEdit_2->clear();

        close();

    }


    // Validate inputs for souvenir
    else if(_souvenir_inputs == true)
    {
        _item_name = ui->lineEdit->text().toStdString();
        _item_price = ui->lineEdit_2->text().toStdString();

        qDebug() << "www\n";

        // Validate non-empty string
        if(_item_price != "")
        {
            // Verify every character to check
            for(size_t j = 0; j < _item_price.length();j++)
            {
                // Only decimal points and digit in the price
                if(!isdigit(_item_price[j]) &&
                  _item_price[j] != '.'      )
                {
                    // If it's not valid
                    _item_price = "";
                    QMessageBox::information(this,"Error",
                                             "Invalid Price input.");
                    break;
                }
            }

        }

        _souvenir_inputs = false;
        close();


    }
}
