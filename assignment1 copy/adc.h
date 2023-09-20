// a1839619

#ifndef ADC_H
#define ADC_H

// Include pin defintions and wrapper functions
# include "stdtypes_C167.h"
# include "pindefs.h"
# include "gpio.h"

//ADC Settings
# define BUFFER_SIZE	(1)
# define AD_CH_SELECT (1)
# define AD_MODE_SELECT	(3)
# define WAIT_FOR_READ_CONTROL (NO)
# define CHANNEL_INJECTION	(NO)
# define ADSTC	(0)
# define ADCTC	(0)

/**
 \fn        void ADC_Init( void )
 \brief     Initialise the ADC
*/
void ADCInit() ;

/**
 \fn			void GetADCVal(int *buffer_copy)
 \brief		Stops any conversion running on the ADC,
					Starts the ADC conversion,
					Waits until the ADC conversion completes by looking at the Data Register (DR),
					Stops any conversion running on the ADC,
					Gets the value returned by the ADC0.0 channel,
*/
void GetADCVal(int *buffer_copy) ;

/**
 \fn			void StartADC( void )	;
 \brief		Stops any conversion running on the ADC,
					Starts the ADC conversion,
					Waits until the ADC conversion completes by looking at the Data Register (DR),
					Stops any conversion running on the ADC,
					Gets the value returned by the ADC0.0 channel,
*/
void StartADC()	;

#endif

