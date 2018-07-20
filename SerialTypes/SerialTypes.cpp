/*
* Contains enum for different data types, and method to get amount of bytes
* By: David O'Sullivan
* https://github.com/davidOSUL/AtTiny85-Arduino-Serial-Monitor
*/
#include "SerialTypes.h"
#include "Arduino.h"
	static const uint8_t SerialTypes::ARR_FORM = FLOAT+1;
	static const uint8_t SerialTypes::ARR_NO_FORM = ARR_FORM+1;
	static uint8_t SerialTypes::getTypeNumBytes(Type type)
	{
		switch (type)
		{
			case BOOL:
			case CHAR:
			case INT8:
			case UINT8:
				return 1;
				break;
			case INT16:
			case UINT16:
				return 2;
				break;
			case INT32:
			case UINT32:
			case FLOAT:
				return 4;
				break;
			case ARR_NO_FORM:
			case ARR_FORM:
				return 6; 
				break;
			default:
				return 0;
				break;
		}
	}
