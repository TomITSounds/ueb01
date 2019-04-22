//
//  tools.c
//  ueb01X
//
//  Created by Tom Mertens on 20.04.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#include <stdio.h>
#include "escapesequenzen.h"
#include "tools.h"

/**********************************************************
 * Funktion: clearBuffer
 * Beschreibung: Leert den Tasturpuffer
 * Parameter: Character
 * Ergebnis:
 **********************************************************/
void clearBuffer()
{  char dummy;
    do
    {  scanf("%c", &dummy);
    }  while (dummy != '\n');
}

/**********************************************************
 * Funktion: askAgain
 * Beschreibung: Fragt den Benutzer ob er dass Programm nochmal ausfuehren moecht
 Parameter: Zeile und Spalte der Frage
 *Ergebnis: Wahrheitswert
 **********************************************************/
int askAgain(int Row, int Col)
{  int ask = 0;
    char ans = 0;
    
    POSITION(Row, Col);
    printf("Wolle sie nochmal? j/n\n");
    do
    {  POSITION (Row+1, Col);
        CLEAR_LINE;
        scanf("%c", &ans);
        if (ans != '\n')
            clearBuffer();
        switch (ans)
        {   case 'j':
            case 'J':   ask = 1; break;
            case 'n':
            case 'N':   ask = 0; break;
            default:    printf("Ungueltige Eingabe. Wollen sie nochmal? j/n\n");
        }
    }  while ( (ans != 'j') && (ans != 'J') && (ans != 'N') && (ans !='n') );
    return ask;
}

void stop()
{  char c;
    do
    {  scanf("%c", &c);
    }  while (c != '\n');
}

/**********************************************************
 * Funktion: waitForEnter
 * Beschreibung:
 Parameter:
 *Ergebnis:
 **********************************************************/
void ClearScreen()

/**********************************************************
 * Funktion:        ClearScreen
 * Beschreibung:    Loescht den Bildschirm
 Parameter:
 *Ergebnis:
 **********************************************************/
void ClearScreen()
