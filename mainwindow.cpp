#include "mainwindow.h"
#include "paths_display.h"
#include "ui_mainwindow.h"
#include "yes_no_window.h"
#include "insertwindow.h"
#include "ui_subwindow.h"
#include "display_stadium_info.h"
#include "password_section.h"
#include <cstdlib>
#include <ctime>


using namespace std;


/*****************************************
 * Read map file
 * ------------------------------
 * Pre-condition: read a file via the textstream
 * object with all the graph list container for 
 * the baseball leagues
 * -------------------------------
 * Post-condtion: all the location and 
 * stadium objects will
 * be added into the graph list container
 ****************************************/
void read_map_file(QTextStream& File,
                   Graph_List<Location_info<Stadium>,Stadium>
                   & All_league,
                   Graph_List<Location_info<Stadium>,Stadium>
                   & AL_league,
                   Graph_List<Location_info<Stadium>,Stadium>
                   & NL_league,
                   vector<string> & locations,
                   set<string> & AL_stadiums,
                   set<string> & NL_stadiums);
void read_map_file(QTextStream& File,
                   Graph_List<Location_info<Stadium>,Stadium>
                   & All_league,
                   Graph_List<Location_info<Stadium>,Stadium>
                   & AL_league,
                   Graph_List<Location_info<Stadium>,Stadium>
                   & NL_league,
                   vector<string> & locations,
                   set<string> & AL_stadiums,
                   set<string> & NL_stadiums)
{
    string Stadium_name;
    string League_type = "";
    QString input;

    Stadium add_stadium;
    Location_info<Stadium> add_location;


    // Reading the file until the end
   for(int index = 0;!File.atEnd();index++)
    {
        input = File.readLine();
        input = input.trimmed();  // Trim the end line at the end

        add_stadium.setName(input.toStdString());  // Line 1

        locations.push_back(input.toStdString()); // Store Names

        qDebug()  << "Line1: " << input << endl;  // Debug


        input = File.readLine();  // Line 2
        input = input.trimmed();  // Trim the end line at the end

        qDebug()  << "Line2: " << input << endl;  // Debug

        // Determine the type of the league from the file
        if(input.toStdString() == "AL")
        {
            add_stadium.setLeague("AL");
            add_location.set_start(add_stadium);


            Location_info<Stadium> l1(add_stadium,0);

            // Add to the graph list and sets
            AL_league.add_vertex(index,l1);
            AL_stadiums.insert(add_stadium.getName());

            // Double check for stadiums that are considered
            // as the same location
            if(add_stadium.getName() == "US Cellular Field")
                NL_stadiums.insert(add_stadium.getName());

            if(add_stadium.getName() == "Yankee Stadium")
                NL_stadiums.insert(add_stadium.getName());

            League_type = "AL";

        }

        else if(input.toStdString() == "NL")
        {
            add_stadium.setLeague("NL");
            add_location.set_start(add_stadium);

            Location_info<Stadium> l2(add_stadium,0);

            // Add to the graph list and sets
            NL_league.add_vertex(index,l2);
            NL_stadiums.insert(add_stadium.getName());

            // Double check for stadiums that are considered
            // as the same location
            if(add_stadium.getName() == "Dodger Stadium")
                AL_stadiums.insert(add_stadium.getName());

            if(add_stadium.getName() == "AT&T Park")
                AL_stadiums.insert(add_stadium.getName());

            if(add_stadium.getName() == "Nationals Park")
                AL_stadiums.insert(add_stadium.getName());

            League_type = "NL";
        }

        int size = 0;

        Location_info<Stadium> l3(add_stadium,0);

        // Add the starting vertex for the league
        All_league.add_vertex(index,l3);

        input = File.readLine();
        input = input.trimmed();
        // Trim the end line at the end

        qDebug()  << "Line3: " << input << endl;  // Debug

        for(;input.toStdString() != "#";size++)
        {

            add_stadium.setName(input.toStdString());

            input = File.readLine();  // Get Cost
            input = input.trimmed();
            // Trim the end line at the end

            add_location.set_start(add_stadium);

            qDebug()  << "Line4: " << input.toInt() << endl;  // Debug

            add_location.set_cost(input.toInt()); // Set the cost


            Location_info<Stadium> l4(add_stadium,input.toInt());

            if(League_type == "AL")
                AL_league.add_vertex(index,l4);

            else if(League_type == "NL")
                NL_league.add_vertex(index,l4);

            All_league.add_vertex(index,l4);
            qDebug()  << "Index: " << index << endl;  // Debug

            // Get the neighbor's name
            input = File.readLine();
            input = input.trimmed();
            // Trim the end line at the end

            qDebug()  << "Line3: " << input << endl;  // Debug

        }
    }

    qDebug() << All_league.get_size() << " size\n";

}


/*****************************************
 * Read Stadium file
 * ------------------------------
 * Pre-condition: read a file via the textstream
 * object with all the stadium container for 
 * the baseball leagues
 * -------------------------------
 * Post-condtion: all the location and 
 * stadium objects will
 * be added into the container
 ****************************************/
void read_stadium_file(QTextStream& file,
                       vector<Stadium>& stadiums);
