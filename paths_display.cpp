#include "paths_display.h"
#include "ui_paths_display.h"
#include "display_stadium_info.h"

#include <QDebug>


/*****************************************
 * Locations selection windo
 * ------------------------------
 * Pre-condition: ready to recieve inputs from
 * the users by the stadium push buttons
 * -------------------------------
 * Post-condtion: all the location and
 * stadium objects will
 * be added into the input sections for later
 * implementations
 ****************************************/
paths_display::paths_display(QWidget *parent,
                             vector<Stadium>& list,
                             set<Souvenir> & chart) :
    QDialog(parent),
    ui(new Ui::paths_display)
{
    ui->setupUi(this);

    _infos = list;     // *not safe for dynamic space

    _list_ptr =& list;

    _chart_ptr =& chart;

    ui->textBrowser->setText("Please select the Starting \n"
                             "Location and the stadiums \n"
                             "you want to travel for your trip by\n"
                             "clikcing the dots next to the stadiums\n\n");


    ui->Return_main->setText("Confirm Your Trip");

    QRect rect(5,5,20,20);
    QRegion regi(rect,QRegion::Ellipse);

    QRegion jh(rect);


    // West-Region setting up icon
    ui->Pectco_Park->setMask(regi);
    ui->AT_T_Park->setMask(regi);
    ui->Angel_Stadium->setMask(regi);
    ui->Safeco_Field->setMask(regi);
    ui->Dodger_stadium->setMask(regi);
    ui->O_Co_Coliseum->setMask(regi);


    // Middle-Region setting up icon
    ui->Coers_Field->setMask(regi);
    ui->Chase_Field->setMask(regi);
    ui->Rangers_Ballpark->setMask(regi);
    ui->Minute_Maid_Park->setMask(regi);


    // East-Region setting up icon
    ui->Kauffman_Stadium->setMask(regi);
    ui->Buschm_Stadium->setMask(regi);
    ui->Target_Field->setMask(regi);
    ui->Miller_Park->setMask(regi);
    ui->Wrigley_Field->setMask(regi);
    ui->US_Cellular->setMask(regi);
    ui->Great_American_Ballpark->setMask(regi);
    ui->Comerica_Park->setMask(regi);
    ui->Progressive_Field->setMask(regi);
    ui->PNC_Park->setMask(regi);

    ui->Rogers_Field->setMask(regi);
    ui->Fenway_Park->setMask(regi);
    ui->Yankee_Stadium->setMask(regi);
    ui->Camden_Yards->setMask(regi);
    ui->Tropicana_Field->setMask(regi);

    ui->Citi_Field->setMask(regi);
    ui->Nationals_Park->setMask(regi);
    ui->Citizens_Bank_Park->setMask(regi);
    ui->Turner_Field->setMask(regi);
    ui->Marlins_Park->setMask(regi);


    this->setWindowTitle("MAPS");





}


