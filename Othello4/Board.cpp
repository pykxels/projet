#include "Board.h"

Board::Board(int taille)
{
    m_taille=taille;
    cout << endl << "Board created";
    matrix = new Pawn*[taille]();
    for(int i(0); i < taille; i++)
        matrix[i]= new Pawn[taille] {'\0','\0','\0','\0','\0','\0','\0','\0'};

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


    char p;
    char c;
    if(_side=='\xFE')
    {
        p = '\xFE';
        c = 'O';

    }
    else
    {
        p = 'O';
        c = '\xFE';
    }



    if(rows+1<=7 && m[rows+1][colums].getside()==c)
    {

        for(int i(2); rows+i<8; i++)
        {
            if(m[rows+i][colums].getside()=='\0' || m[rows+i][colums].getside()=='*')
            break;

            if(m[rows+i][colums].getside()==p)
            {
                m[rows][colums].setside('*');
                break;
            }
        }
    }
    if (rows-1>=0 && m[rows-1][colums].getside()==c)
    {
        for(int i(2); rows-i>-1; i++)
        {
            if(m[rows-i][colums].getside()=='\0' || m[rows-i][colums].getside()=='*')
                break;
            if(m[rows-i][colums].getside()==p)
            {
                m[rows][colums].setside('*');
                break;
            }

        }
    }
    if (colums+1<=7 && m[rows][colums+1].getside()==c)
    {
        for(int i(2); colums+i<8; i++)
        {
            if(m[rows][colums+i].getside()=='\0' || m[rows][colums+i].getside()=='*')
            break;

            if(m[rows][colums+i].getside()==p)
            {
                m[rows][colums].setside('*');
                break;
            }
        }
    }
    if (colums-1>=0 &&  m[rows][colums-1].getside()==c )
    {
        for(int i(2); colums-i>-1; i++)
        {
            if(m[rows][colums-i].getside()=='\0' || m[rows][colums-i].getside()=='*')
                break;

            if(m[rows][colums-i].getside()==p)
            {
                m[rows][colums].setside('*');
                break;
            }

        }
    }
    if ( rows+1<=7 && colums+1<=7 && m[rows+1][colums+1].getside()==c )
    {
        for(int i(2); colums+i<8 && rows+i<8; i++)
        {
            if(m[rows+i][colums+i].getside()=='\0' || m[rows+i][colums+i].getside()=='*')
                break;

            if(m[rows+i][colums+i].getside()==p)
            {
                m[rows][colums].setside('*');
                break;
            }
        }
    }

    if (rows-1>=0 && colums+1<=7 && m[rows-1][colums+1].getside()==c )
    {
        for(int i(2); colums+i<8 && rows-i>-1; i++)
        {
            if(m[rows-i][colums+i].getside()=='\0' || m[rows-i][colums+i].getside()=='*')
                break;

            if(m[rows-i][colums+i].getside()==p)
            {


                m[rows][colums].setside('*');
                break;
            }
        }
    }
    if ( rows-1>=0 && colums-1>=0 && m[rows-1][colums-1].getside()==c )
    {
        for(int i(2); colums-i>-1 && rows-i>-1; i++)
        {
            if(m[rows-i][colums-i].getside()=='\0' || m[rows-i][colums-i].getside()=='*')
                break;

            if(m[rows-i][colums-i].getside()==p)
            {
                m[rows][colums].setside('*');
                break;
            }
        }
    }
    if ( rows+1<=7 && colums+1>=0 && m[rows+1][colums-1].getside()==c )
    {
        for(int i(2); colums-i>-1 && rows+i<8; i++)
        {
            if(m[rows+i][colums-i].getside()=='\0' || m[rows+i][colums-i].getside()=='*')
                break;

            if(m[rows+i][colums-i].getside()==p)
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

    char p;
    char c;
    if(_side=='\xFE')
    {
        p = '\xFE';
        c = 'O';
    }
    else
    {
        p = 'O';
        c = '\xFE';
    }

    if(rows+1<=7 && m[rows+1][colums].getside()==c)
    {
        for(int i(2); rows+i<8; i++)
        {
            if(m[rows+i][colums].getside()=='\0' ||m[rows+i][colums].getside()== '*')
            break;

            if(m[rows+i][colums].getside()==p)
            {
                for(int j(1);  j<i;j++)
                    m[rows+j][colums].setside(p);
            }
        }
    }
    if (rows-1>=0 && m[rows-1][colums].getside()==c)
    {
        for(int i(2); rows-i>-1; i++)
        {
            if(m[rows-i][colums].getside()=='\0' || m[rows-i][colums].getside()=='*')
                break;
            if(m[rows-i][colums].getside()==p)
            {
                for(int j(1);j<i;j++)
                    m[rows-j][colums].setside(p);
            }
        }
    }
    if (colums+1<=7 && m[rows][colums+1].getside()==c)
    {
        for(int i(2); colums+i<8; i++)
        {
            if(m[rows][colums+i].getside()=='\0' || m[rows][colums+i].getside()=='*' )
            break;

            if(m[rows][colums+i].getside()==p)
            {
                for(int j(1);j<i;j++)
                    m[rows][colums+j].setside(p);
            }
        }
    }
    if (colums-1>=0 &&  m[rows][colums-1].getside()==c )
    {
        for(int i(2); colums-i>-1; i++)
        {
            if(m[rows][colums-i].getside()=='\0' || m[rows][colums-i].getside()=='*')
                break;

            if(m[rows][colums-i].getside()==p)
            {
                for(int j(1);j<i;j++)
                    m[rows][colums-j].setside(p);
            }

        }
    }
    if ( rows+1<=7 && colums+1<=7 && m[rows+1][colums+1].getside()==c )
    {
        for(int i(2); colums+i<8 && rows+i<8; i++)
        {
            if(m[rows+i][colums+i].getside()=='\0' || m[rows+i][colums+i].getside()=='*')
                break;

            if(m[rows+i][colums+i].getside()==p)
            {
                for(int j(1);j<i;j++)
                    m[rows+j][colums+j].setside(p);
            }
        }
    }
    if (rows-1>=0 && colums+1<=7 && m[rows-1][colums+1].getside()==c )
    {
        for(int i(2); colums+i<8 && rows-i>-1; i++)
        {
            if(m[rows-i][colums+i].getside()=='\0' || m[rows-i][colums+i].getside()=='*')
                break;

            if(m[rows-i][colums+i].getside()==p)
            {
                for(int j(1);j<i;j++)
                m[rows-j][colums+j].setside(p);
            }
        }
    }
    if ( rows-1>=0 && colums-1>=0 && m[rows-1][colums-1].getside()==c )
    {
        for(int i(2); colums-i>-1 && rows-i>-1; i++)
        {
            if(m[rows-i][colums-i].getside()=='\0' || m[rows-i][colums-i].getside()=='*')
                break;

            if(m[rows-i][colums-i].getside()==p)
            {
                for(int j(1);j<i;j++)
                m[rows-j][colums-j].setside(p);
            }
        }
    }
    if ( rows+1<=7 && colums+1>=0 && m[rows+1][colums-1].getside()==c )
    {
        for(int i(2); colums-i>-1 && rows+i<8; i++)
        {
            if(m[rows+i][colums-i].getside()=='\0' || m[rows+i][colums-i].getside()=='*')
                break;

            if(m[rows+i][colums-i].getside()==p)
            {
                for(int j(1);j<i;j++)
                m[rows+j][colums-j].setside(p);
            }
        }
    }

}
