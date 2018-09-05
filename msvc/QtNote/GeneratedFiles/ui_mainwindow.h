/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabMainFrame;
    QWidget *tabDiary;
    QVBoxLayout *verticalLayout_2;
    QWidget *tabNote;
    QVBoxLayout *verticalLayout_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(916, 680);
        QIcon icon;
        icon.addFile(QStringLiteral("resource/note.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabMainFrame = new QTabWidget(centralWidget);
        tabMainFrame->setObjectName(QStringLiteral("tabMainFrame"));
        tabDiary = new QWidget();
        tabDiary->setObjectName(QStringLiteral("tabDiary"));
        verticalLayout_2 = new QVBoxLayout(tabDiary);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tabMainFrame->addTab(tabDiary, QString());
        tabNote = new QWidget();
        tabNote->setObjectName(QStringLiteral("tabNote"));
        verticalLayout_3 = new QVBoxLayout(tabNote);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tabMainFrame->addTab(tabNote, QString());

        verticalLayout->addWidget(tabMainFrame);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabMainFrame->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\267\245\344\275\234\346\227\245\350\256\260", nullptr));
        tabMainFrame->setTabText(tabMainFrame->indexOf(tabDiary), QApplication::translate("MainWindow", "\345\267\245\344\275\234\346\227\245\350\256\260", nullptr));
        tabMainFrame->setTabText(tabMainFrame->indexOf(tabNote), QApplication::translate("MainWindow", "\345\255\246\344\271\240\347\254\224\350\256\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
