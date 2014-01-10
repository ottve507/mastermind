/*
 * IDENTIFIERING
 *
 * Filnamn:    boardarea.cpp
 * Enhetsnamn: BoardArea
 * Typ:        Klassdefinition
 * Revision:   1.0
 *
 *
 * BESKRIVNING
 *
 * Denna klass koordinerar spelets övriga klasser med hjälp av pekare till GameLogic, RoundArea, ControllerArea samt AnswerArea.
 *
 */

#include "boardarea.h"
#include <vector>
#include <QVBoxLayout>
#include <QGridLayout>
#include <iostream>
#include <QPainter>
#include "popup.h"
using namespace std;

//Konstruktor, sätter font och den layout som används. Skapar tolv RoundAreaobjekt
BoardArea::BoardArea(GameLogic* gl, QWidget *parent) :
    QWidget(parent)
{
    gamelogic = gl;
    layout = new QVBoxLayout(parent);
    layout->setSpacing(0);
    layout->setMargin(0);
    QLabel *header = new QLabel("MastermInd");
    header->setStyleSheet("QLabel { font-size:40px; color : blue; font-family: Impact;}");
    layout->addWidget(header);
    answer = new AnswerArea(gl);
    answer->setMinimumSize(1,1);
    layout->addWidget(answer);

    for (int i = 0; i < 12; ++i)
    {
        RoundArea* round = new RoundArea();
        round->setMinimumSize(1,1);
        layout->addWidget(round);
        rounds.push_back(round);
    }
    layout -> addSpacing(5);
    controller = new ControllerArea(this);
    layout->addWidget(controller);
    label = new QLabel;
    layout->addWidget(label);
    this->setMinimumHeight(400); //Fixar så att man slipper dra ut fönstret vid varje start
    setLayout(layout);
}

//Funktion som kontrollerar spelarens gissning mot det korrekta svaret
void BoardArea::check(int c1, int c2, int c3, int c4)
{

    rounds.at(currentRound)->SetColors(c1,c2,c3,c4);
    vector<int> vec;
    vec.push_back(c1);
    vec.push_back(c2);
    vec.push_back(c3);
    vec.push_back(c4);

    pair<int,int> result=gamelogic->CheckAnswer(vec);

    rounds.at(currentRound)->SetResult(result);

    if(result.first==4) {
        answer->setV(true); //setVisible kunde inte användas så den heter setV(), tar bort gamla pieces och lägger till nya.
        PopUp pUp(12-currentRound);
        pUp.setModal(true);
        pUp.exec();
        newGame();
    }else if(currentRound!=0){
        currentRound--;
    }else{
        answer->setV(true); //setVisible kunde inte användas så den heter setV(), tar bort gamla pieces och lägger till nya.
        PopUp pUp(13);
        pUp.setModal(true);
        pUp.exec();
        newGame();
    }

}

//Skapar ett nytt spel, anropas vid tryck på newgame-knapp och vid programmets uppstart
void BoardArea::newGame() {
    gamelogic->GenerateAnswer();
    for (unsigned int i=0; i<12; i++) {
        rounds.at(i) -> SetColors(8,8,8,8);
        rounds.at(i) -> SetResult(std::pair<int,int>(0,0));
    }
    answer->removePieces();
    std::cout<<currentRound;
    currentRound = 11;
    controller->resetControls();
}
