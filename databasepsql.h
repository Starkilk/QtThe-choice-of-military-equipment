#ifndef DATABASEPSQL_H
#define DATABASEPSQL_H

#include <QObject>
#include <QtSql/QSqlDatabase>//Библиотека для работы с БД
#include <QtSql/QSqlError>//Библиотка для выявления ошибок БД



class DatabasePSql : public QObject
{
    Q_OBJECT
public:
    explicit DatabasePSql(QObject *parent = nullptr);
    void conectDatabase();//подключение БД
    QSqlDatabase getDB();

signals:

private:
    QSqlDatabase db;


};

#endif // DATABASEPSQL_H
