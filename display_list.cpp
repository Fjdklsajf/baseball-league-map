#include "display_list.h"
#include "ui_display_list.h"

display_list::display_list(QWidget *parent,
                           set<Souvenir>& list) :
    QDialog(parent),
    ui(new Ui::display_list)
{
    ui->setupUi(this);
}

display_list::~display_list()
{
    delete ui;
}
