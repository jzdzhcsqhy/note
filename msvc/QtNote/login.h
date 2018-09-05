#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QDialog *parent = 0);
    ~Login();

private slots:
    void on_btOk_clicked();

    void on_btCancel_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
