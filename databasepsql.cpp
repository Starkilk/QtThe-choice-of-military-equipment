#include "databasepsql.h"
#include <QDebug>

DatabasePSql::DatabasePSql(QObject *parent): QObject{parent}{


}

void DatabasePSql::conectDatabase()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("rusbitech");
    db.setHostName("localhost");
    db.setUserName("postgres");
    db.setPassword("22813376914Sql");

    if(db.open()){
        qDebug()<< "Успешно!";
    }else{
        qDebug()<< "Ошибка!";
    }


}
