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
 * enum CLOCK_MODE specifies the clock modification mode
 */
enum CLOCK_MODE {
    MODE_NONE,      // do not modify clock values
    MODE_HOUR,      // modify hour
    MODE_MINUTE,    // modify minutes
    MODE_SECOND     // modify seconds
};

/**
 * Init the clock timer and interrupts
 */
void initClock();

/**
 * Increase the time by one second
 */
void increaseTime();

/**
 * Decrease currently modified part of time by one seconds/minute/hour
 */
void decreaseTime();

/**
 * Reset the time to 0
 */
void resetTime();

/**
 * Prepare setting the next time part by shifting the setmode to the next state
 */
void switchToNextMode();

/**
 * Returns the current Mode
 */
uint8_t getMode();

/**
 * Used to generate a bitmap based on the given time.
 */
void printTime(bitmap_t destination);

#endif // CLOCK_H_INCLUDED
