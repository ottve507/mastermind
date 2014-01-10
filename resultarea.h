/*
 * IDENTIFIERING
 *
 * Filnamn:    resultarea.h
 * Enhetsnamn: ResultArea
 * Typ:        Klassdeklaration
 * Revision:   1.0
 *
 *
 * BESKRIVNING
 *
 * Denna klass hanterar de funktioner som rör varje rundas resultatområde.
 *
 */

#ifndef RESULTAREA_H
#define RESULTAREA_H

#include <QWidget>
#include <QColor>

class ResultArea : public QWidget
{
    Q_OBJECT
public:
    explicit ResultArea(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void SetResult(std::pair<int,int>);

signals:

public slots:

private:
    int correct_col=0;
    int correct_pos=0;
    QColor brushcolor();
};

#endif
