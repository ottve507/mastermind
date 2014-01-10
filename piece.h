/*
 * IDENTIFIERING
 *
 * Filnamn:    piece.h
 * Enhetsnamn: Piece
 * Typ:        Klassdeklarationer
 * Revision:   1.0
 *
 *
 * BESKRIVNING
 *
 * Denna fil innehåller deklarationer till klasserna Piece och HiddenPiece respektive VisiblePiece som
 * ärver från Piece. Klasserna innehåller funktionaliteten för att måla upp en grafisk "plupp"
 *.
 *
 */


#ifndef PIECE_H
#define PIECE_H

#include <QWidget>
#include <QColor>

class Piece
{
public:
    ~Piece() = default;
    virtual void paintEvent(QPaintEvent *) = 0;
    virtual void setVisi(bool) = 0;
};


class VisiblePiece : public QWidget, public Piece
{
    Q_OBJECT
public:
    explicit VisiblePiece(int col = 8, QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void SetColor(int);
    void setVisi(bool);

signals:

public slots:

private:
    int color;
    QColor colours[9] = {QColor("red"), QColor("green"), QColor("blue"), QColor("yellow"),
                         QColor("pink"), QColor("orange"), QColor("black"), QColor("purple"), QColor("white")};
};


class HiddenPiece : public QWidget, public Piece
{
    Q_OBJECT
public:
    HiddenPiece(QWidget *parent=0);
    void paintEvent(QPaintEvent *);
    void setVisi(bool) {;}
private:

};


#endif
