/*
 * IDENTIFIERING
 *
 * Filnamn:    controllerarea.h
 * Enhetsnamn: ControllerArea
 * Typ:        Klassdeklaration
 * Revision:   1.0
 *
 *
 * BESKRIVNING
 *
 * Denna klass hanterar funktionaliteten kring användarens inmatningar och val.
 *
 */


#ifndef CONTROLLERAREA_H
#define CONTROLLERAREA_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <vector>
#include "boardarea.h"
class BoardArea;

class ControllerArea : public QWidget
{
    Q_OBJECT
public:
    explicit ControllerArea(QWidget *parent = 0);
    void resetControls();

signals:

public slots:
    void onCheck();

private:
    BoardArea* ba;
    std::vector<QComboBox*> controls;
    QPushButton* bCheck;

};

#endif
