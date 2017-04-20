#include "Jeu.h"
/*
Curseur::Curseur(int x, int y)
{
    m_x=x;
    m_y=y;
}

void Curseur::setX (int x)
{
    m_x=x;
}
void Curseur::setY (int y)
{
    m_y=y;
}
void Curseur::moveW ()
{
    m_x-=8;
}
void Curseur::moveA ()
{
    m_y-=4;
}
void Curseur::moveS ()
{
    m_x+=8;
}
void Curseur::moveD ()
{
    m_y+=4;
}
int Curseur::getX()
{
    return m_x;
}
int Curseur::getY()
{
    return m_y;
}*/

void afficherCoupsPossibles(char player, Board* board,int taille,char P,char C, Pawn** m)
{
    // Affichage des mouvements possibles pour le joueur
    if(player =='1')
    {
        for(int i(0); i<taille; i++)
        {
            for(int j(0); j<taille; j++)
            {
                if(m[i][j].getside()=='\0')
                {

                    board->possibleMove(P,i,j);
                }
            }
        }
    }

    // Affichage des mouvements possibles pour l'ordinateur
    if(player =='2')
    {
        for(int i(0); i<taille; i++)
        {
            for(int j(0); j<taille; j++)
            {
                if(m[i][j].getside()=='\0')
                {
                    board->possibleMove(C,i,j);
                }
            }
        }
    }
}

bool Curseur (int taille, Console* commande, Pawn** m, char P, Board* board)
{
  // Curseur curseur (4,2);
  int x(4),y(2);
    char key;
    bool tour=0;
    commande->gotoLigCol(x,y);

    while (!tour)
    {
    key = getch();
    // Blindage du curseur pour ne pas sortir de la grille
    if(key=='a')
    {
        if (x!=4)
        {
            x=x-8;
            commande->gotoLigCol(x,y);
        }


    }
    else if(key=='d')
    {
        if (x!=60)
        {
            x=x+8;
            commande->gotoLigCol(x,y);
        }


    }
    else if(key=='s')
    {
        if (y!=30)
        {
            y=y+4;
            commande->gotoLigCol(x,y);
        }

    }
    else if(key=='w')
    {
        if (y!=2)
        {
            y=y-4;
            commande->gotoLigCol(x,y);
        }

    }
    else if(key == '\r') ///saisir "entrer" pour placer un pion
    {
        if(m[(y-2)/4][(x-4)/8].getside() =='*')
        {
            Pawnplacer(x,y,&board, P); ///placement du pion dans les cases possibles
            for(int i(0); i<8; i++)
            {
                for(int j(0); j<8; j++)
                {
                    if(m[i][j].getside() == '*')  ///enleve les cases possibles pour le prochain joueur
                        m[i][j].setside('\0');
                }
            }
            board->sidechanger(P,(y-2)/4,(x-4)/8);
            tour=1;
        }
    }

 }
 return tour;
}


vector<int> TourIA (int taille, Board* board,Pawn** m, char C)
{
    int ci=0, cj=0;
    vector<int> Cstar; // vecteur pour les coordonnees des mouvements possibles pour l'ORDINATEUR
    int randomint=0;

    for(int i(0); i<8; i++)
    {

        for(int j(0); j<8; j++)
        {
            if(m[i][j].getside() =='*')
            {
                Cstar.push_back(i);
                Cstar.push_back(j);
            }
        }
    }
    // Random coordinates du vecteur
    randomint = rand() % (Cstar.size()/2);
    randomint = randomint*2;
    ci=Cstar.at(randomint);
    cj=Cstar.at(randomint+1);


    Pawnplacer(cj*8+4,ci*4+2,&board, C);


    for(int i(0); i<8; i++)
    {
        for(int j(0); j<8; j++)
        {
            if(m[i][j].getside() == '*')  ///enleve les cases possibles pour le prochain joueur
                m[i][j].setside('\0');
        }

    }
    board->sidechanger(C,ci,cj);
    Cstar.clear(); //cleanse vecteur pour avoir des coordinees differentes adequates a chaque mouvement
    return Cstar;
}
