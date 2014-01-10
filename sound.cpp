/*
 * IDENTIFIERING
 *
 * Filnamn:    sound.cpp
 * Enhetsnamn: Sound
 * Typ:        Klassdefinition
 * Revision:   1.0
 *
 *
 * BESKRIVNING
 *
 * Denna klass innehåller funktioner rörande ljudet i spelet.
 *
 */
#include <iostream>
#include <stdio.h>
#include "sound.h"
#include <QMediaPlayer>
#include <QCoreApplication>


Sound::Sound()
{}

Sound::~Sound()
{}

void Sound::playSound(std::string filename)
{
    QMediaPlayer *player = new QMediaPlayer;
    QMediaContent media(QUrl::fromLocalFile(QCoreApplication::applicationDirPath()+"/../../../" + filename.c_str()));

    player->setMedia(media);
    player->play();
}
