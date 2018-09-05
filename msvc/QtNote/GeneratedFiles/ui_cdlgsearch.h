/********************************************************************************
** Form generated from reading UI file 'cdlgsearch.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CDLGSEARCH_H
#define UI_CDLGSEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CDlgSearch
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBoxTime;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QDateEdit *dtStart;
    QDateEdit *dtEnd;
    QLabel *label;
    QGroupBox *groupBoxKeyword;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBoxTopic;
    QCheckBox *checkBoxContent;
    QLineEdit *lineEditKeyword;
    QGroupBox *groupBoxClassfy;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QComboBox *comboBoxType;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *btOk;
    QPushButton *btCancel;

    void setupUi(QWidget *CDlgSearch)
    {
        if (CDlgSearch->objectName().isEmpty())
            CDlgSearch->setObjectName(QStringLiteral("CDlgSearch"));
        CDlgSearch->resize(283, 303);
        gridLayout = new QGridLayout(CDlgSearch);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBoxTime = new QGroupBox(CDlgSearch);
        groupBoxTime->setObjectName(QStringLiteral("groupBoxTime"));
        groupBoxTime->setCheckable(true);
        groupBoxTime->setChecked(false);
        gridLayout_2 = new QGridLayout(groupBoxTime);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(groupBoxTime);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        dtStart = new QDateEdit(groupBoxTime);
        dtStart->setObjectName(QStringLiteral("dtStart"));

        gridLayout_2->addWidget(dtStart, 0, 1, 1, 1);

        dtEnd = new QDateEdit(groupBoxTime);
        dtEnd->setObjectName(QStringLiteral("dtEnd"));

        gridLayout_2->addWidget(dtEnd, 2, 1, 1, 1);

        label = new QLabel(groupBoxTime);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        gridLayout_2->setColumnStretch(1, 1);

        gridLayout->addWidget(groupBoxTime, 2, 0, 1, 1);

        groupBoxKeyword = new QGroupBox(CDlgSearch);
        groupBoxKeyword->setObjectName(QStringLiteral("groupBoxKeyword"));
        groupBoxKeyword->setCheckable(true);
        groupBoxKeyword->setChecked(false);
        verticalLayout_2 = new QVBoxLayout(groupBoxKeyword);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_4 = new QLabel(groupBoxKeyword);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBoxTopic = new QCheckBox(groupBoxKeyword);
        checkBoxTopic->setObjectName(QStringLiteral("checkBoxTopic"));
        checkBoxTopic->setChecked(true);

        horizontalLayout->addWidget(checkBoxTopic);

        checkBoxContent = new QCheckBox(groupBoxKeyword);
        checkBoxContent->setObjectName(QStringLiteral("checkBoxContent"));
        checkBoxContent->setChecked(true);

        horizontalLayout->addWidget(checkBoxContent);


        verticalLayout_2->addLayout(horizontalLayout);

        lineEditKeyword = new QLineEdit(groupBoxKeyword);
        lineEditKeyword->setObjectName(QStringLiteral("lineEditKeyword"));

        verticalLayout_2->addWidget(lineEditKeyword);


        gridLayout->addWidget(groupBoxKeyword, 4, 0, 1, 1);

        groupBoxClassfy = new QGroupBox(CDlgSearch);
        groupBoxClassfy->setObjectName(QStringLiteral("groupBoxClassfy"));
        groupBoxClassfy->setCheckable(true);
        groupBoxClassfy->setChecked(false);
        verticalLayout = new QVBoxLayout(groupBoxClassfy);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(groupBoxClassfy);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        comboBoxType = new QComboBox(groupBoxClassfy);
        comboBoxType->setObjectName(QStringLiteral("comboBoxType"));

        verticalLayout->addWidget(comboBoxType);


        gridLayout->addWidget(groupBoxClassfy, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btOk = new QPushButton(CDlgSearch);
        btOk->setObjectName(QStringLiteral("btOk"));

        horizontalLayout_3->addWidget(btOk);

        btCancel = new QPushButton(CDlgSearch);
        btCancel->setObjectName(QStringLiteral("btCancel"));

        horizontalLayout_3->addWidget(btCancel);


        gridLayout->addLayout(horizontalLayout_3, 5, 0, 1, 1);


        retranslateUi(CDlgSearch);

        QMetaObject::connectSlotsByName(CDlgSearch);
    } // setupUi

    void retranslateUi(QWidget *CDlgSearch)
    {
        CDlgSearch->setWindowTitle(QApplication::translate("CDlgSearch", "\347\255\233\351\200\211", nullptr));
        groupBoxTime->setTitle(QApplication::translate("CDlgSearch", "\346\227\266\351\227\264", nullptr));
        label_2->setText(QApplication::translate("CDlgSearch", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", nullptr));
        label->setText(QApplication::translate("CDlgSearch", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", nullptr));
        groupBoxKeyword->setTitle(QApplication::translate("CDlgSearch", "\345\205\263\351\224\256\345\255\227", nullptr));
        label_4->setText(QApplication::translate("CDlgSearch", "\350\257\267\350\276\223\345\205\245\350\246\201\346\237\245\346\211\276\347\232\204\345\205\263\351\224\256\345\255\227\357\274\232", nullptr));
        checkBoxTopic->setText(QApplication::translate("CDlgSearch", "\344\270\273\351\242\230", nullptr));
        checkBoxContent->setText(QApplication::translate("CDlgSearch", "\345\206\205\345\256\271", nullptr));
        groupBoxClassfy->setTitle(QApplication::translate("CDlgSearch", "\345\210\206\347\261\273", nullptr));
        label_3->setText(QApplication::translate("CDlgSearch", "\350\257\267\351\200\211\346\213\251\344\270\200\344\270\252\345\210\206\347\261\273\357\274\232", nullptr));
        btOk->setText(QApplication::translate("CDlgSearch", "\347\241\256\345\256\232", nullptr));
        btCancel->setText(QApplication::translate("CDlgSearch", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CDlgSearch: public Ui_CDlgSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CDLGSEARCH_H
