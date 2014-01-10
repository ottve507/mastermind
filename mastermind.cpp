/*
 * IDENTIFIERING
 *
 * Filnamn:    mastermind.cpp
 * Enhetsnamn: MasterMind
 * Typ:        Klassdefinitionn
 * Revision:   1.0
 *
 *
 * BESKRIVNING
 *
 * Denna klass är toppklassen som initierar spelet vid spelstart.
 *
 */


#include "mastermind.h"
#include <QVBoxLayout>
#include <iostream>
#include <QGridLayout>


//Initiera klasserna som krävs i spelet och sätt bakgrundsutseende
MasterMind::MasterMind(QWidget *parent)
    : QWidget(parent)
{
    gamelogic = new GameLogic();
    bNewGame = new QPushButton("New Game");
    bNewGame->setStyleSheet("QPushButton {background-color:rgb(50,100,100);}");
    QObject::connect(bNewGame, SIGNAL(clicked()), this, SLOT(newGame()));

    boardarea = new BoardArea(gamelogic);

    QGridLayout* layout =  new QGridLayout;
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->addWidget(boardarea);
    layout->addWidget(bNewGame);
    setStyleSheet("background-color:rgb(100,200,200)");
    setLayout(layout);
    setWindowTitle("MasterMind");
}

MasterMind::~MasterMind()
{
}

void MasterMind::newGame() {
    boardarea->newGame();
}
