#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString DBpath = QDir::toNativeSeparators(qApp->applicationDirPath() + "/student.db");

    sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName(DBpath);

    if(!sdb.open())
    {
        QMessageBox::critical(this, tr("SQLite connection"), tr("Unable connect to DB, check file permission."));
        exit(1);
    }

    QSqlTableModel *model = new QSqlTableModel(ui->studentView);
    model->setTable("Student");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();

    ui->studentView->setModel(model);

    connect(ui->buttonAdd, SIGNAL(clicked()), SLOT(addStudent()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addStudent()
{
    QAbstractItemModel *model = ui->studentView->model();

    if (ui->lineEdit->text() == "" ||
        ui->lineEdit_2->text() == "" ||
        ui->lineEdit_3->text() == "" ||
        ui->lineEdit_4->text() == "")
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Заполните все поля!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
    else
    {
        model->insertRow(model->rowCount());

        int rowCount = model->rowCount() - 1;

        model->setData(model->index(rowCount, 0), model->rowCount());
        model->setData(model->index(rowCount, 1), ui->lineEdit->text());
        model->setData(model->index(rowCount, 2), ui->lineEdit_2->text());
        model->setData(model->index(rowCount, 3), ui->lineEdit_3->text());
        model->setData(model->index(rowCount, 4), ui->lineEdit_4->text());

        model->submit();

        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        ui->lineEdit_3->setText("");
        ui->lineEdit_4->setText("");
    }
}
