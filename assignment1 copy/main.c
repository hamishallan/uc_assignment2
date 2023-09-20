// a1839619
// Microcontroller Programming – Assignment 2
// ------------------------------------------

// Description:


#include <reg167.h>
#include "stdtypes_c167.h"
#include "serial.h"
#include "pindefs.h"
#include "adc.h"
#include "timer.h"

void main(void) {
	
	volatile float variable;
	int buffer_copy[BUFFER_SIZE];
	
	ADCInit();
	SerialInit();
	T3Init();
	StartT3();
	
	
	
	
	// Main loop
	while (1) {
		
		GetADCVal(buffer_copy) ;
		
		variable = 14.2f;
		
		DataFormatLine(U0, sizeof(U0), variable);
		
		variable = 3.1f;
		
		DataFormatLine(U0, sizeof(U0), variable);
		
	}
}
