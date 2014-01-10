/*
 * IDENTIFIERING
 *
 * Filnamn:    piece.cpp
 * Enhetsnamn: Piece
 * Typ:        Klassdefinitioner
 * Revision:   1.0
 *
 *
 * BESKRIVNING
 *
 * Denna fil innehåller deklarationer till klasserna Piece och HiddenPiece respektive VisiblePiece som
 * ärver från Piece. Klasserna innehåller funktionaliteten för att måla upp en grafisk "plupp"
 *.
 *
 */

#include "piece.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPainter>

//Konstruktor
VisiblePiece::VisiblePiece(int col, QWidget *parent) :
    QWidget(parent)
{
    color = col;
    QVBoxLayout* layout = new QVBoxLayout;
    layout->setSpacing(0);
    layout->setMargin(0);
    setLayout(layout);
}

//Funktion som används då objektet målas upp
void VisiblePiece::paintEvent(QPaintEvent *)
{
    if (color != 10){

        QPainter painter(this);
        painter.setBrush(QBrush(colours[color]));
        painter.drawEllipse((this->width()-this->height())/2,0,this->height()-2,this->height()-2);
    }

}

//Funktion som används för att ändra färg på aktuellt objekt.
void VisiblePiece::SetColor(int value) {
    color = value;
    update();

}

//Funktion som döljer eller visar objektet
void VisiblePiece::setVisi(bool arg) {
    setVisible(arg);
}

HiddenPiece::HiddenPiece(QWidget *parent):
    QWidget(parent)
{
}

void HiddenPiece::paintEvent(QPaintEvent *) {
}

