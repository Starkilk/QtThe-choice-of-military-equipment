#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "databasepsql.h"
#include "tablemodels.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setingsTableView();

signals:

private slots:

    void on_btn_next_clicked();

    void on_tvMain_clicked(const QModelIndex &index);

    void on_btn_back_clicked();

    void on_btn_choice_clicked();

private:
    Ui::MainWindow *ui;
    DatabasePSql *db;
    QSqlTableModel *model;

    int currentRow;
};
#endif // MAINWINDOW_H
