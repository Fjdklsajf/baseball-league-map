/********************************************************************************
** Form generated from reading UI file 'insertwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTWINDOW_H
#define UI_INSERTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_InsertWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *WordInput;
    QLabel *TypeLabel;
    QComboBox *comboBox;

    void setupUi(QDialog *InsertWindow)
    {
        if (InsertWindow->objectName().isEmpty())
            InsertWindow->setObjectName(QString::fromUtf8("InsertWindow"));
        InsertWindow->resize(494, 384);
        buttonBox = new QDialogButtonBox(InsertWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(60, 300, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        WordInput = new QLineEdit(InsertWindow);
        WordInput->setObjectName(QString::fromUtf8("WordInput"));
        WordInput->setGeometry(QRect(100, 130, 241, 22));
        TypeLabel = new QLabel(InsertWindow);
        TypeLabel->setObjectName(QString::fromUtf8("TypeLabel"));
        TypeLabel->setGeometry(QRect(50, 40, 341, 61));
        comboBox = new QComboBox(InsertWindow);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(50, 200, 381, 41));

        retranslateUi(InsertWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), InsertWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), InsertWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(InsertWindow);
    } // setupUi

    void retranslateUi(QDialog *InsertWindow)
    {
        InsertWindow->setWindowTitle(QCoreApplication::translate("InsertWindow", "Dialog", nullptr));
        TypeLabel->setText(QCoreApplication::translate("InsertWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">TextLabel</span></p></body></html>", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("InsertWindow", "Sorted by Stadiums Names for Major League Stadiums", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("InsertWindow", "Sorted by Team Names for Major League Stadiums", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("InsertWindow", "Sorted by  Team Names for American League Stadiums", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("InsertWindow", "Sorted by Team Names for National League Stadiums", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("InsertWindow", "Sorted by Team Names for Stadiums with Grass Surface", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("InsertWindow", "Sorted by Stadium Date-Opened for Major League Stadiums", nullptr));

    } // retranslateUi

};

namespace Ui {
    class InsertWindow: public Ui_InsertWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTWINDOW_H
