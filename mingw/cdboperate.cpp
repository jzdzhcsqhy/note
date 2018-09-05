#include "cdboperate.h"

CDbOperate::CDbOperate()
{
    m_Db = QSqlDatabase::addDatabase("QSQLITE");


}



bool CDbOperate::connectDb(const QString &sDbName)
{

    m_Db.setDatabaseName(sDbName);

    if( !m_Db.open() )
    {
        qDebug()<< "Open DataBase Error!";
        return false;
    }
    else
    {
        qDebug() << "Open " << sDbName << "succed!";
        return true;
    }
    return false;
}

bool CDbOperate::getDiaryByDate(QDateTime dtStart, QDateTime dtEnd, QList<DIARY_ITEM> &rtList)
{
    QSqlQuery query;

    QString sSql = QString("select date,seq,topic,content from TABLE_DIARY "
                           "where date >='%1'   "
                           "and date <= '%2'    "
                           "order by date,seq")
                            .arg(dtStart.toString("yyyy-MM-dd"))
                            .arg(dtEnd.toString("yyyy-MM-dd"));
    if( query.exec(sSql ) )
    {
        while( query.next() )
        {
            DIARY_ITEM tmp;
            tmp.dtDate = query.value(0).toDateTime();
            tmp.iSeq= query.value(1).toInt();
            tmp.sTopic = query.value(2).toString();
            tmp.sContent = query.value(3).toString();
            rtList.push_back(tmp);
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool CDbOperate::getMaxSeqForDate(QDateTime dtDate, int *rs)
{
    QSqlQuery query;
    *rs = 0;

    QString sSql = QString("select max(seq) as max from table_diary "
                           "where date = '%1'   ")
                            .arg(dtDate.toString("yyyy-MM-dd"));
    if( query.exec(sSql ) )
    {
        while( query.next() )
        {
            *rs = query.value(0).toInt();
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool CDbOperate::addNewDiaryItem(DIARY_ITEM in)
{
    QSqlQuery query;

    QString sSql = QString("insert into table_diary ( date, seq, topic, content) "
                           "values('%1', %2, '%3', '%4') ")
                            .arg(in.dtDate.toString("yyyy-MM-dd"))
                           .arg(in.iSeq)
                            .arg(in.sTopic).arg(in.sContent);
    if( query.exec(sSql ) )
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool CDbOperate::removeDiaryItem(DIARY_ITEM in)
{
    QSqlQuery query;

    QString sSql = QString("delete from table_diary where date = '%1' and seq = %2")
                            .arg(in.dtDate.toString("yyyy-MM-dd"))
                           .arg(in.iSeq);
    if( query.exec(sSql ) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CDbOperate::updateDiaryItem(DIARY_ITEM in)
{
    QSqlQuery query;

    QString sSql = QString( "update table_diary set topic='%1', content='%2' "
                            "where date ='%3' and seq = %4  ").arg(in.sTopic).arg(in.sContent)
                            .arg(in.dtDate.toString("yyyy-MM-dd"))
                           .arg(in.iSeq);
    if( query.exec(sSql ) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CDbOperate::getTypeMap(NOTE_TYPE_MAP &mapOut)
{
    QSqlQuery query;

    QString sSql = QString("select id,description from table_NOTE_type");
    if( query.exec(sSql ) )
    {
        while( query.next() )
        {
            int iId = query.value(0).toInt();
            QString sName = query.value(1).toString();
            mapOut[iId]= sName;
        }
        return true;
    }
    else
    {
        return false;
    }

}

bool CDbOperate::getNote(QList<NOTE_ITEM> &lstOut, unsigned int uSelectMask, unsigned int uOrderMask, QDateTime dtBegin, QDateTime dtEnd, int iType, QString sKeyword)
{
    Q_UNUSED(uOrderMask);

    QSqlQuery query;

    QString sSql = QString("select id, type, topic, content, create_date, update_date "
                           "from table_note                                           ");

    if( uSelectMask )
    {
        bool bAnd = false;
        sSql += QString(" where ");
        if( uSelectMask & SELECT_BY_DATE )
        {
            sSql += QString( "create_date >='%1'   "
                             "and create_date <= '%2'    ")
                            .arg(dtBegin.toString("yyyy-MM-dd hh:mm:ss.zzz"))
                            .arg(dtEnd.toString("yyyy-MM-dd hh:mm:ss.zzz"));
            bAnd = true;
        }

        if( uSelectMask & SELECT_BY_TYPE )
        {
            if( bAnd )
            {
                sSql += QString(" and ");
            }
            sSql += QString(" type = %1 ").arg(iType);
            bAnd = true;
        }

        if( uSelectMask & SELECT_BY_KEYWORD_TOPIC )
        {
            if( bAnd )
            {
                sSql += QString(" and ");
            }
            sSql += QString(" (topic like '%%1%' ").arg(sKeyword);

            if( uSelectMask & SELECT_BY_KEYWORD_CONTENT )
            {
                sSql += QString(" or content like '%%1%' ").arg(sKeyword);
            }

            sSql += QString(")");
            bAnd = true;
        }
        else
        {
            if( uSelectMask & SELECT_BY_KEYWORD_CONTENT )
            {
                if( bAnd )
                {
                    sSql += QString(" and ");
                }
                 sSql += QString(" content like '%%1%' ").arg(sKeyword);
                 bAnd = true;
            }
        }


    }

    sSql += " order by id ";

//
//                           "order by date,seq")
//                            .arg(dtStart.toString("yyyy-MM-dd"))
//                            .arg(dtEnd.toString("yyyy-MM-dd"));

    qDebug()<< sSql;
    if( query.exec(sSql ) )
    {
        while( query.next() )
        {
            NOTE_ITEM tmp;
            tmp.iId = query.value(0).toInt();
            tmp.iType = query.value(1).toInt();
            tmp.sTopic = query.value(2).toString();
            tmp.sContent = query.value(3).toString();
            tmp.dtCreate = query.value(4).toDateTime();
            tmp.dtUpdate = query.value(5).toDateTime();
            lstOut.push_back(tmp);
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool CDbOperate::updateNoteItem(NOTE_ITEM in)
{
    QSqlQuery query;

    QString sSql;
    sSql = QString( "update table_note set topic = '%1', content ='%2', type=%3, update_date='%4' where id='%5'"
                    ).arg(in.sTopic).arg(in.sContent).arg(in.iType)
                            .arg(in.dtUpdate.toString(DATE_TIME_FORMAT_WITH_ZZZ))
                           .arg(in.iId);
    qDebug()<< sSql;
    if( query.exec(sSql ) )
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool CDbOperate::getMaxIdForNote(int *max)
{
    QSqlQuery query;
    *max = 0;

    QString sSql = QString("select max(id) as max from table_note ");
    if( query.exec(sSql ) )
    {
        while( query.next() )
        {
            *max = query.value(0).toInt();
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool CDbOperate::getDateWhichHasRecord(QList<QDate> &lstOut)
{

    QSqlQuery query;

    QString sSql = QString("select distinct date from table_diary order by date");
    if( query.exec(sSql ) )
    {
        while( query.next() )
        {
            QDate dt = query.value(0).toDate();
            lstOut.push_back(dt);
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool CDbOperate::addNewNoteItem(NOTE_ITEM in)
{
    QSqlQuery query;

    QString sSql = QString("insert into table_note ( id,type, topic, content, create_date, update_date) "
                           "values('%1', %2, '%3', '%4','%5', '%6') ")
                           .arg(in.iId).arg(in.iType).arg(in.sTopic).arg(in.sContent)
                            .arg(in.dtCreate.toString(DATE_TIME_FORMAT_WITH_ZZZ) )
                            .arg(in.dtUpdate.toString(DATE_TIME_FORMAT_WITH_ZZZ));
    if( query.exec(sSql ) )
    {
        return true;
    }
    else
    {
        return false;
    }


}

bool CDbOperate::removeNoteItem(NOTE_ITEM in)
{
    QSqlQuery query;

    QString sSql = QString("delete from table_note where id=%1 ")
                            .arg(in.iId);
    if( query.exec(sSql ) )
    {
        return true;
    }
    else
    {
        return false;
    }
}
