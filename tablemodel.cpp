#include "tablemodel.h"
#include "ui_mainwindow.h"
TableModel::TableModel(QWidget *parent)
    : QMainWindow{parent}
{


}

void TableModel::initClassTable(QSqlDatabase &db)
{
    modelClasses = new QSqlTableModel(this, db);//Связали модель с БД
    modelClasses->setTable("classes");//Указали какую таблицу присваиваем
    modelClasses->select();//Запросили данные

    //Меняем названия столбцов
    // modelClasses->setHeaderData(1, Qt::Horizontal, "Фамилия", Qt::DisplayRole);
    // modelClasses->setHeaderData(2, Qt::Horizontal, "Имя", Qt::DisplayRole);

    ///

    // ui->tvClasses->setModel(modelClasses);//Передали модель в табличное представление
    // ui->tvClasses->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);//Выравнивание таблицы по содержимому
    // ui->tvClasses->setColumnHidden(0, true);//Спрятали стольбец "id"
    // ui->tvClasses->setSelectionBehavior(QAbstractItemView::SelectRows);//ВЫДЕЛЕНИЕ СТРОКИ целеком
    // ui->tvClasses->setSortingEnabled(true);//Сортировка по столбцам
}
