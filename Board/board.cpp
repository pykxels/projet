#include "headerfile.h"



Board::Board()
{
    gotoXY(100,50);
    cout << endl << "Board created";
    matrix = new Pawn*[8]();
    for(int i(0); i < 8; i++)
        matrix[i]= new Pawn[8] {'\0','\0','\0','\0','\0','\0','\0','\0'};



}
Pawn** Board::getboard()
{
    return matrix;
}

void Board::setPawn(char _side, int rows, int colums)
{
    Pawn** m =getboard();
    m[rows][colums].setside(_side);

}

void Board::possibleMove(char _side, int rows, int colums)
{
    Pawn** m =getboard();


    char P;
    char C;
    if(_side=='\xFE')
    {
        P = '\xFE';
        C = 'O';

    }
    else
    {
        P = 'O';
        C = '\xFE';
    }



    if(rows+1<=7 && m[rows+1][colums].getside()==C)
    {

        for(int i(2); rows+i<8; i++)
        {
            if(m[rows+i][colums].getside()=='\0')
            break;

            if(m[rows+i][colums].getside()==P)
            {
                m[rows][colums].setside('*');
                break;
            }
        }
    }
    if (rows-1>=0 && m[rows-1][colums].getside()==C)
    {
        for(int i(2); rows-i>-1; i++)
        {
            if(m[rows-i][colums].getside()=='\0')
                break;
            if(m[rows-i][colums].getside()==P)
            {
                m[rows][colums].setside('*');
                break;
            }

        }
    }
    if (colums+1<=7 && m[rows][colums+1].getside()==C)
    {
        for(int i(2); colums+i<8; i++)
        {
            if(m[rows][colums+i].getside()=='\0')
            break;

            if(m[rows][colums+i].getside()==P)
            {
                m[rows][colums].setside('*');
                break;
            }
        }
    }
    if (colums-1>=0 &&  m[rows][colums-1].getside()==C )
    {
        for(int i(2); colums-i>-1; i++)
        {
            if(m[rows][colums-i].getside()=='\0')
                break;

            if(m[rows][colums-i].getside()==P)
            {
                m[rows][colums].setside('*');
                break;
            }

        }
    }
    if ( rows+1<=7 && colums+1<=7 && m[rows+1][colums+1].getside()==C )
    {
        for(int i(2); colums+i<8 && rows+i<8; i++)
        {
            if(m[rows+i][colums+i].getside()=='\0')
                break;

            if(m[rows+i][colums+i].getside()==P)
            {
                m[rows][colums].setside('*');
                break;
            }
        }
    }

    if (rows-1>=0 && colums+1<=7 && m[rows-1][colums+1].getside()==C )
    {
        for(int i(2); colums+i<8 && rows-i>-1; i++)
        {
            if(m[rows-i][colums+i].getside()=='\0')
                break;

            if(m[rows-i][colums+i].getside()==P)
            {


                m[rows][colums].setside('*');
                break;
            }
        }
    }
    if ( rows-1>=0 && colums-1>=0 && m[rows-1][colums-1].getside()==C )
    {
        for(int i(2); colums-i>-1 && rows-i>-1; i++)
        {
            if(m[rows-i][colums-i].getside()=='\0')
                break;

            if(m[rows-i][colums-i].getside()==P)
            {
                m[rows][colums].setside('*');
                break;
            }
        }
    }
    if ( rows+1<=7 && colums+1>=0 && m[rows+1][colums-1].getside()==C )
    {
        for(int i(2); colums-i>-1 && rows+i<8; i++)
        {
            if(m[rows+i][colums-i].getside()=='\0')
                break;

            if(m[rows+i][colums-i].getside()==P)
            {
                m[rows][colums].setside('*');
                break;
            }
        }
    }

}



void Board::sidechanger(char _side, int rows, int colums)
{
Pawn** m =getboard();


    char P;
    char C;
    if(_side=='\xFE')
    {
        P = '\xFE';
        C = 'O';

    }
    else
    {
        P = 'O';
        C = '\xFE';
    }






    if(rows+1<=7 && m[rows+1][colums].getside()==C)
    {

        for(int i(2); rows+i<8; i++)
        {
            if(m[rows+i][colums].getside()=='\0')
            break;

            if(m[rows+i][colums].getside()==P)
            {
                for(int j(1);  j<i;j++)
                    m[rows+j][colums].setside(P);
            }
        }
    }
    if (rows-1>=0 && m[rows-1][colums].getside()==C)
    {
        for(int i(2); rows-i>-1; i++)
        {
            if(m[rows-i][colums].getside()=='\0')
                break;
            if(m[rows-i][colums].getside()==P)
            {
                for(int j(1);j<i;j++)
                    m[rows-j][colums].setside(P);
            }

        }
    }
    if (colums+1<=7 && m[rows][colums+1].getside()==C)
    {
        for(int i(2); colums+i<8; i++)
        {
            if(m[rows][colums+i].getside()=='\0')
            break;

            if(m[rows][colums+i].getside()==P)
            {
                for(int j(1);j<i;j++)
                    m[rows][colums+j].setside(P);
            }
        }
    }
    if (colums-1>=0 &&  m[rows][colums-1].getside()==C )
    {
        for(int i(2); colums-i>-1; i++)
        {
            if(m[rows][colums-i].getside()=='\0')
                break;

            if(m[rows][colums-i].getside()==P)
            {
                for(int j(1);j<i;j++)
                    m[rows][colums-j].setside(P);
            }

        }
    }
    if ( rows+1<=7 && colums+1<=7 && m[rows+1][colums+1].getside()==C )
    {
        for(int i(2); colums+i<8 && rows+i<8; i++)
        {
            if(m[rows+i][colums+i].getside()=='\0')
                break;

            if(m[rows+i][colums+i].getside()==P)
            {
                for(int j(1);j<i;j++)
                    m[rows+j][colums+j].setside(P);
            }
        }
    }
    if (rows-1>=0 && colums+1<=7 && m[rows-1][colums+1].getside()==C )
    {
        for(int i(2); colums+i<8 && rows-i>-1; i++)
        {
            if(m[rows-i][colums+i].getside()=='\0')
                break;

            if(m[rows-i][colums+i].getside()==P)
            {
                for(int j(1);j<i;j++)
                m[rows-j][colums+j].setside(P);
            }
        }
    }
    if ( rows-1>=0 && colums-1>=0 && m[rows-1][colums-1].getside()==C )
    {
        for(int i(2); colums-i>-1 && rows-i>-1; i++)
        {
            if(m[rows-i][colums-i].getside()=='\0')
                break;

            if(m[rows-i][colums-i].getside()==P)
            {
                for(int j(1);j<i;j++)
                m[rows-j][colums-j].setside(P);
            }
        }
    }
    if ( rows+1<=7 && colums+1>=0 && m[rows+1][colums-1].getside()==C )
    {
        for(int i(2); colums-i>-1 && rows+i<8; i++)
        {
            if(m[rows+i][colums-i].getside()=='\0')
                break;

            if(m[rows+i][colums-i].getside()==P)
            {
                for(int j(1);j<i;j++)
                m[rows+j][colums-j].setside(P);
            }
        }
    }


}

