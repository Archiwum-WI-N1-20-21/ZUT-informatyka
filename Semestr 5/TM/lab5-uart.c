#include <avr/io.h>
#include <avr/interrupt.h>

/* LED */
#define RED1 PORTA0
#define YEL1 PORTA1
#define GRN1 PORTA3
#define RED2 PORTA4
#define YEL2 PORTA5
#define GRN2 PORTA6
#define ALL_LED2 (1 << RED2) | (1 << YEL2) | (1 << GRN2)

/* BUTTONS */
#define BUT1 PORTA7
#define BUT2 PORTB0
#define BUT2_PRESSED !(PINB & (1 << PORTB0))

/* BAUD RATE */
#define FOSC 1843200 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

/* DELAY */
#define F_CPU 1000000UL
#include <util/delay.h>

/* REGISTERS */
#define LED_DDRA_OUTPUT (1 << GRN2) | (1 << RED2) | (1 << YEL2) | (1 << GRN1) | (1 << RED1) | (1 << YEL1);
#define LIGHT_ALL_LED PORTA |= (1 << GRN2) | (1 << RED2) | (1 << YEL2) | (1 << GRN1) | (1 << RED1) | (1 << YEL1);

/* GLOBAL VARIABLES */
volatile unsigned char receivedData;
volatile unsigned char senddData;

#define LIMIT 30
volatile int debounce_cnt;
volatile int btn_before = 1;
volatile int state = 0;
volatile int btn_current = 0;
volatile int cnt = 0;

void enableBUT1( void );
void enableBUT2( void );
void setLED( void );
void lightLED_1(unsigned int ledNumber);
void lightLED_2(unsigned int ledNumber);

void USART_set_baudrate(unsigned int baudrate);
void USART_config( void );
void USART_transmit( unsigned char data);
void USART_receive( void );


ISR (PCINT0_vect) {

    USART_transmit((unsigned char)cnt);
    USART_receive();
    USART_transmit((unsigned char)cnt);
    USART_receive();

    if ( UCSRA & (1 << UDRE) ) {
		for(int i = 0; i < 10; i++) {
			_delay_ms(50);
			lightLED_1(cnt);
            } 
		} 
	else {
		for(int i = 0; i < 10; i++) {
			_delay_ms(50);
			lightLED_2(cnt);
		}
	}
}

ISR (PCINT1_vect) {
}

/* USART Data register empty */
ISR (USART_DRE_vect) {
    UDR = cnt;
}

/* Receive Complete interrupt */
ISR (USART_RXC_vect) {
    receivedData = UDR;
}

void enableBUT1( void ) {

    /* Set DDRA to input */
    DDRA &= ~(1 << BUT1);
    /* Pull-up resistor */
    PUEA |= (1 << BUT1);
    /* Enable pin change interrupt on corresponding I/O pin */
    PCMSK0 |= (1 << PCINT7);
    /* Trigger an interrupt request PCINT[7:0] */
    PCICR |= (1 << PCIE0);

}

void enableBUT2( void ) {

    /* Set DDRA to input */
    DDRB &= ~(1 << BUT2);
    /* Pull-up resistor */
    PUEB |= (1 << BUT2);
    /* Enable pin change interrupt on corresponding I/O pin */
    PCMSK1 |= (1 << PCINT8);
    /* Trigger an interrupt request PCINT[7:0] */
    PCICR |= (1 << PCIE1);

}

void USART_set_baudrate(unsigned int baudrate) {
        UBRRH = (unsigned char)(baudrate >> 8);    
        UBRRL = (unsigned char)baudrate;
}

void USART_config( void ) {

    /* Asynchronous mode */
    UCSRC &= ~(1 << UMSEL0) & ~(1 << UMSEL1);
    /* Parity mode - Disabled */
    UCSRC &= ~(1 << UPM0) & ~(1 << UPM1);
    /* Number of stop bits - 1 */
    UCSRC |= (1 << USBS);
    /* Sets the number of data bit */
    UCSRC |= (1 << UCSZ0) | (1 << UCSZ1);
    /* Enables receiver and transmitter */
    UCSRB |= (1 << RXEN) | (1 << TXEN);
}

void USART_transmit( unsigned char data)
{

    /* Enables interrupt on the TXC0 Flag */
    //UCSRB |= (1 << TXCIE);
    /* Wait for buffer to be empty */
    while( !(UCSRA & (1 << UDRE)));
    /* Enables interrupt on UDRE Flag */
    UCSRB |= (1 << UDRIE);
    UDR = data;
}

void USART_receive( void ) {
    /* Enables interrput on the RXC0 Flag */
    UCSRB |= (1 << RXCIE);
    /* Wait for data in the buffer */
    while ( !(UCSRA & (1 << RXC)));
}

/*
    Transmit Data Buffer Register TXB - will be destination for data written. TXB -> UDRO
    Reading the UDR will return contents of Receive Data Buffer Register.     RXB <- UDR 
*/
void setLED()
{
    btn_current = (PINB & (1<<BUT2));

    switch (state)
    {
        case 0:
        if (btn_before != btn_current)
        {
            state = 1;
            btn_before = btn_current;
        }
        break;
        case 1:
        if (btn_before == btn_current)
        {
            if (debounce_cnt >= LIMIT)
            {
                state = 2;
                cnt++;
                if (cnt > 3) cnt = 1;
            }
            else
            {
                debounce_cnt++;
            }
        }
        else
        {
            state = 0;
            btn_before = btn_current;
            debounce_cnt = 0;
        }
        break;
        case 2:
        if (btn_before != btn_current)
        {
            state = 0;
            btn_before = btn_current;
            debounce_cnt = 0;
        }
        break;
    }
}

void lightLED_1(unsigned int ledNumber)
{
    switch(ledNumber)
    {
        case 1:
        PORTA = (1 << RED1);
        break;
        case 2:
        PORTA = (1 << YEL1);
        break;
        case 3:
        PORTA = (1 << GRN1);
        break;
    }
}

void lightLED_2(unsigned int ledNumber)
{
    switch(ledNumber)
    {
        case 1:
        PORTA = (1 << RED2);
        break;
        case 2:
        PORTA = (1 << YEL2);
        break;
        case 3:
        PORTA = (1 << GRN2 );
        break;
    }
}

int main(void)
{
    DDRA |= (1 << GRN2) | (1 << RED2) | (1 << YEL2) | (1 << GRN1) | (1 << RED1) | (1 << YEL1);
    PORTA = 0;

    sei();
    enableBUT1();
    enableBUT2();
    USART_set_baudrate(MYUBRR);
    USART_config();

 

    /* Replace with your application code */
    while (1) 
    {
        setLED();
        lightLED_1((unsigned int)receivedData);
    }
}

