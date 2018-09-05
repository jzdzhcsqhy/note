#include "cdlgnote.h"
#include "ui_cdlgnote.h"
#include "cdboperate.h"
#include <QFileDialog>

extern CDbOperate gDb;

CDlgNote::CDlgNote(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CDlgNote)
{
    ui->setupUi(this);


    m_pSearch= new CDlgSearch;

    m_pSearch->hide();
    connect(m_pSearch, SIGNAL(clickOk(uint)),this, SLOT(startFilter(uint)));

    m_iCurrId = -1;
    m_bResetFlag = true;

    initMap();
    initCombox();
    getList();
    refreshList();
}

CDlgNote::~CDlgNote()
{
    delete ui;
}

void CDlgNote::startFilter(uint uMask)
{
    getList(uMask);
    refreshList();
}

void CDlgNote::initMap()
{
    m_mapTypeIdToTypeName.clear();
    if( !gDb.getTypeMap(m_mapTypeIdToTypeName) )
    {
        SHOW_ERROR(tr("获得映射失败！"));
    }
}

void CDlgNote::initCombox()
{
    NOTE_TYPE_MAP::iterator mit;

    for(mit=m_mapTypeIdToTypeName.begin();
        mit!= m_mapTypeIdToTypeName.end();
        mit++ )
    {
        ui->comboBoxType->addItem(mit.value(),mit.key());
    }
}

bool CDlgNote::isEdited()
{
    for( int i=0; i<(int)m_lstNoteItem.size(); i++ )
    {
        NOTE_ITEM tmp = m_lstNoteItem.at(i);
        if( m_iCurrId == tmp.iId )
        {
            QString sTopic = ui->lineEditTopic->text();
            QString sContent = QString("").append( ui->textEditContent->toPlainText());
            int iType = ui->comboBoxType->itemData(ui->comboBoxType->currentIndex()).toInt();
            if( sTopic == tmp.sTopic && sContent == tmp.sContent && iType == tmp.iType )
            {
                return false;
            }

        }
    }
    return true;
}

void CDlgNote::clearEditArea()
{
    ui->lineEditTopic->setText(tr("未填写"));
    ui->textEditContent->clear();
    ui->comboBoxType->setCurrentIndex(-1);
    m_bResetFlag = true;
}

void CDlgNote::switchButton()
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

void CDlgNote::getList(uint uSelectMask ,uint uOrderMask )
{
    m_lstNoteItem.clear();
    QDateTime dtBegin;
    QDateTime dtEnd;
    QString sKeyWord;
    int iType = 0;

    if( uSelectMask )
    {
        if( !m_pSearch )
        {
            return ;
        }

        dtBegin = m_pSearch->getDateStart();
        dtEnd = m_pSearch->getDateEnd();
        iType = m_pSearch->getType();
        sKeyWord = m_pSearch->getKeyWord();
    }


    if( !gDb.getNote(m_lstNoteItem,uSelectMask,uOrderMask,dtBegin,dtEnd,iType,sKeyWord) )
    {
        SHOW_ERROR(tr("获得笔记失败！"));
        return ;
    }
}

void CDlgNote::refreshList()
{
    ui->tableList->setRowCount(0);;
    clearEditArea();
    for( int i=0; i<(int)m_lstNoteItem.size(); i++ )
    {
        NOTE_ITEM tmp = m_lstNoteItem.at(i);

        ui->tableList->insertRow(i);
        ui->tableList->setItem(i,0, new QTableWidgetItem(tmp.sTopic));
        ui->tableList->item(i,0)->setData(Qt::UserRole+1,tmp.iId );

        QString sType = m_mapTypeIdToTypeName[tmp.iType];
        if( sType.isNull() || sType.isEmpty() )
        {
            sType = tr("未分类");
        }
        ui->tableList->setItem(i,1,new QTableWidgetItem(sType));
        ui->tableList->item(i,1)->setData(Qt::UserRole+2,tmp.iType);

        ui->tableList->setItem(i,2,new QTableWidgetItem(tmp.dtCreate.toString(DATE_TIME_FORMAT)));
        ui->tableList->setItem(i,3,new QTableWidgetItem(tmp.dtUpdate.toString(DATE_TIME_FORMAT)));
        if( tmp.iId == m_iCurrId )
        {
            selectTableListItem(i);
        }
    }
    if( -1 == m_iCurrId )
    {
        selectTableListItem(0);
    }
    ui->tableList->resizeColumnsToContents();
    ui->tableList->horizontalHeader()->setStretchLastSection(true);

}
void CDlgNote::save()
{
    NOTE_ITEM in;
    in.iId = m_iCurrId;
    in.dtCreate = QDateTime::fromString(ui->labelCreateTime->text(),DATE_TIME_FORMAT);
    in.dtUpdate = QDateTime::currentDateTime();

    in.iType = ui->comboBoxType->itemData(ui->comboBoxType->currentIndex()).toInt();
    in.sTopic = ui->lineEditTopic->text();
    in.sContent ="";
    in.sContent.append(ui->textEditContent->toPlainText());
    if( !gDb.updateNoteItem(in) )
    {
        SHOW_ERROR(tr("更新数据失败"));
        return ;
    }


}