void read_stadium_file(QTextStream& file,
                       vector<Stadium>& stadiums)
{
    QString input;
    QString address;
    QString city;
    QString state;
    string zip_code;
    
    string date;
    
    
    
    
    int count = 0;   // For later access stadiums

    string type = "AL";

    // While not reach the end of the file
    while (!file.atEnd())
    {
        int month = 0;
        int day = 0;
        int year = 0;
        
        qDebug() << "Stadium index:  " << count << endl;
        
        
        // First Line: Stadium line
        input = file.readLine();
        input = input.trimmed();
        
        Stadium s1;   // construct a stadium
        s1.setName(input.toStdString());  // Set the name

        qDebug() << QString::fromStdString(s1.getName()) << endl;
        
        Team t1;
        
        // Second Line: Team name        
        input = file.readLine();
        input = input.trimmed();
        
        t1.setName(input.toStdString());
        
        // Thrid - Five Line : Address
        input = file.readLine();
        input = input.trimmed();
        
        address = input;
        
        input = file.readLine();
        input = input.trimmed();
        
        city = input;
        
        input = file.readLine();
        input = input.trimmed();
        
        state = input;
        
        // Six Line: Zip Code
        input = file.readLine();
        input = input.trimmed();
        
        zip_code = input.toStdString();
        
        
        s1.setAddress(address.toStdString(),
                      city.toStdString(),
                      state.toStdString(),
                      zip_code);
        
        
        // Seven Line: Phone number
        input = file.readLine();
        input = input.trimmed();
        
        
        s1.setPhoneNum(input.toStdString());
        
        
        // Eight line: date open
        input = file.readLine();
        input = input.trimmed();
        
        date = input.toStdString();  // Get the date string
        
        string temp = "";
        
        
        // Go through the date string
        for(size_t i = 0; i < date.length();i++)
        {
            
            if(date[i] != '/'
              &&  i != date.length()-1)   // Add the digit
            {
                temp += date[i];
            }  
            
            // Add the Month
            else if(date[i] == '/' &&
                    i <=2)
            {
                month = stoi(temp);
                temp = "";
            }    
            
            // Add the Day
            else if(date[i] == '/' &&
                    i > 2)
            {
                day = stoi(temp);
                temp = "";
            }  
            
            // Add the Year
            else if(i == date.length()-1)
            {
                temp += date[i];
                year = stoi(temp);
                temp = "";
                
            }    
        }   


        qDebug() << QString::fromStdString(to_string(month))  << " "
                 << QString::fromStdString(to_string(day))    << " "
                 << QString::fromStdString(to_string(year))   << endl;

        Date get_date(day,month,year);
        
        // Set up the date
        s1.setOpenedDate(get_date);
        
        // Nine Line: Capacity
        input = file.readLine();
        input = input.trimmed();
        
        s1.setSeatCapacity(stoi(input.toStdString()));
        
        // Ten Line: has grass
        input = file.readLine();
        input = input.trimmed();
        
        if(input.toStdString() == "Y")    
            s1.setGrass(1);
        else  
            s1.setGrass(0);


        // Set the team info
        s1.setTeam(t1);
        s1.getTeam().setLeague(type);  // Set the type

        // Type switch for the league
        if(s1.getName() == "Yankee Stadium")
            type = "NL";
        
        stadiums.push_back(s1);  // Push into the vector



        count++;


    }
}


/*****************************************
 * MainWindow Display
 * ------------------------------
 * Pre-condition: read the parent window with
 * it own ui window pointer
 * -------------------------------
 * Post-condtion: all the map locations and
 * command actions will be displayed.
 ****************************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Baseball League Map");

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




    QBitmap image_star("/Users/dachenglink/Downloads/CS 008/"
                       "Baseball_League_Map/Star_icon_stylized.svg.png");


    QPixmap maij(":/new/prefix1/Star_icon_stylized.svg.png");

    ui->picked_start->setText("Please click the dots\n"
                              "next to the stadiums to\n"
                              "reveal its information\n");



}

/*****************************************
 * Mainwindow destructor
 * ------------------------------
 * Pre-condition: None
 * -------------------------------
 * Post-condtion: free the ui pointer
 ****************************************/
MainWindow::~MainWindow()
{
    delete ui;
}


/*****************************************
 * Read files
 * ------------------------------
 * Pre-condition: The files are ready to be
 * read in the program with specific formats
 * -------------------------------
 * Post-condtion: The selected files will be
 * read and the private containers will be
 * initialized.
 ****************************************/
