#include "HealthStoneSimulator.h"
#include "ui_HealthStoneSimulator.h"
#include <QTime>
#include <QMessageBox>

CHealthStoneSimulator::CHealthStoneSimulator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CHealthStoneSimulator)
{
    ui->setupUi(this);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    reset();
}

CHealthStoneSimulator::~CHealthStoneSimulator()
{
    delete ui;
}

bool CHealthStoneSimulator::playAGame()
{
    const int ciBase = 10000;
    int dRate = ui->lineEditRate->text().toDouble()*ciBase ;

    int iRs = qrand()%ciBase;
    if( iRs < dRate )
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool CHealthStoneSimulator::reset()
{
    //复位界面
    ui->lineEditCurLevel->setText(ui->lineEditLevel->text());

    ui->lineEditTotal->setText(tr("0"));
    ui->lineEditWin->setText(tr("0"));
    ui->lineEditLose->setText(tr("0"));

    ui->lineEditCurLevel->setText(ui->lineEditLevel->text());
    ui->lineEditCurStar->setText(ui->lineEditStar->text());

    ui->lineEditContinue->setText(tr("0"));

     //复位数据
    int iLevel = ui->lineEditLevel->text().toInt();
    int iStar = ui->lineEditCurStar->text().toInt();
    m_iCurStarts = getAllStars(iLevel, iStar);
    m_iTotal = 0;
    m_iWin = 0;
    m_iLose = 0;
    m_iStreak = 0;
    return true;
}

bool CHealthStoneSimulator::getLevel(int iAllStars, int &iLevel, int &iStar)
{


    int iLeft = 125 -iAllStars;

    iLevel = iLeft /5 +1;
    iStar = 5 - iLeft%5;

    if( !( iLeft % 5) )
    {
        if( !m_bThisGame )
        {
            iLevel --;
            iStar = 0;
        }
    }

    return true;
}

int CHealthStoneSimulator::getAllStars(int iLevel, int iStars)
{
    return 125 - ( iLevel-1 )*5 -(5-iStars);
}

bool CHealthStoneSimulator::refresh()
{
    ui->lineEditTotal->setText(QString::number(m_iTotal));
    ui->lineEditWin->setText(QString::number(m_iWin));
    ui->lineEditLose->setText(QString::number(m_iLose));

    int iLevel = 0;
    int iStar = 0;
    getLevel(m_iCurStarts, iLevel, iStar);

    ui->lineEditCurLevel->setText(QString::number(iLevel));
    ui->lineEditCurStar->setText(QString::number(iStar));
    ui->lineEditContinue->setText(QString::number(m_iStreak));

    return true;
}

void CHealthStoneSimulator::on_pushButtonOne_clicked()
{
    bool bRs = playAGame();

    m_iTotal ++;

    if( bRs )
    {
        m_iWin ++;
        m_iStreak ++;
        m_iCurStarts++;
        if(m_iStreak>2 && m_iCurStarts < 100)
        {
            m_iCurStarts ++;
        }
    }
    else
    {
        m_iLose ++;
        if( m_iCurStarts %25 )
        {
            m_iCurStarts --;
        }

        m_iStreak = 0;
    }
    if( m_iCurStarts >= 125 )
    {
        QMessageBox::information(this,tr("恭喜"),tr("传说妹子是你的了！") );
        reset();
    }
    refresh();
}

void CHealthStoneSimulator::on_lineEditRate_editingFinished()
{

}

void CHealthStoneSimulator::on_lineEditLevel_editingFinished()
{
    reset();
}

void CHealthStoneSimulator::on_lineEditStar_editingFinished()
{
    reset();
}