void CDlgNote::on_tableList_itemClicked(QTableWidgetItem *item)
{


    if( !item )
    {
        return ;
    }
    int iNewId = ui->tableList->item(item->row(),0)->data(Qt::UserRole+1).toInt();

    if(isEdited() && !m_bResetFlag )
    {
        if( QMessageBox::Yes == SHOW_CONFIRM(tr("需要保存现有的修改吗？")))
        {
            save();
            getList();
            m_iCurrId= iNewId;
            refreshList();
        }
        else
        {
            m_iCurrId= iNewId;
        }
    }
    else
    {
         m_iCurrId= iNewId;
    }





    for( int i=0; i<(int)m_lstNoteItem.size(); i++ )
    {
        NOTE_ITEM tmp = m_lstNoteItem.at(i);
        if( tmp.iId == iNewId )
        {
            ui->lineEditTopic->setText(tmp.sTopic);
            ui->labelCreateTime->setText(tmp.dtCreate.toString(DATE_TIME_FORMAT));
            ui->labelUpdateTime->setText(tmp.dtUpdate.toString(DATE_TIME_FORMAT));
            ui->textEditContent->setText(tmp.sContent);
            for( int i=0; i<ui->comboBoxType->count(); i++ )
            {
                int iType = ui->comboBoxType->itemData(i).toInt();
                if( iType == tmp.iType )
                {
                    ui->comboBoxType->setCurrentIndex(i);
                }
            }
            switchButton();
        }
    }
}
void CDlgNote::selectTableListItem(int iRow)
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

void CDlgNote::on_btSave_clicked()
{
    save();
    getList();
    refreshList();
}

void CDlgNote::on_lineEditTopic_cursorPositionChanged(int arg1, int arg2)
{
    Q_UNUSED(arg1);
    Q_UNUSED(arg2);
    m_bResetFlag =false;
    switchButton();
}

void CDlgNote::on_comboBoxType_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    m_bResetFlag = false;
    switchButton();
}

void CDlgNote::on_textEditContent_textChanged()
{
    m_bResetFlag = false;
    switchButton();
}

void CDlgNote::on_btNew_clicked()
{
    NOTE_ITEM in;
    if(!gDb.getMaxIdForNote(&in.iId) )
    {
        SHOW_ERROR(tr("获得ID失败"));
        return;
    }
    in.iId ++;
    in.sTopic =tr("未填写");
    in.iType = 0;
    in.sContent = tr("");
    in.dtCreate = QDateTime::currentDateTime();
    in.dtUpdate = QDateTime::currentDateTime();
    if( !gDb.addNewNoteItem(in) )
    {
        SHOW_ERROR(tr("新增记录失败！"));
        return;
    }
    m_iCurrId = in.iId;
    getList();
    refreshList();
}

void CDlgNote::on_btRemove_clicked()
{
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

    NOTE_ITEM in;
    in.iId = m_iCurrId;
    if( !gDb.removeNoteItem(in) )
    {
        SHOW_ERROR(tr("删除记录失败"));
        return ;
    }
    m_iCurrId = -1;
    getList();
    refreshList();
}

void CDlgNote::on_btCancel_clicked()
{
    if(QMessageBox::No == SHOW_CONFIRM(tr("确认恢复吗？此操作无法撤销！")))
    {
        return ;
    }

    for( int i=0; i<(int) m_lstNoteItem.size(); i++ )
    {
        NOTE_ITEM tmp = m_lstNoteItem.at(i);
        if( tmp.iId == m_iCurrId )
        {
            ui->lineEditTopic->setText(tmp.sTopic);
            ui->textEditContent->setText(tmp.sContent);
            for( int i=0; i<ui->comboBoxType->count(); i++ )
            {
                int iType = ui->comboBoxType->itemData(i).toInt();
                if( iType == tmp.iType )
                {
                    ui->comboBoxType->setCurrentIndex(i);
                }
            }
            switchButton();
        }
    }
}

void CDlgNote::on_btExport_clicked()
{
    QString sPath = QFileDialog::getSaveFileName(this,tr("选择保存位置"),".",tr("Text file(*.txt)"));
    QFile fileSave(sPath);
    fileSave.open(QIODevice::WriteOnly);
    if( !fileSave.isOpen() )
    {
        return ;
    }

    fileSave.write(tr("标题:").toStdString().c_str());
    fileSave.write(ui->lineEditTopic->text().toStdString().c_str());
    fileSave.write("\n");

    fileSave.write(tr("分类:").toStdString().c_str());
    fileSave.write(ui->comboBoxType->currentText().toStdString().c_str());
    fileSave.write("\n");

    fileSave.write(tr("======================================正文======================================\r\n").toStdString().c_str());
    fileSave.write(ui->textEditContent->toPlainText().toStdString().c_str());

}

void CDlgNote::on_btSearch_clicked()
{
    m_pSearch->show();
}