void MainWindow::on_Add_files_clicked()
{
    Yes_No_Window files_upod(this,"Please pick the type of the file.");
    files_upod.exec();

    // Loading map info
    if(files_upod.get_answer() == 0)
    {
        InsertWindow get_info(this,
                               "Please type the name of the data file.");

        get_info.exec();
        if(get_info.is_valid())
        {
            // Get the input from the window
            qDebug() << QString::fromStdString(get_info
                                               .get_input());

            // Formatting for file accessing
            QFile map_file(":/new/prefix1/"
                           + QString::fromStdString(get_info
                                                   .get_input()));


            // Message box for not founding
            if(!map_file.open(QIODevice::ReadOnly))
            {
                QMessageBox::information(this,"Error","File not found.");
                return;
            }

            else
                QMessageBox::information(this,"Success","File uploaded.");


            // Set the Permission for the file (read&write)
            map_file.setPermissions(QFileDevice::ReadOwner|
                                                  QFileDevice::WriteOther);

            // Text Stream to read the inputs
            QTextStream in(&map_file);

            // Read all the map infos
            read_map_file(in,_All_League,_AL_League,_NL_League,_locations,
                          _AL_stadium_names,_NL_stadium_names);
        }     


    }


    // Loading stadium info
    else if(files_upod.get_answer() == 1)
    {
        InsertWindow get_info(this,
                               "Please type the name of the data file.");

        get_info.exec();
        if(get_info.is_valid())
        {
            qDebug() << QString::fromStdString(get_info
                                               .get_input());
            QFile map_file(":/new/prefix1/"
                           + QString::fromStdString(get_info
                                                   .get_input()));


            // Message box for not founding
            if(!map_file.open(QIODevice::ReadOnly))
            {
                QMessageBox::information(this,"Error","File not found.");
                return;
            }

            else
            {
                _stadium_file = ":/new/prefix1/stadium_input.txt";
                QMessageBox::information(this,"Success","File uploaded.");
            }

            // Set the Permission for the file (read&write)
            map_file.setPermissions(QFileDevice::ReadOwner|
                                                  QFileDevice::WriteOther);

            // Text Stream to read the inputs
            QTextStream in(&map_file);

            // Read all the map infos
            read_stadium_file(in,_stadium_infos);


            // Store into all the sorting heaps
            for(size_t n =0; n < _stadium_infos.size(); n++)
            {



                // Determine the type of the league
                if(_stadium_infos.at(n).getTeam().getLeague() == "AL")
                {
                    _stadium_infos.at(n).getTeam().setLeague("AL");

                    _AL_stadium_team.insert(_stadium_infos.at(n));
                }

                else if(_stadium_infos.at(n).getTeam().getLeague()== "NL")
                {
                    _stadium_infos.at(n).getTeam().setLeague("NL");

                    _NL_stadium_team.insert(_stadium_infos.at(n));
                }

                // Add it for the grass surf
                if(_stadium_infos.at(n).hasGrass())
                    _stadium_grass_team.insert(_stadium_infos.at(n));


                _stadium_team.insert(_stadium_infos.at(n));
                _stadium_date.insert(_stadium_infos.at(n));
                _stadium_sort.insert(_stadium_infos.at(n));
            }


        }

     }
        // Loading Souvenir info
        else if(files_upod.get_answer() == 3)
        {
            InsertWindow get_info(this,
                                   "Please type the name of the data file.");

            get_info.exec();
            if(get_info.is_valid())
            {
                qDebug() << QString::fromStdString(get_info
                                                   .get_input());
                QFile map_file(":/new/prefix1/"
                               + QString::fromStdString(get_info
                                                       .get_input()));


                // Message box for not founding
                if(!map_file.open(QIODevice::ReadOnly))
                {
                    QMessageBox::information(this,"Error","File not found.");
                    return;
                }

                else
                {    _souvenir_file = ":/new/prefix1/souvenir_input.txt";
                    QMessageBox::information(this,"Success","File uploaded.");
                }

                // Set the Permission for the file (read&write)
                map_file.setPermissions(QFileDevice::ReadOwner|
                                                     QFileDevice::WriteOther);

                // Text Stream to read the inputs
                QTextStream in(&map_file);
                QString input;

                string lines;


                // While not reaching the end of the file
                while(!in.atEnd())
                {
                    string prices = "";
                    string item = "";

                    Souvenir s1;

                    bool is_item = false;

                    input = in.readLine();
                    input = input.trimmed();

                    lines = input.toStdString();

                    // Go through the input lines
                    for(size_t n = 0; n < lines.length(); n++)
                    {
                        // Figure out the prices first
                        if(!is_item && !isspace(lines[n]))
                            prices += lines[n];

                        else if(!isspace(lines[n])
                                || item.length() > 0)
                            item += lines[n];

                        if(isspace(lines[n]))
                        {
                            s1.setPrice(stod(prices)); // Convert
                            is_item = true;    // Switch
                        }
                    }


                    s1.setName(item);  // Set the item

//                    qDebug() << QString::fromStdString
//                                (to_string(s1.getPrice())) << "  "
//                             << QString::fromStdString(s1.getName())
//                             << "  " << _stadium_infos.size() << endl;

                    // Go through the stadium
                    for(size_t i = 0; i < _stadium_infos.size();i++)
                    {
                        // Add the souvenir item for each stadium
                        _stadium_infos.at(i).getTeam().adding(s1);

                        // Go through the souvenir list with iterator
//                        set<Souvenir> :: iterator it =
//                                _stadium_infos.at(i).getTeam().getSV().begin();

//                        qDebug() << QString:: fromStdString
//                                        (it->getName()) << endl;
                    }


                }



            }


    }


}

/*****************************************
 * Plan Trips
 * ------------------------------
 * Pre-condition: The input files are uploaded
 * and the containers is not empty
 * graph list classes should be ready
 * -------------------------------
 * Post-condtion: The paths for specific
 * trips will be drawn with a subwindow
 * based on the shorest path alogrithm
 * in the graph list classes.
 ****************************************/
