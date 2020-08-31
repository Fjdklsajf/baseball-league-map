#ifndef SOUVENIR_MODIFICATIONS_H
#define SOUVENIR_MODIFICATIONS_H

#include <QDialog>
#include <stadium.h>
#include <set>
#include <functional>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QTableWidgetItem>
#include <QTableWidget>
#include "yes_no_window.h"
#include "QMessageBox"
#include <set>
#include <functional>

using namespace  std;

namespace Ui {
class Souvenir_Modifications;
}

class Souvenir_Modifications : public QDialog
{
    Q_OBJECT

public:

    //---------CONSTRCUTOR--DESTRUTOR-----------------
    explicit Souvenir_Modifications(QWidget *parent,
                                    vector<Stadium>& stadiums,
                                    bool need_modify = false,
                                    int  type = 2);

    ~Souvenir_Modifications();


    //---------ACCESSORS-----------
    string get_item() {return _item_name;}
    string get_price() {return _item_price;}
    Stadium&  get_added() {return current_added;}
    bool is_added() {return _is_added;}

private slots:
    void on_pushButton_clicked();

    void on_add_souvenir_clicked();

    void on_delete_souvenir_clicked();

private:
    Ui::Souvenir_Modifications * ui;

    //------------ACCESS OF LISTS--------------
    vector<Stadium>*  _list_stadium = nullptr;

    //------------OBJECTS & NAMES-------------
    string _stadium_file = "";
    string _souvenir_file = "";
    string _item_name = "";
    string _item_price = "";

    bool _is_added = false;
    Stadium current_added;


    int _modify_type = 0;         // 1 for stadiums
                                  // 2 for souvenir
};

#endif // SOUNVENIR_MODIFICATIONS_H
