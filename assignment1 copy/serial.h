// a1839619

# ifndef SERIAL_H
# define SERIAL_H

# define U0		"U0 %04.1f m/s :"
# define UW		"UW %04.1f m/s :"
# define NEW_LINE ((unsigned char) 10)

void SerialInit(	) ;

void SerialSendByte(char byte) ;

void SerialSendFloatData(float rawdata) ;

void SerialSendPayload(unsigned char *payload, unsigned char size_payload) ;

void DataFormatLine( unsigned char *format_string, unsigned char str_length, float variable ) ;

# endif