void MainWindow::on_Plan_trips_clicked()
{
    // Need to prompt user to select the
    // Starting point and Ending point


    if(_AL_League.get_size() > 0)
    {
        // Choosing the start and traveling places
        // from another window by the user
        paths_display input_selection(this,_stadium_infos,_fan_chart);
        input_selection.exec();

        // Check if there is a starting input
        if(input_selection.get_start_input() == "")
        {
            QMessageBox::information(this,"Error","Empty inputs.");
            return;
        }

        // Get an iterator for the input string set
        set<string> :: iterator it;

        // Pointing at the beginning of the set
        it = input_selection.input_stadiums().begin();


        // Initialize a starting point
        Stadium x1;
        x1.setName(input_selection.get_start_input());

        // *** Debugging
        qDebug() << "Start: " << QString::fromStdString
                 (input_selection.get_start_input())
                 << endl;


        // Need vectors to store the shortest paths and costs
        vector<Location_info<Stadium>> desired_solution;
        vector<int> desired_cost;

        // Construct a stadium for later insertions
        Stadium input_stadium;



        // Add the start location first to the solution
        desired_solution.push_back(x1);
        desired_cost.push_back(0);

        // Varaibles for finding/storing costs with indices
        int solution_size;
        int lowest_cost;
        int compare_index;
        int lowest_index;
        int total_cost = 0;

        // Stadium name for the starting point
        string updated_start_point;


        // Have solution ptr ready for paths storage
        vector<Location_info<Stadium>>* solution_ptr;


        // Figure the loop for finding pathes based on the input size
        size_t loop_time = input_selection.input_stadiums().size();

        //******** Can be a Recursive Pathing finding Function here
        for(size_t k = 0; k < loop_time; k++)
        {
            // Figure out the shortest path using DA with a
            // starting point object and store the paths into a vector
            // with the updated cost array as parameter
            solution_ptr = _All_League.Dijkstra_Algorithm(
                                                  x1,
                                                  solution_size, _path_costs);

            // Ready to find the lowest cost for paths
            it = input_selection.input_stadiums().begin();

            input_stadium.setName(*it);


            qDebug() <<  QString::fromStdString("Debugging #1: ")
                     <<   QString:: fromStdString(input_stadium.getName())
                     << endl;
            lowest_index = _All_League.vertex_index_of
                           (Location_info<Stadium> (input_stadium,0));

            lowest_cost = _path_costs[lowest_index];   // Initialize the lowest
                                                    // to be at the beginning

            // Go through indices set to compare costs
            for(; it != input_selection.input_stadiums().end(); it++)
            {
                input_stadium.setName(*it);

                qDebug() <<  QString::fromStdString("Debugging #2: ")
                         <<   QString:: fromStdString(input_stadium.getName())
                         << endl;

                Stadium jk;

                jk.setName(*it);
                compare_index = _All_League.vertex_index_of
                        (Location_info<Stadium> (jk,0));

                // Find the lowest path with given input indices
                if(_path_costs[compare_index] <= lowest_cost)
                {
                    lowest_index = compare_index;
                    lowest_cost = _path_costs[lowest_index];
                }

            }

            // Lowest cost traveling path is found

            // Go to that particular lowest cost's index to get the paths
            for(size_t h = 1; h < solution_ptr[lowest_index].size(); h++)
            {
                // Push the Locations infos that have been travelled
                desired_solution.push_back
                        (solution_ptr[lowest_index].at(h));
                desired_cost.push_back
                        (solution_ptr[lowest_index].at(h).get_cost());

                // Add the cost to total
                total_cost += desired_cost.at(desired_cost.size()-1);


            }

            // Changing the ending point to be the new start point
            updated_start_point = desired_solution.
                                   at(desired_solution.size()-1)
                                  .get_start().getName();

            // Remove the found location from the set
            input_selection.input_stadiums().erase(updated_start_point);

            // Reset the starting point for the next path finding
            x1.setName(updated_start_point);

            qDebug() << QString::fromStdString(" End loop")
                      << QString::fromStdString(updated_start_point);
            delete [] solution_ptr;  // Free the space after one loop
                                     // For the Dijkstra Alogrithm
        }


        // **Debugging for the alorigthm above
        qDebug() << QString::fromStdString("Found solution set:\n");

        for(size_t c =0; c < desired_solution.size() ; c++)
        {
            qDebug() << QString::fromStdString
                        (desired_solution.at(c).get_start().getName() + " ");

        }

        qDebug() << endl;

        for(size_t y = 0; y < desired_cost.size(); y++)
        {
            qDebug() << QString::fromStdString(to_string(desired_cost.at(y))+" ");
        }


        qDebug() << _AL_League.get_size() <<  " Here" << endl;


        // Get a pointer pointing at the solutio vector
        vector<Location_info<Stadium>>* final_solution = &
                                        desired_solution;



        // Draw the paths with updated solution vector, array, end point, size
        paths_display display_paths(this,final_solution,
                                    static_cast<int>(final_solution->size()),
                                    _locations,total_cost,desired_cost,
                                    _stadium_infos,_fan_chart);

        display_paths.exec();

        // Clear the set before next run
        input_selection.input_stadiums().clear();

    }

    else
    {
        // Display exiting message
        QMessageBox::information(this,"Error","Map file not found.");
        return;
    }



}

/*****************************************
 * Picking Starting points
 * ------------------------------
 * Pre-condition: The switches should be
 * set correctly
 * -------------------------------
 * Post-condtion: Based on the switch, to
 * display stadium info or plan trips
 * to the leagues
 ****************************************/
void MainWindow::on_Safeco_Field_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,10,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Safeco Field";
        ui->picked_start->setText("Safeco Field");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location\n");

    }
    else if(start_point != "")
    {
        _end_location = "Safeco Field";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }


}

void MainWindow::on_AT_T_Park_clicked()
{
    // Case 1: Trip is not planned for AL,NL
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,15,is_adminstr);

        show_this.exec(); // Run the window
    }

    // Case 2: Trip is planned
    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "AT&T Park";

        ui->picked_start->setText("AT&T Park");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");

    }

    else if(start_point != "")
    {
        _end_location = "AT&T Park";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }


}

void MainWindow::on_O_Co_Coliseum_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,6,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "AT&T Park";

        ui->picked_start->setText("O.co Coliseum");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");
    }

    else if(start_point != "")
    {
        _end_location = "AT&T Park";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }

}

void MainWindow::on_Dodger_stadium_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,21,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Dodger Stadium";
        ui->picked_start->setText("Dodger Stadium");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");
    }

    else if(start_point != "")
    {
        _end_location = "Dodger Stadium";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }


}

void MainWindow::on_Angel_Stadium_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,0,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Dodger Stadium";
        ui->picked_start->setText("Angel Stadium");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");
    }

    else if(start_point != "")
    {
        _end_location = "Dodger Stadium";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }

}

void MainWindow::on_Pectco_Park_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,26,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "PETCO Park";

        ui->picked_start->setText("PETCO Park");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");
    }

    else if(start_point != "")
    {
        _end_location = "PETCO Park";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }

}

void MainWindow::on_Chase_Field_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,17,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Chase Field";

        ui->picked_start->setText("Chase Field");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");
    }

    else if(start_point != "")
    {
        _end_location = "Chase Field";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }

}

void MainWindow::on_Coers_Field_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,20,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Coors Field";

        ui->picked_start->setText("Coors Field");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");
    }

    else if(start_point != "")
    {
        _end_location = "Coors Field";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }
}

void MainWindow::on_Rangers_Ballpark_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,3,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Rangers Ballpark";

        ui->picked_start->setText("Rangers Ballpark");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");

    }

    else if(start_point != "")
    {
        _end_location = "Rangers Ballpark";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }

}

void MainWindow::on_Minute_Maid_Park_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,5,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Minute Maid Park";

        ui->picked_start->setText("Minute Maid Park");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");
    }

    else if(start_point != "")
    {
        _end_location = "Minute Maid Park";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }

}


void MainWindow::on_Comerica_Park_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,1,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Comerica Park";

        ui->picked_start->setText("Comerica Park");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");
    }

    else if(start_point != "")
    {
        _end_location = "Comerica Park";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }

}

void MainWindow::on_Fenway_Park_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,2,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Fenway Park";

        ui->picked_start->setText("Fenway Park");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");

    }

    else if(start_point != "")
    {
        _end_location = "Fenway Park";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }

}

