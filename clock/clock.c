/*
Copyright (C) 2011  Dirk Rudolph, Lucas Stach, Paul Ritter, Heiko Schmidt

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
#include <inttypes.h>

#include "../globalconf.h"
#include "../output/display_12_10.h"
#include "clock.h"
#include "themes_12_10/simpleBinary.h"
#include "themes_12_10/raisingBars.h"
#include "themes_12_10/analogClock.h"
#include "themes_12_10/dices.h"

volatile struct timeval_t time = {
    .seconds = 0,
    .minutes = 0,
    .hours = 0,
    .milliseconds = 0
};

#ifdef STOP_WATCH
enum CLOCK_MODE currentMode = MODE_IDLE;
#else
enum CLOCK_MODE currentMode = MODE_NONE;
#endif

void initClock() {
    ASSR = (1<<AS2);    // wire external timesource to tcnt2
    TCNT2 = 0x00;       // set count reg to 0
    TCCR2 = 0x0d;       // prescaler 128
    TIMSK |= (1<<TOIE2);
}

inline void stopClock() {
    TCCR2 &= ~0x05;
}

inline void startClock() {
    TCNT2 = 0x00;
    TCCR2 |= 0x05;
}

void increaseTime() {
    switch(currentMode) {
        case MODE_NONE:
            time.milliseconds++;
            break;
        #ifdef STOP_WATCH
        case MODE_SECOND:
            time.seconds++;
            break;
        case MODE_MINUTE:
            time.minutes++;
            break;
        case MODE_HOUR:
            time.hours++;
            break;
        #endif
        default: break;
    }

    if(time.milliseconds == 1000) {
        time.seconds++;
        time.milliseconds = 0;
    }

    if(time.seconds == 60) {
        time.minutes++;
        time.seconds = 0;
    }

    if(time.minutes == 60) {
        time.hours++;
        time.minutes = 0;
    }

    if(time.hours == 24) {
        time.hours = 0;
    }
}

void descreaseTime() {
    switch(currentMode) {
        case MODE_IDLE:
        case MODE_NONE:
            return;
        case MODE_SECOND:
            time.seconds--;
            break;
        case MODE_MINUTE:
            time.minutes--;
            break;
        case MODE_HOUR:
            time.hours--;
            break;
    }

    if(time.seconds == 255) {
        time.seconds = 59;
    }

    if(time.minutes == 255) {
        time.minutes = 59;
    }

    if(time.hours == 255) {
        time.hours = 23;
    }
}

void resetTime() {
    time.milliseconds = 0;
    time.hours = 0;
    time.minutes = 0;
    time.seconds = 0;
}

void switchToNextMode() {
    switch(currentMode) {
        #ifdef STOP_WATCH
        case MODE_IDLE:
            currentMode = MODE_NONE;
            startClock();
            break;
        #else
        case MODE_HOUR:
            currentMode = MODE_MINUTE;
            break;
        case MODE_MINUTE:
            currentMode = MODE_SECOND;
            break;
        case MODE_SECOND:
            currentMode = MODE_NONE;
            startClock();
            break;
        #endif
        case MODE_NONE:
            #ifdef STOP_WATCH
            currentMode = MODE_IDLE;
            #else
            currentMode = MODE_HOUR;
            #endif
            stopClock();
            break;
        default: break;
    }
}

inline uint8_t getMode() {
    return currentMode;
}

void printTime(bitmap_t destination) {
    //simpleBinary(destination, time.hours, time.minutes, time.seconds, currentMode);
    raisingBars(destination, time.hours, time.minutes, time.seconds, currentMode);
    //analogClock(destination, time.hours, time.minutes, time.seconds, currentMode);
    //dices(destination, time.hours, time.minutes, time.seconds, currentMode);
}

// Interupt service routine for clock overflow
ISR(TIMER2_OVF_vect) {
    increaseTime();
}
