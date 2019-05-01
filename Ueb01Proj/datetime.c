
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
#include <stdlib.h>
/***************************************************************************
 Funktion:  isLeapYear
 Parameter: Jahreszahl als int
 Ergebnis:  Wahrheitswert
 Beschreib: Wahr = Jahr ist ein Schaltjahr
 ***************************************************************************/
int isLeapYear(int year)
{   int leapYear = 0;
    if ((year % 4) == 0)
        if ((year % 100) == 0)
            if ((year % 400) == 0)
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
int isDateValid(TDate *Date)
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
int isTimeValid(TTime *Time)
{   // Stunden gueltig ?
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
    char pDay[10];
    char pMonth[10];
    char pYear[10];
    *pDay = '\0';
    *pMonth = '\0';
    *pYear = '\0';

    for(i = 0; i < 3; i ++)
    {
        j = 0;
        while(*Input != '.' && *Input)
        {
                switch(i)      // Bei jedem for durchlauf wird ein anderer Wert geprueft
                {
                    case 0: *(pDay+j) = *Input;    // bei i=0 wird Day beschrieben
                        break;
                    case 1: *(pMonth+j) = *Input;  // bei i=1 wird Month beschrieben
                        break;
                    case 2: *(pYear+j) = *Input;   // bei i=2 wird year beschrieben
                        break;
                }

            Input ++;
            j ++;
        }

        switch(i)           // Das letzte Zeichen der Arrays auf \0 setzen...
        {
            case 0: *(pDay+j) = '\0';
                break;
            case 1: *(pMonth+j) = '\0';
                break;
            case 2: *(pYear+j) = '\0';
                break;
        }
        Input ++;
    }

    Date->Day = atoi(pDay);
    Date->Month = atoi(pMonth);
    Date->Year = atoi(pYear);
    if(isDateValid(Date))
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
    char pHour[10];
    char pMinute[10];
    char pSecond[10];
    *pHour = '\0';
    *pMinute = '\0';
    *pSecond = '\0';

    int i,j;
    for(i = 0; i < 3; i ++)
    {
        if(*Input == ':' && i < 2)
            return 0;
        j = 0;
        while(*Input != ':' && *Input)
        {
            if(!(*Input <= '9' && *Input >= '0'))
                return 0;
            switch(i)      // Bei jedem for durchlauf wird ein anderer Wert geprueft
            {
                case 0: *(pHour+j) = *Input;    // bei i=0 wird Std beschrieben
                    break;
                case 1: *(pMinute+j) = *Input;  // bei i=1 wird Min beschrieben
                    break;
                case 2: *(pSecond+j) = *Input;   // bei i=2 wird Sek beschrieben
                    break;
            }
            j ++;
            Input ++;
        }
        switch(i)           // Das letzte Zeichen der Arrays auf \0 setzen...
        {
            case 0: *(pHour+j) = '\0';
                break;
            case 1: *(pMinute+j) = '\0';
                break;
            case 2: *(pSecond+j) = '\0';
                break;
        }
        Input ++;
    }

    Time->Hour = atoi(pHour);
    Time->Minute = atoi(pMinute);
    Time->Second = atoi(pSecond);
    if(isTimeValid(Time))
        return 1;
    else
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