void MainWindow::on_Kauffman_Stadium_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,4,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Kauffman Stadium";

        ui->picked_start->setText("Kauffman Stadium");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");
    }

    else if(start_point != "")
    {
        _end_location = "Kauffman Stadium";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }

}

void MainWindow::on_Camden_Yards_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,7,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Nationals Park";

        ui->picked_start->setText("Camden Yards");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");

    }

    else if(start_point != "")
    {
        _end_location = "Nationals Park";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }

}


void MainWindow::on_Progressive_Field_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,8,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Progressive Field";

        ui->picked_start->setText("Progressive Field");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");
    }

    else if(start_point != "")
    {
        _end_location = "Progressive Field";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }


}

void MainWindow::on_Rogers_Field_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,9,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Rogers Center";

        ui->picked_start->setText("Rogers Center");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");
    }

    else if(start_point != "")
    {
        _end_location = "Rogers Center";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }

}

void MainWindow::on_Target_Field_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,11,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Target Field";

        ui->picked_start->setText("Target Field");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");

    }

    else if(start_point != "")
    {
        _end_location = "Target Field";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }

}

void MainWindow::on_Tropicana_Field_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,12,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Tropicana Field";

        ui->picked_start->setText("Tropicana Field");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");
    }

    else if(start_point != "")
    {
        _end_location = "Tropicana Field";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }


}

void MainWindow::on_US_Cellular_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,13,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "US Cellular Field";

        ui->picked_start->setText("US Cellular Field");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");

    }

    else if(start_point != "")
    {
        _end_location = "US Cellular Field";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }

}

void MainWindow::on_Yankee_Stadium_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,14,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Yankee Stadium";

        ui->picked_start->setText("Yankee Stadium");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");
    }

    else if(start_point != "")
    {
        _end_location = "Yankee Stadium";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }

}



void MainWindow::on_Buschm_Stadium_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,16,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Busch Stadium";

        ui->picked_start->setText("Busch Stadium");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");

    }

    else if(start_point != "")
    {
        _end_location = "Busch Stadium";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }

}

void MainWindow::on_Citi_Field_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,18,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Yankee Stadium";

        ui->picked_start->setText("Citi Field");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");
    }

    else if(start_point != "")
    {
        _end_location = "Yankee Stadium";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }

}

void MainWindow::on_Citizens_Bank_Park_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,19,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Citizens Bank Park";

        ui->picked_start->setText("Citizens Bank Park");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again
    }

    else if(start_point != "")
    {
        _end_location = "Citizens Bank Park";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }

}

void MainWindow::on_Great_American_Ballpark_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,22,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Great American Ballpark";

        ui->picked_start->setText("Great American Ballpark");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");

    }

    else if(start_point != "")
    {
        _end_location = "Great American Ballpark";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }

}

void MainWindow::on_Marlins_Park_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,23,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Marlins Park";

        ui->picked_start->setText("Marlins Park");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");
    }

    else if(start_point != "")
    {
        _end_location = "Marlins Park";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }

}

void MainWindow::on_Miller_Park_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,24,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Miller Park";

        ui->picked_start->setText("Miller Park");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");
    }

    else if(start_point != "")
    {
        _end_location = "Miller Park";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }


}

void MainWindow::on_Nationals_Park_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,25,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Nationals Park";

        ui->picked_start->setText("Nationals Park");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");
    }

    else if(start_point != "")
    {
        _end_location = "Nationals Park";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }
}

void MainWindow::on_PNC_Park_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,27,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "PNC Park";

        ui->picked_start->setText("PNC Park");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again
    }

    else if(start_point != "")
    {
        _end_location = "PNC Park";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }

}

void MainWindow::on_Turner_Field_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,28,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "Turner Field";

        ui->picked_start->setText("Turner Field");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");
    }

    else if(start_point != "")
    {
        _end_location = "Turner Field";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }



}

void MainWindow::on_Wrigley_Field_clicked()
{
    if(_start_planing == false && _print_distance == false)
    {
        Stadium_info show_this(this,_stadium_infos,29,is_adminstr);

        show_this.exec(); // Run the window
    }

    else if( (_start_planing || _print_distance)
             && start_point == "")
    {
        start_point = "US Cellular Field";

        ui->picked_start->setText("Wrigley Field");

        if(is_AL_trip)
            on_AL_Stadiums_trip_clicked();  // Call the click again

        else if(is_NL_trip)
            on_NL_Stadiums_trip_clicked();  // Call the click again

        else if(_print_distance)
            ui->picked_start->setText("Pick An Ending Location.\n");

    }

    else if(start_point != "")
    {
        _end_location = "US Cellular Field";

        if(_print_distance)
            on_Print_distance_clicked();  // Call the click again

    }

}

/*****************************************
 * Random Access stadiums
 * ------------------------------
 * Pre-condition: files and containers should
 * be initialized
 * -------------------------------
 * Post-condtion: the stadium info will be accessed
 * randomly in the mainwindow with info window
 ****************************************/
void MainWindow::on_Random_access_clicked()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    if(_stadium_infos.size() == 0)
    {
        QMessageBox::information(this,"Error","Sorry, File not found.");

        return;

    }

    int size = static_cast<int>(_stadium_infos.size());
    int index = rand() % size;

    size_t position = static_cast<size_t>(index);

    Stadium_info show_this(this,_stadium_infos,position,
                           is_adminstr);

    show_this.exec(); // Run the window
}

/*****************************************
 * Password input
 * ------------------------------
 * Pre-condition: The correct password
 * should be initialized
 * -------------------------------
 * Post-condtion: Ready to verify the input
 * password
 ****************************************/
