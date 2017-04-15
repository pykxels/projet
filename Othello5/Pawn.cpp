#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(char _side)
{
    side=_side;
}
Pawn::~Pawn() {}

Pawn::Pawn() {}

char  Pawn::getside()
{
    return side;
}

void Pawn::setside(char _side)
{
    side=_side;
}
