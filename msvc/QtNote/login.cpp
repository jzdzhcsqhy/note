#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif

#include "login.h"
#include "ui_login.h"
#include "globle.h"
Login::Login(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

}

Login::~Login()
{
    delete ui;
}

void Login::on_btOk_clicked()
{

    QString sPwd = ui->lineEdit->text();
    if( sPwd== "abc123" )
    {
         this->accept();
    }
    else
    {
        SHOW_ERROR(tr("密码错误，请重新输入！"));
        return ;
    }

}

void Login::on_btCancel_clicked()
{
    this->reject();
}
