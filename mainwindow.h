#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QSaveFile>
#include "graph_list.h"
#include <QMessageBox>
#include <QPen>
#include <QLine>
#include <QLineF>
#include <QtGui>
#include <QtCore>
#include <QRegion>
#include <QBitmap>
#include "heap.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_Add_files_clicked();

    void on_Safeco_Field_clicked();

    void on_AT_T_Park_clicked();

    void on_O_Co_Coliseum_clicked();

    void on_Dodger_stadium_clicked();

    void on_Angel_Stadium_clicked();

    void on_Pectco_Park_clicked();

    void on_Chase_Field_clicked();

    void on_Coers_Field_clicked();

    void on_Rangers_Ballpark_clicked();

    void on_Minute_Maid_Park_clicked();

    void on_Plan_trips_clicked();

    void on_Comerica_Park_clicked();

    void on_Fenway_Park_clicked();

    void on_Kauffman_Stadium_clicked();

    void on_Camden_Yards_clicked();

    void on_Progressive_Field_clicked();

    void on_Rogers_Field_clicked();

    void on_Target_Field_clicked();

    void on_Tropicana_Field_clicked();

    void on_US_Cellular_clicked();

    void on_Yankee_Stadium_clicked();

    void on_Buschm_Stadium_clicked();

    void on_Citi_Field_clicked();

    void on_Citizens_Bank_Park_clicked();

    void on_Great_American_Ballpark_clicked();

    void on_Marlins_Park_clicked();

    void on_Miller_Park_clicked();

    void on_Nationals_Park_clicked();

    void on_PNC_Park_clicked();

    void on_Turner_Field_clicked();

    void on_Wrigley_Field_clicked();

    void on_Random_access_clicked();

    void on_password_input_clicked();

    void on_AL_Stadiums_trip_clicked();

    void on_NL_Stadiums_trip_clicked();

    void on_Print_distance_clicked();

    void on_shopping_chart_clicked();

    void on_List_of_stadiums_clicked();

private:
    Ui::MainWindow *ui;

    //----------CALCULATING SHORTEST PATH--------
    Graph_List<Location_info<Stadium>,Stadium> _All_League;
    Graph_List<Location_info<Stadium>,Stadium> _AL_League;
    Graph_List<Location_info<Stadium>,Stadium> _NL_League;
    
    //----------CONTAINERS----------------
    vector<Stadium> _stadium_infos;
    set<string> _AL_stadium_names;
    set<string> _NL_stadium_names;
    set<Souvenir> _fan_chart;

    //----------HEAP SORTED--------------
    Heap<Stadium,CompareDate> _stadium_date;
    Heap<Stadium,CompareTeam_Alph> _stadium_team;
    Heap<Stadium,CompareStadium_Alph> _stadium_sort;

    Heap<Stadium,CompareTeam_Alph> _stadium_grass_team;
    Heap<Stadium,CompareTeam_Alph> _AL_stadium_team;
    Heap<Stadium,CompareTeam_Alph> _NL_stadium_team;

    //----------STORGES OF SHORTEST PATHS & COORDINATES--------
    vector<string> _locations;
    QPoint _solution_points[300];   // Capacity may vary for
    int _path_costs[300];           // different applications
    int _num_points;

    //----------PICKING TRIPS STARTING AND ENDING--------
    string _start_location;     // Input from user
    string _end_location;
    string _stadium_file = "";
    string _souvenir_file = "";
    string start_point;

    bool   _start_planing = false;
    bool   _print_distance = false;

    bool is_adminstr = false;
    bool is_AL_trip = false;
    bool is_NL_trip = false;

    //----------STADIUM SORTED LISTS--------

};

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
/*****************************************
 * Mainwindow destructor
 * ------------------------------
 * Pre-condition: None
 * -------------------------------
 * Post-condtion: free the ui pointer
 ****************************************/
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
/*****************************************
 * Shopping Chart info
 * ------------------------------
 * Pre-condition: None
 * -------------------------------
 * Post-condtion: Ready to the displa
 ****************************************/
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


#endif // MAINWINDOW_H
