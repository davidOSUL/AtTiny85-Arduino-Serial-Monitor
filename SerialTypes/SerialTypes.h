
#ifndef SerialTypes_h
#define SerialTypes_h
#include "Arduino.h"
class SerialTypes
{
	public:	
		enum Type { //defining values isn't strictly necessary, but is for clarity
			BOOL = 0,
			CHAR = 1,
			INT8 = 2,
			UINT8 = 3,
			INT16 = 4,
			UINT16 = 5,
			INT32 = 6,
			UINT32 = 7,
			FLOAT = 8
		
		};
	static uint8_t getTypeNumBytes(Type type);
	static const uint8_t ARR_FORM;
	static const uint8_t ARR_NO_FORM;
};

#endif
