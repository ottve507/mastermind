/*
 * IDENTIFIERING
 *
 * Filnamn:    gamelogic.h
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

#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <vector>
#include "sound.h"

class GameLogic
{
private:
    std::vector<int> correctanswer;
    Sound sound;

public:
    GameLogic();
    std::pair<int,int> CheckAnswer(std::vector<int> guess);
    void GenerateAnswer();
    std::vector<int> getAnswer();

};

#endif
