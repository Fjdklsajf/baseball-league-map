#ifndef DISPLAY_STADIUM_INFO_H
#define DISPLAY_STADIUM_INFO_H
#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QDialog>
#include <iostream>
#include <QtDebug>
#include <QApplication>
#include "ui_display_stadium_info.h"
#include "graph_list.h"

using namespace std;


namespace Ui {
class Stadium_info;
}

class Stadium_info : public QDialog
{
    Q_OBJECT

public:

    //------------CONSTRUCTOR-----------------
    explicit Stadium_info(QWidget *parent,
                          vector<Stadium>& list,
                          size_t index = 0,
                          bool is_access = false);

    explicit Stadium_info(QWidget *parent,
                          set<Souvenir> & list);
    ~Stadium_info();

private slots:
    void on_Stadium_info_accepted();

    void on_Editing_clicked();

    void on_Editing_stad_clicked();

private:
    Ui::Stadium_info *ui;

    //-------------CONTAINER ACCESS---------------
    List<Stadium> _stadium_list;
    vector<Stadium>* _list_access = nullptr;  // Stadium & souvenir

    set<Souvenir>* _chart_access = nullptr;   //
    bool _is_access = false;  // Access for modifying the list




};

/*****************************************
 * Stadium info window
 * ------------------------------
 * Pre-condition: receive the parent window,
 * a vector of stadiums, the access mode
 * -------------------------------
 * Post-condtion: The list info will be
 * displayed to the window
 ****************************************/
/*****************************************
 * Stadium info window
 * ------------------------------
 * Pre-condition: receive the parent window,
 * a set of souvenirs, the access mode
 * -------------------------------
 * Post-condtion: The list info will be
 * displayed to the window
 ****************************************/
/*****************************************
 * Stadium info Editing
 * ------------------------------
 * Pre-condition: there is an access to the
 * container
 * -------------------------------
 * Post-condtion: The list info will be
 * updated with the window
 ****************************************/





#endif // DISPLAY_STADIUM_INFO_H
