#include <avr/io.h>
#include <avr/interrupt.h>

#define RED1 PORTA0
#define YEL1 PORTA1
#define GRN1 PORTA3

#define RED2 PORTA4
#define YEL2 PORTA5
#define GRN2 PORTA6

int interval = 1;
volatile int dupa = 0;
volatile int timer = 0;

ISR (ADC_vect) {
	dupa = ADCH;
	ADCSRA |= (1 << ADSC);
}

ISR (TIM0_COMPA_vect) {
	timer++;
	
	if (timer > interval) {
		PORTA ^= (1 << RED1) | (1 << RED2);
		timer = 0;
	}
}

int main(void) {
    DDRA = (1 << RED1) | (1 << YEL1) | (1 << GRN1) | (1 << RED2) | (1 << YEL2) | (1 << GRN2);
    OCR0A = 100;
	TCCR0A = 0;
	TCCR0B = 0;
	TCCR0B |= (1 << WGM02);
	TCCR0B |= (1 << CS02) | (1 << CS00);
	TIMSK0 |= (1 << OCIE0A);
	
	ADMUX &= ~(3 << 6);
	ADMUX |= (1 << MUX0) | (1 << MUX2);
	ADCSRA |= (3 << 1);
	ADCSRB &= ~(7);
	ADCSRB |= (1 << 7);
	ADCSRA |= (1 << ADEN);
	ADCSRA |= (1 << ADIE);
	
	sei();
    ADCSRA |= (1 << ADSC);
	
	while (1) {
		interval = dupa/100;
	}
}