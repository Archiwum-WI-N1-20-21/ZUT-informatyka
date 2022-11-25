#include <avr/io.h>
#include <avr/interrupt.h>

#define RED1 PORTA0
#define YEL1 PORTA1
#define GRN1 PORTA3

#define RED2 PORTA4
#define YEL2 PORTA5
#define GRN2 PORTA6

#define MAX_INTERVAL 50
volatile int counter;

ISR (TIM0_COMPA_vect) {
    counter++;
    if (counter > MAX_INTERVAL) counter = 0;
}

int main(void) {
    counter = 0;
    DDRA = (1 << RED1) | (1 << YEL1) | (1 << GRN1) | (1 << RED2) | (1 << YEL2) | (1 << GRN2);
    TCCR0A = 0;
    TCCR0B = 0;
    OCR0A = 200;
    TCCR0B |= (1 << WGM02);
    TCCR0B |= (1 << CS02) | (1 << CS00);
    TIMSK0 |= (1 << OCIE0A);
    sei();
    while (1) {
            switch (counter) {
                case 0 ... 10:
					PORTA = (1 << RED1) | (1 << GRN2);
					break;
                case 11 ... 15:
					PORTA = (1 << RED1) | (1 << YEL2);
					break;
                case 16 ... 20:
					PORTA = (1 << RED1) | (1 << RED2);
					break;
                case 21 ... 25:
					PORTA = (1 << RED1) | (1 << YEL1) | (1 << RED2);
					break;
                case 26 ... 35:
					PORTA = (1 << GRN1) | (1 << RED2);
					break;
                case 36 ... 40:
					PORTA = (1 << YEL1) | (1 << RED2);
					break;
                case 41 ... 45:
					PORTA = (1 << RED1) | (1 << RED2);
					break;
                case 46 ... 50:
					PORTA = (1 << RED1) | (1 << RED2) | (1 << YEL2);
					break;
            }

    }
}