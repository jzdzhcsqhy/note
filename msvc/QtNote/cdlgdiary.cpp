#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif

#include "cdlgdiary.h"
#include "ui_cdlgdiary.h"
#include "globle.h"
#include "cdboperate.h"

extern CDbOperate gDb;

CDlgDiary::CDlgDiary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CDlgDiary)
{
    ui->setupUi(this);
    ui->tableList->setFocusPolicy(Qt::NoFocus);
    m_iCurrSeq = -1;
    m_bEditFlag = false;
    m_bResetFlag = true;

    m_bShowDataGroupbox = false;
    ui->groupBoxDate->hide();;
}

CDlgDiary::~CDlgDiary()
{
    delete ui;
}


void CDlgDiary::getList()
{
    m_lstDiary.clear();
    gDb.getDiaryByDate(ui->dateEditDate->dateTime(), ui->dateEditDate->dateTime(), m_lstDiary);
}

void CDlgDiary::setDate(QDateTime &dt)
{
    ui->dateEditDate->setDateTime(dt);
}

void CDlgDiary::selectTableListItem(int iRow)
{
    if( iRow > (int) ui->tableList->rowCount() )
    {
        return;
    }
    QTableWidgetItem* pItem = ui->tableList->item(iRow,0);
    if( pItem )
    {
        ui->tableList->selectRow(iRow);
        on_tableList_itemClicked(pItem);
    }
}

void CDlgDiary::refreshList()
{
    clearEditArea();
    ui->tableList->setRowCount(0);
    if( 0 == (int) m_lstDiary.size() )
    {
        m_iCurrSeq = -1;
        return ;
    }

    for( int i=0; i<(int) m_lstDiary.size(); i++ )
    {
        DIARY_ITEM tmp = m_lstDiary.at(i);
        ui->tableList->insertRow(i);
//        ui->tableList->setItem(i,0,new QTableWidgetItem(QString::number(tmp.iSeq)));
//        ui->tableList->item(i,0)->setData(Qt::UserRole+1,tmp.iSeq);
        ui->tableList->setItem(i,0,new QTableWidgetItem(tmp.sTopic) );
        ui->tableList->item(i,0)->setData(Qt::UserRole+1, tmp.iSeq);
        if( m_iCurrSeq == tmp.iSeq )
        {
            selectTableListItem(i);
        }
    }
    if( -1 == m_iCurrSeq )
    {
        selectTableListItem(0);
    }
    ui->tableList->resizeColumnsToContents();
    ui->tableList->horizontalHeader()->setStretchLastSection(true);
}

void CDlgDiary::on_tableList_itemClicked(QTableWidgetItem *item)
{
    if( !item )
    {
        return ;
    }
    int iNewSeq = item->data(Qt::UserRole+1).toInt();;
    if(isEdited() && !m_bResetFlag )
    {
        if( QMessageBox::Yes == SHOW_CONFIRM(tr("需要保存现有的修改吗？")))
        {
            save();
            getList();
            m_iCurrSeq = iNewSeq;
            refreshList();
        }
        else
        {
            m_iCurrSeq = iNewSeq;
        }
    }
    else
    {
        m_iCurrSeq = iNewSeq;
    }


    for( int i=0; i<(int) m_lstDiary.size(); i++ )
    {
        DIARY_ITEM tmp = m_lstDiary.at(i);
        if( tmp.iSeq == m_iCurrSeq )
        {
            ui->lineEditTopic->setText(tmp.sTopic);
            ui->textEditContent->setText(tmp.sContent);
            m_bResetFlag = false;
            switchButton();
        }
    }
}

void CDlgDiary::on_btNew_clicked()
{

    if( isEdited() )
    {
        SHOW_WARNING(tr("有正在编辑的修改，必须保存之后才能新建！"));
        return;
    }
    DIARY_ITEM in;
    in.dtDate = ui->dateEditDate->dateTime();

    if( !gDb.getMaxSeqForDate(in.dtDate, &in.iSeq ) )
    {
        return ;
    }
    in.iSeq ++;
    in.sTopic = tr("未填写");
    in.sContent = "";
    if( !gDb.addNewDiaryItem(in) )
    {
        return;
    }
    clearEditArea();
    getList();
    m_iCurrSeq = in.iSeq;
    refreshList();
}


void CDlgDiary::on_btRemove_clicked()
{
    DIARY_ITEM in;
    in.dtDate = ui->dateEditDate->dateTime();

    QTableWidgetItem* pItem = ui->tableList->currentItem();
    if( !pItem )
    {
        SHOW_WARNING(tr("请选择一条记录!"));
        return ;
    }
    if(QMessageBox::No == SHOW_CONFIRM(tr("确定要删除该记录吗？")) )
    {
        return ;
    }

    in.iSeq =pItem->data(Qt::UserRole+1).toInt();
    if( !gDb.removeDiaryItem(in) )
    {
        SHOW_ERROR(tr("删除记录失败"));
        return ;
    }
    m_iCurrSeq = -1;
    getList();
    refreshList();
}



void CDlgDiary::on_dateEditDate_dateChanged(const QDate &date)
{
    Q_UNUSED(date);
    m_iCurrSeq = -1;
    getList();
    refreshList();
}

