#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    nam = new QNetworkAccessManager(this);

    hideForm();

    connect(ui->buttonGet, SIGNAL(clicked()), this, SLOT(showGetForm()));
    connect(ui->buttonPost, SIGNAL(clicked()), this, SLOT(showPostForm()));
    connect(ui->buttonSubmit, SIGNAL(clicked()), this, SLOT(submit()));
    connect(ui->buttonReset, SIGNAL(clicked()), this, SLOT(reset()));
    connect(ui->buttonMenu, SIGNAL(clicked()), this, SLOT(hideForm()));
    connect(ui->buttonMenu, SIGNAL(clicked()), this, SLOT(reset()));
    connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(finished(QNetworkReply*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hideForm()
{
    ui->buttonGet->setHidden(false);
    ui->buttonPost->setHidden(false);
    ui->buttonSubmit->setHidden(true);
    ui->buttonReset->setHidden(true);
    ui->label_2->setHidden(true);
    ui->label_3->setHidden(true);
    ui->label_4->setHidden(true);
    ui->lineEditUrl->setHidden(true);
    ui->lineEditData->setHidden(true);
    ui->plainTextEdit->setHidden(true);
    ui->buttonMenu->setHidden(true);
}

void MainWindow::showGetForm()
{
    ui->buttonGet->setHidden(true);
    ui->buttonPost->setHidden(true);
    ui->buttonSubmit->setHidden(false);
    ui->buttonReset->setHidden(false);
    ui->label_2->setHidden(false);
    ui->label_4->setHidden(false);
    ui->lineEditUrl->setHidden(false);
    ui->plainTextEdit->setHidden(false);
    ui->buttonMenu->setHidden(false);
}

void MainWindow::showPostForm()
{
    ui->buttonGet->setHidden(true);
    ui->buttonPost->setHidden(true);
    ui->buttonSubmit->setHidden(false);
    ui->buttonReset->setHidden(false);
    ui->label_2->setHidden(false);
    ui->label_3->setHidden(false);
    ui->label_4->setHidden(false);
    ui->lineEditUrl->setHidden(false);
    ui->lineEditData->setHidden(false);
    ui->plainTextEdit->setHidden(false);
    ui->buttonMenu->setHidden(false);
}

void MainWindow::submit()
{
    QString url = ui->lineEditUrl->text();
    QString data = ui->lineEditData->text();

    QByteArray postData;
    postData.append(data.toUtf8());

    if (postData.isEmpty() == true) {
        nam->get(QNetworkRequest(QUrl(url)));
    }
    else
    {
        nam->post(QNetworkRequest(QUrl(url)), postData);
    }
}

void MainWindow::reset()
{
    ui->lineEditUrl->setText("");
    ui->lineEditData->setText("");
    ui->plainTextEdit->setPlainText("");
}

void MainWindow::finished(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        ui->plainTextEdit->setPlainText(reply->readAll());
    }
    else
    {
        ui->plainTextEdit->setPlainText(reply->errorString());
    }
}