void MainWindow::on_password_input_clicked()
{
    Password_section get_access(this);

    // Only execute when the switch is off
    if(is_adminstr== false)
        get_access.exec();



    // Determine whether the input password is correct
    if(get_access.is_accessed())
    {
        // Set up the switch for later access
        is_adminstr = true;
        QMessageBox::information(this,"Success","Login in successfully.");
        ui->password_input->setText("Log Out");
    }

    // Else if it's already logged in
    else
    if(is_adminstr == true &&
       ui->password_input->text()== "Log Out"      )
    {
        // Change the switch
        is_adminstr = false;

        // Reset the condition
        ui->password_input->setText("Administrator Mode");
    }


}

/*****************************************
 * AL stadium trip
 * ------------------------------
 * Pre-condition: The starting locations
 * should be selected at the beginning
 * -------------------------------
 * Post-condtion: Ready to the draw the path
 * with the help of subwindow and path display
 * window
 ****************************************/
void MainWindow::on_AL_Stadiums_trip_clicked()
{
    // If the League container is not empty
    if(_AL_League.get_size()>0)
    {
        if(!_start_planing)
        {
            ui->picked_start->setText("Please pick a \n"
                                      "starting location.\n");

            _start_planing = true;   // Set the switch
            is_AL_trip = true;
        }

        // If every condition is met, ready to draw the trip
        if(ui->picked_start->isVisible() && start_point != ""
           && _start_planing == true     )
        {
            // Get an iterator for the input string set
            set<string> :: iterator it;

            // Form a copy of the private set
            set<string> input_set = _AL_stadium_names;

            // Initialize a starting point
            Stadium x1;
            x1.setName(start_point);

            // *** Debugging
            qDebug() << "Start: " << QString::fromStdString
                     (start_point)
                     << endl;


            // Need vectors to store the shortest paths and costs
            vector<Location_info<Stadium>> desired_solution;
            vector<int> desired_cost;

            // Construct a stadium for later insertions
            Stadium input_stadium;



            // Add the start location first to the solution
            desired_solution.push_back(x1);
            desired_cost.push_back(0);

            // Varaibles for finding/storing costs with indices
            int solution_size;
            int lowest_cost;
            int compare_index;
            int lowest_index;
            int total_cost = 0;

            // Stadium name for the starting point
            string updated_start_point;


            // Have solution ptr ready for paths storage
            vector<Location_info<Stadium>>* solution_ptr;


            // Figure the loop for finding pathes based on the input size
            size_t loop_time = input_set.size();

            //******** Can be a Recursive Pathing finding Function here
            for(size_t k = 0; k < loop_time; k++)
            {
                // Figure out the shortest path using DA with a
                // starting point object and store the paths into a vector
                // with the updated cost array as parameter
                solution_ptr = _All_League.Dijkstra_Algorithm(
                                                      x1,
                                                      solution_size, _path_costs);

                // Ready to find the lowest cost for paths
                it = input_set.begin();

                input_stadium.setName(*it);


                qDebug() <<  QString::fromStdString("Debugging #1: ")
                         <<   QString:: fromStdString(input_stadium.getName())
                         << endl;
                lowest_index = _All_League.vertex_index_of
                               (Location_info<Stadium> (input_stadium,0));

                lowest_cost = _path_costs[lowest_index];   // Initialize the lowest
                                                        // to be at the beginning

                // Go through indices set to compare costs
                for(; it != input_set.end(); it++)
                {
                    input_stadium.setName(*it);

                    qDebug() <<  QString::fromStdString("Debugging #2: ")
                             <<   QString:: fromStdString(input_stadium.getName())
                             << endl;

                    Stadium jk;

                    jk.setName(*it);
                    compare_index = _All_League.vertex_index_of
                            (Location_info<Stadium> (jk,0));

                    // Find the lowest path with given input indices
                    if(_path_costs[compare_index] <= lowest_cost)
                    {
                        lowest_index = compare_index;
                        lowest_cost = _path_costs[lowest_index];
                    }

                }

                // Lowest cost traveling path is found

                // Go to that particular lowest cost's index to get the paths
                for(size_t h = 1; h < solution_ptr[lowest_index].size(); h++)
                {
                    // Push the Locations infos that have been travelled
                    desired_solution.push_back
                            (solution_ptr[lowest_index].at(h));
                    desired_cost.push_back
                            (solution_ptr[lowest_index].at(h).get_cost());

                    // Add the cost to total
                    total_cost += desired_cost.at(desired_cost.size()-1);


                }

                // Changing the ending point to be the new start point
                updated_start_point = desired_solution.
                                       at(desired_solution.size()-1)
                                      .get_start().getName();

                // Remove the found location from the set
                input_set.erase(updated_start_point);

                // Reset the starting point for the next path finding
                x1.setName(updated_start_point);

                qDebug() << QString::fromStdString(" End loop")
                          << QString::fromStdString(updated_start_point);
                delete [] solution_ptr;  // Free the space after one loop
                                         // For the Dijkstra Alogrithm
            }


            // **Debugging for the alorigthm above
            qDebug() << QString::fromStdString("Found solution set:\n");

            for(size_t c =0; c < desired_solution.size() ; c++)
            {
                qDebug() << QString::fromStdString
                            (desired_solution.at(c).get_start().getName() + " ");

            }

            qDebug() << endl;

            for(size_t y = 0; y < desired_cost.size(); y++)
            {
                qDebug() << QString::fromStdString(to_string(desired_cost.at(y))+" ");
            }





            // Get a pointer pointing at the solutio vector
            vector<Location_info<Stadium>>* final_solution = &
                                            desired_solution;



            // Draw the paths with updated solution vector, array, end point, size
            paths_display display_paths(this,final_solution,
                                        static_cast<int>(final_solution->size()),
                                        _locations,total_cost,desired_cost,
                                        _stadium_infos,_fan_chart);

            display_paths.exec();

            // Clear and Reset every conditions
            input_set.clear();

            start_point ="";
            _start_planing  = false;
            ui->picked_start->setText("");
            is_AL_trip = false;

            ui->picked_start->setText("Please click the dots\n"
                                      "next to the stadiums to\n"
                                      "reveal its information\n");



        }

    }

    else
    {
        // Error Message
        QMessageBox::information(this,"Error","No Map files found.\n");
        return;
    }
}




