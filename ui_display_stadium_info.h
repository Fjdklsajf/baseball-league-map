/********************************************************************************
** Form generated from reading UI file 'display_stadium_info.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAY_STADIUM_INFO_H
#define UI_DISPLAY_STADIUM_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Stadium_info
{
public:
    QDialogButtonBox *buttonBox;
    QTextBrowser *textBrowser;
    QPushButton *Editing;
    QLabel *label;
    QPushButton *Editing_stad;

    void setupUi(QDialog *Stadium_info)
    {
        if (Stadium_info->objectName().isEmpty())
            Stadium_info->setObjectName(QString::fromUtf8("Stadium_info"));
        Stadium_info->resize(655, 419);
        buttonBox = new QDialogButtonBox(Stadium_info);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(330, 370, 301, 32));
        buttonBox->setStyleSheet(QString::fromUtf8("font: 57 italic 16pt \"Avenir\";"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textBrowser = new QTextBrowser(Stadium_info);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(80, 30, 491, 301));
        textBrowser->setStyleSheet(QString::fromUtf8("font: 87 italic 15pt \"Avenir\";"));
        Editing = new QPushButton(Stadium_info);
        Editing->setObjectName(QString::fromUtf8("Editing"));
        Editing->setGeometry(QRect(20, 370, 131, 32));
        Editing->setStyleSheet(QString::fromUtf8("font: 57 italic 14pt \"Avenir\";"));
        label = new QLabel(Stadium_info);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 370, 151, 20));
        label->setStyleSheet(QString::fromUtf8("color:rgb(95, 21, 255);\n"
"font: 81 14pt \"Avenir\";\n"
""));
        Editing_stad = new QPushButton(Stadium_info);
        Editing_stad->setObjectName(QString::fromUtf8("Editing_stad"));
        Editing_stad->setGeometry(QRect(20, 340, 131, 32));
        Editing_stad->setStyleSheet(QString::fromUtf8("font: 57 italic 14pt \"Avenir\";"));

        retranslateUi(Stadium_info);
        QObject::connect(buttonBox, SIGNAL(accepted()), Stadium_info, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Stadium_info, SLOT(reject()));

        QMetaObject::connectSlotsByName(Stadium_info);
    } // setupUi

    void retranslateUi(QDialog *Stadium_info)
    {
        Stadium_info->setWindowTitle(QCoreApplication::translate("Stadium_info", "Dialog", nullptr));
        Editing->setText(QCoreApplication::translate("Stadium_info", "Modify Souvenirs", nullptr));
        label->setText(QString());
        Editing_stad->setText(QCoreApplication::translate("Stadium_info", "Modify Stadiums", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Stadium_info: public Ui_Stadium_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAY_STADIUM_INFO_H
