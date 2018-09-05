/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *btOk;
    QPushButton *btCancel;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(375, 321);
        verticalLayout = new QVBoxLayout(Login);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        calendarWidget = new QCalendarWidget(Login);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));

        verticalLayout->addWidget(calendarWidget);

        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(Login);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btOk = new QPushButton(Login);
        btOk->setObjectName(QStringLiteral("btOk"));

        horizontalLayout->addWidget(btOk);

        btCancel = new QPushButton(Login);
        btCancel->setObjectName(QStringLiteral("btCancel"));

        horizontalLayout->addWidget(btCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        label->setText(QApplication::translate("Login", "\350\257\267\347\273\231\346\210\221\344\270\200\344\270\252\345\257\206\347\240\201\357\274\232", nullptr));
        btOk->setText(QApplication::translate("Login", "\347\241\256\345\256\232", nullptr));
        btCancel->setText(QApplication::translate("Login", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
