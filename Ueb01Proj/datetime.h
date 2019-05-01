#ifndef DATETIME_H
#define DATETIME_H DATETIME_H
#include "datastructure.h"

/***************************************************************************
 Funktion:  isLeapYear
 Parameter: Jahreszahl als int
 Ergebnis:  Wahrheitswert
 Beschreib: Wahr = Jahr ist ein Schaltjahr
 ***************************************************************************/
int isLeapYear(int year);

/***************************************************************************
 Funktion:  isDateValid
 Parameter: struct TDate
 Ergebnis:  Wahrheitswert als int
 Beschreib: Angeben ob das uebergebene Datum gueltig ist
 ***************************************************************************/
int isDateValid(TDate *Date);

/***************************************************************************
 Funktion:  isTimeValid
 Parameter: struct TTime
 Ergebnis:  Wahrheitswert als int
 Beschreib: Angeben ob die uebergebene Uhrzeit gueltig ist
 ***************************************************************************/
int isTimeValid(TTime *Time);

/***************************************************************************
 Funktion:  getDateFromString
 Parameter: *char Input, *TDate
 Ergebnis:  Wahrheitswert als int bei erfolgreichem Kopieren
 Beschreib: Liest ein Datum aus einer Zeichenkette und kopiert die in Struct, ruft IsDateValid auf
 ***************************************************************************/
int getDateFromString(char *Input, TDate *Date);

/***************************************************************************
 Funktion:  getTimeFromString
 Parameter: *char Input, *TTime
 Ergebnis:  Wahrheitswert als int bei erfolgreichem Kopieren
 Beschreib: Liest eine Zeit aus einer Zeichenkette und kopiert die in Struct, ruft IsTimeValid auf
 ***************************************************************************/
int getTimeFromString(char *Input, TTime *Time);

/***************************************************************************
 Funktion:  askYesOrNo
 Parameter: char string (Userprompt)
 Ergebnis:  Wahrheitswert als int
 Beschreib: Zeigt dem User einen Text (Aufforderung) Liest j/n Antwort ein
 ***************************************************************************/
int askYesOrNo(char *Promt);

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

#endif
