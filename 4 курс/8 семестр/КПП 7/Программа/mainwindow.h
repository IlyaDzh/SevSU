#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QByteArray>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QNetworkAccessManager *nam;

private slots:
    void hideForm();
    void showGetForm();
    void showPostForm();
    void submit();
    void reset();
    void finished(QNetworkReply *reply);
};
#endif // MAINWINDOW_H
