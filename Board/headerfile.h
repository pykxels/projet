#ifndef HEADERFILE_H_INCLUDED
#define HEADERFILE_H_INCLUDED
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;
class Pawn{

public:
Pawn(char _side);
~Pawn();
Pawn();
char getside();
void setside(char _side);

private:
    char side;
};

class Board{

private:
Pawn** matrix;
public:
Board();
Pawn** getboard();
void setPawn(char _side, int rows, int colums);
void possibleMove(char _side, int rows, int colums);
void sidechanger(char _side, int rows, int colums);
};




void gotoXY(int x, int y);
void PawnDisplay (int rows, int columns, char sign);
void Boarddisplay(Pawn** m);
void Pawnplacer(int x, int y, Board** board, char side);
void SetColor(int ForgC);

#endif // HEADERFILE_H_INCLUDED
