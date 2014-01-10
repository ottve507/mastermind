/*
 * IDENTIFIERING
 *
 * Filnamn:    popup.cpp
 * Enhetsnamn: PopUp
 * Typ:        Klassdefinition
 * Revision:   1.0
 *
 *
 * BESKRIVNING
 *
 * Denna klass hanterar de popup-promptar som används i spelet.
 *
 */

#include "popup.h"
#include <QVBoxLayout>
#include <iostream>
#include <QApplication>
#include <string>
#include <sstream>

//skapar dialogruta med info till spelaren
PopUp::PopUp(int score, QWidget *parent) :
    QDialog(parent)
{
    //Skapa objekt till rutan och koppla med funktioner
    exitGame = new QPushButton("Exit");
    QObject::connect(exitGame, SIGNAL(clicked()), this, SLOT(onExit()));
    newGame = new QPushButton("New Game");
    QObject::connect(newGame, SIGNAL(clicked()), this, SLOT(onNewGame()));

    if(score==13){
        label = new QLabel("You lost, loser");
    }else{
        label = new QLabel("Du vann på: " + QString::number(score)+ " rundor!\n     GRATTIS");
    }

    //Skapa layout
    QVBoxLayout* layMeDownOnABedOfRosesLayout = new QVBoxLayout;

    //Lägg till objekten i layouten
    layMeDownOnABedOfRosesLayout->addWidget(label);
    layMeDownOnABedOfRosesLayout->addWidget(newGame);
    layMeDownOnABedOfRosesLayout->addWidget(exitGame);
    setLayout(layMeDownOnABedOfRosesLayout);
}

void PopUp::onExit(){
    QApplication::quit();
}

void PopUp::onNewGame(){
    this->close();
}

