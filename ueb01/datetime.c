
Skip to content
Pull requests
Issues
Marketplace
Explore
@TomITSounds

0
0

0

TomITSounds/ueb01
Code
Issues 0
Pull requests 1
Projects 1
Wiki
Insights
Settings
ueb01/ueb01-master.2/ueb01/datetime.c
@freddiefreund freddiefreund Add files via upload db0c154 11 hours ago
345 lines (315 sloc) 10.1 KB
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
    int YearMax=2050;
    int YearMin=2018;
    
    //Jahr gueltig ?
    if (Date->Year < YearMin || Date->Year > YearMax)
    {
        return 0;
    }
    
    int DayMax;
    
    switch (Date->Month){                           //versch. Cases für alle Monate
            
        case 1: DayMax=31;
            break;
        case 2: if(isLeapYear(Date->Year)){
            DayMax=29;
        } else
            DayMax=28;
            break;
        case 3: DayMax=31;
            break;
        case 4: DayMax=30;
            break;
        case 5: DayMax=31;
            break;
        case 6: DayMax=30;
            break;
        case 7: DayMax=31;
            break;
        case 8: DayMax=31;
            break;
        case 9: DayMax=30;
            break;
        case 10: DayMax=31;
            break;
        case 11: DayMax=30;
            break;
        case 12: DayMax=31;
            break;
            
        default:    return 0;
            break;
    }
    
    // Tag gueltig ?
    if(Date->Day < 1 || Date->Day > DayMax)
    {
        return 0;
    }
    
    return 1;
}
/***************************************************************************
 Funktion:  isTimeValid
 Parameter: struct TTime
 Ergebnis:  Wahrheitswert als int
 Beschreib: Angeben ob die uebergebene Uhrzeit gueltig ist
 ***************************************************************************/
int isTimeValid(TTime Time)
{
    // Stunden gueltig ?
    if(Time->Hour < 0 || Time->Hour > 23)
        return 0;
    
    // Minuten gueltig ?
    if(Time->Minute < 0 || Time->Minute > 59)
        return 0;
    
    // Sekunden gueltig ?
    if(Time->Second < 0 || Time->Second > 59)
        return 0;
    
    // Wenn alles gueltig
    return 1;
}
/***************************************************************************
 Funktion:  getDateFromString
 Parameter: char *Input, TDate *Date
 Ergebnis:  Wahrheitswert als int bei erfolgreichem Kopieren
 Beschreib: Liest ein Datum aus einer Zeichenkette und kopiert die in Struct, ruft IsDateValid auf
 ***************************************************************************/
int getDateFromString(char *Input, TDate *Date)
{
    int i,j;
    char *inputCount = input;
    char *dayArray;
    char *monthArray;
    char *yearArray;
    *dayArray = '\0';       // Fuer den Fall, dass der Nutzer
    *monthArray = '\0';     // nur einen Punkt eingibt, werden
    *yearArray = '\0';      // Tag,Monat,Jahr auf Null gesetzt.
    
    for(i = 0; i < 3; i ++)
    {
        j = 0;
        while(*inputCount != '.' && *inputCount != '\n')
        {
            if(*inputCount)
            {
                switch(i)      // Bei jedem for durchlauf wird ein anderer Wert geprueft
                {
                    case 0: *(dayArray+j) = *inputCount;    // bei i=0 wird Day beschrieben
                        break;
                    case 1: *(monthArray+j) = *inputCount;  // bei i=1 wird Month beschrieben
                        break;
                    case 2: *(yearArray+j) = *inputCount;   // bei i=2 wird year beschrieben
                        break;
                }
            }
            else
                return 0;
            inputCount ++;
            j ++;
        }
        if(*inputCount == '\n' && i < 2)
            return 0;
        switch(i)           // Das letzte Zeichen der Arrays auf \0 setzen...
        {
            case 0: *(dayArray+j) = '\0';
                break;
            case 1: *(monthArray+j) = '\0';
                break;
            case 2: *(yearArray+j) = '\0';
                break;
        }
        inputCount ++;
    }
    
    newDate->Day = atoi(dayArray);
    newDate->Month = atoi(monthArray);
    newDate->Year = atoi(yearArray);
    if(isDateValid(newDate))
        return 1;
    else
        return 0;
}
/***************************************************************************
 Funktion:  getTimeFromString
 Parameter: *char Input, *TTime
 Ergebnis:  Wahrheitswert als int bei erfolgreichem Kopieren
 Beschreib: Liest eine Zeit aus einer Zeichenkette und kopiert die in Struct, ruft IsTimeValid auf
 ***************************************************************************/
int getTimeFromString(char *Input, TTime *Time)
{
    char *StdArray;
    char *MinArray;
    char *SekArray;
    StdArray = '\0'; // wegen moeglicher Fehleingabe
    MinArray = '\0'; // auf \0 setzen
    SekArray = '\0';
    
    int i,j;
    for(i = 0; i < 3; i ++)
    {
        j = 0;
        while(*input != ':' && *input != '\n')
        {
            if(*input)
            {
                switch(i)      // Bei jedem for durchlauf wird ein anderer Wert geprueft
                {
                    case 0: *(StdArray+j) = *inputCount;    // bei i=0 wird Std beschrieben
                        break;
                    case 1: *(MinArray+j) = *inputCount;  // bei i=1 wird Min beschrieben
                        break;
                    case 2: *(SekArray+j) = *inputCount;   // bei i=2 wird Sek beschrieben
                        break;
                }
            }
            else
                return 0;
            j ++;
            input ++;
        }
        if(*input == '\n' && i == 0)
            return 0;
        switch(i)           // Das letzte Zeichen der Arrays auf \0 setzen...
        {
            case 0: *(StdArray+j) = '\0';
                break;
            case 1: *(MinArray+j) = '\0';
                break;
            case 2: *(SekArray+j) = '\0';
                break;
        }
        input ++;
    }
    
    Time->Hour = atoi(StdArray);
    Time->Minute = atoi(MinArray);
    Time->Second = atoi(SekArray);
    if(isTimeValid(Time))
    {
        return 1;
    }
    
    return 0;
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

© 2019 GitHub, Inc.
Terms
Privacy
Security
Status
Help

Contact GitHub
Pricing
API
Training
Blog
About

