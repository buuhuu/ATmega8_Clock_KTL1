#ifndef KEYINPUT_H_INCLUDED
#define KEYINPUT_H_INCLUDED

#define KEY_PORT PORTD
#define KEY_PIN PIND
#define KEY_DDR DDRD

#define KEY_TIMER TCCR0
#define KEY_TIMER_COUNT TCNT0
#define KEY_TIMER_CONF 0x05
#define KEY_TIMER_OVF_MASK 1<<TOIE0
#define KEY_TIMER_OVF_VECT TIMER0_OVF_vect

#define SAMPLE_RATE 0xf7
#define KEY0 0x04
#define KEYS KEY0

/**
 * When the ADC value is higher then this const the current modified part of time will be incresed each 500 ms
 */
#define INCREMENT_ADC_BOUNDARY 768

/**
 * When the ADC value is lower then this bounday the currend modified part of time will be decremented each 500 ms
 */
#define DECREMENT_ADC_BOUNDAY 255



void initKeys(uint8_t keyMask);
uint8_t getKeyPressed(uint8_t keyMask);

#endif // KEYINPUT_H_INCLUDED
