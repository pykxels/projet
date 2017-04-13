#include "libmain.h"

using namespace std;

void initialization (Board* board, char P, char C);
void Boarddisplay (Pawn** m,Console* commande);
void afficherCoupsPossibles(char player, Board* board,int taille,char P,char C, Pawn** m);
vector<int> TourIA (int taille, Board* board,Pawn** m, char C);
bool Curseur (int taille, Console* commande, Pawn** m, char P, Board* board);
void PawnDisplay (int rows, int columns, char sign, Console* commande);

int main()
{
    srand (time(NULL));
    int taille = selectionTaille();
    bool fin(0);
    const char P = '\xFE'; // Caractere pour le joeur
    const char C = 'O'; // Joueur = ordinateur


    Console* commande;
    Board* board = new Board(taille);
    Pawn** m = board->getboard(); // matrice des pions
    commande->gotoLigCol(0,0);
    Boarddisplay(m,commande);

    initialization (board, P,C);

    // Le joueur commmence
    char player = '1';
    vector<int> Cstars; // vecteur pour les coordonnees des mouvements possibles pour l'ORDINATEUR
    int randomint=0;


 int ctr(0), Pctr(0), Cctr(0);
commande->gotoLigCol(0,0);
    while(fin==0)
    {
        bool tour(0);
        int ctr(0),Pctr(0),Cctr(0);
        commande->gotoLigCol(4,2);

        afficherCoupsPossibles(player, board,taille,P,C, m);

        // Affichage matrice
        Boarddisplay(m,commande);
        commande->gotoLigCol(4,2);

        for(int i(0); i<taille; i++)
        {
            for(int j(0); j<taille; j++)
            {
                if(m[i][j].getside()!='\0')
                {
                    ctr++;
                    if(m[i][j].getside()==P)
                        Pctr++;
                    if(m[i][j].getside()==C)
                        Cctr++;
                }
            }
        }
                if(ctr==64)
            fin=1;
        else
        {
        Sleep(500);
        commande->gotoLigCol(70,5);
        cout << "Noir (bleu) :"  << Pctr <<"              "<< "Blanc (rouge) : " << Cctr;
        while(!tour && player=='1') //
        {
           tour=Curseur(taille, commande,m,P,board);
        }

        // Mouvements possibles pour l'ordinateur mis dans un vecteur
        if (player=='2')
            Cstars=TourIA(taille,board,m,C);

        Boarddisplay(m,commande);
        // changement du tour
       if (player=='1')
        {
            player='2';
        }
        else if (player=='2')
        {
            player='1';
        }

}

       // commande->gotoLigCol(30,10);
       // cout << "Noir (bleu) :"  << Pctr <<"              "<< "Blanc (rouge) : " << Cctr;

    }

    system("cls");
    commande->gotoLigCol(20,30);
    cout << "Noir (bleu) :"  << Pctr <<"              "<< "Blanc (rouge) : " << Cctr;
    if(Pctr>Cctr)
        cout << "PLAYER 1 WINS";
    else if(Pctr==Cctr)
        cout << "EGALITE!";
    else
        cout << "COMPUTER WINS";

    commande->gotoLigCol(100,50);
    return 0;

}
