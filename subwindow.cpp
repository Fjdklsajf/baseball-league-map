#include "subwindow.h"
#include "yes_no_window.h"
#include "insertwindow.h"


using namespace std;

SubWindow::SubWindow(QWidget *parent,
                     const QString name) :
    QDialog(parent),
    ui(new Ui::SubWindow)
{
    ui->setupUi(this);

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


     //ui->label_3->setPixmap(maij.scaled(23,23,Qt::KeepAspectRatio));


//    QPixmap bk_pc(":/new/prefix1/Map_of_USA_without_state_names.svg");
//    bk_pc = bk_pc.scaled(this->size(),Qt::IgnoreAspectRatio);

//    QPalette set_bg;
//    set_bg.setBrush(QPalette::Background,bk_pc);
//    this->setPalette(set_bg);

}

SubWindow::~SubWindow()
{
    delete ui;
}

void SubWindow::paintEvent(QPaintEvent *event)
{
    QPainter drawing(this);

    drawing.drawLine(QPoint(50,60),QPoint(100,200));

    drawing.end();

}


void SubWindow::on_Add_files_clicked()
{
//    Yes_No_Window files_upod(this,"Please pick the type of the file.");
//    files_upod.exec();

//    if(files_upod.get_answer() == 0)
//    {
//        InsertWindow get_info(this,
//                               "Please type the name of the data file.");

//        get_info.exec();
//        if(get_info.is_valid())
//        {
//            qDebug() << QString::fromStdString(get_info
//                                               .get_input());
//            QFile map_file(":/new/prefix1/"
//                           + QString::fromStdString(get_info
//                                                   .get_input()));


//            // Message box for not founding
//            if(!map_file.open(QIODevice::ReadOnly))
//            {
//                QMessageBox::information(this,"Error","File not found.");
//                return;
//            }

//            else
//                QMessageBox::information(this,"Success","File uploaded.");


//            // Set the Permission for the file (read&write)
//            map_file.setPermissions(QFileDevice::ReadOwner|
//                                                  QFileDevice::WriteOther);

//            // Text Stream to read the inputs
//            QTextStream in(&map_file);

//            // Read all the map infos
//            read_map_file(in,_All_League,_AL_League,_NL_League);
//        }

//        int size = _All_League.get_size();
//        string size_str = to_string(size);

//        QString out_size;

//        out_size = QString::fromStdString(size_str);
//        qDebug() << out_size << endl;
//    }
}

void SubWindow::on_Safeco_Field_clicked()
{
    // If the object is not empty

}

void SubWindow::on_AT_T_Park_clicked()
{

}

void SubWindow::on_O_Co_Coliseum_clicked()
{

}

void SubWindow::on_Dodger_stadium_clicked()
{

}

void SubWindow::on_Angel_Stadium_clicked()
{

}

void SubWindow::on_Pectco_Park_clicked()
{

}

void SubWindow::on_Chase_Field_clicked()
{

}

void SubWindow::on_Coers_Field_clicked()
{

}

void SubWindow::on_Rangers_Ballpark_clicked()
{

}

void SubWindow::on_Minute_Maid_Park_clicked()
{

}
