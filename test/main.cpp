#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;

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
    cout << sign ;

}


int main ()
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
    const char R = '\xFE';
    const char C = '\xB8';
    const char TM= '\xCB'; //209
    const char BM='\xCA'; // 208
    const char LM='\xCC'; //
    const char MM='\xCE'; //
    const char RM='\xB9'; //

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



    ///} Affichage des pions au centre
    gotoXY(28,14);
    cout << R;
    gotoXY(36,14);
    cout << C;
    gotoXY(28,18);
    cout << C;
    gotoXY(36,18);
    cout << R;

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
            if (x==4)
                x=4;
            else
            {
            x=x-8;
            gotoXY(x,y);

            }

        }
        else if(key=='d')
        {
            if (x==60)
                x=60;
            else
            {
                x=x+8;
                gotoXY(x,y);
            }
        }
        else if(key=='s')
        {
            if (y==30)
                y=30;
            else
            {
            y=y+4;
            gotoXY(x,y);
            }
        }
        else if(key=='w')
        {
            if (y==2)
                y=2;
            else
            {
            y=y-4;
            gotoXY(x,y);
            }
        }

        else if (key = 'v')
            break;

    }

    // exemple affichage

    PawnDisplay(1,7,'A');

    gotoXY(100,50);

    return 0;
}
