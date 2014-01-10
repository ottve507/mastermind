/*
 * IDENTIFIERING
 *
 * Filnamn:    answerarea.h
 * Enhetsnamn: AnswerArea
 * Typ:        Klassdeklaration
 * Revision:   1.0
 *
 *
 * BESKRIVNING
 *
 * Denna klass innehåller de funktioner krävs för visning av korrekt svar vid spelets slut.
 *
 */


#ifndef ANSWERAREA_H
#define ANSWERAREA_H

#include <QWidget>
#include <piece.h>
#include <vector>
#include <QHBoxLayout>
#include "gamelogic.h"

class AnswerArea : public QWidget
{
    Q_OBJECT
public:
    explicit AnswerArea(GameLogic *g, QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void setV(bool b);
    void removePieces();

signals:

public slots:

private:
    std::vector<Piece*> pieces;
    GameLogic* gl;
    QHBoxLayout* layout;
    HiddenPiece* hidden;

};

#endif // ANSWERAREA_H
