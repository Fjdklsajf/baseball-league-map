/********************************************************************************
** Form generated from reading UI file 'souvenir_modifications.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOUVENIR_MODIFICATIONS_H
#define UI_SOUVENIR_MODIFICATIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Souvenir_Modifications
{
public:
    QTableWidget *Souvenir_items;
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *add_souvenir;
    QPushButton *delete_souvenir;

    void setupUi(QDialog *Souvenir_Modifications)
    {
        if (Souvenir_Modifications->objectName().isEmpty())
            Souvenir_Modifications->setObjectName(QString::fromUtf8("Souvenir_Modifications"));
        Souvenir_Modifications->resize(796, 539);
        Souvenir_items = new QTableWidget(Souvenir_Modifications);
        if (Souvenir_items->columnCount() < 2)
            Souvenir_items->setColumnCount(2);
        QFont font;
        font.setPointSize(16);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        Souvenir_items->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        Souvenir_items->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (Souvenir_items->rowCount() < 49)
            Souvenir_items->setRowCount(49);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(5, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(6, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(7, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(8, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(9, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(10, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(11, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(12, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(13, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(14, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(15, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(16, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(17, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(18, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(19, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(20, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(21, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(22, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(23, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(24, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(25, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(26, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(27, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(28, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(29, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(30, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(31, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(32, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(33, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(34, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(35, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(36, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(37, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(38, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(39, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(40, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(41, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(42, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(43, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(44, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(45, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(46, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(47, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        Souvenir_items->setVerticalHeaderItem(48, __qtablewidgetitem50);
        Souvenir_items->setObjectName(QString::fromUtf8("Souvenir_items"));
        Souvenir_items->setGeometry(QRect(110, 30, 591, 281));
        Souvenir_items->setStyleSheet(QString::fromUtf8("font: 57 14pt \"Avenir\";"));
        Souvenir_items->setLineWidth(1);
        Souvenir_items->setAutoScroll(false);
        Souvenir_items->setShowGrid(true);
        comboBox = new QComboBox(Souvenir_Modifications);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(180, 370, 481, 41));
        label = new QLabel(Souvenir_Modifications);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 340, 401, 21));
        label->setStyleSheet(QString::fromUtf8("\n"
"font: 87 italic 18pt \"Avenir\";"));
        pushButton = new QPushButton(Souvenir_Modifications);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 450, 141, 41));
        pushButton->setStyleSheet(QString::fromUtf8("font: 81 18pt \"Avenir\";"));
        add_souvenir = new QPushButton(Souvenir_Modifications);
        add_souvenir->setObjectName(QString::fromUtf8("add_souvenir"));
        add_souvenir->setGeometry(QRect(590, 410, 141, 41));
        add_souvenir->setStyleSheet(QString::fromUtf8("font: 81 18pt \"Avenir\";"));
        delete_souvenir = new QPushButton(Souvenir_Modifications);
        delete_souvenir->setObjectName(QString::fromUtf8("delete_souvenir"));
        delete_souvenir->setGeometry(QRect(590, 450, 141, 41));
        delete_souvenir->setStyleSheet(QString::fromUtf8("font: 81 18pt \"Avenir\";"));

        retranslateUi(Souvenir_Modifications);

        QMetaObject::connectSlotsByName(Souvenir_Modifications);
    } // setupUi

    void retranslateUi(QDialog *Souvenir_Modifications)
    {
        Souvenir_Modifications->setWindowTitle(QCoreApplication::translate("Souvenir_Modifications", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = Souvenir_items->verticalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = Souvenir_items->verticalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = Souvenir_items->verticalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = Souvenir_items->verticalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = Souvenir_items->verticalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = Souvenir_items->verticalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = Souvenir_items->verticalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = Souvenir_items->verticalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = Souvenir_items->verticalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = Souvenir_items->verticalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = Souvenir_items->verticalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = Souvenir_items->verticalHeaderItem(11);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = Souvenir_items->verticalHeaderItem(12);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = Souvenir_items->verticalHeaderItem(13);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = Souvenir_items->verticalHeaderItem(14);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = Souvenir_items->verticalHeaderItem(15);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = Souvenir_items->verticalHeaderItem(16);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = Souvenir_items->verticalHeaderItem(17);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = Souvenir_items->verticalHeaderItem(18);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = Souvenir_items->verticalHeaderItem(19);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = Souvenir_items->verticalHeaderItem(20);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = Souvenir_items->verticalHeaderItem(21);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = Souvenir_items->verticalHeaderItem(22);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = Souvenir_items->verticalHeaderItem(23);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = Souvenir_items->verticalHeaderItem(24);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = Souvenir_items->verticalHeaderItem(25);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = Souvenir_items->verticalHeaderItem(26);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = Souvenir_items->verticalHeaderItem(27);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = Souvenir_items->verticalHeaderItem(28);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = Souvenir_items->verticalHeaderItem(29);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = Souvenir_items->verticalHeaderItem(30);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = Souvenir_items->verticalHeaderItem(31);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = Souvenir_items->verticalHeaderItem(32);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = Souvenir_items->verticalHeaderItem(33);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = Souvenir_items->verticalHeaderItem(34);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = Souvenir_items->verticalHeaderItem(35);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = Souvenir_items->verticalHeaderItem(36);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = Souvenir_items->verticalHeaderItem(37);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = Souvenir_items->verticalHeaderItem(38);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = Souvenir_items->verticalHeaderItem(39);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = Souvenir_items->verticalHeaderItem(40);
        ___qtablewidgetitem40->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = Souvenir_items->verticalHeaderItem(41);
        ___qtablewidgetitem41->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = Souvenir_items->verticalHeaderItem(42);
        ___qtablewidgetitem42->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = Souvenir_items->verticalHeaderItem(43);
        ___qtablewidgetitem43->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = Souvenir_items->verticalHeaderItem(44);
        ___qtablewidgetitem44->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = Souvenir_items->verticalHeaderItem(45);
        ___qtablewidgetitem45->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = Souvenir_items->verticalHeaderItem(46);
        ___qtablewidgetitem46->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = Souvenir_items->verticalHeaderItem(47);
        ___qtablewidgetitem47->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem48 = Souvenir_items->verticalHeaderItem(48);
        ___qtablewidgetitem48->setText(QCoreApplication::translate("Souvenir_Modifications", "New Row", nullptr));
        label->setText(QCoreApplication::translate("Souvenir_Modifications", "Please select one of the items below ", nullptr));
        pushButton->setText(QCoreApplication::translate("Souvenir_Modifications", "Modify", nullptr));
        add_souvenir->setText(QCoreApplication::translate("Souvenir_Modifications", "Add ", nullptr));
        delete_souvenir->setText(QCoreApplication::translate("Souvenir_Modifications", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Souvenir_Modifications: public Ui_Souvenir_Modifications {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOUVENIR_MODIFICATIONS_H
