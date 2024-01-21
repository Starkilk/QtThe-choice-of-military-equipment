#ifndef TABLEMODELS_H
#define TABLEMODELS_H

#include <QObject>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlDatabase>//Библиотека для работы с БД



class TableModels : public QObject
{
    Q_OBJECT
public:
    explicit TableModels(QObject *parent = nullptr);




public slots:


signals:

private:


};

#endif // TABLEMODELS_H
