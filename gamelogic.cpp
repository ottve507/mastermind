/*
 * IDENTIFIERING
 *
 * Filnamn:    gamelogic.cpp
 * Enhetsnamn: GameLogic
 * Typ:        Klassdeklaration
 * Revision:   1.0
 *
 *
 * BESKRIVNING
 *
 * Innehåller logiken bakom spelet.
 *
 *
 */

#include "gamelogic.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

GameLogic::GameLogic()
{
    GenerateAnswer();
}

//Funktion som kontrollerar användarens svar mot det korrekta.
std::pair<int,int> GameLogic::CheckAnswer(std::vector<int> guess)
{
    std::vector<int> rightanswer = correctanswer;
    std::vector<int> guesses = guess;
    std::pair<int, int> tupphona (0,0);

    for (int i=0; i<4; i++) {
        if (rightanswer.at(i)==guesses.at(i)) {
            tupphona.first++;
            guesses.at(i)=10;
            rightanswer.at(i)=9;
        }
    }
    for (int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if(guesses.at(i)==rightanswer.at(j)){
                tupphona.second++;
                guesses.at(i)=10;
                rightanswer.at(j)=9;
            }
        }
    }
    switch (tupphona.first)
    {
    case 0:
        sound.playSound("shortGiggles.mp3");
        break;
    case 1:
        sound.playSound("Balloon1.mp3");
        break;
    case 2:
        sound.playSound("Balloon2.mp3");
        break;
    case 3:
        sound.playSound("Balloon3.mp3");
        break;
    case 4:
        sound.playSound("Balloon4.mp3");
        break;
    }

    return tupphona;
}

//Funktion som skapar ett nytt svar.
void GameLogic::GenerateAnswer() {
    std::vector<int> temp (4,0);
    srand (time(NULL));
    for (int i=0; i<4; i++) {
        temp.at(i) = rand() % 8;
    }
    correctanswer = temp;
}

//Funktion som returnerar korrekt svar.
std::vector<int> GameLogic::getAnswer(){
    return correctanswer;
}
