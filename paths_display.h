#ifndef PATHS_DISPLAY_H
#define PATHS_DISPLAY_H

#include <QDialog>
#include <QPainter>
#include <QPen>
#include <QPoint>
#include <iostream>
#include <string>
#include "graph_list.h"
#include <set>
#include <functional>
#include "souvenir_modifications.h"

using namespace std;



namespace Ui {
class paths_display;
}

class paths_display : public QDialog
{
    Q_OBJECT

public:

    //--------CONSTRUCTORS---------------
    explicit paths_display(QWidget *parent,
                           vector<Stadium>& list,
                           set<Souvenir> & chart);
    explicit paths_display(QWidget* parent,
                           vector<Location_info<Stadium>>* paths,
                           int paths_size,
                           vector<string> & locations,
                           int total_costs,
                           vector<int> & _paths,
                           vector<Stadium>& list,
                           set<Souvenir> & chart);
    ~paths_display();

    //---------DRAWING EVENT------------
    virtual void paintEvent(QPaintEvent * event);


    //---------ACCESSORS--------------
    string get_start_input() const {return user_start_point;}
    string get_end_input() const {return end_point;}
    set<string>& input_stadiums()
    {return user_inputs;}

private slots:


    //--------BUTTONS ACCESS----------
    void on_Safeco_Field_clicked();

    void on_AT_T_Park_clicked();

    void on_O_Co_Coliseum_clicked();

    void on_Dodger_stadium_clicked();

    void on_Angel_Stadium_clicked();

    void on_Pectco_Park_clicked();

    void on_Return_main_clicked();

    void on_Chase_Field_clicked();

    void on_Coers_Field_clicked();

    void on_Target_Field_clicked();

    void on_Miller_Park_clicked();

    void on_Wrigley_Field_clicked();

    void on_US_Cellular_clicked();

    void on_Kauffman_Stadium_clicked();

    void on_Buschm_Stadium_clicked();

    void on_Great_American_Ballpark_clicked();

    void on_Progressive_Field_clicked();

    void on_Comerica_Park_clicked();

    void on_PNC_Park_clicked();

    void on_Camden_Yards_clicked();

    void on_Nationals_Park_clicked();

    void on_Citizens_Bank_Park_clicked();

    void on_Rogers_Field_clicked();

    void on_Yankee_Stadium_clicked();

    void on_Citi_Field_clicked();

    void on_Fenway_Park_clicked();

    void on_Turner_Field_clicked();

    void on_Tropicana_Field_clicked();

    void on_Marlins_Park_clicked();

    void on_Minute_Maid_Park_clicked();

    void on_Rangers_Ballpark_clicked();

    void on_add_delete_chart_clicked();

private:
    Ui::paths_display *ui;   // Default ui window pointer

    // A Array of vectors of shortest paths,stadiums
    vector<Location_info<Stadium>>* _shortest_paths = nullptr;
    vector<Stadium>* _list_ptr = nullptr;
    set<Souvenir>* _chart_ptr = nullptr;

    //------------------STORAGES OF PATHS INFO-------------------
    int _size;
    vector<string> _locations;      // Locations for maps
    vector<Stadium> _infos;         // Displaying only


    set<string> user_inputs;       // Stadium inputs from the user
    string user_start_point;       // User selected input

    set<string>* inputs;

    string start_point;
    string end_point;


    //-------------------BOOLEANS FOR SWITCHES------------
    bool input_completed = false;
    bool start_picked = false;
    int end_point_index;

    bool is_modifier = false;
    bool path_painted = false;

    vector<int> path_cost;



};

#endif // PATHS_DISPLAY_H
