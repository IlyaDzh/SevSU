#ifndef FILE_H
#define FILE_H

#include <QtGui/QGuiApplication>
#include <QFile>
#include <QTextStream>


class File : public QObject
{
    Q_OBJECT

public:
    File(QObject *parent = 0);

    Q_INVOKABLE QString load(QString fileName);
    Q_INVOKABLE void save(QString fileName, QString text);
};

#endif // FILE_H
