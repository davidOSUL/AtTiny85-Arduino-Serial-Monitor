
/*
* Library Uploaded to AtTiny to Write to arduino
* By: David O'Sullivan
* https://github.com/davidOSUL/AtTiny85-Arduino-Serial-Monitor
*/
#ifndef TinySerialOut_h
#define TinySerialOut_h
#include "Arduino.h"
#include <SoftwareSerial.h>
#include "SerialTypes.h"
/*
*Comment Out To Prevent 100 ms delay after writing (not reccomended if frequent calls will be made, can cause timing issues)
*/
#define USE_DELAY 

/*
*Change default delay (recomended: 100)
*/
#define DELAY 100

/*
*Comment Out To disable all the overloaded write() functions
*/
#define USE_SHORTHAND_FUNCTIONS

/*
*Comment Out To disable printing bools
*/
#define USE_BOOL

/*
*Comment Out To disable printing chars
*/
#define USE_CHAR

/*
*Comment Out To disable printing int8_ts
*/
#define USE_INT8

/*
*Comment Out To disable printing unt8_ts
*/
#define USE_UINT8

/*
*Comment Out To disable printing int16_ts
*/
#define USE_INT16

/*
*Comment Out To disable printing uint16_ts
*/
#define USE_UINT16

/*
*Comment Out To disable printing int32_ts
*/
#define USE_INT32

/*
*Comment Out To disable printing uint32_ts
*/
#define USE_UINT32

/*
*Comment Out To disable printing floats
*/
#define USE_FLOAT

/*
*Comment Out To disable printing arrays (and consequently strings)
*/
#define USE_ARRAY

class TinySerialOut {
	
public:
	/*
	*The Digital Pin on the attiny. Note that this is not the same pin # as the literal hardware pin. Instead this is the digital pin #
	(E.g. if you are putting a wire from hardware pin 3 (the 3rd down on the lefthand side), TX would be 4). 
	*/
	TinySerialOut(uint8_t  TX);
	#ifdef USE_BOOL
		/*
		*Writes a boolean (true or false). To write a 1 or a 0 use writeUnsignedInt8
		*/
		writeBool(bool out);
	#endif

	#ifdef USE_CHAR
		/*
		*Writes a alphanumeric character (e.g. 'h'). To write a character as a number use writeInt8
		*/
		writeChar(char out);
	#endif

	#ifdef USE_INT8
		/*
		*Writes an 8 bit signed integer number
		*/
		writeInt8(int8_t out);
	#endif

	#ifdef USE_UINT8
		/*
		*Writes an 8 bit unsigned integer number
		*/
		writeUnsignedInt8(uint8_t out);
	#endif

	#ifdef USE_INT16
		/*
		*Writes a 16 bit signed integer number
		*/
		writeInt16(int16_t out);
	#endif

	#ifdef USE_UINT16
		/*
		*Writes a 16 bit unsigned integer number
		*/
		writeUnsignedInt16(uint16_t out);
	#endif
	
	#ifdef USE_INT32
		/*
		*Writes a 32 bit signed integer number
		*/
		writeInt32(int32_t out);
	#endif
	
	#ifdef USE_UINT32
		/*
		*Writes a 32 bit unsigned integer number
		*/
		writeUnsignedInt32(uint32_t out);
	#endif
	
	#ifdef USE_FLOAT
		/*
		*Writes a floating point number. Note that the AtTiny does not have double precision floats available
		*/
		writeFloat(float out);
	#endif

	#ifdef USE_ARRAY
		/*
		*Writes an array of any type with optional formatting. "addFormatting" will seperate values by commas and spaces. Length and type 
		of array must both be specified (type is specified from the enum in SerialTypes).
		Ex1:
			int16_t a[] = {1,2,3,4,5};
			writeArray(a, SerialTypes::INT16, 5, true);
			output: "[1,2,3,4,5]"
		Ex2:
			int16_t a[] = {1,2,3,4,5};
			writeArray(a, SerialTypes::INT16, 5, false);
			output: "12345"
		Ex3:
			char a[] = {'h','e','l','l','o'} ;
			writeArray(a, SerialTypes::CHAR, sizeof(a), false);
			output: "hello" 
		Ex4:
			char a[] = "hello";
			writeArray(a, SerialTypes::CHAR, sizeof(a), false);
			output: "hello" 
		Ex5:
			char a[] = "hello";
			writeArray(a, SerialTypes::CHAR, sizeof(a), true);
			output: "['h', 'e', 'l', 'l', 'o', ]"" //extra space from null terminator, use sizeof(a)-1 to avoid 
		*/
		writeArray(void * out, SerialTypes::Type type, uint32_t length, bool addFormatting);
		
		/*
		*Exact same as calling writeArray(out, SerialType::CHAR, length, false)
		Ex1:
			char a[] = "hello";
			writeString(hello, sizeof(a)); //(or writeString(hello, sizeof(a)-1)), same output due to null terminator
			output: "hello"
		*/
		writeString(char * out, uint32_t length);
		
	#endif
begin(int rate);
#ifdef USE_SHORTHAND_FUNCTIONS
	#ifdef USE_INT16
		/*
		* Same as calling writeInt16(out); 
		* Note that int16_t is equivalent to arduinos "int"
		*/
		write(int16_t out);
	#endif
	
	#ifdef USE_INT32
		/*
		* Same as calling writeInt32(out).
		* Note that int32_t is equivalent to arduinos "long"
		*/
		write(int32_t out);
	#endif
	
	#ifdef USE_ARRAY
		/*
		* Same as calling writeString(out, length)
		*/
		write(char * out, uint32_t length);
	#endif
	
	#ifdef USE_BOOL
		/*
		*Same as calling writeBool(out);
		*/
		write(bool out);
	#endif

	#ifdef USE_CHAR
		/*
		*Same as calling writeChar(out);
		*/
		write(char out);
	#endif
	
	#ifdef USE_FLOAT
		/*
		* Same as calling writeFloat(out);
		*/
		write(float out);
		/*
		* Same as calling writeFloat(out);
		*(note that AtTiny does not actually have "doubles", they are just converted to floats.
		* However, defining this function allows one to avoid appending "f" to numeric constant)
		*/
		write(double out); 
	#endif
	
#endif
private:
	SoftwareSerial _mySerial;
	writeAllBytes(void  * bytes, uint8_t numBytes);
	writeAllBytesNoFlush(void * bytes, uint8_t numBytes);
	writeArrayLength(uint32_t size);

};
#endif