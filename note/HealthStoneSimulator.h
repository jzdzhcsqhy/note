#ifndef HEALTHSTONESIMULATOR_H
#define HEALTHSTONESIMULATOR_H

#include <QDialog>

namespace Ui {
class CHealthStoneSimulator;
}

class CHealthStoneSimulator : public QDialog
{
    Q_OBJECT

public:
    explicit CHealthStoneSimulator(QWidget *parent = 0);
    ~CHealthStoneSimulator();

public:
    bool playAGame();
    bool reset();
    bool getLevel( int iAllStars, int& iLevel, int& iStar );
    int getAllStars( int iLevel, int iStars );

    bool refresh();

public:

    int m_iTotal;
    int m_iWin;
    int m_iLose;
    int m_iCurStarts;
    int m_iStreak;

    bool m_bThisGame;
private slots:
    void on_pushButtonOne_clicked();

    void on_lineEditRate_editingFinished();

    void on_lineEditLevel_editingFinished();

    void on_lineEditStar_editingFinished();

private:
    Ui::CHealthStoneSimulator *ui;
};

#endif // HEALTHSTONESIMULATOR_H