/***************************************
 * Shortest Path Drawing window
 *-------------------------------------
 * Pre-condition: Receive a vector of location
 * info for the path displaying, the size for
 * the number of paths, total cost to travel
 * all the paths, a vector of each cost stored
 * ------------------------------------
 * Post-condition: The desired paths will be
 * drawn with Qpainters and Qpoints in a
 * Q dialog window, the cost info for the path
 * will be display in the text browser.

*****************************************/
paths_display::paths_display(QWidget *parent,
                             vector<Location_info<Stadium> > *paths,
                             int paths_size,
                             vector<string> & locations,
                             int total_costs,
                             vector<int> & _paths,
                             vector<Stadium>& list,
                             set<Souvenir> & chart)
               :QDialog (parent),ui(new Ui::paths_display),
               _size (paths_size)
{

    ui->setupUi(this);
    this->setWindowTitle("Paths");  // Title

    input_completed = true;  // The input section is completed

    _infos = list;     // *not safe for dynamic space

    _list_ptr  =& list;
    _chart_ptr =& chart;

    // Receive the info from the parameters
    _shortest_paths = paths;
    _locations = locations;

    // Copy over the path cost elements
    path_cost = _paths;

    // Mask for the locations
    QRect rect(5,5,20,20);
    QRegion regi(rect,QRegion::Ellipse);

    QRegion jh(rect);


    // West-Region setting up icon
    ui->Pectco_Park->setMask(regi);
    ui->AT_T_Park->setMask(regi);
    ui->Angel_Stadium->setMask(regi);
    ui->Safeco_Field->setMask(regi);
    ui->Dodger_stadium->setMask(regi);
    ui->O_Co_Coliseum->setMask(regi);


    // Middle-Region setting up icon
    ui->Coers_Field->setMask(regi);
    ui->Chase_Field->setMask(regi);
    ui->Rangers_Ballpark->setMask(regi);
    ui->Minute_Maid_Park->setMask(regi);


    // East-Region setting up icon
    ui->Kauffman_Stadium->setMask(regi);
    ui->Buschm_Stadium->setMask(regi);
    ui->Target_Field->setMask(regi);
    ui->Miller_Park->setMask(regi);
    ui->Wrigley_Field->setMask(regi);
    ui->US_Cellular->setMask(regi);
    ui->Great_American_Ballpark->setMask(regi);
    ui->Comerica_Park->setMask(regi);
    ui->Progressive_Field->setMask(regi);
    ui->PNC_Park->setMask(regi);

    ui->Rogers_Field->setMask(regi);
    ui->Fenway_Park->setMask(regi);
    ui->Yankee_Stadium->setMask(regi);
    ui->Camden_Yards->setMask(regi);
    ui->Tropicana_Field->setMask(regi);

    ui->Citi_Field->setMask(regi);
    ui->Nationals_Park->setMask(regi);
    ui->Citizens_Bank_Park->setMask(regi);
    ui->Turner_Field->setMask(regi);
    ui->Marlins_Park->setMask(regi);



    // Ready to display all the traveling info to the textbox
    ui->textBrowser->append("Traveling Distance Costs Total: "
                           + QString::fromStdString
                           (to_string(total_costs))
                           + "\n");

   for (size_t n = 0; n < _shortest_paths->size(); n++)
   {
       // Display the detailed path info to the user
       ui->textBrowser->append(QString::fromStdString
                               (to_string(n+1)) + ". " +
                               QString:: fromStdString(
                               _shortest_paths->at(n)
                              .get_start().getName()) + "  " +
                               QString:: fromStdString(
                               _shortest_paths->at(n)
                              .get_start().getTeam().getLeague()) + "   "+
                               QString::fromStdString
                               (to_string(path_cost.at(n))) + "\n");
   }

   // Scroll up the browser to the top
   QTextCursor cursor_ = ui->textBrowser->textCursor();
   cursor_.setPosition(0);
   ui->textBrowser->setTextCursor(cursor_);

}

paths_display::~paths_display()
{
    path_painted = false;


    delete ui;

}

/*****************************************
 * Path Paint
 * ------------------------------
 * Pre-condition: The list container
 * should be initialized
 * -------------------------------
 * Post-condtion: Ready to display the path
 * for the stadiums
 *
 ****************************************/
