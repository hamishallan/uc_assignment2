// a1839619

# include "adc.h"
# include <reg167.h>
# include "timer.h"

static int adc_buffer[BUFFER_SIZE];
static int adc_buffer2[BUFFER_SIZE];
static int index = 0;

void ADC_ISR(void) interrupt 0x28 {
	
		if (T3OTL == 1) {
			T3OTL	=	0;
			StartT3();
		}
		else {
		}
			
	if ( (ADDAT & 0xF000) == 0) {
		adc_buffer[index]	=	(ADDAT & 0x03FF);
	}
	else {
		adc_buffer2[index]	=	(ADDAT & 0x03FF);
	}

}

void GetADCVal(int *buffer_copy) {
	
	int i;
	
	for(i = 0 ; i< BUFFER_SIZE ; i++) {
	
		buffer_copy[i] = adc_buffer[i];
	
	}
	
}
																

void ADCInit(void){
	
	//ADCON = 0x0004;	// Select channel 4 of port 5
	
	IEN = 1;					// Enable interrupts (PSW |= 0x0800)
	
	ADCIC = 0x0044;		// Enable ADC interrupts ILVL = 1, GLVL = 0
	
	ADCON = 0x0000;		// Reset ADCON register
	
	ADCON	|=	AD_CH_SELECT;							// ADCH 	- Select channel 1 and 0 in autoscan mode
	ADCON |=	(	AD_MODE_SELECT << 4	);	// ADM 		- Select auto scan continuous conversion
	ADWR	=	WAIT_FOR_READ_CONTROL;			// - 
	ADCIN	=	CHANNEL_INJECTION;					// -
	ADCON |=	(	ADSTC	<< 12	);					// ADSTC	- 
	ADCON |=	(	ADCTC	<< 14	);					// ADCTC	- 

}																				

void StartADC( void	)	{

	ADST = 1;		// ADST - Start ADC conversion

}
