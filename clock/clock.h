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
 * enum CLOCK_TYPE specifies how the clock behaves
 */
enum CLOCK_TYPE {
    TYPE_NORMAL
    #ifdef STOP_WATCH
    ,TYPE_STOPWATCH
    #endif
};

/**
 * enum CLOCK_MODE specifies the clock modification mode
 */
enum CLOCK_MODE {
    MODE_IDLE = 0xff,      // when STOP_WATCH is idle
    MODE_NONE = 0x01,      // do not modify clock values
    MODE_HOUR = 0x02,      // modify hours
    MODE_MINUTE = 0x04,    // modify minutes
    MODE_SECOND = 0x08     // modify seconds
};

/**
 * enum CLOCK_THEME specifies the printTime() design
 */
enum CLOCK_THEME {
    THEME_ANALOG,
    THEME_DICES,
    THEME_BARS,
    THEME_BINARY
};

/**
 * struct timeval_t holds all time related values
 */
struct timeval_t {
    uint8_t seconds, minutes, hours;
    uint16_t milliseconds;
    uint8_t dirty;
};

/**
 * Init the clock timer and interrupts
 */
void initClock(const enum CLOCK_TYPE type);

/**
 * Reset the time to 0
 */
void resetTime();

/**
 * Prepare setting the next time part by shifting the setmode to the next state
 */
void switchToNextMode();

/**
 * Used to generate a bitmap based on the given time.
 */
void printTime(bitmap_t destination, const enum CLOCK_THEME theme);

#endif // CLOCK_H_INCLUDED
