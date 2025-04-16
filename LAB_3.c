#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

#define F_CPU 16000000UL  // Define CPU frequency
#define BAUD 9600          // Define baud rate
#define MYUBRR F_CPU/16/BAUD-1

void serialBegin(unsigned int ubrr);
void serialTransmit(unsigned char data);
unsigned char serialReceive(void);
void displayDigit(char digit);
void clearDisplay();
void setup();
void loop();

int main(void) {
    setup();
    while (1) {
        loop();
    }
    return 0;
}

void setup() {
    
    DDRD = 0xFF;  
    DDRB = 0xFF; 

    serialBegin(MYUBRR);  
}

void loop() {
    char input = serialReceive();

    if (input == 'c') {
        clearDisplay();  
    } else if (input >= '0' && input <= '9') {
        if (input == '4') {
            displayDigit('8');  
        } else if (input == '3') {
            for (int j = 3; j >= 0; j--) {
                displayDigit('0' + j);  
            }
        } else {
            displayDigit(input);  
        }
    }
}

void serialBegin(unsigned int ubrr) {
    
    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)ubrr;
    
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
    
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

unsigned char serialReceive(void) {
    
    while (!(UCSR0A & (1 << RXC0)));
    
    return UDR0;
}

void displayDigit(char digit) {
    switch (digit) {
        case '0':
            PORTD = 0b00100000;
            PORTB = 0b11111000;
            break;
        case '1':
            PORTD = 0b10101000;
            PORTB = 0b11111101;
            break;
        case '2':
            PORTD = 0b10000111;
            PORTB = 0b00010010;
            break;
        case '3':
            PORTD = 0b10000111;
            PORTB = 0b00010001;
            break;
        case '4':
            PORTD = 0b00001000;
            PORTB = 0b11111101;
            break;
        case '5':
            PORTD = 0b01000000;
            PORTB = 0b11111001;
            break;
        case '6':
            PORTD = 0b01000000;
            PORTB = 0b11111000;
            break;
        case '7':
            PORTD = 0b10100000;
            PORTB = 0b11111101;
            break;
        case '8':
            PORTD = 0b00000000;
            PORTB = 0b11111000;
            break;
        case '9':
            PORTD = 0b00000111;
            PORTB = 0b00010001;
            break;
        default:
            clearDisplay();
            break;
    }
    _delay_ms(1000);
}

void clearDisplay() {
    PORTD = 0xFF;
    PORTB = 0xFF;
}
