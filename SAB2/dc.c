
#include <p18f4520.h>

#pragma config OSC = HS //Oscillator Selection
#pragma config WDT = OFF //Disable Watchdog timer
#pragma config LVP = OFF //Disable Low Voltage Programming
#pragma config PBADEN = OFF //Disable PORTB Analog inputs

void myMsDelay (unsigned int time) 	// Definition of delay subroutine
{
	unsigned int i, j;
	for (i = 0; i < time; i++)		// Loop for i time
		for (j = 0; j < 375; j++);	// Calibrated for a 1 ms delay in MPLAB
}

void main()
{ 
	TRISCbits.TRISC0 = 0 ;	// Set PORTC, RC0 as output (DCM IN1)
	TRISCbits.TRISC1 = 0 ;	// Set PORTC, RC1 as output (DCM IN2)	
	TRISCbits.TRISC2 = 0 ;	// Set PORTC, RC2 as output (DCM EN1)
    TRISCbits.TRISC3 = 0 ;	// Set PORTC, RC3 as output (DCM EN2)
	TRISCbits.TRISC4 = 0 ;	// Set PORTC, RC4 as output (DCM IN3)	
	TRISCbits.TRISC5 = 0 ;	// Set PORTC, RC5 as output (DCM IN4)
   
	PORTCbits.RC0 = 0;	
    PORTCbits.RC1 = 0;
    PORTCbits.RC2 = 0;	
    PORTCbits.RC3 = 0;
    PORTCbits.RC4 = 0;	
    PORTCbits.RC5 = 0;
    
  while(1)	// Endless Loop
	{
        PORTCbits.RC0 = 1;	
        PORTCbits.RC1 = 0;
        PORTCbits.RC2 = 1;	
        PORTCbits.RC3 = 1;
        PORTCbits.RC4 = 1;	
        PORTCbits.RC5 = 0;
		
		myMsDelay(5000);
        
        PORTCbits.RC0 = 0;	
        PORTCbits.RC1 = 0;
        PORTCbits.RC2 = 0;	
        PORTCbits.RC3 = 0;
        PORTCbits.RC4 = 0;	
        PORTCbits.RC5 = 0;
        
        myMsDelay(2000);
        
        PORTCbits.RC0 = 0;	
        PORTCbits.RC1 = 1;
        PORTCbits.RC2 = 1;	
        PORTCbits.RC3 = 1;
        PORTCbits.RC4 = 0;	
        PORTCbits.RC5 = 1;
        
        myMsDelay(2000);
        
        PORTCbits.RC0 = 0;	
        PORTCbits.RC1 = 0;
        PORTCbits.RC2 = 0;	
        PORTCbits.RC3 = 0;
        PORTCbits.RC4 = 0;	
        PORTCbits.RC5 = 0;
        
         myMsDelay(2000);
		
 	}   
 
}


