#include "mainwindow.h"
#include <QApplication>
#include "cdboperate.h"
#include <QTextCodec>
#include <windows.h>
#include "login.h"

#define DB_NAME "D:\\lzb\\qt\\note\\db\\db.db"

CDbOperate gDb;

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF8"));

    HANDLE hMutex = CreateMutexA(NULL,TRUE,"Note.exe");

    if( hMutex != NULL )
    {
        if(ERROR_ALREADY_EXISTS == GetLastError() )
        {
            QMessageBox::information(qApp->activeWindow(),QString::fromUtf8("提示"),QString::fromUtf8("程序已经运行了"));
            return 1;
        }
    }

    Login *pLogin = new Login;
    if( QDialog::Rejected == pLogin->exec() )
    {
        return 0;
    }


    QSettings setting("config.cfg",QSettings::IniFormat);
    QString sDbName = setting.value("DATABASE/DBNAME",QVariant(QString("D:\\lzb\\qt\\note\\db.db"))).toString();
    if(!  gDb.connectDb(sDbName) )
    {
        QMessageBox::critical(qApp->activeWindow(),QString::fromUtf8("错误"),QString::fromUtf8("连接数据库失败"));
        return 1;
    }

    MainWindow w;
    w.show();
    return a.exec();
}
