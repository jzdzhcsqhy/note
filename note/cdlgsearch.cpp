#include "cdlgsearch.h"
#include "ui_cdlgsearch.h"
#include "cdboperate.h"

extern CDbOperate gDb;
CDlgSearch::CDlgSearch(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::CDlgSearch)
{
    ui->setupUi(this);
    initCombox();
    ui->dtStart->setDate(QDate::currentDate());
    ui->dtEnd->setDate(QDate::currentDate());
}

CDlgSearch::~CDlgSearch()
{
    delete ui;
}

void CDlgSearch::makeMask()
{
    m_uMask = 0;
    if( ui->groupBoxTime->isChecked() )
    {
        m_uMask |= SELECT_BY_DATE;
    }
    if( ui->groupBoxClassfy->isChecked() )
    {
        m_uMask |= SELECT_BY_TYPE;
    }
    if( ui->groupBoxKeyword->isChecked() )
    {
        if( ui->checkBoxTopic->isChecked() )
        {
            m_uMask|= SELECT_BY_KEYWORD_TOPIC;
        }
        if( ui->checkBoxContent->isChecked() )
        {
            m_uMask|=SELECT_BY_KEYWORD_CONTENT;
        }
    }
}

void CDlgSearch::initCombox()
{
    QMap<int, QString> mapType;
    mapType.clear();
    if( !gDb.getTypeMap(mapType) )
    {
        SHOW_ERROR(tr("获得映射失败！"));
    }
    QMap<int, QString>::iterator mit;

    for(mit=mapType.begin();
        mit!= mapType.end();
        mit++ )
    {
        ui->comboBoxType->addItem(mit.value(),mit.key());
    }

}

int CDlgSearch::getType()
{
    int iType = ui->comboBoxType->itemData(ui->comboBoxType->currentIndex()).toInt();
    return iType;
}

QString CDlgSearch::getKeyWord()
{
    return ui->lineEditKeyword->text();
}

QDateTime CDlgSearch::getDateStart()
{
    return ui->dtStart->dateTime();
}

QDateTime CDlgSearch::getDateEnd()
{
    return ui->dtEnd->dateTime();
}

void CDlgSearch::on_btOk_clicked()
{
    makeMask();
    emit clickOk(m_uMask);
    this->hide();
}
