// a1839619

# include "serial.h"
# include <reg167.h>
# include <stdio.h>

typedef union {

	float	float_in;
	char	bytes[sizeof(float)];

} Bytestream_Typedef;



void SerialInit(){
	
	// Port 3 direction control register
	DP3		|=	0x0400;			// Set P3.10 to output (TxD)
	DP3		&=	~0x0800;		// Set P3.11 to input (RxD)
	// Port 3 data register
	P3		|=	0x0400;			// Set P3.10 to high (A)
	// Transmit interrupt flag
	S0TIC	=		0x80;				// Set S0TIR - active before last bit transferred
												// (transmission finished)
	// Receive interrupt flag
	S0RIC	=		0x00;				// Set S0RIR - active before last bit received
												// (buffer cleared)
	// Set baud rate
	S0BG	=		0x40;				// Reload value - 9600 baud
	// Serial configuration
	S0CON	=		0xC011;			// 1000 0000 0001 0001
												// SOM - 8 bit async
												// S0STP - 1 stop bit,
												// Reciever enabled, 
												// S0R - Baudrate generator run bit
												// set Tx to Rx when SOCON = 0x8011
}


void SerialSendByte(char byte) {

	while(S0TIR == 0);
	S0TIR = 0;
	S0TBUF = byte;
	
}


void SerialSendPayload(unsigned char *payload, unsigned char size_payload) {
	
	int i;

	for (i=0; i < size_payload; i++) {
		
			SerialSendByte(payload[i]);
		
	}
}


void SerialSendFloatData(float rawdata) {
	
	int i;
	
	Bytestream_Typedef payload;
	payload.float_in = rawdata;

	for (i=0; i < sizeof(payload.bytes); i++) {
		
			SerialSendByte(payload.bytes[i]);
		
	}
}


void DataFormatLine( unsigned char *format_string, unsigned char str_length, float variable ) {
	
	// if sizeof(str_length > 20) {do something}
	
	unsigned char str_buf[20];												// Oversized buffer for variable inputs
	
	sprintf(str_buf, format_string, variable);			// Formatting a display string
	
	SerialSendPayload(str_buf, str_length-1);				// Sending the string byte by byte
	
	SerialSendFloatData(variable);									// Send raw data using our Union
	
	SerialSendByte(NEW_LINE);												// New line
	
}
