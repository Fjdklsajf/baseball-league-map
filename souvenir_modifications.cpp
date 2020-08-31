#include "souvenir_modifications.h"
#include "ui_souvenir_modifications.h"
#include <QDebug>

Souvenir_Modifications::Souvenir_Modifications(QWidget *parent,
                                               vector<Stadium>& stadiums,
                                               bool need_modify,
                                               int type) :
    QDialog(parent),
    ui(new Ui::Souvenir_Modifications)
{
    ui->setupUi(this);

    set<Souvenir>:: iterator it;

    // Display the combox based on the switch
    if(need_modify)
    {
        ui->label->setVisible(true);
        ui->comboBox->setVisible(true);
    }

    else
    {
        ui->label->setVisible(false);
        ui->comboBox->setVisible(false);
    }


    int index = 0;

    _list_stadium =& stadiums;  // Connect the pointer

    // Adjust the column size
    ui->Souvenir_items->setColumnWidth(0,260);
    ui->Souvenir_items->setColumnWidth(1,260);

    _modify_type = type;  // Set the type

    // Stadium
    if(type == 1)
    {
        ui->add_souvenir->setVisible(false);
        ui->delete_souvenir->setVisible(false);

        _modify_type = 1;
        this->setWindowTitle("Stadiums");

        // Add a empty string first
        ui->comboBox->addItem("");

        // Initialize the combobox and the row for the list
        for(size_t k = 0; k < stadiums.size();index++, k++)
        {
            // Display combox only when modifying
            if(need_modify)
                ui->comboBox->addItem(QString::fromStdString
                                      (stadiums.at(k).getName()));
            ui->Souvenir_items->setRowCount(index);
        }

        ui->Souvenir_items->setRowCount(index);

        index = 0;

        // Hide the second column for the stadiums
        ui->Souvenir_items->setColumnHidden(1,1);

        for(size_t j = 0; j < stadiums.size();index++,j++)
        {
            QTableWidgetItem* item = new QTableWidgetItem;
            item->setText(QString::fromStdString
                          (stadiums.at(j).getName()));

            QTableWidgetItem* team = new QTableWidgetItem;
            team->setText(QString::fromStdString
                                   (stadiums.at(j)
                                   .getTeam().getName()));

            // Set the item to the column
            ui->Souvenir_items->setItem(index,0,item);
            ui->Souvenir_items->setItem(index,1,team);

        }


    }


    // Display sorting stadiums
    if(type == 4)
    {
        ui->add_souvenir->setVisible(false);
        ui->delete_souvenir->setVisible(false);

        _modify_type = 4;
        this->setWindowTitle("Stadiums Sorted");

        // Add a empty string first
        ui->comboBox->addItem("");

        // Initialize the combobox and the row for the list
        for(size_t k = 0; k < stadiums.size();index++, k++)
        {
            // Display combox only when modifying
            if(need_modify)
                ui->comboBox->addItem(QString::fromStdString
                                      (stadiums.at(k).getName()));
            ui->Souvenir_items->setRowCount(index);
        }

        ui->Souvenir_items->setRowCount(index);

        index = 0;

        // Hide the second column for the stadiums

        for(size_t j = 0; j < stadiums.size();index++,j++)
        {
            QTableWidgetItem* item = new QTableWidgetItem;
            item->setText(QString::fromStdString
                          (stadiums.at(j).getName()) +
                          "  (" +
                          QString::fromStdString(stadiums.at(j)
                          .getTeam().getName()) + ")");

            QTableWidgetItem* date_open = new QTableWidgetItem;

            date_open->setText(QString::fromStdString(stadiums.at(j).
                                                      getOpenedDate().
                                                      getPrint()));

            // Set the item to the column
            ui->Souvenir_items->setItem(index,0,item);
            ui->Souvenir_items->setItem(index,1,date_open);

        }
    }


    // Go to one particular team's list
    it = stadiums.at(0).getTeam().getSV().begin();

    // Select the type for the modifying
    if(type == 2)
    {
        ui->add_souvenir->setVisible(true);
        ui->delete_souvenir->setVisible(true);

        _modify_type = 2;
        this->setWindowTitle("Souvenirs");

        index = 0;

        // Add a empty string first
        ui->comboBox->addItem("");

        // Initialize the combobox and the row for the list
        for(; it!= stadiums.at(0).getTeam().getSV().end();index++, it++)
        {


            if(need_modify)
            ui->comboBox->addItem(QString::fromStdString(it->getName()));

            ui->Souvenir_items->setRowCount(index);



        }

        ui->Souvenir_items->setRowCount(index);

        // Reset the iterator and index
        it = stadiums.at(0).getTeam().getSV().begin();
        index = 0;



        // Go through the souvenir list again
        for(; it!= stadiums.at(0).getTeam().getSV().end();index++, it++)
        {

            // Widget Items to list all the items in the table
            QTableWidgetItem* item_name = new QTableWidgetItem;

            item_name->setText(QString::fromStdString(it->getName()));

            QTableWidgetItem* price = new QTableWidgetItem;

            price->setText(  "$ " + QString::number
                             ((*it).getPrice(),'g',5));


            ui->Souvenir_items->setItem(index,0,item_name);
            ui->Souvenir_items->setItem(index,1,price);
        }
    }



    // Adding souvenir inputs
    if(type == 3)
    {
        // Only allow add feature of the adding
        ui->pushButton->setVisible(false);
        ui->delete_souvenir->setVisible(false);

        ui->comboBox->setVisible(true);
        ui->label->setVisible(true);

        this->setWindowTitle("Souvenirs");

        index = 0;

        // Add a empty string first
        ui->comboBox->addItem("");

        // Initialize the combobox and the row for the list
        for(; it!= stadiums.at(0).getTeam().getSV().end();index++, it++)
        {

            if(need_modify)
            ui->comboBox->addItem(QString::fromStdString(it->getName()));

            ui->Souvenir_items->setRowCount(index);


        }

        ui->Souvenir_items->setRowCount(index);

        // Reset the iterator and index
        it = stadiums.at(0).getTeam().getSV().begin();
        index = 0;



        // Go through the souvenir list again
        for(; it!= stadiums.at(0).getTeam().getSV().end();index++, it++)
        {

            // Widget Items to list all the items in the table
            QTableWidgetItem* item_name = new QTableWidgetItem;

            item_name->setText(QString::fromStdString(it->getName()));

            QTableWidgetItem* price = new QTableWidgetItem;

            price->setText(  "$ " + QString::number
                             ((*it).getPrice(),'g',5));


            ui->Souvenir_items->setItem(index,0,item_name);
            ui->Souvenir_items->setItem(index,1,price);
        }


    }





    // Close the window nicely
    if(this->close())
    {
        close();
    }


}


