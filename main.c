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

#include "main.h"
#include "clock/clock.h"
#include "output/display_12_10.h"


bitmap_t bitmap = {0,0,0,0,0,0,0,0,0,0};

int main(void)
{

    init();

    while(1) {
        if(TCNT1 >= 7813) {
            TCNT1 = 0;
            increaseTime();
            printTime(bitmap);
        }

        scanout(bitmap);
    }

    return 0;
}

void init() {
    // enable PORTC pins as output pins
    DDRC = 0x0f;
    // enable PORTB pins as output pins
    DDRB = 0x1f;
    // enable PORTD pins as output pins
    DDRD = 0xf0;

    // reset all ports
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;

    // configure the interrupts for rising edge
    MCUCR |= (1 << ISC00) | (1 << ISC01);
    // enable INT0 interrupt
	GICR |= (1 << INT0);
	// enable timer overflow interrupt for timer0
	TIMSK |= (1 << TOIE0);
	// enable interrupts in general
	sei();

    // Timer1 (16Bit) CPU-Takt/1024
    // http://www.info-rlp.de/lernteams/eli05/abschnitt_3_mikrocontroller/problemloesung_2/timer.htm
    TCNT1 = 0;
    TCCR1B |= (1 << CS12) | (0 << CS11) | (1 << CS10);

    // Timer0 (8Bit) CPU-Takt/1024
    // react on overflow interrupts 15 times per second
    TCNT0 = 0;
    TCCR0 |= (1 << CS12) | (0 << CS11) | (1 << CS10);
}

/*
 * Interrupt handling
 */

 uint16_t int0startTime = 0;

ISR(INT0_vect) {
    if((int0startTime + 3906) % 7813 < TCNT1) {
        nextSetMode();
        printTime(bitmap);
        scanout(bitmap);
        int0startTime = 0;
    } else if(int0startTime == 0) {
        int0startTime = TCNT1;
    }
}

ISR(TIMER0_OVF_vect) {

}