void CDlgDiary::on_btCancel_clicked()
{
    if(QMessageBox::No == SHOW_CONFIRM(tr("确认恢复吗？此操作无法撤销！")))
    {
        return ;
    }
    QTableWidgetItem* pItem = ui->tableList->currentItem();
    if( !pItem )
    {
        SHOW_WARNING(tr("请选择一条记录!"));
        return ;
    }
    int iSeq = pItem->data(Qt::UserRole+1).toInt();
    for( int i=0; i<(int) m_lstDiary.size(); i++ )
    {
        DIARY_ITEM tmp = m_lstDiary.at(i);
        if( tmp.iSeq == iSeq )
        {
            ui->lineEditTopic->setText(tmp.sTopic);
            ui->textEditContent->setText(tmp.sContent);
        }
    }
}

void CDlgDiary::clearEditArea()
{
    ui->lineEditTopic->setText(tr("未填写"));
    ui->textEditContent->clear();
    m_bResetFlag = true;
}

void CDlgDiary::save()
{
    DIARY_ITEM in;
    in.dtDate = ui->dateEditDate->dateTime();

    in.iSeq = m_iCurrSeq;
    in.sTopic = ui->lineEditTopic->text();
    in.sContent ="";
    in.sContent.append(ui->textEditContent->toPlainText());
    if( !gDb.updateDiaryItem(in) )
    {
        SHOW_ERROR(tr("更新数据失败"));
        return ;
    }
    m_bEditFlag =false;
}

void CDlgDiary::switchButton()
{
    if(isEdited())
    {
//        ui->btSave->setDisabled(false);
//        ui->btCancel->setDisabled(false);
        ui->btSave->show();
        ui->btCancel->show();
    }
    else
    {
//        ui->btSave->setDisabled(true);
//        ui->btCancel->setDisabled(true);
        ui->btSave->hide();
        ui->btCancel->hide();
    }
}

void CDlgDiary::RefreshDataTree()
{
    QList<QDate> lstOut;
    gDb.getDateWhichHasRecord(lstOut);

    ui->treeDate->clear();

    int iYear = 0;
    int iMonth = 0;
    QTreeWidgetItem* pYear = 0;
    QTreeWidgetItem* pMonth = 0;
    QTreeWidgetItem* pDate = 0;

    for( QList<QDate>::iterator lit = lstOut.begin(); lit != lstOut.end(); lit ++ )
    {
        QDate dtNew = *lit;
        int iInsertYear = dtNew.year();
        int iInsertMonth = dtNew.month();
        int iInsertDay = dtNew.day();

        if(  iYear != iInsertYear )
        {
            pYear = new QTreeWidgetItem;
            pYear->setText(0,QString::number(iInsertYear) + "年");
            ui->treeDate->addTopLevelItem(pYear);
            iYear = iInsertYear;
        }
        if( iMonth != iInsertMonth )
        {
            pMonth = new QTreeWidgetItem;
            pMonth->setText(0,QString::number(iInsertMonth) + "月");
            pYear->addChild(pMonth);
            iMonth = iInsertMonth;
        }


        pDate = new QTreeWidgetItem;
        pDate->setText(0,QString::number(iInsertDay) + "日");
        pDate->setData(0,Qt::UserRole+1,QVariant(dtNew));
        pMonth->addChild(pDate);
    }
}

bool CDlgDiary::isEdited()
{
    if( -1 == m_iCurrSeq )
    {
        return false;
    }
    QString sTopic = ui->lineEditTopic->text();
    QString sContent ="";
    sContent.append(ui->textEditContent->toPlainText() );

    for( int i=0; i<(int)m_lstDiary.size(); i++ )
    {
        DIARY_ITEM tmp = m_lstDiary.at(i);
        if( tmp.iSeq == m_iCurrSeq )
        {
            if( sTopic == tmp.sTopic && sContent == tmp.sContent )
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}

void CDlgDiary::on_btSave_clicked()
{
    save();
    getList();
    refreshList();
}

void CDlgDiary::on_btPre_clicked()
{
    QDateTime dt = ui->dateEditDate->dateTime();
    ui->dateEditDate->setDateTime( dt.addDays(-1));
}

void CDlgDiary::on_btNext_clicked()
{
    QDateTime dt = ui->dateEditDate->dateTime();
    ui->dateEditDate->setDateTime( dt.addDays(1));
}

void CDlgDiary::on_lineEditTopic_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    switchButton();
}

void CDlgDiary::on_lineEditTopic_textEdited(const QString &arg1)
{
     Q_UNUSED(arg1);
     m_bEditFlag = true;
    switchButton();
}

void CDlgDiary::on_textEditContent_textChanged()
{
    switchButton();
}

void CDlgDiary::on_btToday_clicked()
{
    QDateTime dtToday = QDateTime::currentDateTime();
    ui->dateEditDate->setDateTime(dtToday);
}

void CDlgDiary::on_pushButton_clicked()
{
    m_bShowDataGroupbox = !m_bShowDataGroupbox;
    if( m_bShowDataGroupbox )
    {
        RefreshDataTree();
        ui->groupBoxDate->show();
    }
    else
    {
        ui->groupBoxDate->hide();
    }
}

void CDlgDiary::on_treeDate_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    Q_UNUSED(previous);
    if(!current )
    {
        return ;
    }
    QDate dtNew = current->data(0,Qt::UserRole+1).toDate();
    ui->dateEditDate->setDate( dtNew);
}
