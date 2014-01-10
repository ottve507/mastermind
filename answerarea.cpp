/*
 * IDENTIFIERING
 *
 * Filnamn:    answerarea.cpp
 * Enhetsnamn: AnswerArea
 * Typ:        Klassdefinition
 * Revision:   1.0
 *
 *
 * BESKRIVNING
 *
 * Denna klass innehåller de funktioner krävs för visning av korrekt svar vid spelets slut.
 *
 */


#include "answerarea.h"
#include "piece.h"
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QPainter>
#include <iostream>
#include <vector>

AnswerArea::AnswerArea(GameLogic* g, QWidget *parent) :
    QWidget(parent), gl(g)
{
    layout = new QHBoxLayout;
    layout -> setSpacing(0);
    layout->setMargin(0);
    hidden = new HiddenPiece();
    layout->addWidget(hidden);
    setLayout(layout);
}

//Målar upp en vit ruta för svarsdelen!
void AnswerArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setBrush(QBrush(QColor("white")));
    painter.drawRect(0,0,this->width()*(4/5.0),this->height());

}

//Sätter svaret synligt om funktionen anropas med true som argument
void AnswerArea::setV(bool b){
    std::vector<int> temp = gl->getAnswer();

    for (int i = 3; i >= 0; --i)
    {
        VisiblePiece* p = new VisiblePiece(temp.at(i));
        layout->insertWidget(0,p);
        pieces.push_back(p);
    }
}

//Tar bort nuvarande svar.
void AnswerArea::removePieces() {
    for(unsigned int i=0; i<pieces.size(); i++) {
        pieces.at(i)->setVisi(false);
    }
}
