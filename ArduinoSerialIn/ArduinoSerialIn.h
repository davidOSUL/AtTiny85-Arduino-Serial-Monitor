/*
* Library to be uploaded to arduino to read input from teensy
* Author: David O'Sullivan
*/
#ifndef ArduinoSerialIn_h
#define ArduinoSerialIn_h
#include "SerialTypes.h"
#include "Arduino.h"
class ArduinoSerialIn{
public:
	/*
	*Initialize the Arduino to read in data
	*/
	ArduinoSerialIn();
	/*
	*To be called repetively, if there is data to be read will print out to serial monitor
	*/
	void readIfShould();
private:
	int8_t _currentByteSize;
	uint8_t _currentType;
	void readIfArray(uint8_t currType);
	template <typename T>
	T readIntType();
	float readFloatType();
	void readAndPrintType(uint8_t type, bool putOnNewLine);
};
#endif