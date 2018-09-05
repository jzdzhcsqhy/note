#ifndef DATASTRUCT
#define DATASTRUCT

#include <QDateTime>
#include <QList>

#ifndef __DIARY_ITEM__
#define __DIARY_ITEM__
typedef struct
{
    QDateTime dtDate;
    int         iSeq;
    QString sTopic;
    QString sContent;
}DIARY_ITEM;

#endif


#ifndef __NOTE_ITEM__
#define __NOTE_ITEM__
typedef struct
{
    int iId;
    int iType;
    QString sTopic;
    QString sContent;
    QDateTime dtCreate;
    QDateTime dtUpdate;
}NOTE_ITEM;
#endif

typedef QMap<int,QString > NOTE_TYPE_MAP;



#endif // DATASTRUCT