/*****************************************
 * NL stadium trip
 * ------------------------------
 * Pre-condition: The starting locations
 * should be selected at the beginning
 * -------------------------------
 * Post-condtion: Ready to the draw the path
 * with the help of subwindow and path display
 * window
 ****************************************/
void MainWindow::on_NL_Stadiums_trip_clicked()
{
    // If the League container is not empty
    if(_NL_League.get_size()>0)
    {
        if(!_start_planing)
        {
            ui->picked_start->setText("Please pick a \n"
                                      "starting location.\n"
                                      "by clicking the icon on the map");

            _start_planing = true;   // Set the switch
            is_NL_trip = true;
        }

        // If every condition is met, ready to draw the trip
        if(ui->picked_start->isVisible() && start_point != ""
           && _start_planing == true     )
        {
            // Get an iterator for the input string set
            set<string> :: iterator it;

            // Form a copy of the private set
            set<string> input_set = _NL_stadium_names;

            // Initialize a starting point
            Stadium x1;
            x1.setName(start_point);

            // *** Debugging
            qDebug() << "Start: " << QString::fromStdString
                     (start_point)
                     << endl;


            // Need vectors to store the shortest paths and costs
            vector<Location_info<Stadium>> desired_solution;
            vector<int> desired_cost;

            // Construct a stadium for later insertions
            Stadium input_stadium;



            // Add the start location first to the solution
            desired_solution.push_back(x1);
            desired_cost.push_back(0);

            // Varaibles for finding/storing costs with indices
            int solution_size;
            int lowest_cost;
            int compare_index;
            int lowest_index;
            int total_cost = 0;

            // Stadium name for the starting point
            string updated_start_point;


            // Have solution ptr ready for paths storage
            vector<Location_info<Stadium>>* solution_ptr;


            // Figure the loop for finding pathes based on the input size
            size_t loop_time = input_set.size();

            //******** Can be a Recursive Pathing finding Function here
            for(size_t k = 0; k < loop_time; k++)
            {
                // Figure out the shortest path using DA with a
                // starting point object and store the paths into a vector
                // with the updated cost array as parameter
                solution_ptr = _All_League.Dijkstra_Algorithm(
                                                      x1,
                                                      solution_size, _path_costs);

                // Ready to find the lowest cost for paths
                it = input_set.begin();

                input_stadium.setName(*it);


                qDebug() <<  QString::fromStdString("Debugging #1: ")
                         <<   QString:: fromStdString(input_stadium.getName())
                         << endl;
                lowest_index = _All_League.vertex_index_of
                               (Location_info<Stadium> (input_stadium,0));

                lowest_cost = _path_costs[lowest_index];   // Initialize the lowest
                                                        // to be at the beginning

                // Go through indices set to compare costs
                for(; it != input_set.end(); it++)
                {
                    input_stadium.setName(*it);

                    qDebug() <<  QString::fromStdString("Debugging #2: ")
                             <<   QString:: fromStdString(input_stadium.getName())
                             << endl;

                    Stadium jk;

                    jk.setName(*it);
                    compare_index = _All_League.vertex_index_of
                            (Location_info<Stadium> (jk,0));

                    // Find the lowest path with given input indices
                    if(_path_costs[compare_index] <= lowest_cost)
                    {
                        lowest_index = compare_index;
                        lowest_cost = _path_costs[lowest_index];
                    }

                }

                // Lowest cost traveling path is found

                // Go to that particular lowest cost's index to get the paths
                for(size_t h = 1; h < solution_ptr[lowest_index].size(); h++)
                {
                    // Push the Locations infos that have been travelled
                    desired_solution.push_back
                            (solution_ptr[lowest_index].at(h));
                    desired_cost.push_back
                            (solution_ptr[lowest_index].at(h).get_cost());

                    // Add the cost to total
                    total_cost += desired_cost.at(desired_cost.size()-1);


                }

                // Changing the ending point to be the new start point
                updated_start_point = desired_solution.
                                       at(desired_solution.size()-1)
                                      .get_start().getName();

                // Remove the found location from the set
                input_set.erase(updated_start_point);

                // Reset the starting point for the next path finding
                x1.setName(updated_start_point);

                qDebug() << QString::fromStdString(" End loop")
                          << QString::fromStdString(updated_start_point);
                delete [] solution_ptr;  // Free the space after one loop
                                         // For the Dijkstra Alogrithm
            }


            // **Debugging for the alorigthm above
            qDebug() << QString::fromStdString("Found solution set:\n");

            for(size_t c =0; c < desired_solution.size() ; c++)
            {
                qDebug() << QString::fromStdString
                            (desired_solution.at(c).get_start().getName() + " ");

            }

            qDebug() << endl;

            for(size_t y = 0; y < desired_cost.size(); y++)
            {
                qDebug() << QString::fromStdString(to_string(desired_cost.at(y))+" ");
            }





            // Get a pointer pointing at the solutio vector
            vector<Location_info<Stadium>>* final_solution = &
                                            desired_solution;



            // Draw the paths with updated solution vector, array, end point, size
            paths_display display_paths(this,final_solution,
                                        static_cast<int>(final_solution->size()),
                                        _locations,total_cost,desired_cost,
                                        _stadium_infos,_fan_chart);

            display_paths.exec();

            // Clear and Reset every conditions
            input_set.clear();

            start_point ="";
            _start_planing  = false;
            ui->picked_start->setText("");
            is_NL_trip = false;

            ui->picked_start->setText("Please click the dots\n"
                                      "next to the stadiums to\n"
                                      "reveal its information\n");



        }

    }

    else
    {
        // Error Message
        QMessageBox::information(this,"Error","No Map files found.\n");
        return;
    }
}

/*****************************************
 * Print Distance
 * ------------------------------
 * Pre-condition: The input files are uploaded
 * and the containers is not empty
 * graph list classes should be ready
 * -------------------------------
 * Post-condtion: The paths for specific
 * trips will be drawn with a subwindow
 * based on the shorest path alogrithm
 * in the graph list classes and print results.
 ****************************************/
