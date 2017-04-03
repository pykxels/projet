
#include "headerfile.h"




//This will set the position of the cursor

void gotoXY(int x, int y)
{

    //Initialize the coordinates

    COORD coord = {x, y};

    //Set the position

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    return;

}

void PawnDisplay (int rows, int columns, char sign)
{
    int x, y;
    x = 4 + columns * 8 ;
    y = 2 + rows * 4;

    gotoXY(x,y);
    if (sign=='*')
        SetColor(8); ///gris
    else if (sign=='\xFE')
        SetColor(17); ///bleu
    else if (sign=='O')
        SetColor(28); ///rouge
    cout << sign ;
    SetColor(7); ///blanc

}



int main ()
{
    Board* board = new Board();
    Pawn** m = board->getboard();
    Boarddisplay(m);
    const char P = '\xFE';
    const char C = 'O';
    const char possiblemove = '\xCF';
    board->setPawn(P,3,3);
    board->setPawn(C,3,4);
    board->setPawn(C,4,3);
    board->setPawn(P,4,4);
    Boarddisplay(m);
    char player = '1';
    int ctr=0;
    int Pctr=0;
    int Cctr=0;


    while(true)
    {


    if(player =='1')
    {
        for(int i(0); i<8; i++)
        {
            for(int j(0); j<8; j++)
            {
                if(m[i][j].getside()=='\0')
                {

                    board->possibleMove(P,i,j);
                }

            }
        }
    }

    if(player =='2')
    {
        for(int i(0); i<8; i++)
        {
            for(int j(0); j<8; j++)
            {
                if(m[i][j].getside()=='\0')
                {

                    board->possibleMove(C,i,j);
                }

            }
        }
    }

    Boarddisplay(m);


    /// Affichage des pions au centre


    // curseur
    int x=4;
    int y=2;
    char key;
    while(true)
    {

        gotoXY(x,y);

        key = getch();

        if(key=='a')
        {
            if (x!=4)

            {
                x=x-8;
                gotoXY(x,y);

            }

        }
        else if(key=='d')
        {
            if (x!=60)

            {
                x=x+8;
                gotoXY(x,y);
            }
        }
        else if(key=='s')
        {
            if (y!=30)

            {
                y=y+4;
                gotoXY(x,y);
            }
        }
        else if(key=='w')
        {
            if (y!=2)

            {
                y=y-4;
                gotoXY(x,y);
            }
        }

        else if (key == 'c')
            break;

        else if(key == '\r') ///place a pawn enter
        {
            if(player=='1')
            {
                if(m[(y-2)/4][(x-4)/8].getside() =='*')
                {
                    Pawnplacer(x,y,&board, P); ///placement des pions dans les cases possibles
                    for(int i(0); i<8; i++)
                    {
                        for(int j(0); j<8; j++)
                        {
                            if(m[i][j].getside() == '*')  ///enlever le reste des cases possibles apres le mouvement
                                m[i][j].setside('\0');
                        }
                    }
                    board->sidechanger(P,(y-2)/4,(x-4)/8);
                    break;
                }
            }
            if(player=='2') ///for player2
            {
                if(m[(y-2)/4][(x-4)/8].getside() =='*')
                {
                    Pawnplacer(x,y,&board, C); ///placement des pions dans les cases possibles
                    for(int i(0); i<8; i++)
                    {
                        for(int j(0); j<8; j++)
                        {
                            if(m[i][j].getside() == '*')  ///enlever le reste des cases possibles apres le mouvement
                                m[i][j].setside('\0');
                        }
                    }
                    board->sidechanger(C,(y-2)/4,(x-4)/8);
                    break;
                }
            }


        }


    }

    Boarddisplay(m);
    if (player=='1')
    {
        player='2';
        gotoXY(100,50);

    }

    else if (player=='2')
    {
        player='1';
        gotoXY(50,50);

    }
    ///si la matrice est pleine, end game
    for(int i(0); i<8; i++)
        {
            for(int j(0); j<8; j++)
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
    gotoXY(50,50);
    cout << "Noir (bleu) :"  << Pctr <<"              "<< "Blanc (rouge) : " << Cctr;
    if(ctr==64)
        break;

    ctr=0;
    Pctr=0;
    Cctr=0;
    }

    system("cls");
    if(Pctr>Cctr)
        cout << "PLAYER 1 WINS";
    else if(Pctr==Cctr)
        cout << "EGALITE!";
    else
        cout << "COMPUTER WINS";

    gotoXY(100,50);
    return 0;

}

void Pawnplacer(int x, int y, Board** board, char side)
{
    int columns=(x-4)/8;

    int rows = (y-2)/4;

    (*board)->setPawn(side,rows,columns);
}
void SetColor(int ForgC)
{
    WORD wColor;


    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;


    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {

        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}




