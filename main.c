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

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

#include "globalconf.h"
#include "input/input.h"
#include "output/display_12_10.h"
#include "clock/clock.h"

void init();

/* -------------------------------------------------------------------------- */

bitmap_t bitmap = {0,0,0,0,0,0,0,0,0,0};

/* -------------------------------------------------------------------------- */

int main(void)
{

    init();

    while(1) {
        if(getKeyShort(KEY0)) {
            switchToNextMode();
        }

        #ifdef STOP_WATCH
        printTime(bitmap, THEME_BINARY);
        #else
        printTime(bitmap, THEME_BARS);
        #endif
        scanout(bitmap);
    }

    return 0;
}

void init()
{
    // set i/o pin direction
    DDRB = 0xdf;    // external crystal pins must be 0
    DDRC = 0x0f;
    DDRD = 0xf0;

    initKeys(KEYS);
    #ifdef STOP_WATCH
    initClock(TYPE_STOPWATCH);
    #else
    initClock(TYPE_NORMAL);
    #endif


    sei();
}
