#ifndef DISPLAY_LIST_H
#define DISPLAY_LIST_H

#include <QDialog>
#include "stadium.h"
#include <set>
#include <functional>

namespace Ui {
class display_list;
}

class display_list : public QDialog
{
    Q_OBJECT

public:
    explicit display_list(QWidget *parent,
                          set<Souvenir>& list);
    ~display_list();

private:
    Ui::display_list *ui;
};

#endif // DISPLAY_LIST_H
