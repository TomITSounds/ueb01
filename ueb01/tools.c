//
//  tools.c
//  ueb01X
//
//  Created by Tom Mertens on 20.04.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#include <stdio.h>
#include "tools.h"
#include <stdlib.h>

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
int askYesOrNo(char *Prompt)
 {   char ans;
 int ask;
 do
 {   printf("\n");
 printf(Prompt);
 printf("\n");
 scanf("%c", &ans);
 if (ans != '\n')
 clearBuffer();
 switch (ans)
 {   case 'j':
 case 'J':   ask = 1; break;
 case 'n':
 case 'N':   ask = 0; break;
 default:    printf("Ungueltige Eingabe.\nWollen sie nochmal? j/n\n");
 }
 }  while ( (ans != 'j') && (ans != 'J') && (ans != 'N') && (ans !='n') );
 return ask;
 }

/**********************************************************
 * Funktion: waitForEnter
 * Beschreibung:
 Parameter:
 *Ergebnis:
 **********************************************************/
void waitForEnter()
{
    
}

/**********************************************************
 * Funktion:        ClearScreen
 * Beschreibung:    Loescht den Bildschirm
 Parameter:
 *Ergebnis:
 **********************************************************/
void clearScreen()
{   system("clear");
    system("cls");
}
