/*
 Embedded C program for External interrupt input switch press, output at relay.
 */

#include <p18f4520.h>

//Configuration bits setting//
#pragma config OSC = HS //Oscillator Selection
#pragma config WDT = OFF //Disable Watchdog timer
#pragma config LVP = OFF //Disable Low Voltage Programming
#pragma config PBADEN = OFF //Disable PORTB Analog inputs


//Function Prototypes
void msdelay (unsigned int time);//Function for delay


void __interrupt(high_priority) switch_isr (void)
{
	PORTBbits.RB2 = ~PORTBbits.RB2; //Toggle the RB0
    //msdelay (500);
 	INTCONbits.INT0IF=0; //Reset the interrupt flag
}

void main()
{
    ADCON1 = 0x0F;              //Configuring the PORTE pins as digital I/O 
	TRISBbits.TRISB2 = 0;       //Configuring the RB2 as output (Relay))
	PORTBbits.RB2 = 0;          //Setting the initial value	
    TRISBbits.TRISB0=1;        /make INT0 pin as an input pin/
    INTCON2=0x00;              /Set Interrupt detection on falling Edge/
    INTCONbits.INT0IF=0;       /clear INT0IF flag/
    INTCONbits.INT0IE=1;       /Enable INT0 external interrupt/
    INTCONbits.GIE=1;          /Enable Global Interrupt/  
    while(1);
}



//Function Definitions
void msdelay (unsigned int time)//Function for delay
{
unsigned int i, j;
 for (i = 0; i < time; i++)
	 for (j = 0; j < 710; j++);	//Calibrated for a 1 ms delay in MPLAB
}