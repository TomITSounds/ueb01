
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
