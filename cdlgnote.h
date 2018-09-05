#ifndef CDLGNOTE_H
#define CDLGNOTE_H

#include <QWidget>
#include <QMap>
#include "globle.h"
#include <QtGui>
#include <QTableWidgetitem>
#include <QTreeWidgetItem>
#include "cdlgsearch.h"
namespace Ui {
class CDlgNote;
}



class CDlgNote : public QWidget
{
    Q_OBJECT

public:
    explicit CDlgNote(QWidget *parent = 0);
    ~CDlgNote();

    void initMap();
    void getList(uint uSelectMask =0,uint uOrderMask = 0  );
    void refreshList();
    void initCombox();


    void switchButton();
    bool isEdited();
    void save();
    void clearEditArea();
    void selectTableListItem(int iRow);
private slots:
    void on_tableList_itemClicked(QTableWidgetItem *item);

    void on_btSave_clicked();

    void on_lineEditTopic_cursorPositionChanged(int arg1, int arg2);

    void on_comboBoxType_currentIndexChanged(int index);

    void on_textEditContent_textChanged();

    void on_btNew_clicked();

    void on_btRemove_clicked();

    void on_btCancel_clicked();

    void on_btExport_clicked();

    void on_btSearch_clicked();

    void startFilter(uint uMask);

private:
    bool m_bResetFlag;
    int m_iCurrId;
    NOTE_TYPE_MAP m_mapTypeIdToTypeName;
    QList<NOTE_ITEM> m_lstNoteItem;

    CDlgSearch* m_pSearch;
private:
    Ui::CDlgNote *ui;
};

#endif // CDLGNOTE_H
