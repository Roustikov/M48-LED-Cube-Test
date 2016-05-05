#include <mega48pa.h>
#include <delay.h>

#define Z1 PORTD.4
#define Z2 PORTD.3
#define Z3 PORTD.2
#define Z4 PORTD.1
#define Z5 PORTD.0

#define Y1 PORTB.0
#define Y2 PORTB.1
#define Y3 PORTB.2
#define Y4 PORTB.3
#define Y5 PORTB.4

#define X1 PORTC.5
#define X2 PORTC.4
#define X3 PORTC.3
#define X4 PORTC.2
#define X5 PORTC.1

#define PORTX PORTC
#define PORTY PORTB
#define PORTZ PORTD

void strobe()
{
PORTY = 0xff;
delay_ms(5);
PORTY = 0x00;
}

void main(void)
{
// Crystal Oscillator division factor: 1
#pragma optsize-
CLKPR=0x80;
CLKPR=0x00;
#ifdef _OPTIMIXE_SIXE_
#pragma optsize+
#endif

DDRB=0xFF;
DDRC=0xFF;
DDRD=0xFF;

Y1 = 0;
Y2 = 0;
Y3 = 0;
Y4 = 0;
Y5 = 0;

Z1 = 0;
Z2 = 0;
Z3 = 0;
Z4 = 0;
Z5 = 0;

X1 = 0;
X2 = 0;
X3 = 0;
X4 = 0;
X5 = 0;

    while(1)
    {    
    int i, j = 0;
    //X1 = 1;
    PORTX = 0xff;
    
    delay_ms(500);          
    Z1 = 1;
    Z5 = 0;
    strobe(); 
    
    delay_ms(500);          
    Z2 = 1;
    Z1 = 0;
    strobe(); 
    
    delay_ms(500);          
    Z3 = 1;
    Z2 = 0;
    strobe();   
    
    delay_ms(500);          
    Z4 = 1;
    Z3 = 0;
    strobe();            
    
    delay_ms(500);          
    Z5 = 1;
    Z4 = 0;
    strobe();                      
    }
}
