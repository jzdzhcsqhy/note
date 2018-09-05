/********************************************************************************
** Form generated from reading UI file 'HealthStoneSimulator.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEALTHSTONESIMULATOR_H
#define UI_HEALTHSTONESIMULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CHealthStoneSimulator
{
public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditLevel;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEditRate;
    QLabel *label_8;
    QLabel *label_3;
    QPushButton *pushButtonOne;
    QLineEdit *lineEditStar;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *label_10;
    QLineEdit *lineEditWin;
    QSpacerItem *verticalSpacer;
    QLabel *label_11;
    QLineEdit *lineEditTotal;
    QLabel *label_7;
    QLineEdit *lineEditLose;
    QLineEdit *lineEditContinue;
    QLineEdit *lineEditCurLevel;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_17;
    QLineEdit *lineEditCurStar;
    QTableWidget *tableWidget;

    void setupUi(QDialog *CHealthStoneSimulator)
    {
        if (CHealthStoneSimulator->objectName().isEmpty())
            CHealthStoneSimulator->setObjectName(QStringLiteral("CHealthStoneSimulator"));
        CHealthStoneSimulator->resize(457, 419);
        verticalLayout_2 = new QVBoxLayout(CHealthStoneSimulator);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(CHealthStoneSimulator);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditLevel = new QLineEdit(CHealthStoneSimulator);
        lineEditLevel->setObjectName(QStringLiteral("lineEditLevel"));
        lineEditLevel->setMaximumSize(QSize(80, 80));

        gridLayout->addWidget(lineEditLevel, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 7, 1, 1);

        lineEditRate = new QLineEdit(CHealthStoneSimulator);
        lineEditRate->setObjectName(QStringLiteral("lineEditRate"));
        lineEditRate->setMaximumSize(QSize(80, 80));

        gridLayout->addWidget(lineEditRate, 0, 1, 1, 1);

        label_8 = new QLabel(CHealthStoneSimulator);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 0, 5, 1, 1);

        label_3 = new QLabel(CHealthStoneSimulator);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        pushButtonOne = new QPushButton(CHealthStoneSimulator);
        pushButtonOne->setObjectName(QStringLiteral("pushButtonOne"));

        gridLayout->addWidget(pushButtonOne, 0, 8, 1, 1);

        lineEditStar = new QLineEdit(CHealthStoneSimulator);
        lineEditStar->setObjectName(QStringLiteral("lineEditStar"));
        lineEditStar->setMaximumSize(QSize(80, 80));

        gridLayout->addWidget(lineEditStar, 0, 6, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(CHealthStoneSimulator);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 1, 1, 1, 1);

        lineEditWin = new QLineEdit(groupBox);
        lineEditWin->setObjectName(QStringLiteral("lineEditWin"));
        lineEditWin->setReadOnly(true);

        gridLayout_3->addWidget(lineEditWin, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 7, 1, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_3->addWidget(label_11, 2, 1, 1, 1);

        lineEditTotal = new QLineEdit(groupBox);
        lineEditTotal->setObjectName(QStringLiteral("lineEditTotal"));
        lineEditTotal->setReadOnly(true);

        gridLayout_3->addWidget(lineEditTotal, 0, 2, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 3, 1, 1, 1);

        lineEditLose = new QLineEdit(groupBox);
        lineEditLose->setObjectName(QStringLiteral("lineEditLose"));
        lineEditLose->setReadOnly(true);

        gridLayout_3->addWidget(lineEditLose, 2, 2, 1, 1);

        lineEditContinue = new QLineEdit(groupBox);
        lineEditContinue->setObjectName(QStringLiteral("lineEditContinue"));
        lineEditContinue->setReadOnly(true);

        gridLayout_3->addWidget(lineEditContinue, 3, 2, 1, 1);

        lineEditCurLevel = new QLineEdit(groupBox);
        lineEditCurLevel->setObjectName(QStringLiteral("lineEditCurLevel"));
        lineEditCurLevel->setReadOnly(true);

        gridLayout_3->addWidget(lineEditCurLevel, 5, 2, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 0, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 5, 1, 1, 1);

        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_3->addWidget(label_17, 6, 1, 1, 1);

        lineEditCurStar = new QLineEdit(groupBox);
        lineEditCurStar->setObjectName(QStringLiteral("lineEditCurStar"));
        lineEditCurStar->setReadOnly(true);

        gridLayout_3->addWidget(lineEditCurStar, 6, 2, 1, 1);


        horizontalLayout->addWidget(groupBox);

        tableWidget = new QTableWidget(CHealthStoneSimulator);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        horizontalLayout->addWidget(tableWidget);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(CHealthStoneSimulator);

        QMetaObject::connectSlotsByName(CHealthStoneSimulator);
    } // setupUi

    void retranslateUi(QDialog *CHealthStoneSimulator)
    {
        CHealthStoneSimulator->setWindowTitle(QApplication::translate("CHealthStoneSimulator", "Dialog", nullptr));
        label->setText(QApplication::translate("CHealthStoneSimulator", "\350\203\234\347\216\207\357\274\232", nullptr));
        lineEditLevel->setText(QApplication::translate("CHealthStoneSimulator", "25", nullptr));
        lineEditRate->setText(QApplication::translate("CHealthStoneSimulator", "0.51", nullptr));
        label_8->setText(QApplication::translate("CHealthStoneSimulator", "\345\210\235\345\247\213\346\230\237\346\225\260\357\274\232", nullptr));
        label_3->setText(QApplication::translate("CHealthStoneSimulator", "\345\210\235\345\247\213\347\255\211\347\272\247\357\274\232", nullptr));
        pushButtonOne->setText(QApplication::translate("CHealthStoneSimulator", "\344\270\200\345\261\200", nullptr));
        lineEditStar->setText(QApplication::translate("CHealthStoneSimulator", "0", nullptr));
        groupBox->setTitle(QApplication::translate("CHealthStoneSimulator", "\344\277\241\346\201\257", nullptr));
        label_10->setText(QApplication::translate("CHealthStoneSimulator", "\350\216\267\350\203\234\346\254\241\346\225\260\357\274\232", nullptr));
        label_11->setText(QApplication::translate("CHealthStoneSimulator", "\345\244\261\350\264\245\346\254\241\346\225\260\357\274\232", nullptr));
        label_7->setText(QApplication::translate("CHealthStoneSimulator", "\350\277\236\350\203\234\345\234\272\346\254\241\357\274\232", nullptr));
        label_5->setText(QApplication::translate("CHealthStoneSimulator", "\346\270\270\346\210\217\346\254\241\346\225\260\357\274\232", nullptr));
        label_6->setText(QApplication::translate("CHealthStoneSimulator", "\345\275\223\345\211\215\347\255\211\347\272\247\357\274\232", nullptr));
        label_17->setText(QApplication::translate("CHealthStoneSimulator", "\345\275\223\345\211\215\346\230\237\346\225\260\357\274\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CHealthStoneSimulator", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CHealthStoneSimulator", "\350\203\234\350\264\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CHealthStoneSimulator: public Ui_CHealthStoneSimulator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEALTHSTONESIMULATOR_H
