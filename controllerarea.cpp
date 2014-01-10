/*
 * IDENTIFIERING
 *
 * Filnamn:    controllerarea.cpp
 * Enhetsnamn: ControllerArea
 * Typ:        Klassdefinition
 * Revision:   1.0
 *
 *
 * BESKRIVNING
 *
 * Denna klass hanterar funktionaliteten kring användarens inmatningar och val.
 *
 */

#include "controllerarea.h"
#include <QHBoxLayout>
#include <iostream>

//Konstruktor, skapar de fyra "rullgardinerna" samt sätter layouten för området.
ControllerArea::ControllerArea(QWidget *parent) :
    QWidget(parent)
{
    ba = static_cast<BoardArea*> (parent);
    QHBoxLayout* layout = new QHBoxLayout;
    layout->setSpacing(10);
    layout->setMargin(0);
    for (int i = 0; i < 4; ++i)
    {
        QComboBox* cb = new QComboBox;
        cb->setStyleSheet("QComboBox {background-color:rgb(170,200,203);}");
        cb->addItem("RED");
        cb->addItem("GREEN");
        cb->addItem("BLUE");
        cb->addItem("YELLOW");
        cb->addItem("PINK");
        cb->addItem("ORANGE");
        cb->addItem("BLACK");
        cb->addItem("PURPLE");
        cb->show();
        layout->addWidget(cb);
        controls.push_back(cb);
    }
    layout->addSpacing(10);
    bCheck = new QPushButton("Check");
    bCheck->setStyleSheet("QPushButton {background-color:rgb(50,100,100);}");
    QObject::connect(bCheck, SIGNAL(clicked()), this, SLOT(onCheck()));
    layout->addWidget(bCheck);

    setLayout(layout);
}

//Läser av spelarens val och skickar dessa vidare. Anropas då spelaren trycker på Check-knappen
void ControllerArea::onCheck()
{
    int c1 = controls[0]->currentIndex();
    int c2 = controls[1]->currentIndex();
    int c3 = controls[2]->currentIndex();
    int c4 = controls[3]->currentIndex();

    ba->check(c1, c2, c3, c4);
}

//Återställer rullgardinerna. Anropas vid nytt spel.
void ControllerArea::resetControls(){
    controls[0]->setCurrentIndex(0);
    controls[1]->setCurrentIndex(0);
    controls[2]->setCurrentIndex(0);
    controls[3]->setCurrentIndex(0);
}