void paths_display::paintEvent(QPaintEvent *event)
{

    if(_shortest_paths == nullptr)
        return;

    else
    {
        vector<QPoint> path_points;
        QPoint coordinate;

        qDebug() << "size info: " << _shortest_paths->size() << endl;
        // Go to that particular spot to get the solution at that endpoint
        for(size_t i=0; i < _shortest_paths->size(); i++)
        {

            qDebug() << "Name: " << QString::fromStdString
                     (_shortest_paths->at(i).get_start().getName())
                     << endl;

            // Set up the answer path's point location(x,y)
            if(_shortest_paths->at(i).get_start().getName()
                    == "Safeco Field")
            {
                coordinate.setX(ui->Safeco_Field->x()+15);
                coordinate.setY(ui->Safeco_Field->y()+15);

            }

            else if(_shortest_paths->at(i).get_start().getName()
                    == "AT&T Park")
            {
                coordinate.setX(ui->AT_T_Park->x()+15);
                coordinate.setY(ui->AT_T_Park->y()+15);
            }

            else if(_shortest_paths->at(i).get_start().getName()
                    == "Dodger Stadium")
            {
                coordinate.setX(ui->Dodger_stadium->x()+15);
                coordinate.setY(ui->Dodger_stadium->y()+15);
            }

            else if(_shortest_paths->at(i).get_start().getName()
                    == "PETCO Park")
            {
                coordinate.setX(ui->Pectco_Park->x()+15);
                coordinate.setY(ui->Pectco_Park->y()+15);
            }

            else if(_shortest_paths->at(i).get_start().getName()
                    == "Chase Field")
            {
                coordinate.setX(ui->Chase_Field->x()+15);
                coordinate.setY(ui->Chase_Field->y()+15);
            }

            else if(_shortest_paths->at(i).get_start().getName()
                    == "Coors Field")
            {
                coordinate.setX(ui->Coers_Field->x()+15);
                coordinate.setY(ui->Coers_Field->y()+15);
            }

            else if(_shortest_paths->at(i).get_start().getName()
                    == "Kauffman Stadium")
            {
                coordinate.setX(ui->Kauffman_Stadium->x()+15);
                coordinate.setY(ui->Kauffman_Stadium->y()+15);

            }
            else if(_shortest_paths->at(i).get_start().getName()
                    == "Busch Stadium")
            {
                coordinate.setX(ui->Buschm_Stadium->x()+15);
                coordinate.setY(ui->Buschm_Stadium->y()+15);
            }
            else if(_shortest_paths->at(i).get_start().getName()
                    == "Great American Ballpark")
            {
                coordinate.setX(ui->Great_American_Ballpark->x()+15);
                coordinate.setY(ui->Great_American_Ballpark->y()+15);
            }
            else if(_shortest_paths->at(i).get_start().getName()
                    == "Progressive Field")
            {
                coordinate.setX(ui->Progressive_Field->x()+15);
                coordinate.setY(ui->Progressive_Field->y()+15);
            }
            else if(_shortest_paths->at(i).get_start().getName()
                    == "Comerica Park")
            {
                coordinate.setX(ui->Comerica_Park->x()+15);
                coordinate.setY(ui->Comerica_Park->y()+15);
            }
            else if(_shortest_paths->at(i).get_start().getName()
                    == "Rogers Center")
            {
                coordinate.setX(ui->Rogers_Field->x()+15);
                coordinate.setY(ui->Rogers_Field->y()+15);
            }
            else if(_shortest_paths->at(i).get_start().getName()
                    == "PNC Park")
            {
                coordinate.setX(ui->PNC_Park->x()+15);
                coordinate.setY(ui->PNC_Park->y()+15);
            }
            else if(_shortest_paths->at(i).get_start().getName()
                    == "Citizens Bank Park")
            {
                coordinate.setX(ui->Citizens_Bank_Park->x()+15);
                coordinate.setY(ui->Citizens_Bank_Park->y()+15);
            }
            else if(_shortest_paths->at(i).get_start().getName()
                    == "Yankee Stadium")
            {
                coordinate.setX(ui->Yankee_Stadium->x()+15);
                coordinate.setY(ui->Yankee_Stadium->y()+15);
            }
            else if(_shortest_paths->at(i).get_start().getName()
                    == "Fenway Park")
            {
                coordinate.setX(ui->Fenway_Park->x()+15);
                coordinate.setY(ui->Fenway_Park->y()+15);
            }
            else if(_shortest_paths->at(i).get_start().getName()
                    == "Marlins Park")
            {
                coordinate.setX(ui->Marlins_Park->x()+15);
                coordinate.setY(ui->Marlins_Park->y()+15);
            }
            else if(_shortest_paths->at(i).get_start().getName()
                    == "Tropicana Field")
            {
                coordinate.setX(ui->Tropicana_Field->x()+15);
                coordinate.setY(ui->Tropicana_Field->y()+15);
            }
            else if(_shortest_paths->at(i).get_start().getName()
                    == "Minute Maid Park")
            {
                coordinate.setX(ui->Minute_Maid_Park->x()+15);
                coordinate.setY(ui->Minute_Maid_Park->y()+15);
            }
            else if(_shortest_paths->at(i).get_start().getName()
                    == "Rangers Ballpark")
            {
                coordinate.setX(ui->Rangers_Ballpark->x()+15);
                coordinate.setY(ui->Rangers_Ballpark->y()+15);
            }
            else if(_shortest_paths->at(i).get_start().getName()
                    == "Turner Field")
            {
                coordinate.setX(ui->Turner_Field->x()+15);
                coordinate.setY(ui->Turner_Field->y()+15);
            }
            else if(_shortest_paths->at(i).get_start().getName()
                    == "Miller Park")
            {
                coordinate.setX(ui->Miller_Park->x()+15);
                coordinate.setY(ui->Miller_Park->y()+15);
            }
            else if(_shortest_paths->at(i).get_start().getName()
                    == "Target Field")
            {
                coordinate.setX(ui->Target_Field->x()+15);
                coordinate.setY(ui->Target_Field->y()+15);
            }
            else if(_shortest_paths->at(i).get_start().getName()
                    == "US Cellular Field")
            {
                coordinate.setX(ui->US_Cellular->x()+15);
                coordinate.setY(ui->US_Cellular->y()+15);
            }
            else if(_shortest_paths->at(i).get_start().getName()
                    == "Nationals Park")
            {
                coordinate.setX(ui->Nationals_Park->x()+15);
                coordinate.setY(ui->Nationals_Park->y());

            }


            path_points.push_back(coordinate);  // Push the coordinate into vector

            qDebug()  << " x :  " << path_points[path_points.size()-1].x()
                      << "  y:  "  << path_points[path_points.size()-1].y() << endl;

        } // End of for loop for adding coordinates


        qDebug() << QString::fromStdString(_locations[22]) << endl;
        // Start drawing the paths by using points

        QPainter drawing(this);
        for(size_t j = 0; j < _shortest_paths->size()-1; j++)
        {

            //** Debugging purpose for the coordinates
            qDebug() << "Path1: " << path_points[j] << " "
                                  << path_points[j+1] << endl;

            // Formating the pen style
            QPen _path(Qt::darkGreen);
            _path.setWidth(7);
            drawing.setPen(_path);

            // Draw the line with correct coordinated found
            drawing.drawLine(path_points[j],path_points[j+1]);

        }

        drawing.end();

    }



    path_painted = true;






}
/*****************************************
 * Return Main
 * ------------------------------
 * Pre-condition: The list container
 * should be initialized
 * -------------------------------
 * Post-condtion: Ready to Return to main
 *
 ****************************************/
