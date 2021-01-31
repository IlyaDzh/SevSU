#include "file.h"

File::File(QObject *parent):QObject(parent)
{

}

QString File::load(QString fileName)
{
    QFile file(fileName);
    QString result = "";
    if (file.open(QFile::ReadWrite))
    {
        QTextStream inStream(&file);
        result = inStream.readAll();
    }
    file.close();
    return result;
}

void File::save(QString fileName, QString text)
{
     QFile file(fileName);
     if (file.open(QFile::ReadWrite | QIODevice::Truncate))
     {
         QTextStream outStream(&file);
         outStream << text;
     }
     file.close();
}
