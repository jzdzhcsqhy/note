#ifndef CDBOPERATE_H
#define CDBOPERATE_H

#include <QtSql>
#include <QDebug>
#include "datastruct.h"
#include <QMap>
#include "globle.h"

class CDbOperate
{
public:
    CDbOperate();

    bool connectDb( const QString& sDbName );

    bool getDiaryByDate(QDateTime dtStart, QDateTime dtEnd, QList<DIARY_ITEM>& rtList);

    bool getMaxSeqForDate(QDateTime dtDate, int* rs );
    bool addNewDiaryItem(DIARY_ITEM in );
    bool removeDiaryItem(DIARY_ITEM in);
    bool updateDiaryItem(DIARY_ITEM in);

    bool getTypeMap(NOTE_TYPE_MAP& mapOut);

    bool getNote(QList<NOTE_ITEM>& lstOut,
                 unsigned int uSelectMask,
                 unsigned int uOrderMask,
                 QDateTime dtBegin,
                 QDateTime dtEnd,
                 int iType,
                 QString sKeyWord);
    bool addNewNoteItem( NOTE_ITEM in);
    bool removeNoteItem( NOTE_ITEM in);
    bool updateNoteItem( NOTE_ITEM in);
    bool getMaxIdForNote(int *max);
    //bool ( QList<NOTE_ITEM>& lstOut, unsinged int uMask, QDateTime dtBegin, QDateTime dtEnd, int iType );

    bool getDateWhichHasRecord( QList<QDate>& lstOut );
private:
    QSqlDatabase m_Db;

};

#endif // CDBOPERATE_H
