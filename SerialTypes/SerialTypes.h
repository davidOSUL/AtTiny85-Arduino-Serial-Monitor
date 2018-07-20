/*
* Contains enum for different data types, and method to get amount of bytes
* Author: David O'Sullivan
*/
#ifndef SerialTypes_h
#define SerialTypes_h
#include "Arduino.h"
class SerialTypes
{
	public:	
		/*
		* Used internally to determine what type of data is being sent. Also used as input to the writeArray function to specify what type of array
		is being inputed
		*/
		enum Type { //defining integer values isn't strictly necessary (as they would be defined automatically), but is for clarity
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
		
	/*
	*Get the number of bytes associated with a type
	*/
	static uint8_t getTypeNumBytes(Type type);
	
	/*
	*Constant used internally to signify an array with formatting
	*/
	static const uint8_t ARR_FORM;

	/*
	*Constant used internally to signify an array without formatting
	*/
	static const uint8_t ARR_NO_FORM;
};

#endif
