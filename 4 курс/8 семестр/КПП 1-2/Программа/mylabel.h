#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
private:
    const int limit = 10;

public:
    MyLabel(QWidget *parent = 0);

public slots:
    void setCount(int);

signals:
    void ownSignal();
};

#endif // MYLABEL_H
