/********************************************************************************
** Form generated from reading UI file 'cdlgdiary.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CDLGDIARY_H
#define UI_CDLGDIARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CDlgDiary
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QFrame *line;
    QPushButton *btPre;
    QDateEdit *dateEditDate;
    QPushButton *btNext;
    QPushButton *btToday;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBoxDate;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QTreeWidget *treeDate;
    QGroupBox *groupBoxList;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btNew;
    QPushButton *btRemove;
    QTableWidget *tableList;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEditTopic;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btSave;
    QPushButton *btCancel;
    QTextEdit *textEditContent;

    void setupUi(QDialog *CDlgDiary)
    {
        if (CDlgDiary->objectName().isEmpty())
            CDlgDiary->setObjectName(QStringLiteral("CDlgDiary"));
        CDlgDiary->resize(579, 609);
        QPalette palette;
        QBrush brush(QColor(51, 153, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush);
        CDlgDiary->setPalette(palette);
        verticalLayout = new QVBoxLayout(CDlgDiary);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(CDlgDiary);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(25, 25));

        horizontalLayout->addWidget(pushButton);

        line = new QFrame(CDlgDiary);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        btPre = new QPushButton(CDlgDiary);
        btPre->setObjectName(QStringLiteral("btPre"));
        btPre->setMaximumSize(QSize(25, 25));

        horizontalLayout->addWidget(btPre);

        dateEditDate = new QDateEdit(CDlgDiary);
        dateEditDate->setObjectName(QStringLiteral("dateEditDate"));
        dateEditDate->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEditDate);

        btNext = new QPushButton(CDlgDiary);
        btNext->setObjectName(QStringLiteral("btNext"));
        btNext->setMaximumSize(QSize(25, 25));

        horizontalLayout->addWidget(btNext);

        btToday = new QPushButton(CDlgDiary);
        btToday->setObjectName(QStringLiteral("btToday"));

        horizontalLayout->addWidget(btToday);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBoxDate = new QGroupBox(CDlgDiary);
        groupBoxDate->setObjectName(QStringLiteral("groupBoxDate"));
        groupBoxDate->setMaximumSize(QSize(200, 16777215));
        groupBoxDate->setStyleSheet(QLatin1String("QGroupBox#groupBoxDate\n"
"{\n"
"	border:1px solid gray;\n"
"	border-radius:10px;\n"
"	background-color: rgb(209, 200, 245);\n"
"}\n"
""));
        verticalLayout_4 = new QVBoxLayout(groupBoxDate);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_4 = new QLabel(groupBoxDate);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        label_4->setFont(font);

        horizontalLayout_7->addWidget(label_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout_7);

        treeDate = new QTreeWidget(groupBoxDate);
        treeDate->setObjectName(QStringLiteral("treeDate"));
        QFont font1;
        font1.setPointSize(9);
        treeDate->setFont(font1);
        treeDate->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeDate->header()->setVisible(false);

        verticalLayout_4->addWidget(treeDate);


        horizontalLayout_2->addWidget(groupBoxDate);

        groupBoxList = new QGroupBox(CDlgDiary);
        groupBoxList->setObjectName(QStringLiteral("groupBoxList"));
        groupBoxList->setMaximumSize(QSize(220, 16777215));
        groupBoxList->setStyleSheet(QLatin1String("QGroupBox#groupBoxList\n"
"{\n"
"	border:1px solid gray;\n"
"	border-radius:10px;\n"
"	background-color: rgb(209, 247, 245);\n"
"}\n"
""));
        verticalLayout_3 = new QVBoxLayout(groupBoxList);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(groupBoxList);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_5->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        btNew = new QPushButton(groupBoxList);
        btNew->setObjectName(QStringLiteral("btNew"));
        btNew->setMaximumSize(QSize(25, 25));
        btNew->setStyleSheet(QLatin1String("QPushButton#btNew\n"
"{\n"
"	border-image: url(:/img/resource/add.png);\n"
"}\n"
"QPushButton#btNew:hover\n"
"{\n"
"	border-image: url(:/img/resource/add-hover.png);\n"
"}\n"
"QPushButton#btNew:pressed\n"
"{\n"
"	border-image: url(:/img/resource/add-click.png);\n"
"}\n"
"\n"
""));

        horizontalLayout_5->addWidget(btNew);

        btRemove = new QPushButton(groupBoxList);
        btRemove->setObjectName(QStringLiteral("btRemove"));
        btRemove->setMaximumSize(QSize(25, 25));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush);
        btRemove->setPalette(palette1);
        btRemove->setStyleSheet(QLatin1String("QPushButton#btRemove\n"
"{\n"
"	border-image: url(:/img/resource/remove.png);\n"
"}\n"
"QPushButton#btRemove:hover\n"
"{\n"
"	border-image: url(:/img/resource/remove-hover.png);\n"
"}\n"
"QPushButton#btRemove:pressed\n"
"{\n"
"	border-image: url(:/img/resource/remove-click.png);\n"
"}\n"
"\n"
""));

        horizontalLayout_5->addWidget(btRemove);


        verticalLayout_3->addLayout(horizontalLayout_5);

        tableList = new QTableWidget(groupBoxList);
        if (tableList->columnCount() < 1)
            tableList->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableList->setObjectName(QStringLiteral("tableList"));
        tableList->setMaximumSize(QSize(200, 16777215));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Highlight, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::HighlightedText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Highlight, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush1);
        tableList->setPalette(palette2);
        tableList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableList->setSelectionMode(QAbstractItemView::SingleSelection);
        tableList->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableList->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_3->addWidget(tableList);


        horizontalLayout_2->addWidget(groupBoxList);

        groupBox = new QGroupBox(CDlgDiary);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QLatin1String("QGroupBox#groupBox\n"
"{\n"
"	border:1px solid gray;\n"
"	border-radius:10px;\n"
"	background-color: rgb(218, 218, 218);\n"
"}\n"
""));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        lineEditTopic = new QLineEdit(groupBox);
        lineEditTopic->setObjectName(QStringLiteral("lineEditTopic"));

        horizontalLayout_3->addWidget(lineEditTopic);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        btSave = new QPushButton(groupBox);
        btSave->setObjectName(QStringLiteral("btSave"));
        btSave->setMinimumSize(QSize(25, 25));
        btSave->setMaximumSize(QSize(25, 25));
        btSave->setStyleSheet(QLatin1String("QPushButton#btSave\n"
"{\n"
"	border-image: url(:/img/resource/save.png);\n"
"}\n"
"QPushButton#btSave:hover\n"
"{\n"
"	border-image: url(:/img/resource/save-hover.png);\n"
"}\n"
"QPushButton#btSave:pressed\n"
"{\n"
"	border-image: url(:/img/resource/save-click.png);\n"
"}\n"
"\n"
""));

        horizontalLayout_6->addWidget(btSave);

        btCancel = new QPushButton(groupBox);
        btCancel->setObjectName(QStringLiteral("btCancel"));
        btCancel->setMinimumSize(QSize(25, 25));
        btCancel->setMaximumSize(QSize(25, 25));
        btCancel->setStyleSheet(QLatin1String("QPushButton#btCancel\n"
"{\n"
"	border-image: url(:/img/resource/refresh.png);\n"
"}\n"
"QPushButton#btCancel:hover\n"
"{\n"
"	border-image: url(:/img/resource/refresh-hover.png);\n"
"}\n"
"QPushButton#btCancel:pressed\n"
"{\n"
"	border-image: url(:/img/resource/refresh-click.png);\n"
"}\n"
"\n"
""));

        horizontalLayout_6->addWidget(btCancel);


        verticalLayout_2->addLayout(horizontalLayout_6);

        textEditContent = new QTextEdit(groupBox);
        textEditContent->setObjectName(QStringLiteral("textEditContent"));

        verticalLayout_2->addWidget(textEditContent);


        horizontalLayout_2->addWidget(groupBox);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(CDlgDiary);

        QMetaObject::connectSlotsByName(CDlgDiary);
    } // setupUi

    void retranslateUi(QDialog *CDlgDiary)
    {
        CDlgDiary->setWindowTitle(QApplication::translate("CDlgDiary", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("CDlgDiary", "\342\212\231", nullptr));
        btPre->setText(QApplication::translate("CDlgDiary", "<", nullptr));
        btNext->setText(QApplication::translate("CDlgDiary", ">", nullptr));
        btToday->setText(QApplication::translate("CDlgDiary", "\344\273\212\345\244\251", nullptr));
        groupBoxDate->setTitle(QString());
        label_4->setText(QApplication::translate("CDlgDiary", "\346\227\245\346\234\237", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeDate->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("CDlgDiary", "\346\227\245\346\234\237", nullptr));
        groupBoxList->setTitle(QString());
        label_2->setText(QApplication::translate("CDlgDiary", "\345\210\227\350\241\250", nullptr));
        btNew->setText(QString());
        btRemove->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CDlgDiary", "\344\270\273\351\242\230", nullptr));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("CDlgDiary", "\344\270\273\351\242\230\357\274\232", nullptr));
        label_3->setText(QApplication::translate("CDlgDiary", "\345\206\205\345\256\271\357\274\232", nullptr));
        btSave->setText(QString());
        btCancel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CDlgDiary: public Ui_CDlgDiary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CDLGDIARY_H
