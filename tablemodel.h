#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <MainWindow.h>
#include <QMainWindow>
#include <QtSql/QSqlTableModel>//Библиотека для передставления Таблиц бд

class TableModel : public QMainWindow
{
    Q_OBJECT
public:
    explicit TableModel(QWidget *parent = nullptr);
    void initClassTable(QSqlDatabase &db);


signals:

private:
    QSqlTableModel *modelClasses;
    Ui::MainWindow *ui;

};

#endif // TABLEMODEL_H