void paths_display::on_Return_main_clicked()
{
    qDebug() << QString::fromStdString("set size: ")
             << user_inputs.size() << endl;


    close();
}

/*****************************************
 * Path Choosing or displaying info
 * ------------------------------
 * Pre-condition: The list container
 * should be initialized
 * -------------------------------
 * Post-condtion: Ready to display the path
 * for the stadiums
 *
 ****************************************/
void paths_display::on_Safeco_Field_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Safeco Field";

        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

            //user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }




    }


    // If the input section is completed
    else
    {

        Stadium_info show_this(this,_infos,10,is_modifier);

        show_this.exec(); // Run the window


    }
}

void paths_display::on_AT_T_Park_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "AT&T Park";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

           // user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }

    // Display stadium info
    else
    {
        Stadium_info show_this(this,_infos,15,is_modifier);

        show_this.exec(); // Run the window
    }
}

void paths_display::on_O_Co_Coliseum_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "AT&T Park";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString("O.co Coliseum"));

        //    user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString("O.co Coliseum"));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString("O.co Coliseum"));
            }

        }
    }

    else
    {
        Stadium_info show_this(this,_infos,6,is_modifier);

        show_this.exec(); // Run the window
    }


}

void paths_display::on_Dodger_stadium_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Dodger Stadium";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

        //    user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }

    else
    {
        Stadium_info show_this(this,*_list_ptr,21,is_modifier);

        show_this.exec(); // Run the window
    }



}

void paths_display::on_Angel_Stadium_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Dodger Stadium";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString("Angel Stadium"));

          //  user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString("Angel Stadium"));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString("Angel Stadium"));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,0,is_modifier);

        show_this.exec(); // Run the window
    }

}

void paths_display::on_Pectco_Park_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "PETCO Park";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

          //  user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,26,is_modifier);

        show_this.exec(); // Run the window
    }

}




void paths_display::on_Chase_Field_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Chase Field";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

          //  user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,17,is_modifier);

        show_this.exec(); // Run the window
    }

}


void paths_display::on_Coers_Field_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Coors Field";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

          //  user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,20,is_modifier);

        show_this.exec(); // Run the window
    }

}



void paths_display::on_Target_Field_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Target Field";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

          //  user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,11,is_modifier);

        show_this.exec(); // Run the window
    }


}



void paths_display::on_Miller_Park_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Miller Park";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

         //   user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,24,is_modifier);

        show_this.exec(); // Run the window
    }

}

void paths_display::on_Wrigley_Field_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "US Cellular Field";

        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString("Wrigley Field"));

         //   user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString("Wrigley Field"));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString("Wrigley Field"));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,29,is_modifier);

        show_this.exec(); // Run the window
    }

}

void paths_display::on_US_Cellular_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "US Cellular Field";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

         //   user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,13,is_modifier);

        show_this.exec(); // Run the window
    }
}

void paths_display::on_Kauffman_Stadium_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Kauffman Stadium";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

         //   user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,4,is_modifier);

        show_this.exec(); // Run the window
    }
}

void paths_display::on_Buschm_Stadium_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Busch Stadium";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

          //  user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,16,is_modifier);

        show_this.exec(); // Run the window
    }
}



