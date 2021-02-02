#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    nam = new QNetworkAccessManager(this);

    ui->tableView->setModel(&model);

    this->getUsers();

    connect(ui->buttonAdd, SIGNAL(clicked()), this, SLOT(addUser()));
    connect(ui->buttonRemove, SIGNAL(clicked()), this, SLOT(removeUser()));
    connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(finished(QNetworkReply*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getUsers()
{
    QNetworkReply *reply = nam->get(QNetworkRequest(QUrl("http://localhost:3000/users")));
    hash[reply] = 1;
}

void MainWindow::addUser()
{
    if (ui->lineEdit->text() != "" && ui->lineEdit_2->text() != "" && ui->lineEdit_3->text() != "")
    {
        QString fullname = "fullname=" + ui->lineEdit->text() + "&";
        QString age = "age=" + ui->lineEdit_2->text() + "&";
        QString address = "address=" + ui->lineEdit_3->text() + "&";
        QString createdAt = "created_at=" + QDateTime().currentDateTime().toString();

        QByteArray postData;
        postData.append(fullname.toUtf8());
        postData.append(age.toUtf8());
        postData.append(address.toUtf8());
        postData.append(createdAt.toUtf8());

        QNetworkRequest request;
        request.setUrl(QUrl("http://localhost:3000/users"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

        QNetworkReply *reply = nam->post(request, postData);
        hash[reply] = 2;
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Заполните все поля");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
}

void MainWindow::removeUser()
{
    QItemSelectionModel *select = ui->tableView->selectionModel();

    if (select->hasSelection())
    {
        QString id = select->selectedRows(0).value(0).data().toString();
        removedIndex = select->selectedIndexes().first().row();

        QNetworkReply *reply = nam->deleteResource(QNetworkRequest(QUrl("http://localhost:3000/users/" + id)));
        hash[reply] = 3;
    }
}

void MainWindow::finished(QNetworkReply *reply)
{
    switch(hash[reply])
    {
        case 1:
            getUsersCompleted(reply);
            break;
        case 2:
            addUserCompleted(reply);
            break;
        case 3:
            removeUserCompleted(reply);
            break;
    }

    hash.remove(reply);
}

void MainWindow::getUsersCompleted(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        QJsonArray data = doc.array();

        QStringList headers = QStringList() << "ID" << "Fullname" << "Age" << "Address" << "Created At";
        model.setHorizontalHeaderLabels(headers);
        model.setColumnCount(headers.size());

        const int rowCount = data.count();
        const int columnCount = headers.size();

        model.setRowCount(rowCount);
        model.setColumnCount(columnCount);

        for (int i = 0; i < rowCount; i++)
        {
            QJsonObject row = data[i].toObject();

            model.setItem(i, 0, new QStandardItem(QString::number(row["id"].toInt())));
            model.setItem(i, 1, new QStandardItem(row["fullname"].toString()));
            model.setItem(i, 2, new QStandardItem(row["age"].toString()));
            model.setItem(i, 3, new QStandardItem(row["address"].toString()));
            model.setItem(i, 4, new QStandardItem(row["created_at"].toString()));
        }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Упс, сервер не отвечает");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
}

void MainWindow::addUserCompleted(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        QJsonObject data = doc.object();

        QList<QStandardItem*> newRow;
        newRow.append(new QStandardItem(QString::number(data["id"].toInt())));
        newRow.append(new QStandardItem(data["fullname"].toString()));
        newRow.append(new QStandardItem(data["age"].toString()));
        newRow.append(new QStandardItem(data["address"].toString()));
        newRow.append(new QStandardItem(data["created_at"].toString()));
        model.appendRow(newRow);

        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        ui->lineEdit_3->setText("");
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Упс, сервер не отвечает");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
}

void MainWindow::removeUserCompleted(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        model.removeRow(removedIndex);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Упс, сервер не отвечает");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
}
