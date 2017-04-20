#include "GestionPlateau.h"
#include "libmain.h"


int selectionTaille ()
{
    int taille(8);
    //cout << "Choisir le nombre de colonnes/lignes du plateau"<<endl;
    //cin >> taille;
    return taille;
}

void initialization (Board* board, char P, char C)
{
    // Affichage des pion du debut de jeu
    board->setPawn(C,3,3);
    board->setPawn(P,3,4);
    board->setPawn(P,4,3);
    board->setPawn(C,4,4);
}

void PawnDisplay (int rows, int columns, char sign, Console* commande)
{
    /// Les coordonnees de la matrice pour les coordinees de la grille
    int x, y;
    x = 4 + columns * 8 ;
    y = 2 + rows * 4;

    commande -> gotoLigCol(x,y);
    if (sign=='*')
        commande->setColor(COLOR_GREY); ///gris
    else if (sign=='\xFE')
        commande->setColor(COLOR_BLUE); ///bleu
    else if (sign=='O')
        commande->setColor(COLOR_RED); ///rouge
    cout << sign ;
    commande->setColor(COLOR_WHITE); ///blanc
}


// placement des pions
void Pawnplacer(int x, int y, Board** board, char side)
{
    int columns=(x-4)/8;

    int rows = (y-2)/4;

    (*board)->setPawn(side,rows,columns);
}


void Boarddisplay (Pawn** m, Console* commande)
{
// Box edges and corners (all double thick line)
// T for top, B for bottom, L for left, R for right
// Conversion Hexadecimale a Decimal
    const char TB = '\xCD'; // 205
    const char LR = '\xBA'; // 186
    const char TL = '\xC9'; // 201
    const char TR = '\xBB'; // 187
    const char BL = '\xC8'; // 200
    const char BR = '\xBC'; // 188

    const char C = '\xB8';
    const char TM= '\xCB'; //209
    const char BM='\xCA'; // 208
    const char LM='\xCC'; //
    const char MM='\xCE'; //
    const char RM='\xB9'; //

    commande->gotoLigCol(0,0);

///first row
    cout << TL;
    for(int i=0; i<7; i++)
    {

        for(int i=0; i<7; i++)
            cout << TB;
        cout<<TM;

    }

    for(int i=0; i<7; i++)
        cout << TB;

    cout<< TR;

    cout<<endl;

    ///7 rows inbetween (espaces et bottom bars)

    for(int i=0; i<7; i++)
    {

        for(int i=0; i<3; i++)
        {
            cout<< LR;
            for(int i=0; i<8; i++)
                cout << "       " << LR;
            cout <<endl;
        }

        cout << LM;
        for(int i=0; i<7; i++)
            cout << TB << TB << TB << TB << TB << TB << TB << MM;
        cout << TB << TB << TB << TB << TB << TB << TB << RM;
        cout<< endl;
    }

    ///last row
    for(int i=0; i<3; i++)
    {
        cout<< LR;
        for(int i=0; i<8; i++)
            cout << "       " << LR;
        cout <<endl;
    }

    cout << BL;
    for(int i=0; i<7; i++)
        cout << TB << TB << TB << TB << TB << TB << TB << BM;
    cout << TB << TB << TB << TB << TB << TB << TB << BR;


    char side;
    for(int i(0); i < 8; i++)
    {
        for(int j(0); j < 8; j++)
        {
            side = m[i][j].getside();
            if(side!='\0')
            PawnDisplay(i,j,side,commande);
        }
    }
}