Souvenir_Modifications::~Souvenir_Modifications()
{

    delete ui;

}

void Souvenir_Modifications::on_pushButton_clicked()
{

    // Modifying stadium
    if(_modify_type == 1)
    {
        if(ui->comboBox->currentText() == "")
        {
            QMessageBox::information(this,"Error","None Selected.");
            return;
        }

        // Get the stadium name for modification
        string name = ui->comboBox->currentText().toStdString();

        size_t target_index = 0;
        bool found = false;

        // Check in the stadium for the target
        if(_list_stadium != nullptr)
        {
            // Go through the list
            for(size_t j =0; j < _list_stadium->size();j++)
            {
                // Index to be found
                if(_list_stadium->at(j).getName() == name)
                {
                    target_index = j;
                    found = true;
                    break;
                }
            }
        }

        // Error Checking
        if(!found)
        {
            QMessageBox::information(this,"Error","List not found");
            close();  // Close the window
        }

        // Ready to get inputs
        Yes_No_Window edit_stadium(this,"Editing Stadiums",
                                   0,1,0);
        edit_stadium.exec();


        //Ready to modify
        if(edit_stadium.get_stadium() != "")
        {
            // Change the Stadium name
            _list_stadium->at(target_index).
                    setName(edit_stadium.get_stadium());

            // Also Change the file formating
            qDebug() << QString::fromStdString
                        (_list_stadium->at(target_index).getName());


        }


        if(edit_stadium.get_team() != "")
        {
            // Change the team name
            _list_stadium->at(target_index).getTeam().
                    setName(edit_stadium.get_team());

            // Change the file formating
        }

        if(edit_stadium.get_phone() != "")
        {
            // Change the Phone-number
            _list_stadium->at(target_index).
                    setPhoneNum(edit_stadium.get_phone());

            // Change the file formating
        }

        if(edit_stadium.get_capacity() != "")
        {
            // Change the Phone-number
            _list_stadium->at(target_index).
                    setSeatCapacity(stoi(edit_stadium.get_capacity()));

            // Change the file formating
        }


    }

    // Modifying Souvenir
    else if (_modify_type == 2)
    {
        if(ui->comboBox->currentText() == "")
        {
            QMessageBox::information(this,"Error","None Selected.");
            return;
        }

        // Get the stadium name for modification
        string name = ui->comboBox->currentText().toStdString();



        // Ready to get inputs
        Yes_No_Window edit_stadium(this,"Editing Souvenirs",
                                   0,0,1);
        edit_stadium.exec();


        //Ready to modify
        if(edit_stadium.get_item() != "")
        {
            // Check in the stadium for the target
            if(_list_stadium != nullptr)
            {
                // Go through the list
                for(size_t l =0; l < _list_stadium->size();l++)
                {

                    set<Souvenir>::iterator it;

                    string found_name = "";
                    double price = 0;

                    // Set the iterator to the target
                    it = _list_stadium->at(l)
                            .getTeam().getSV().begin();

                    Souvenir hello;

                    for(;it !=_list_stadium->at(l)
                        .getTeam().getSV().end(); it++ )
                    {
                        // Searching in the list
                        if(it->getName()== name)
                        {
                            hello.setName(it->getName());
                            price = it->getPrice();

                        }
                    }

                    // Delete the old info
                    _list_stadium->at(l).getTeam().getSV().erase
                                        (hello);

                    // Add the new info
                    if(edit_stadium.get_price() != "")
                        _list_stadium->at(l).getTeam().getSV().
                                insert(Souvenir(edit_stadium.get_item(),
                                stod(edit_stadium.get_price())));

                    else
                        _list_stadium->at(l).getTeam().getSV().
                                insert(Souvenir(edit_stadium.get_item(),
                                price));

                }

            }
        }


        else if(edit_stadium.get_price() != "")
        {
            // Check in the stadium for the target
            if(_list_stadium != nullptr)
            {
                // Go through the list
                for(size_t l =0; l < _list_stadium->size();l++)
                {

                    set<Souvenir>::iterator it;

                    string found_name = "";

                    // Set the iterator to the target
                    it = _list_stadium->at(l)
                            .getTeam().getSV().begin();

                    Souvenir hello;

                    // Go over the souvenir list
                    for(;it !=_list_stadium->at(l)
                        .getTeam().getSV().end(); it++ )
                    {
                        // Search in the list
                        if(it->getName()== name)
                        {
                            hello.setName(it->getName());
                        }
                    }

                    // Delete the old info
                    _list_stadium->at(l).getTeam().getSV().erase
                                        (hello);

                    // Add the new info
                    _list_stadium->at(l).getTeam().getSV().
                            insert(Souvenir(name,
                                            stod(edit_stadium.get_price())));


                }
            }
        }
    }

    // Adding stadiums
    else if (_modify_type ==4)
    {
        // Ready to get inputs
        Yes_No_Window edit_stadium(this,"Adding One Stadium",
                                   0,1,0);
        edit_stadium.exec();


        //Ready to modify
        if(edit_stadium.get_stadium() != "")
        {
            Stadium s1;

            s1.setName(edit_stadium.get_stadium());

            Date d1(1,3,2020);

            // Construct new team
            if(edit_stadium.get_team() != "")
            {
                s1.setTeam(Team(edit_stadium.get_team()));
            }

            else
            {
                s1.setTeam(Team("N/A"));
            }

            //Construct New Number
            if(edit_stadium.get_phone() != "")
            {
                s1.setPhoneNum(edit_stadium.get_phone());
            }
            else
                s1.setPhoneNum("000");


            // Construct New Capacity
            if(edit_stadium.get_capacity() != "")
                s1.setSeatCapacity(stoi
                                  (edit_stadium.get_capacity()));
            else
                s1.setSeatCapacity(0);

            s1.setOpenedDate(d1);
            _list_stadium->push_back(s1); // Push the new added

            current_added = s1;  // Keep one Copy
            _is_added = true;

        }

    }

    QMessageBox::information(this,"Success","Changes Saved");
    close();  // Close the window, After modifying everything

}