void MainWindow::on_Print_distance_clicked()
{
    // Perfrom when it's not empty container
    if(_All_League.get_size() > 0)
    {
        if(!_print_distance)
        {
            ui->picked_start->setText("Please pick a \n"
                                      "starting location.\n"
                                      "by clicking the icon on the map");
            _print_distance = true;
        }

        // Ready to run the algorithm
        else if(_print_distance &&
                start_point != "" &&
                _end_location != "")
        {
            // Initialize a starting point
            Stadium x1,x2;
            x1.setName(start_point);
            x2.setName(_end_location);

            vector<Location_info<Stadium>>* solution_ptr;
            int solution_size;

            // Run the Dijstra alogrithm
            solution_ptr = _All_League.Dijkstra_Algorithm(x1,
                                                         solution_size,
                                                          _path_costs);
            // Find the index of the ending vertex
            int end_index = _All_League.vertex_index_of(Location_info<Stadium>
                                                        (x2,0));

            Yes_No_Window display(this,"The distance between\n"
                                        +QString::fromStdString(start_point)
                                        + " and " + QString::fromStdString
                                        (_end_location) +"\n"
                                        + "is " +
                                        QString::fromStdString(to_string
                                        (_path_costs[end_index])),
                                  0,0,0);

            display.exec();

            // Reset all the conditions
            _print_distance = false;
            start_point = "";
            _end_location = "";

            ui->picked_start->setText("Please click the dots\n"
                                      "next to the stadiums to\n"
                                      "reveal its information\n");
        }
    }
    else
    {
        // Error Message
        QMessageBox::information(this,"Error","No Map files found.\n");
        return;
    }

}

/*****************************************
 * Shopping Chart info
 * ------------------------------
 * Pre-condition: None
 * -------------------------------
 * Post-condtion: Ready to the displa
 ****************************************/
void MainWindow::on_shopping_chart_clicked()
{

    Stadium_info display(this,_fan_chart);

    display.exec();


}

/*****************************************
 * List of Stadiums
 * ------------------------------
 * Pre-condition: The list containers
 * should be initialized
 * -------------------------------
 * Post-condtion: Ready to display the stadiums
 * in certain sorting style with other windows
 *
 ****************************************/
void MainWindow::on_List_of_stadiums_clicked()
{
    if(_stadium_infos.size() == 0)
    {
        QMessageBox::information(this,"Error","No Files Found");
        return;
    }

    else
    {
        //Ready to pick the selections
        InsertWindow make_selection(this,"Please select the sorting type "
                                         "for the Stadiums",true);

        make_selection.exec();


        // Different selection type
        if(make_selection.get_type() == 0)
        {
            Souvenir_Modifications omg(this,_stadium_sort.
                                       sortedList(),false,4);
            omg.exec();

            // Add the newly added stadium info
            if(omg.is_added())
            {
                _stadium_sort.insert(omg.get_added());
                _stadium_team.insert(omg.get_added());
                _AL_stadium_team.insert(omg.get_added());
                _NL_stadium_team.insert(omg.get_added());
                _stadium_grass_team.insert(omg.get_added());
                _stadium_date.insert(omg.get_added());
            }
        }

        else if(make_selection.get_type() == 1)
        {
            Souvenir_Modifications omg(this,_stadium_team.
                                       sortedList(),false,4);
            omg.exec();

            // Add the newly added stadium info
            if(omg.is_added())
            {
                _stadium_sort.insert(omg.get_added());
                _stadium_team.insert(omg.get_added());
                _AL_stadium_team.insert(omg.get_added());
                _NL_stadium_team.insert(omg.get_added());
                _stadium_grass_team.insert(omg.get_added());
                _stadium_date.insert(omg.get_added());
            }
        }

        else if(make_selection.get_type() == 2)
        {
            Souvenir_Modifications omg(this,_AL_stadium_team.
                                       sortedList(),false,4);
            omg.exec();

            // Add the newly added stadium info
            if(omg.is_added())
            {
                _stadium_sort.insert(omg.get_added());
                _stadium_team.insert(omg.get_added());
                _AL_stadium_team.insert(omg.get_added());
                _NL_stadium_team.insert(omg.get_added());
                _stadium_grass_team.insert(omg.get_added());
                _stadium_date.insert(omg.get_added());
            }
        }

        else if(make_selection.get_type() == 3)
        {
            Souvenir_Modifications omg(this,_NL_stadium_team.
                                       sortedList(),false,4);
            omg.exec();

            // Add the newly added stadium info
            if(omg.is_added())
            {
                _stadium_sort.insert(omg.get_added());
                _stadium_team.insert(omg.get_added());
                _AL_stadium_team.insert(omg.get_added());
                _NL_stadium_team.insert(omg.get_added());
                _stadium_grass_team.insert(omg.get_added());
                _stadium_date.insert(omg.get_added());
            }
        }

        else if(make_selection.get_type() == 4)
        {
            Souvenir_Modifications omg(this,_stadium_grass_team.
                                       sortedList(),false,4);
            omg.exec();

            // Add the newly added stadium info
            if(omg.is_added())
            {
                _stadium_sort.insert(omg.get_added());
                _stadium_team.insert(omg.get_added());
                _AL_stadium_team.insert(omg.get_added());
                _NL_stadium_team.insert(omg.get_added());
                _stadium_grass_team.insert(omg.get_added());
                _stadium_date.insert(omg.get_added());
            }
        }

        else if(make_selection.get_type() == 5)
        {
            Souvenir_Modifications omg(this,_stadium_date.
                                       sortedList(),false,4);
            omg.exec();

            // Add the newly added stadium info
            if(omg.is_added())
            {
                _stadium_sort.insert(omg.get_added());
                _stadium_team.insert(omg.get_added());
                _AL_stadium_team.insert(omg.get_added());
                _NL_stadium_team.insert(omg.get_added());
                _stadium_grass_team.insert(omg.get_added());
                _stadium_date.insert(omg.get_added());
            }
        }





    }
}
