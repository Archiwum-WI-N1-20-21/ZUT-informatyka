#include <avr/io.h>
#include <avr/interrupt.h>

#define RED1 PORTA0
#define YEL1 PORTA1
#define GRN1 PORTA3

#define RED2 PORTA4
#define YEL2 PORTA5
#define GRN2 PORTA6

#define BTN1 PORTA7
#define BTN2 PORTB0

#define BTN_LIMIT 25

void turnOnLED(int value) {
    PORTA = 0;
    
    if (value & 0x01) (PORTA |= (1 << RED1));
    if (value & 0x02) (PORTA |= (1 << YEL1));
    if (value & 0x04) (PORTA |= (1 << GRN1));
	if (value & 0x08) (PORTA |= (1 << RED2));
	if (value & 0x10) (PORTA |= (1 << YEL2));
	if (value & 0x20) (PORTA |= (1 << GRN2));

	return;
}

int main(void) {
    int btn1_current = 0;
    int btn2_current = 0;
    int btn1_before = 1;
	int btn2_before = 1;
    int btn1_state = 0;
	int btn2_state = 0;
    int debounce_counter = 0;
    int led_counter = 0;
    DDRA = (1 << RED1) | (1 << YEL1) | (1 << GRN1) | (1 << RED2) | (1 << YEL2) | (1 << GRN2) | !(1 << BTN1);
    DDRB = !(1 << BTN2);
    TCCR0A = 0;
    TCCR0B = 0;
    PUEA |= (1 << BTN1);
    PUEB |= (1 << BTN2);
    OCR0A = 200;
    TCCR0B |= (1 << WGM02);
    TCCR0B |= (1 << CS02) | (1 << CS00);
    TIMSK0 |= (1 << OCIE0A);
    PORTA = 0;
    while (1) {
        btn1_current = (PINA & (1 << BTN1));
        btn2_current = (PINB & (1 << BTN2));
		
		if (led_counter < 0 || led_counter > 21) led_counter = 0;
        
		switch (btn1_state) {
			case 0:
				if (btn1_before != btn1_current) {
					btn1_state = 1;
					btn1_before = btn1_current;
				}
				break;
		
			case 1:
				if (btn1_before == btn1_current) {
					if (debounce_counter >= BTN_LIMIT) {
						btn1_state = 2;
						led_counter++;
						turnOnLED(led_counter);
					} else {
						debounce_counter++;
					}
				} else {
					btn1_state = 0;
					btn1_before = btn1_current;
					debounce_counter = 0;
				}
				break;

			case 2:
				if (btn1_before != btn1_current) {
					btn1_state = 0;
					btn1_before = btn1_current;
					debounce_counter = 0;
				}
				break;
		}

		switch (btn2_state) {
			case 0:
				if (btn2_before != btn2_current) {
					btn2_state = 1;
					btn2_before = btn2_current;
				}
				break;
			
			case 1:
				if (btn2_before == btn2_current) {
					if (debounce_counter >= BTN_LIMIT) {
						btn2_state = 2;
						led_counter--;
						turnOnLED(led_counter);
					} else {
						debounce_counter++;
					}
				} else {
					btn2_state = 0;
					btn2_before = btn2_current;
					debounce_counter = 0;
				}
				break;

			case 2:
				if (btn2_before != btn2_current) {
					btn2_state = 0;
					btn2_before = btn2_current;
					debounce_counter = 0;
				}
				break;
		}
    }
}