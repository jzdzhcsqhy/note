/********************************************************************************
** Form generated from reading UI file 'cdlgnote.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CDLGNOTE_H
#define UI_CDLGNOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CDlgNote
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBoxList;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btNew;
    QPushButton *btRemove;
    QPushButton *btSearch;
    QTableWidget *tableList;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEditTopic;
    QLabel *label_4;
    QComboBox *comboBoxType;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *labelCreateTime;
    QSpacerItem *horizontalSpacer;
    QLabel *label_5;
    QLabel *labelUpdateTime;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btSave;
    QPushButton *btCancel;
    QPushButton *btExport;
    QTextEdit *textEditContent;

    void setupUi(QWidget *CDlgNote)
    {
        if (CDlgNote->objectName().isEmpty())
            CDlgNote->setObjectName(QStringLiteral("CDlgNote"));
        CDlgNote->resize(824, 668);
        verticalLayout = new QVBoxLayout(CDlgNote);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBoxList = new QGroupBox(CDlgNote);
        groupBoxList->setObjectName(QStringLiteral("groupBoxList"));
        groupBoxList->setMinimumSize(QSize(450, 0));
        groupBoxList->setMaximumSize(QSize(850, 16777215));
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
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
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
        QPalette palette;
        QBrush brush(QColor(51, 153, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush);
        btRemove->setPalette(palette);
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

        btSearch = new QPushButton(groupBoxList);
        btSearch->setObjectName(QStringLiteral("btSearch"));
        btSearch->setMaximumSize(QSize(25, 25));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush);
        btSearch->setPalette(palette1);
        btSearch->setStyleSheet(QLatin1String("QPushButton#btRemove\n"
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

        horizontalLayout_5->addWidget(btSearch);


        verticalLayout_3->addLayout(horizontalLayout_5);

        tableList = new QTableWidget(groupBoxList);
        if (tableList->columnCount() < 4)
            tableList->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableList->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableList->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableList->setObjectName(QStringLiteral("tableList"));
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

        groupBox = new QGroupBox(CDlgNote);
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

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        comboBoxType = new QComboBox(groupBox);
        comboBoxType->setObjectName(QStringLiteral("comboBoxType"));

        horizontalLayout_3->addWidget(comboBoxType);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        labelCreateTime = new QLabel(groupBox);
        labelCreateTime->setObjectName(QStringLiteral("labelCreateTime"));

        horizontalLayout->addWidget(labelCreateTime);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        labelUpdateTime = new QLabel(groupBox);
        labelUpdateTime->setObjectName(QStringLiteral("labelUpdateTime"));

        horizontalLayout->addWidget(labelUpdateTime);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

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

        btExport = new QPushButton(groupBox);
        btExport->setObjectName(QStringLiteral("btExport"));
        btExport->setMinimumSize(QSize(25, 25));
        btExport->setMaximumSize(QSize(25, 25));
        btExport->setStyleSheet(QLatin1String("QPushButton#btExport\n"
"{\n"
"	border-image: url(:/img/resource/export.png);\n"
"}\n"
"QPushButton#btExport:hover\n"
"{\n"
"	border-image: url(:/img/resource/export-hover.png);\n"
"}\n"
"QPushButton#btExport:pressed\n"
"{\n"
"	border-image: url(:/img/resource/export-click.png);\n"
"}\n"
"\n"
""));

        horizontalLayout_6->addWidget(btExport);


        verticalLayout_2->addLayout(horizontalLayout_6);

        textEditContent = new QTextEdit(groupBox);
        textEditContent->setObjectName(QStringLiteral("textEditContent"));

        verticalLayout_2->addWidget(textEditContent);


        horizontalLayout_2->addWidget(groupBox);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(CDlgNote);

        QMetaObject::connectSlotsByName(CDlgNote);
    } // setupUi

    void retranslateUi(QWidget *CDlgNote)
    {
        CDlgNote->setWindowTitle(QApplication::translate("CDlgNote", "Form", nullptr));
        groupBoxList->setTitle(QString());
        label_2->setText(QApplication::translate("CDlgNote", "\345\210\227\350\241\250", nullptr));
        btNew->setText(QString());
        btRemove->setText(QString());
        btSearch->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CDlgNote", "\344\270\273\351\242\230", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CDlgNote", "\345\210\206\347\261\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableList->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("CDlgNote", "\345\210\233\345\273\272\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableList->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("CDlgNote", "\344\277\256\346\224\271\346\227\266\351\227\264", nullptr));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("CDlgNote", "\344\270\273\351\242\230\357\274\232", nullptr));
        label_4->setText(QApplication::translate("CDlgNote", "\345\210\206\347\261\273\357\274\232", nullptr));
        label_3->setText(QApplication::translate("CDlgNote", "\345\210\233\345\273\272\346\227\266\351\227\264\357\274\232", nullptr));
        labelCreateTime->setText(QApplication::translate("CDlgNote", "TextLabel", nullptr));
        label_5->setText(QApplication::translate("CDlgNote", "\344\277\256\346\224\271\346\227\266\351\227\264\357\274\232", nullptr));
        labelUpdateTime->setText(QApplication::translate("CDlgNote", "TextLabel", nullptr));
        label_6->setText(QApplication::translate("CDlgNote", "\345\206\205\345\256\271\357\274\232", nullptr));
#ifndef QT_NO_TOOLTIP
        btSave->setToolTip(QApplication::translate("CDlgNote", "\344\277\235\345\255\230", nullptr));
#endif // QT_NO_TOOLTIP
        btSave->setText(QString());
#ifndef QT_NO_TOOLTIP
        btCancel->setToolTip(QApplication::translate("CDlgNote", "\346\201\242\345\244\215", nullptr));
#endif // QT_NO_TOOLTIP
        btCancel->setText(QString());
#ifndef QT_NO_TOOLTIP
        btExport->setToolTip(QApplication::translate("CDlgNote", "\345\257\274\345\207\272\345\210\260\346\226\207\346\234\254", nullptr));
#endif // QT_NO_TOOLTIP
        btExport->setText(QApplication::translate("CDlgNote", "^", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CDlgNote: public Ui_CDlgNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CDLGNOTE_H
