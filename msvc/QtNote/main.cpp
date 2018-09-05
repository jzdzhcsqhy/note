#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif


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

	// 这两行遗留自最初使用的qt4.0 在高版本的qt中，这两个函数已经不再使用
	// QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF8"));
    // QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));

	// 进程只能启动一个，用互斥量的方式判断是否有已经在运行的进程了
    HANDLE hMutex = CreateMutexA(NULL,TRUE,"Note.exe");

    if( hMutex != NULL )
    {
        if(ERROR_ALREADY_EXISTS == GetLastError() )
        {
            QMessageBox::information(qApp->activeWindow(),QString::fromUtf8("提示"),QString::fromUtf8("程序已经运行了"));
            return 1;
        }
    }

	// 从配置文件中读取使用的数据库文件的位置，默认使用同一个目录下的
	QSettings setting("config.cfg", QSettings::IniFormat);
	QString sDbName = setting.value("DATABASE/DBNAME", QVariant(QString("db.db"))).toString();
	if (!gDb.connectDb(sDbName))
	{
		QMessageBox::critical(qApp->activeWindow(), QString::fromUtf8("错误"), QString::fromUtf8("连接数据库失败"));
		return 1;
	}


	// 登录，但是目前没有实现太多功能，密码还是写死的呢
    Login *pLogin = new Login;
    if( QDialog::Rejected == pLogin->exec() )
    {
        return 0;
    }

	
    MainWindow w;

	//使窗口以最大化方式启动
	w.setWindowState(Qt::WindowMaximized);
    return a.exec();
}
