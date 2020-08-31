#ifndef PASSWORD_SECTION_H
#define PASSWORD_SECTION_H

#include <QDialog>
#include <iostream>

using namespace std;

namespace Ui {
class Password_section;
}

class Password_section : public QDialog
{
    Q_OBJECT

public:
    explicit Password_section(QWidget *parent = nullptr,
                              const string& title ="Administrator");
    ~Password_section();

    string get_correct() const
    {
        return  _correct_password;
    }

    bool is_accessed() const
    {
        return _access;
    }

private slots:
    void on_lineEdit_2_editingFinished();

    void on_pushButton_clicked();

private:
    Ui::Password_section *ui;

    string input;     // For the password
    string _correct_password = "CS008";

    bool _access = false;
};

#endif // PASSWORD_SECTION_H
