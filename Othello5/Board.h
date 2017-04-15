#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include "libmain.h"
#include "Pawn.h"

class Pawn
{

public:
    Pawn(char _side);
    ~Pawn();
    Pawn();
    char getside();
    void setside(char _side);

private:
    char side;
};
// classe pour le tableau
class Board
{
private:
    Pawn** matrix;
    int m_taille;
public:
    Board(int taille);
    Pawn** getboard();
    void setPawn(char _side, int rows, int colums);
    void possibleMove(char _side, int rows, int colums);
    void sidechanger(char _side, int rows, int colums);
    void save();
    void nettoyer();
    char load();
};

void Pawnplacer(int x, int y, Board** board, char side);


#endif // BOARD_H_INCLUDED
