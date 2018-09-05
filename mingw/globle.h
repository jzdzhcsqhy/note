#ifndef GLOBLE
#define GLOBLE


#include "datastruct.h"
#include <QMessageBox>

#define SHOW_WARNING( str )   \
    QMessageBox::warning(NULL,tr("警告"),(str) )

#define SHOW_ERROR( str )   \
    QMessageBox::warning(NULL,tr("错误"), (str) )

#define SHOW_CONFIRM( str ) \
    QMessageBox::information(NULL,tr("确认"),(str),QMessageBox::Yes|QMessageBox::No,QMessageBox::No)

#define DATE_FORMAT "yyyy-MM-dd"
#define DATE_TIME_FORMAT_WITH_ZZZ "yyyy-MM-dd hh:mm:ss.zzz"
#define DATE_TIME_FORMAT    "yyyy-MM-dd hh:mm:ss"

enum SELECT_ORDER_MASK
{
    SELECT_BY_DATE=0x0001,
    SELECT_BY_TYPE=0x0001<<1,
    SELECT_BY_KEYWORD_TOPIC=0x0001<<2,
    SELECT_BY_KEYWORD_CONTENT=0x0001<<3,

    ORDER_BY_CREATE_DATE =0x0001<<11,
    ORDER_BY_UPDATE_DATE =0x0001<<12,
    ORDER_BY_TYPE        =0x0001<<13
};

#endif // GLOBLE

