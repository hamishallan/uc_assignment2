// a1839619

# include <reg167.h>
# include "timer.h"
# include "adc.h"

void T3elapsed(void) interrupt 0x23 {
	
	StartADC(	)	;

}

void T3Init( void ) {
	
	IEN	=	1					;		// Enable interrupts (PSW |= 0x0800)
	T3	=	T3_RELOAD	;		// Reset T3
	
	// Timer3 in timer mode, counting down, pre-scale factor of 128
	// period: 420 ms, alternate output function disabled
	// T3CON = 0000 0000 1000 0100 = 0x0084
	T3CON = 0x0084	;
//	T3CON	|=	T3I									;
//	T3CON	|=	(	T3M	<<	3	)				;
//	T3UD	=		UD_CONTROL					;
//	T3UDE	=		EX_UD_ENABLE				;
//	T3OE	=		ALT_OUT_FUNC_ENABLE	;
//	T3IC	=	0x0044	;		// Enable T3 interrupt, ILVL = 1, GLVL = 0

}

void StartT3( void )	{
	
	T3	=	T3_RELOAD	;		// Reset T3
	T3R	=	1					;		// Start timer

}