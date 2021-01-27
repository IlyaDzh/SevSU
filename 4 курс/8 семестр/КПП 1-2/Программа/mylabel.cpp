#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

}

void MyLabel::setCount(int value)
{
    if (value > limit)
    {
        emit ownSignal();
    }
    this->setText(QString::number(value));
}
