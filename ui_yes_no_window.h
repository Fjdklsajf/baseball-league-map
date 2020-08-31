/********************************************************************************
** Form generated from reading UI file 'yes_no_window.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YES_NO_WINDOW_H
#define UI_YES_NO_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Yes_No_Window
{
public:
    QPushButton *Yes;
    QPushButton *No;
    QLabel *label;
    QPushButton *Yes_3;
    QPushButton *pushButton;
    QLabel *Team_label;
    QLabel *phone_label;
    QLabel *Stadium_label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *phone_label_2;
    QLineEdit *lineEdit_4;

    void setupUi(QDialog *Yes_No_Window)
    {
        if (Yes_No_Window->objectName().isEmpty())
            Yes_No_Window->setObjectName(QString::fromUtf8("Yes_No_Window"));
        Yes_No_Window->resize(449, 343);
        Yes_No_Window->setStyleSheet(QString::fromUtf8(""));
        Yes = new QPushButton(Yes_No_Window);
        Yes->setObjectName(QString::fromUtf8("Yes"));
        Yes->setGeometry(QRect(100, 120, 101, 28));
        Yes->setStyleSheet(QString::fromUtf8("font: 57 italic 14pt \"Avenir\";"));
        No = new QPushButton(Yes_No_Window);
        No->setObjectName(QString::fromUtf8("No"));
        No->setGeometry(QRect(210, 120, 111, 28));
        No->setStyleSheet(QString::fromUtf8("font: 57 italic 14pt \"Avenir\";"));
        label = new QLabel(Yes_No_Window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 50, 361, 71));
        label->setStyleSheet(QString::fromUtf8("font: 81 italic 20pt \"Avenir\";"));
        Yes_3 = new QPushButton(Yes_No_Window);
        Yes_3->setObjectName(QString::fromUtf8("Yes_3"));
        Yes_3->setGeometry(QRect(210, 150, 111, 28));
        Yes_3->setStyleSheet(QString::fromUtf8("font: 57 italic 14pt \"Avenir\";"));
        pushButton = new QPushButton(Yes_No_Window);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 310, 113, 32));
        pushButton->setStyleSheet(QString::fromUtf8("font: 57 italic 16pt \"Avenir\";"));
        Team_label = new QLabel(Yes_No_Window);
        Team_label->setObjectName(QString::fromUtf8("Team_label"));
        Team_label->setGeometry(QRect(40, 220, 151, 16));
        Team_label->setStyleSheet(QString::fromUtf8("font: 57 italic 14pt \"Avenir\";"));
        phone_label = new QLabel(Yes_No_Window);
        phone_label->setObjectName(QString::fromUtf8("phone_label"));
        phone_label->setGeometry(QRect(40, 250, 131, 16));
        phone_label->setStyleSheet(QString::fromUtf8("font: 57 italic 14pt \"Avenir\";"));
        Stadium_label = new QLabel(Yes_No_Window);
        Stadium_label->setObjectName(QString::fromUtf8("Stadium_label"));
        Stadium_label->setGeometry(QRect(40, 190, 181, 16));
        Stadium_label->setStyleSheet(QString::fromUtf8("font: 57 italic 14pt \"Avenir\";"));
        lineEdit = new QLineEdit(Yes_No_Window);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(220, 190, 171, 21));
        lineEdit->setStyleSheet(QString::fromUtf8("font: 57 italic 14pt \"Avenir\";"));
        lineEdit_2 = new QLineEdit(Yes_No_Window);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(220, 220, 171, 21));
        lineEdit_2->setStyleSheet(QString::fromUtf8("font: 57 italic 14pt \"Avenir\";"));
        lineEdit_3 = new QLineEdit(Yes_No_Window);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(220, 250, 171, 21));
        lineEdit_3->setStyleSheet(QString::fromUtf8("font: 57 italic 14pt \"Avenir\";"));
        phone_label_2 = new QLabel(Yes_No_Window);
        phone_label_2->setObjectName(QString::fromUtf8("phone_label_2"));
        phone_label_2->setGeometry(QRect(40, 280, 131, 16));
        phone_label_2->setStyleSheet(QString::fromUtf8("font: 57 italic 14pt \"Avenir\";"));
        lineEdit_4 = new QLineEdit(Yes_No_Window);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(220, 280, 171, 21));
        lineEdit_4->setStyleSheet(QString::fromUtf8("font: 57 italic 14pt \"Avenir\";"));

        retranslateUi(Yes_No_Window);

        QMetaObject::connectSlotsByName(Yes_No_Window);
    } // setupUi

    void retranslateUi(QDialog *Yes_No_Window)
    {
        Yes_No_Window->setWindowTitle(QCoreApplication::translate("Yes_No_Window", "Dialog", nullptr));
        Yes->setText(QCoreApplication::translate("Yes_No_Window", "Map File", nullptr));
        No->setText(QCoreApplication::translate("Yes_No_Window", "Stadiums File", nullptr));
        label->setText(QCoreApplication::translate("Yes_No_Window", "<html><head/><body><p align=\"center\"><span style=\" font-size:8pt;\">TextLabel</span></p></body></html>", nullptr));
        Yes_3->setText(QCoreApplication::translate("Yes_No_Window", "Souvenirs File", nullptr));
        pushButton->setText(QCoreApplication::translate("Yes_No_Window", "Confirm", nullptr));
        Team_label->setText(QCoreApplication::translate("Yes_No_Window", "Enter New Team Name:", nullptr));
        phone_label->setText(QCoreApplication::translate("Yes_No_Window", "Enter New Phone#:", nullptr));
        Stadium_label->setText(QCoreApplication::translate("Yes_No_Window", "Enter New Stadium Name:", nullptr));
        phone_label_2->setText(QCoreApplication::translate("Yes_No_Window", "Enter New Capacity:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Yes_No_Window: public Ui_Yes_No_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YES_NO_WINDOW_H
