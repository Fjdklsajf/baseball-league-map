#include "display_stadium_info.h"
#include <QMessageBox>
#include <set>
#include <functional>
#include <souvenir_modifications.h>


using namespace std;
/*****************************************
 * Stadium info window
 * ------------------------------
 * Pre-condition: receive the parent window,
 * a vector of stadiums, the access mode
 * -------------------------------
 * Post-condtion: The list info will be
 * displayed to the window
 ****************************************/
Stadium_info::Stadium_info(QWidget* parent,
                           vector<Stadium> & list,
                           size_t index,
                           bool is_access):
    QDialog(parent),ui(new Ui::Stadium_info)
{
    ui->setupUi(this);

    if(list.size() > 0)
        _list_access =& list;  // Pointer to the object

    // Hide the modifying feature when needed
    if(!is_access)
    {
        ui->Editing->setVisible(false);
        ui->Editing_stad->setVisible(false);
        ui->label->setText("Mode: User");
        _is_access = false;
    }
    else
    {
        ui->Editing->setVisible(true);
        ui->Editing_stad->setVisible(true);
        ui->label->setText("Mode: Administrator");
        _is_access = true;
    }

    // No access to empty container
    if(list.size() == 0)
    {
        QMessageBox::information(this,"Error","Sorry, File not found.");

        return;
    }

    QString line_end("");

    this->setWindowTitle(QString:: fromStdString
                         (list.at(index).getName()));

    // Ready to display all the informations
    ui->textBrowser->append("Stadium Name: " +
                            QString:: fromStdString
                            (list.at(index).getName()));

    ui->textBrowser->append("Team Name: " +
                            QString:: fromStdString
                            (list.at(index).getTeam().getName()));

    ui->textBrowser->append("\n");

    ui->textBrowser->append("Address: " +
                            QString:: fromStdString
                            (list.at(index).getAddress())
                            + "\n" +
                            QString:: fromStdString(list.at(index).getCity())
                            + " "
                            + QString:: fromStdString
                            (list.at(index).getState())
                            + " "
                            + QString:: fromStdString(
                                list.at(index).getZip())
                            + "\n");

    ui->textBrowser->append("Phone#: " +
                            QString:: fromStdString
                            (list.at(index).getPhoneNum())
                            +"\n");

    ui->textBrowser->append("Date Opened: " +
                            QString::fromStdString
                            (list.at(index).getOpenedDate().
                                                   getPrint()) + "\n");

    ui->textBrowser->append("Capacity: "+
                            QString::fromStdString
                            (to_string(list.at(index).getSeatCap()))
                            + "\n");

    if(list.at(index).hasGrass())
        ui->textBrowser->append("Has Grass Surface\n");

    else
        ui->textBrowser->append("No Grass Surface\n\n\n");


    set<Souvenir>:: iterator it;

    it = list.at(index).getTeam().getSV().begin();


    ui->textBrowser->append("Souvenirs List:\n");

    qDebug() << list.at(index).getTeam().getSV().size() << endl;


    // Get the souvenior list from the stadium's team info
    for(;it !=list.at(index).getTeam().getSV().end();it++)
    {
        ui->textBrowser->append(QString:: fromStdString
                                ((*it).getName())
                                + "     $" +
                                QString::number((*it).getPrice(),'g',5));
                                // Formating the decimals with Qstring number

    }

    // Scroll up the browser to the top
    QTextCursor cursor_ = ui->textBrowser->textCursor();
    cursor_.setPosition(0);
    ui->textBrowser->setTextCursor(cursor_);




}

/*****************************************
 * Stadium info window
 * ------------------------------
 * Pre-condition: receive the parent window,
 * a set of souvenirs, the access mode
 * -------------------------------
 * Post-condtion: The list info will be
 * displayed to the window
 ****************************************/
Stadium_info::Stadium_info(QWidget *parent,
                           set<Souvenir> & list_souv):
    QDialog(parent),ui(new Ui::Stadium_info)
{

    ui->setupUi(this);

    this->setWindowTitle("Purchase History");

        //Hide the buttons
    ui->Editing->setVisible(false);
    ui->Editing_stad->setVisible(false);
    ui->buttonBox->setVisible(false);
    double total_cost = 0;

    if(list_souv.size() == 0)
    {
        return;
    }

    else
    {
        // Assign the iterator
        set<Souvenir>::iterator it;
        it = list_souv.begin();

        // Go through the list
        for(;it!=list_souv.end(); it++)
        {
            // Calculate the total cost
            total_cost += it->getPrice();
        }


        ui->textBrowser->append("Total Costs: $ "
                              + QString::number(total_cost,'g',5)
                                +"\n\n");

        for(it=list_souv.begin();it!=list_souv.end();it++)
        {
            ui->textBrowser->append(QString::fromStdString
                                    (it->getName() + "   $ ")
                                    + QString::number
                                    (it->getPrice(),'g',5));
        }

        close();

    }


}

void Stadium_info::on_Stadium_info_accepted()
{

}

Stadium_info::~Stadium_info()
{
    delete ui;
}

/*****************************************
 * Stadium info Editing
 * ------------------------------
 * Pre-condition: there is an access to the
 * container
 * -------------------------------
 * Post-condtion: The list info will be
 * updated with the window
 ****************************************/
void Stadium_info::on_Editing_clicked()
{
    // Execute this only when the container in non-empty
    if(_list_access != nullptr)
    {
        Souvenir_Modifications modify(this,*_list_access,
                                   _is_access,2);

        modify.exec();

        close();   // Close after modifying
    }

    else
    {
        QMessageBox::information(this,"Error","No Files found\n");
    }

}

/*****************************************
 * Stadium info Editing
 * ------------------------------
 * Pre-condition: there is an access to the
 * container
 * -------------------------------
 * Post-condtion: The list info will be
 * updated with the window
 ****************************************/
void Stadium_info::on_Editing_stad_clicked()
{
    // Execute this only when the container in non-empty
    if(_list_access != nullptr)
    {
        Souvenir_Modifications modify(this,*_list_access,
                                   _is_access,1);

        modify.exec();
        close();   // Close after modifying
    }

    else
    {
        QMessageBox::information(this,"Error","No Files found\n");
    }
}
