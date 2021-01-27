#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(changeTitle()));
    connect(ui->plainTextEdit, SIGNAL(textChanged()), this, SLOT(copyTextToSecondTextBox()));
    connect(ui->plainTextEdit_2, SIGNAL(textChanged()), this, SLOT(getCountOfSpecialCharacters()));
    connect(ui->label, SIGNAL(ownSignal()), this, SLOT(disablePlainTextEdit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeTitle()
{
    QString newTitle= ui->lineEdit->text();
    this->setWindowTitle(newTitle);
    ui->lineEdit->clear();
}

void MainWindow::copyTextToSecondTextBox()
{
    QString text = ui->plainTextEdit->toPlainText();
    text.replace("a", "*");
    ui->plainTextEdit_2->setPlainText(text);
}

void MainWindow::getCountOfSpecialCharacters()
{
    int count = ui->plainTextEdit_2->toPlainText().count("*");
    ui->label->setCount(count);
}

void MainWindow::disablePlainTextEdit()
{
    ui->plainTextEdit->setDisabled(true);
}
