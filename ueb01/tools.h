//
//  tools.h
//  ueb01X
//
//  Created by Tom Mertens on 20.04.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#ifndef TOOLS_H
#define TOLS_H TOOLS_H

/**********************************************************
 * Funktion: clearBuffer
 * Beschreibung: Leert den Tasturpuffer
 * Parameter: Character
 * Ergebnis:
 **********************************************************/
void clearBuffer();

/**********************************************************
 * Funktion: askAgain
 * Beschreibung: Fragt den Benutzer ob er dass Programm nochmal ausfuehren moecht
 Parameter: Zeile und Spalte der Frage
 *Ergebnis: Wahrheitswert
 **********************************************************/
int askAgain(int Row, int Column);

/**********************************************************
 * Funktion: waitForEnter
 * Beschreibung:
 Parameter:
 *Ergebnis:
 **********************************************************/
void waitForEnter();

/**********************************************************
 * Funktion:        ClearScreen
 * Beschreibung:    Loescht den Bildschirm
 Parameter:
 *Ergebnis:
 **********************************************************/
void clearScreen();

#endif /* tools_h */
