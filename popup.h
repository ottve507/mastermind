/*
 * IDENTIFIERING
 *
 * Filnamn:    popup.h
 * Enhetsnamn: PopUp
 * Typ:        Klassdeklaration
 * Revision:   1.0
 *
 *
 * BESKRIVNING
 *
 * Denna klass hanterar de popup-promptar som används i spelet.
 *
 */

#ifndef POPUP_H
#define POPUP_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>

class PopUp : public QDialog
{
    Q_OBJECT
public:
    explicit PopUp(int, QWidget *parent = 0);
    QPushButton* exitGame;
    QPushButton* newGame;
    QLabel* label;
    
signals:
    
public slots:
    void onExit();
    void onNewGame();
    
};

#endif
