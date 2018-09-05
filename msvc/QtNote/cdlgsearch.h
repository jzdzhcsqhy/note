#ifndef CDLGSEARCH_H
#define CDLGSEARCH_H

#include <QDialog>
#include <QDateTime>
#include "globle.h"
namespace Ui {
class CDlgSearch;
}

class CDlgSearch : public QDialog
{
    Q_OBJECT

public:
    explicit CDlgSearch(QDialog *parent = 0);
    ~CDlgSearch();

    void makeMask();

    QDateTime getDateStart();
    QDateTime getDateEnd();

    int getType();
    QString getKeyWord();

    void initCombox();

signals:
    void clickOk( unsigned int uMask);

private slots:
    void on_btOk_clicked();

private:

    unsigned int m_uMask;
    Ui::CDlgSearch *ui;
};

#endif // CDLGSEARCH_H
