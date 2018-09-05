#ifndef CDLGDIARY_H
#define CDLGDIARY_H

#include <QDialog>
#include "datastruct.h"
#include <QtGui>
namespace Ui {
class CDlgDiary;
}

class CDlgDiary : public QDialog
{
    Q_OBJECT

public:
    explicit CDlgDiary(QWidget *parent = 0);
    ~CDlgDiary();

    void getList();
    void refreshList();

    void setDate( QDateTime& dt);
    void selectTableListItem(int iRow );
    void save();
    void clearEditArea();
    bool isEdited();
    void switchButton();

    void RefreshDataTree();
private slots:
    void on_tableList_itemClicked(QTableWidgetItem *item);

    void on_btNew_clicked();

    void on_btRemove_clicked();

    void on_dateEditDate_dateChanged(const QDate &date);

    void on_btCancel_clicked();

    void on_btSave_clicked();

    void on_btPre_clicked();

    void on_btNext_clicked();

    void on_lineEditTopic_textChanged(const QString &arg1);


    void on_lineEditTopic_textEdited(const QString &arg1);

    void on_textEditContent_textChanged();

    void on_btToday_clicked();

    void on_pushButton_clicked();

    void on_treeDate_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

private:
    bool m_bEditFlag;
    bool m_bResetFlag;
    bool m_bShowDataGroupbox;
    QList<DIARY_ITEM>   m_lstDiary;
    int     m_iCurrSeq;
private:
    Ui::CDlgDiary *ui;
};

#endif // CDLGDIARY_H