void Souvenir_Modifications::on_add_souvenir_clicked()
{
    // Modifying souvenir
    if(_modify_type == 2)
    {
        // Ready to get inputs
        Yes_No_Window edit_stadium(this,"Editing Souvenirs",
                                   0,0,1);
        edit_stadium.exec();

        // Empty input handling
        if(edit_stadium.get_item() == "")
        {
            QMessageBox::information(this,"Error","Invalid input");
            return;
        }

        else
        {
            // Check in the stadium for the target
            if(_list_stadium != nullptr)
            {
                // Go through the list
                for(size_t l =0; l < _list_stadium->size();l++)
                {

                    // Add the new info with proper price
                    if(edit_stadium.get_price() != "")
                        _list_stadium->at(l).getTeam().getSV().
                                insert(Souvenir(edit_stadium.get_item(),
                                stod(edit_stadium.get_price())));

                    else
                        _list_stadium->at(l).getTeam().getSV().
                                insert(Souvenir(edit_stadium.get_item(),
                                0));

                }

            }

        }
    }

    // Adding the item
    if(_modify_type == 3)
    {

        if(ui->comboBox->currentText() == "")
        {
            QMessageBox::information(this,"Error","No item Selected");
            return;
        }

        _item_name = ui->comboBox->currentText().toStdString();

        set<Souvenir>::iterator it;

        string found_name = "";

        // Set the iterator to the target
        it = _list_stadium->at(0)
                .getTeam().getSV().find(_item_name);

        //Obtain the item price
        _item_price = to_string(it->getPrice());





    }

    QMessageBox::information(this,"Success","Item added");
    close();  // Close the window
}

void Souvenir_Modifications::on_delete_souvenir_clicked()
{
    // Modifying the souvenir
    if(_modify_type == 2)
    {
        if(ui->comboBox->currentText() == "")
        {
            QMessageBox::information(this,"Error","None Selected.");
            return;
        }

        // Get the stadium name for modification
        string name = ui->comboBox->currentText().toStdString();



        //Ready to modify
        if(name != "")
        {
            // Check in the stadium for the target
            if(_list_stadium != nullptr)
            {
                // Go through the list
                for(size_t l =0; l < _list_stadium->size();l++)
                {

                    Souvenir hello(name,0);

                    // Delete the old info
                    _list_stadium->at(l).getTeam().getSV().erase
                                        (hello);

                }

            }
        }
    }

    QMessageBox::information(this,"Success","Item deleted");
    close();

}
