/*
 * IDENTIFIERING
 *
 * Filnamn:    resultarea.cpp
 * Enhetsnamn: ResultArea
 * Typ:        Klassdefintion
 * Revision:   1.0
 *
 *
 * BESKRIVNING
 *
 * Denna klass hanterar de funktioner som rör varje rundas resultatområde.
 *
 */


#include "resultarea.h"
#include <QPainter>
#include <QVBoxLayout>
#include <iostream>

//Skapa ResultArea
ResultArea::ResultArea(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout;
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->setGeometry(QRect(0,0,0,0));
    setLayout(layout);

}

//Rita upp ResultArea
void ResultArea::paintEvent(QPaintEvent *)
{
    int pos_temp=correct_pos;
    int col_temp=correct_col;
    QPainter painter(this);
    painter.setBrush(QBrush(QColor("cyan")));
    painter.drawRect(1,1,this->height()-1,this->height()-1);
    painter.setBrush(QBrush(QColor("black")));

    painter.setBrush(QBrush(brushcolor()));
    painter.drawEllipse(this->height()/8+1,this->height()/8+1,this->height()/3,this->height()/3);
    painter.setBrush(QBrush(brushcolor()));
    painter.drawEllipse(this->height()*(5.0/8),this->height()/8+1,this->height()/3,this->height()/3);
    painter.setBrush(QBrush(brushcolor()));
    painter.drawEllipse(this->height()/8+1,this->height()*(5.0/8)+1,this->height()/3,this->height()/3);
    painter.setBrush(QBrush(brushcolor()));
    painter.drawEllipse(this->height()*(5.0/8),this->height()*(5.0/8)+1,this->height()/3,this->height()/3);

    correct_pos=pos_temp;
    correct_col=col_temp;

}

//hjälpfunktion för att sätta rätt färg då resultatet ritas upp
QColor ResultArea::brushcolor() {
    QColor color = QColor("cyan");
    if(correct_pos != 0) {
        color = QColor("red");
        correct_pos--;
    }
    else if(correct_col != 0) {
        color = QColor("white");
        correct_col--;
    }
    return color;
}


void ResultArea::SetResult(std::pair<int,int> result) {
    correct_pos = result.first;
    correct_col = result.second;
    update();
}
