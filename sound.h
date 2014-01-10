/*
 * IDENTIFIERING
 *
 * Filnamn:    sound.h
 * Enhetsnamn: Sound
 * Typ:        Klassdeklaration
 * Revision:   1.0
 *
 *
 * BESKRIVNING
 *
 * Denna klass innehåller funktioner rörande ljudet i spelet.
 *
 */

#ifndef SOUND_H
#define SOUND_H
#include <string>

class Sound
{
public:
    Sound();
    ~Sound();
    void playSound(std::string filename);
};

#endif
