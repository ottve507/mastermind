/*
 * IDENTIFIERING
 *
 * Filnamn:    boardarea.h
 * Enhetsnamn: BoardArea
 * Typ:        Klassdeklaration
 * Revision:   1.0
 *
 *
 * BESKRIVNING
 *
 * Denna klass koordinerar spelets övriga klasser med hjälp av pekare till GameLogic, RoundArea, ControllerArea samt AnswerArea.
 *
 */

#ifndef BOARDAREA_H
#define BOARDAREA_H

#include "gamelogic.h"
#include "roundarea.h"
#include "controllerarea.h"
#include "answerarea.h"
#include <QWidget>
#include <vector>
#include <QLabel>
#include <QGridLayout>
class ControllerArea;

class BoardArea : public QWidget
{
    Q_OBJECT
public:
    explicit BoardArea(GameLogic* gl, QWidget *parent = 0);
    void check(int, int, int, int);

    void newGame();

signals:

public slots:

private:
    GameLogic* gamelogic;
    ControllerArea* controller;
    AnswerArea* answer;
    std::vector<RoundArea*> rounds;
    QLabel* label;
    int currentRound = 11;

    QVBoxLayout* layout;
};

#endif
