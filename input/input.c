#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "input.h"

volatile uint8_t keyPressed;


void initTimer() {
    KEY_TIMER = KEY_TIMER_CONF;
    TIMSK |= KEY_TIMER_OVF_MASK;
}

void initKeys(uint8_t keyMask) {
    initTimer();

    KEY_DDR &= ~keyMask;
    KEY_PORT |= keyMask;
}

ISR( KEY_TIMER_OVF_VECT )
{
    static uint8_t q0, q1, keyState;
    uint8_t c;

    KEY_TIMER_COUNT = SAMPLE_RATE;
                                                //          pressed     unpressed
    c = keyState ^ ~KEY_PIN;                    // ~PIN     1           0
    q0 = ~(q0 & c);
    q1 = q0 ^ (q1 & c);
    c &= q0 & q1;

    keyState ^= c;
    keyPressed |= keyState & c;
}

uint8_t getKeyPressed(uint8_t keyMask) {
    cli();
    keyMask &= keyPressed;
    keyPressed ^= keyMask;
    sei();
    return keyMask;
}
