/*
Copyright (C) 2011  Dirk Rudolph

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

#ifndef KEYINPUT_H_INCLUDED
#define KEYINPUT_H_INCLUDED

#define KEY_PORT PORTD
#define KEY_PIN PIND
#define KEY_DDR DDRD

#define KEY_TIMER TCCR0
#define KEY_TIMER_COUNT TCNT0
#define KEY_TIMER_CONF 0x05 // prescaler: 1024
#define KEY_TIMER_OVF_MASK 1<<TOIE0
#define KEY_TIMER_OVF_VECT TIMER0_OVF_vect

#define KEY_REPEAT_START 30
#define KEY_REPEAT_NEXT 15


#define SAMPLE_RATE F_CPU/1024*10e-3+0.5
#define KEY0 0x04
#define KEYS KEY0

/**
 * initializes a predefined keymask and timer
 */
void initKeys(const uint8_t keyMask);

/**
 * returns true if the key(s) given by the keymask were pressed for a short
 * time before invocation.
 */
uint8_t getKeyShort(uint8_t keyMask);

/**
 * returns true if the key(s) given by the keymask were pressed for a longer
 * time before invocation.
 */
uint8_t getKeyRepeated(uint8_t keyMask);

#endif // KEYINPUT_H_INCLUDED
