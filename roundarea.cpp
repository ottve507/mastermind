/*
 * IDENTIFIERING
 *
 * Filnamn:    roundarea.cpp
 * Enhetsnamn: RoundArea
 * Typ:        Klassdefinition
 * Revision:   1.0
 *
 *
 * BESKRIVNING
 *
 * Denna klass hanterar de funktioner som rör varje runda.
 *
 */

#include "roundarea.h"
#include <QHBoxLayout>

RoundArea::RoundArea(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout* layout = new QHBoxLayout;
    layout -> setSpacing(0);
    layout->setMargin(0);
    for (int i = 0; i < 4; ++i)
    {
        VisiblePiece* p = new VisiblePiece();
        layout->addWidget(p);
        pieces.push_back(p);
    }
    result = new ResultArea;
    layout->addWidget(result);
    setLayout(layout);
}

//Sätter alla färger i omgången
void RoundArea::SetColors(int g1, int g2, int g3, int g4) {
    pieces.at(0) -> SetColor(g1);
    pieces.at(1) -> SetColor(g2);
    pieces.at(2) -> SetColor(g3);
    pieces.at(3) -> SetColor(g4);
}

//Sätter resultatet för omgången
void RoundArea::SetResult(std::pair<int,int> results) {
    result -> SetResult(results);
}

