/********************************************************************************
** Form generated from reading UI file 'QtNote.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTNOTE_H
#define UI_QTNOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtNoteClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtNoteClass)
    {
        if (QtNoteClass->objectName().isEmpty())
            QtNoteClass->setObjectName(QStringLiteral("QtNoteClass"));
        QtNoteClass->resize(600, 400);
        menuBar = new QMenuBar(QtNoteClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtNoteClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtNoteClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtNoteClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtNoteClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtNoteClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtNoteClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtNoteClass->setStatusBar(statusBar);

        retranslateUi(QtNoteClass);

        QMetaObject::connectSlotsByName(QtNoteClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtNoteClass)
    {
        QtNoteClass->setWindowTitle(QApplication::translate("QtNoteClass", "QtNote", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtNoteClass: public Ui_QtNoteClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTNOTE_H
