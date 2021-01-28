#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(validate()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::validate()
{
    QString userName = ui->lineEdit->text();
    bool radio1 = ui->radioButton->isChecked();
    bool radio2 = ui->radioButton_2->isChecked();

    bool nameContainsNumber = !QRegExp("\\D*").exactMatch(userName);
    bool radioIsNotChecked = !(radio1 || radio2);

    QMessageBox msgBox;

    if (userName == "" || radioIsNotChecked || nameContainsNumber)
    {
        QString errorsText = "";

        if (userName == "") errorsText += "Заполните ваше имя! \n";
        if (userName != "" && nameContainsNumber) errorsText += "Имя содержит недопустимые символы! \n";
        if (radioIsNotChecked) errorsText += "Вы не ответили на второй вопрос";

        msgBox.setWindowTitle("Ошибка");
        msgBox.setText(errorsText);
    }
    else
    {
        msgBox.setWindowTitle("Удача");
        msgBox.setText("Ваши ответы были отправлены!");
    }

    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}

