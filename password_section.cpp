#include "password_section.h"
#include "ui_password_section.h"

/*****************************************
 * Password mainwinow
 * ------------------------------
 * Pre-condition: parent windwow
 * -------------------------------
 * Post-condtion: Ready to display the stadiums
 * in certain sorting style with other windows
 *
 ****************************************/
Password_section::Password_section(QWidget *parent,
                                   const string& title) :
    QDialog(parent),
    ui(new Ui::Password_section)
{
    ui->setupUi(this);

    this->setWindowTitle(QString::fromStdString(title));

}

Password_section::~Password_section()
{
    _access = false;
    delete ui;
}

void Password_section::on_lineEdit_2_editingFinished()
{
    if(ui->lineEdit_2->text() ==
       QString::fromStdString(get_correct()))
    {
        _access = true;
        this->close();

    }

    else
    {
        ui->message->setText("Incorrect Password.");
    }
}

void Password_section::on_pushButton_clicked()
{
    // Call line editing finish
    this->on_lineEdit_2_editingFinished();
}
