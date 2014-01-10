/*
 * IDENTIFIERING
 *
 * Filnamn:    roundarea.h
 * Enhetsnamn: RoundArea
 * Typ:        Klassdeklaration
 * Revision:   1.0
 *
 *
 * BESKRIVNING
 *
 * Denna klass hanterar de funktioner som rör varje runda.
 *
 */

#ifndef ROUNDAREA_H
#define ROUNDAREA_H

#include <vector>
#include <QWidget>
#include "piece.h"
#include "resultarea.h"

class RoundArea : public QWidget
{
    Q_OBJECT
public:
    explicit RoundArea(QWidget *parent = 0);
    void SetColors(int, int, int, int);
    void SetResult(std::pair<int,int>);

signals:

public slots:

private:
    std::vector<VisiblePiece*> pieces;
    ResultArea* result;
};

#endif
