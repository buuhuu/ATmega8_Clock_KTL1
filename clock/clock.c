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
#include <inttypes.h>

#include "../output/display_12_10.h"
#include "clock.h"
#include "themes_12_10/simpleBinary.h"
#include "themes_12_10/raisingBars.h"
#include "themes_12_10/analogClock.h"
#include "themes_12_10/dices.h"

volatile uint8_t seconds = 0, minutes = 0, hours = 0;
enum CLOCK_MODE currentMode = MODE_NONE;

void initClock() {
    ASSR = (1<<AS2);    // wire external timesource to tcnt2
    TCNT2 = 0x00;       // set count reg to 0
    TCCR2 = 0x05;       // prescaler 128
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
        case MODE_SECOND:
            seconds ++;
            break;
        case MODE_MINUTE:
            minutes ++;
            break;
        case MODE_HOUR:
            hours ++;
            break;
    }


    if(seconds == 60) {
        minutes ++;
        seconds = 0;
    }

    if(minutes == 60) {
        hours ++;
        minutes = 0;
    }

    if(hours == 24) {
        hours = 0;
    }

    return;
}

void descreaseTime() {
    switch(currentMode) {
        case MODE_NONE:
            return;
        case MODE_SECOND:
            seconds --;
            break;
        case MODE_MINUTE:
            minutes --;
            break;
        case MODE_HOUR:
            hours --;
            break;
    }

    if(seconds == 255) {
        seconds = 59;
    }

    if(minutes == 255) {
        minutes = 59;
    }

    if(hours == 255) {
        hours = 23;
    }

}

void resetTime() {
    hours = 0;
    minutes = 0;
    seconds = 0;
}

void switchToNextMode() {
    switch(currentMode) {
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
        case MODE_NONE:
            currentMode = MODE_HOUR;
            stopClock();
            break;
        //default setMode = SET_MODE_NONE;
    }
}

inline uint8_t getMode() {
    return currentMode;
}

void printTime(bitmap_t destination) {

    //simpleBinary(destination, hours, minutes, seconds, currentMode);
    raisingBars(destination, hours, minutes, seconds, currentMode);
    //analogClock(destination, hours, minutes, seconds, currentMode);
    //dices(destination, hours, minutes, seconds, currentMode);

    return;
}

// Interupt service routine for clock overflow
ISR(TIMER2_OVF_vect) {
    increaseTime();
}
