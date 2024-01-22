#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btn_choice->hide();

    db = new DatabasePSql();
    db->conectDatabase();

    ////////Присвоили и вывели нашу таблицу
    model = new QSqlTableModel(this, db->getDB());//Связали модель с БД
    model->setTable("classes");//Указали какую таблицу присваиваем
    model->select();//Запросили данные
    ui->tvMain->setModel(model);
    ////////

    setingsTableView();//Настройки вида таблицы


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setingsTableView()
{

    model->setHeaderData(1, Qt::Horizontal, "Название", Qt::DisplayRole);
    model->setHeaderData(2, Qt::Horizontal, "Количество", Qt::DisplayRole);

    ui->tvMain->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);//Выравнивание таблицы по содержимому
    ui->tvMain->setColumnHidden(0, true);//Спрятали стольбец "id"
    ui->tvMain->setSelectionBehavior(QAbstractItemView::SelectRows);//ВЫДЕЛЕНИЕ СТРОКИ целеком
    //ui->tvMain->setSortingEnabled(true);//Сортировка по столбцам
}

//Перейти к списку шаблонов
void MainWindow::on_btn_next_clicked()
{
    switch (currentRow) {
    case 0:
        model->setTable("tank_templates");//Указали какую таблицу присваиваем
        ui->tvMain->setModel(model);
        model->select();//Запросили данные
         break;
    case 1:
        model->setTable("plane_templates");//Указали какую таблицу присваиваем
        ui->tvMain->setModel(model);
        model->select();//Запросили данные
        break;
    case 2:
        model->setTable("helicopter_templates");//Указали какую таблицу присваиваем
        ui->tvMain->setModel(model);
        model->select();//Запросили данные
        break;
    }

    ui->btn_next->hide();
    ui->btn_choice->show();
    typeClass = currentRow;//запомнили тип класса, в который перешли

}

//Слушатель нажатия на элементы таблицы
void MainWindow::on_tvMain_clicked(const QModelIndex &index)
{
    currentRow = index.row();
}

//Вернуться к списку классов
void MainWindow::on_btn_back_clicked()
{
    model->setTable("classes");//Указали какую таблицу присваиваем
    ui->tvMain->setModel(model);
    model->select();//Запросили данные

    setingsTableView();//Настройки вида таблицы

    ui->btn_next->show();
    ui->btn_choice->hide();
}

//Добавление шаблонов в хранилище
void MainWindow::on_btn_choice_clicked()
{
    QModelIndex currentDiscount  = ui->tvMain->currentIndex();

    QString name = ui->tvMain->model()->data(ui->tvMain->model()->index(currentDiscount.row(),1),0).toString();
    double weight = ui->tvMain->model()->data(ui->tvMain->model()->index(currentDiscount.row(),2),0).toDouble();
    int value = ui->tvMain->model()->data(ui->tvMain->model()->index(currentDiscount.row(),3),0).toInt();

    Factory factory;
    qDebug() << 5;
    Interface *interface = factory.factoryMetod(name, weight, value, typeClass);
    qDebug() << 6;



}

