
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
#include <math.h>

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
  
    return leapYear;
}
/***************************************************************************
 Funktion:  isDateValid
 Parameter: struct TDate
 Ergebnis:  Wahrheitswert als int
 Beschreib: Angeben ob das uebergebene Datum gueltig ist
 ***************************************************************************/
int isDateValid(TDate *pDate)
{   int YearMax=2050;
    int YearMin=2018;
    int MaxDay;
    
    if (pDate->Year < YearMin || pDate->Year > YearMax)     //Jahr gueltig ?
        return 0;
    
    if (pDate->Month < 1 || pDate->Month > 12)          //Monat gueltig
        return 0;
    
    if (pDate->Day % 2 == 0)                         //Gerade Monate = 30 ausser Feb sonst 31
        if (pDate->Month == 2)
            MaxDay = 28 + isLeapYear(pDate->Year);
        else
            MaxDay = 30;
    else
        MaxDay = 31;
    
    if(pDate->Day < 1 || pDate->Day > MaxDay)           // Tag gueltig ?
        return 0;
    
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
int getDateFromString(char *Input, TDate *pDate)
    {   char *pDay = 0;
        char *pMonth = 0;
        char *pYear = 0;
        
        if (!*Input) //Falls String leer
            return 0;

        pDay = Input;
        
        while (*Input != '.')           //Zeiger bis Punkt
            Input++;
        
        Input++;
        pMonth = Input;
        
        while (*Input != '.')           //Zeiger auf 2. Punkt
        {   Input++;
            pYear =  Input;
        }
        pYear++;

        pDate->Day = atoi(pDay);        //Wert Zuweisungen
        pDate->Month = atoi(pMonth);
        pDate->Year = atoi(pYear);
        
        return isDateValid(pDate);
        
    
}
/***************************************************************************
 Funktion:  getTimeFromString
 Parameter: *char Input, *TTime
 Ergebnis:  Wahrheitswert als int bei erfolgreichem Kopieren
 Beschreib: Liest eine Zeit aus einer Zeichenkette und kopiert die in Struct, ruft IsTimeValid auf
 ***************************************************************************/
int getTimeFromString(char *Input, TTime *Time)
{   char *pHour = 0;
    char *pMinute = 0;
    
    if (!*Input) //Falls String leer
        return 0;
    if((*Input<='0') || (*Input >='9')) //Fals erste character Keine Zahl
        return 0;
    
    pHour = Input;
    
    while (*Input != ':')
        Input++;
    Input++;
    pMinute = Input;
    
    if((*Input>'9') && (*Input <'0')) //Fals erste character Keine Zahl
        return 0;
    
    do
        Input++;
    while (*Input != ':' && (*Input != 0));
    
    Time->Hour = atoi(pHour);
    Time->Minute = atoi(pMinute);
    Time->Second = 0;
    if((*Input) == ':')
        Input++;
        if ((*Input>='0') && (*Input <='9'))
            Time->Second = atoi(Input);
    
    return isTimeValid(Time);
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
