/*
 * IDENTIFIERING
 *
 * Filnamn:    mastermind.h
 * Enhetsnamn: MasterMind
 * Typ:        Klassdeklaration
 * Revision:   1.0
 *
 *
 * BESKRIVNING
 *
 * Denna klass är toppklassen som initierar spelet vid spelstart.
 *
 */

#ifndef MASTERMIND_H
#define MASTERMIND_H

#include "boardarea.h"
#include "gamelogic.h"
#include <QWidget>
#include <QPushButton>
#include <QLabel>

class MasterMind : public QWidget
{
    Q_OBJECT

public:
    MasterMind(QWidget *parent = 0);
    ~MasterMind();
private:
    GameLogic* gamelogic;
    QPushButton* bNewGame;
    BoardArea* boardarea;

public slots:
    void newGame();
};

#endif
