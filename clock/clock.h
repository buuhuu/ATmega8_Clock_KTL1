/*
Copyright (C) 2011  Dirk Rudolph, Lucas Stach, Paul Ritter

Dieses Programm ist freie Software. Sie können es unter den Bedingungen der GNU
General Public License Version 2, wie von der Free Software Foundation veröffentlicht,
weitergeben und/oder modifizieren.

Die Veröffentlichung dieses Programms erfolgt in der Hoffnung, daß es Ihnen von Nutzen
sein wird, aber OHNE IRGENDEINE GARANTIE, sogar ohne die implizite Garantie der
MARKTREIFE oder der VERWENDBARKEIT FÜR EINEN BESTIMMTEN ZWECK. Details finden Sie in
der GNU General Public License.

Sie sollten ein Exemplar der GNU General Public License zusammen mit diesem Programm
erhalten haben. Falls nicht, schreiben Sie an die Free Software Foundation, Inc., 51
Franklin St, Fifth Floor, Boston, MA 02110, USA.
*/

#ifndef CLOCK_H_INCLUDED
#define CLOCK_H_INCLUDED

/**
 * Don't edit the clock values
 */
#define SET_MODE_NONE       1

/**
 * Is used when the hours value should be modified by the user
 */
#define SET_MODE_HOUR       2

/**
 * Is used when the minutes value should be modified by the user
 */
#define SET_MODE_MINUTES    3

/**
 * Is used when the seconds value should be modified by the user
 */
 #define SET_MODE_SECONDS    4

/**
 * Increase the time by one second
 */
void increaseTime();

/**
 * Reset the time to 0
 */
void resetTime();

/**
 * Prepare setting the next time part by shifting the setmode to the next state
 */
void nextSetMode();

/**
 * Used to generate a bitmap based on the given time.
 */
void printTime(bitmap_t destination);

/**
 * Start clock timer.
 */
inline void startTimer();

/**
 * Stop clock timer
 */
inline void stopTimer();


#endif // CLOCK_H_INCLUDED
