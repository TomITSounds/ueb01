
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
        if ((leapYear % 100) == 0)
            if ((leapYear % 400) == 0)
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
{
    int YearMax=2050;
    int YearMin=2018;
    
    //Jahr gueltig ?
    if (pDate->Year < YearMin || pDate->Year > YearMax)
    {
        return 0;
    }
    
    int DayMax;
    
    switch (pDate->Month){                           //versch. Cases für alle Monate
            
        case 1: DayMax=31;
            break;
        case 2: if(isLeapYear(pDate->Year)){
                    DayMax=29;
                }
                else
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
    if(pDate->Day < 1 || pDate->Day > DayMax)
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
        int success;
        
        if (!*Input) //Falls String leer
            return 0;
      //  if(*Input>='0' && *Input <='0') //Fals erste character Keine Zahl
        //    return 0;
        
        pDay = Input;
        
        while (*Input != '.')
        {   Input++;
            pMonth =  Input;
        }
        pMonth++;
        Input++;
        
      //  if(*Input>='0' && *Input <='0') //Fals erste character Keine Zahl
        //    return 0;
        
        while (*Input != '.')
        {   Input++;
            pYear =  Input;
        }
        pYear++;
        
      //  if(*Input>='0' && *Input <='0') //Fals erste character Keine Zahl
          //  return 0;
        
        pDate->Day = atoi(pDay);
        pDate->Month = atoi(pMonth);
        pDate->Year = atoi(pYear);
        
        success = isDateValid(pDate);
        
        return success;
        
    
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
    char *pSecond = 0;
    
    if (!*Input) //Falls String leer
        return 0;
    if(*Input<='0' || *Input >='9') //Fals erste character Keine Zahl
        return 0;
    
    pHour = Input++;
    
    while (*Input != ':')
        pMinute =  ++Input;
    pMinute++;
    
    if(*Input>='0' && *Input <='0') //Fals erste character Keine Zahl
        return 0;
    
    while (*Input != ':' || !*Input)
        pSecond =  ++Input;
    
    
    Time->Hour = atoi(pHour);
    Time->Minute = atoi(pMinute);
    if(*Input != ':')
        Time->Second = atoi(pSecond);
    else
        Time->Second = 0;
    
    
    return isTimeValid(Time);
    
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
            default:    printf("Ungueltige Eingabe.\nWollen sie nochmal? j/n\n");
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
