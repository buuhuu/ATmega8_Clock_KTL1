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

#include <stdint.h>
#include <string.h>
#include <avr/io.h>

#include "display_12_10.h"

void scanout(const bitmap_t bitmap)
{
    uint8_t currentRow, currentBit;

    // for each row
    for(currentRow = 0; currentRow < 10; currentRow++) {
        if(bitmap[currentRow] == 0) {
            // if all leds in a row are dark, we could skip this row
            continue;
        }

        // for each bit, start at lsb
        for(currentBit = 0; currentBit < 12; currentBit++) {
            if((bitmap[currentRow] & (0x01 << currentBit)) == 0) {
                PORTB |= (0x01 << 4);
            } else {
                PORTB &= ~(0x01 << 4);
            }

            // clk
            PORTB |= (0x01 << 3);
            PORTB &= ~(0x01 << 3);
        }

        // disable all rows
        PORTB &= ~(0x03);
        PORTC &= ~(0x0f);
        PORTD &= ~(0xf0);

        // strobe
        PORTB |= (0x01 << 2);
        PORTB &= ~(0x01 << 2);

        // activate the current row
        switch(currentRow) {
            case 0: PORTC |= 0x01; break;
            case 1: PORTC |= 0x02; break;
            case 2: PORTC |= 0x04; break;
            case 3: PORTC |= 0x08; break;

            case 4: PORTD |= 0x10; break;
            case 5: PORTD |= 0x20; break;
            case 6: PORTD |= 0x40; break;
            case 7: PORTD |= 0x80; break;

            case 8: PORTB |= 0x01; break;
            case 9: PORTB |= 0x02; break;
        }
    }
}

void clearBuffer(bitmap_t bitmap, const uint8_t pattern)
{
    for(uint8_t i = 0; i < 10; i++) {
        bitmap[i] = ((pattern << 8) | (pattern));
    }
}

void shiftBuffer(bitmap_t bitmap, const uint8_t shift)
{
    if(shift > 0) {
        for(uint8_t i = 0; i < 10; i++) {
            bitmap[i] <<= shift;
        }
    } else {
        for(uint8_t i = 0; i < 10; i++) {
            bitmap[i] >>= -shift;
        }
    }
}

void shadowBuffer(bitmap_t shadow, const bitmap_t source)
{
    memcpy(shadow, source, sizeof(bitmap_t));
}