void paths_display::on_Great_American_Ballpark_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Great American Ballpark";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

         //   user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,22,is_modifier);

        show_this.exec(); // Run the window
    }


}


void paths_display::on_Progressive_Field_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Progressive Field";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

         //   user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,8,is_modifier);

        show_this.exec(); // Run the window
    }
}

void paths_display::on_Comerica_Park_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Comerica Park";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

         //   user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,1,is_modifier);

        show_this.exec(); // Run the window
    }
}


void paths_display::on_PNC_Park_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "PNC Park";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

        //    user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,27,is_modifier);

        show_this.exec(); // Run the window
    }
}



void paths_display::on_Camden_Yards_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Nationals Park";

        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString("Camden Yards"));

        //    user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString("Camden Yards"));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString("Camden Yards"));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,7,is_modifier);

        show_this.exec(); // Run the window
    }
}



void paths_display::on_Nationals_Park_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Nationals Park";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

        //    user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,25,is_modifier);

        show_this.exec(); // Run the window
    }
}



void paths_display::on_Citizens_Bank_Park_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Citizens Bank Park";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

        //    user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,19,is_modifier);

        show_this.exec(); // Run the window
    }
}

void paths_display::on_Rogers_Field_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {

        start_point = "Rogers Center";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

       //     user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,9,is_modifier);

        show_this.exec(); // Run the window
    }

}


void paths_display::on_Yankee_Stadium_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Yankee Stadium";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

         //   user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,14,is_modifier);

        show_this.exec(); // Run the window
    }


}



void paths_display::on_Citi_Field_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Yankee Stadium";

        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString("Citi Field"));

        //   user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString("Citi Field"));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString("Citi Field"));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,18,is_modifier);

        show_this.exec(); // Run the window
    }
}



void paths_display::on_Fenway_Park_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Fenway Park";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

         //   user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,2,is_modifier);

        show_this.exec(); // Run the window
    }
}



void paths_display::on_Turner_Field_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Turner Field";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

        //    user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,28,is_modifier);

        show_this.exec(); // Run the window
    }
}



void paths_display::on_Tropicana_Field_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Tropicana Field";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

         //   user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,12,is_modifier);

        show_this.exec(); // Run the window
    }
}

void paths_display::on_Marlins_Park_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Marlins Park";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

          //  user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,23,is_modifier);

        show_this.exec(); // Run the window
    }
}

void paths_display::on_Minute_Maid_Park_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Minute Maid Park";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

          //  user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,5,is_modifier);

        show_this.exec(); // Run the window
    }
}

void paths_display::on_Rangers_Ballpark_clicked()
{
    // Set up the starting input or ending
    if(!input_completed)
    {
        start_point = "Rangers Ballpark";
        // If the start location is not completed
        if(!start_picked)
        {
            user_start_point = start_point;
            ui->text_start_point->setText(QString::fromStdString(start_point));

          //  user_inputs.insert(start_point);  // Add the desired stadiums
                                              // to the set

            // Display to the screen
            ui->textBrowser->append(QString::fromStdString(start_point));
            start_picked = true;
        }

        // Else if it's not starting location, verify the info
        else
        {
            set<string>::iterator it = user_inputs.begin();
            bool found = false;

            // Go through the set to see if repeat
            for(;it!=user_inputs.end();it++)
            {
                if(*it == start_point)   // If the element already existed
                {
                    found = true;      // Mark the boolean expression
                    break;
                }
            }

            if(!found)     // If not found, add and display it
            {
                user_inputs.insert(start_point);

                // Displays
                 ui->textBrowser->append(QString::fromStdString(start_point));
            }

        }
    }
    else
    {
        Stadium_info show_this(this,_infos,3,is_modifier);

        show_this.exec(); // Run the window
    }
}

void paths_display::on_add_delete_chart_clicked()
{
    if(_infos.size() > 0)
    {


        Souvenir_Modifications get_item_1(this,*_list_ptr,1,3);
        get_item_1.exec();  // Display the window

        // If it's valid inputs
        if(get_item_1.get_item() != "" &&
           get_item_1.get_price() != ""     )
        {
            // Add the souvenir to list if not nullptr

                _chart_ptr->insert(Souvenir(get_item_1.get_item(),
                                            stod(get_item_1.get_price())));


                set<Souvenir>:: iterator it;

                it=_chart_ptr->begin();

                qDebug() << QString::fromStdString(it->getName() + " "
                                                   )
                         << QString::fromStdString(get_item_1.get_price()) <<endl;


        }
    }

    else
    {
        QMessageBox::information(this,"Error","No files Found");
        return;
    }

}
