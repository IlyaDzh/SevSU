#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QDateTime>

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
    QStandardItemModel model;
    QHash<QNetworkReply*, int> hash;
    int removedIndex;

private slots:
    void getUsers();
    void getUsersCompleted(QNetworkReply *reply);
    void addUser();
    void addUserCompleted(QNetworkReply *reply);
    void removeUser();
    void removeUserCompleted(QNetworkReply *reply);
    void finished(QNetworkReply *reply);
};
#endif // MAINWINDOW_H
