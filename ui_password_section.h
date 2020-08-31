/********************************************************************************
** Form generated from reading UI file 'password_section.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORD_SECTION_H
#define UI_PASSWORD_SECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Password_section
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *message;

    void setupUi(QDialog *Password_section)
    {
        if (Password_section->objectName().isEmpty())
            Password_section->setObjectName(QString::fromUtf8("Password_section"));
        Password_section->resize(576, 426);
        lineEdit = new QLineEdit(Password_section);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(350, 150, 141, 21));
        lineEdit_2 = new QLineEdit(Password_section);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(350, 230, 141, 21));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        label = new QLabel(Password_section);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 150, 91, 20));
        label->setStyleSheet(QString::fromUtf8("font: 57 italic 18pt \"Avenir\";"));
        textBrowser = new QTextBrowser(Password_section);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(60, 110, 171, 171));
        textBrowser->setStyleSheet(QString::fromUtf8("#textBrowser\n"
"{\n"
"border-image:url(:/new/prefix1/baseball-1-featured-2.png);\n"
"}"));
        pushButton = new QPushButton(Password_section);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(310, 330, 113, 32));
        label_2 = new QLabel(Password_section);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 230, 91, 20));
        label_2->setStyleSheet(QString::fromUtf8("font: 57 italic 18pt \"Avenir\";"));
        label_3 = new QLabel(Password_section);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 40, 241, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 57 italic 18pt \"Avenir\";\n"
"color:rgb(104, 127, 255);"));
        message = new QLabel(Password_section);
        message->setObjectName(QString::fromUtf8("message"));
        message->setGeometry(QRect(380, 280, 151, 20));
        message->setStyleSheet(QString::fromUtf8("font: 57 italic 18pt \"Avenir\";\n"
"color:rgb(253, 132, 73);"));

        retranslateUi(Password_section);

        QMetaObject::connectSlotsByName(Password_section);
    } // setupUi

    void retranslateUi(QDialog *Password_section)
    {
        Password_section->setWindowTitle(QCoreApplication::translate("Password_section", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Password_section", "Username:", nullptr));
        pushButton->setText(QCoreApplication::translate("Password_section", "Log in", nullptr));
        label_2->setText(QCoreApplication::translate("Password_section", "Password:", nullptr));
        label_3->setText(QCoreApplication::translate("Password_section", "BaseBall League Editing", nullptr));
        message->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Password_section: public Ui_Password_section {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORD_SECTION_H
