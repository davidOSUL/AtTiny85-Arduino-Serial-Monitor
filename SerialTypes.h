
#ifndef SerialTypes_h
#define SerialTypes_h
#include "Arduino.h"
class SerialTypes
{
	public:	
		enum Type {
			BOOL,
			CHAR,
			INT8,
			UINT8,
			INT16,
			UINT16,
			INT32,
			UINT32,
			FLOAT
		
		};
	static uint8_t getTypeNumBytes(Type type);
	static const uint8_t ARR_FORM;
	static const uint8_t ARR_NO_FORM;
};

#endif
