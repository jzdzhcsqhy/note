#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cdlgdiary.h"
#include "cdlgnote.h"
#include <QSystemTrayIcon>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void initMenu();

private:
    void closeEvent(QCloseEvent *e);

private slots:

    void onSystemTrayIconClick(QSystemTrayIcon::ActivationReason reason);
    void onMenuAction(QAction*);
private:
    CDlgDiary* m_pDiary;
    CDlgNote* m_pNote;

    QSystemTrayIcon* m_pTrayIcon;
    QMenu*   m_pTrayIconMenu;

    bool m_bCloseFlag;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
