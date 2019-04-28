//
//  datetime.c
//  ueb01X
//
//  Created by Tom Mertens on 20.04.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#include <stdio.h>
#include "datetime.h"
#include "tools.h"
#include "datastructure.h"
/***************************************************************************
 Funktion:  isLeapYear
 Parameter: Jahreszahl als int
 Ergebnis:  Wahrheitswert
 Beschreib: Wahr = Jahr ist ein Schaltjahr
 ***************************************************************************/
int isLeapYear(int year)
{   int leapYear = 0;
    if ((year & 4) == 0)
        if ((leapYear & 100) == 0)
                if ((leapYear & 400) == 0)
                    leapYear = 1;
                else
                    leapYear = 0;
        else
            leapYear = 1;
        
    else
        leapYear = 0;
    
    return leapYear;
}
/***************************************************************************
 Funktion:  isDateValid
 Parameter: struct TDate
 Ergebnis:  Wahrheitswert als int
 Beschreib: Angeben ob das uebergebene Datum gueltig ist
 ***************************************************************************/
int isDateValid(TDate Date)
{
    
}
/***************************************************************************
 Funktion:  isTimeValid
 Parameter: struct TTime
 Ergebnis:  Wahrheitswert als int
 Beschreib: Angeben ob die uebergebene Uhrzeit gueltig ist
 ***************************************************************************/
int isTimeValid(TTime Time)
{
    
}
/***************************************************************************
 Funktion:  getDateFromString
 Parameter: *char Input, *TDate
 Ergebnis:  Wahrheitswert als int bei erfolgreichem Kopieren
 Beschreib: Liest ein Datum aus einer Zeichenkette und kopiert die in Struct, ruft IsDateValid auf
 ***************************************************************************/
int getDateFromString(char *Input, TDate *Date)
{
    
    
}
/***************************************************************************
 Funktion:  getTimeFromString
 Parameter: *char Input, *TTime
 Ergebnis:  Wahrheitswert als int bei erfolgreichem Kopieren
 Beschreib: Liest eine Zeit aus einer Zeichenkette und kopiert die in Struct, ruft IsTimeValid auf
 ***************************************************************************/
int getTimeFromString(char *Input, TTime *Time)
{
    
}
/***************************************************************************
 Funktion:  askYesOrNo
 Parameter: char string (Userprompt)
 Ergebnis:  Wahrheitswert als int
 Beschreib: Zeigt dem User einen Text (Aufforderung) Liest j/n Antwort ein
 ***************************************************************************/
int askYesOrNo(char *Prompt)
{   char ans;
    int ask;
    do
    {   printf("\n");
        printf(*Prompt);
        printf("\n");
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

/***************************************************************************
 Funktion:
 Parameter:
 Ergebnis:
 Beschreib:
 ***************************************************************************/

/***************************************************************************
 Funktion:
 Parameter:
 Ergebnis:
 Beschreib:
 ***************************************************************************/

/***************************************************************************
 Funktion:
 Parameter:
 Ergebnis:
 Beschreib:
 ***************************************************************************/

/***************************************************************************
 Funktion:
 Parameter:
 Ergebnis:
 Beschreib:
 ***************************************************************************/

/***************************************************************************
 Funktion:
 Parameter:
 Ergebnis:
 Beschreib:
 ***************************************************************************/

/***************************************************************************
 Funktion:
 Parameter:
 Ergebnis:
 Beschreib:
 ***************************************************************************/

/***************************************************************************
 Funktion:
 Parameter:
 Ergebnis:
 Beschreib:
 ***************************************************************************/

/***************************************************************************
 Funktion:
 Parameter:
 Ergebnis:
 Beschreib:
 ***************************************************************************/

/***************************************************************************
 Funktion:
 Parameter:
 Ergebnis:
 Beschreib:
 ***************************************************************************/

/***************************************************************************
 Funktion:
 Parameter:
 Ergebnis:
 Beschreib:
 ***************************************************************************/

/***************************************************************************
 Funktion:
 Parameter:
 Ergebnis:
 Beschreib:
 ***************************************************************************/
