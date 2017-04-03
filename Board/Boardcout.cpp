#include "headerfile.h"

void Boarddisplay(Pawn** m){
    gotoXY(0,0);
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
            PawnDisplay(i,j,side);
        }
    }


}
