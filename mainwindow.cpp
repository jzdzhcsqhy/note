#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCloseEvent>
#include <QAction>
#include <QMenu>
#include "HealthStoneSimulator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_pTrayIcon = new QSystemTrayIcon(this);
    connect(m_pTrayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(onSystemTrayIconClick(QSystemTrayIcon::ActivationReason)));

    initMenu();

    QIcon icon(":/img/resource/icon.png");
    m_pTrayIcon->setIcon(icon);
    m_pTrayIcon->show();
    m_pTrayIcon->setContextMenu(m_pTrayIconMenu);
    m_pTrayIcon->setToolTip(tr("罗志彬的工作日志"));

    m_bCloseFlag = false;

    m_pDiary = new CDlgDiary(this);

    QDateTime dtToday = QDateTime::currentDateTime();
    m_pDiary->setDate(dtToday);
    m_pDiary->getList();
    m_pDiary->refreshList();
    ui->tabDiary->layout()->addWidget(m_pDiary);
    m_pDiary->show();

    m_pNote = new CDlgNote(this);
    ui->tabNote->layout()->addWidget(m_pNote);

    this->setWindowIcon(icon);
//    this->showMaximized();
}

MainWindow::~MainWindow()
{
    if( m_pDiary )
    {
        delete m_pDiary;
        m_pDiary = 0;
    }
    if( m_pNote )
    {
        delete m_pNote;
        m_pNote = 0;
    }
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    if( !m_bCloseFlag )
    {
        e->ignore();
        this->hide();
    }
}

void MainWindow::initMenu()
{
    m_pTrayIconMenu = new QMenu();
    m_pTrayIconMenu->hide();

    m_pTrayIconMenu->addAction(tr("显示"));


    QMenu* pSubMenu = new QMenu(tr("工具"));
    pSubMenu->addAction(tr("炉石对战模拟器"));

    m_pTrayIconMenu->addMenu(pSubMenu);
    m_pTrayIconMenu->addAction(tr("退出"));
    connect(m_pTrayIconMenu,SIGNAL(triggered(QAction*)),this,SLOT(onMenuAction(QAction*)));
}

void MainWindow::onMenuAction(QAction * a)
{
    QString sOption = a->text();
    if( sOption == tr("显示") )
    {
        this->show();
    }
    else if( sOption == tr("退出") )
    {

        if( QMessageBox::Yes == SHOW_CONFIRM(tr("确认要退出吗？")))
        {
            m_bCloseFlag = true;
            this->close();
        }
    }
    else if( sOption == tr("炉石对战模拟器") )
    {
        CHealthStoneSimulator dlg(this);
        dlg.exec();

    }
    else
    {

    }
}

void MainWindow::onSystemTrayIconClick(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
//    case QSystemTrayIcon::Trigger:
    case QSystemTrayIcon::DoubleClick:
        if( this->isHidden() )
        {
            this->show();
        }
        else
        {
            this->hide();
        }
        break;
    default:
        break;
    }
}
