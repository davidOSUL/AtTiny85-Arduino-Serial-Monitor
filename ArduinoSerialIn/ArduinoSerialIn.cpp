/*
* Library to be uploaded to arduino to read input from teensy
* By: David O'Sullivan
* https://github.com/davidOSUL/AtTiny85-Arduino-Serial-Monitor
*/
#include "ArduinoSerialIn.h"
#include "SerialTypes.h"
#include "Arduino.h"
ArduinoSerialIn::ArduinoSerialIn()
{
	_currentByteSize = -1;

}

void ArduinoSerialIn::readIfShould()
{

	
	if (Serial.available() >= 1 && _currentByteSize == -1)
	{
		uint8_t type = (uint8_t) Serial.read();
		_currentType = type;
		_currentByteSize = SerialTypes::getTypeNumBytes(type);
		if (_currentByteSize == 0) {
			Serial.println("ERROR in read, serial out of sync");
		}
	}
	else if (_currentByteSize != -1 && Serial.available() >= _currentByteSize)
	{
		readAndPrintType(_currentType, true);
		_currentByteSize = -1;
	}
}

void ArduinoSerialIn::readIfArray(uint8_t currType)
{
	if (currType != SerialTypes::ARR_FORM && currType != SerialTypes::ARR_NO_FORM)
	{
		Serial.println("ERROR in read, serial out of sync");
		return;
	}
	while (Serial.available() < 5){} //1 byte for the type of the array and 4 bytes for the size
	
	uint8_t arrayElementType = Serial.read();
	_currentByteSize = SerialTypes::getTypeNumBytes(SerialTypes::UINT32);
	uint32_t arrayLength = readIntType<uint32_t>();
	_currentByteSize = SerialTypes::getTypeNumBytes(arrayElementType);
	
	while (Serial.available() < arrayLength*_currentByteSize) {} //wait for all elements to be read
	
	if (currType == SerialTypes::ARR_FORM)
	{
		Serial.print("[");
		for (int i = 0; i < arrayLength; i++) {
			if (i > 0) {
				Serial.print(", ");
			}
			readAndPrintType(arrayElementType, false);
		}
		Serial.print("]");
	}

	else if (currType == SerialTypes::ARR_NO_FORM)
	{
		for (int i = 0; i < arrayLength; i++) {
			readAndPrintType(arrayElementType, false);
		}
	}
	Serial.println("");
}

template <typename T>
T ArduinoSerialIn::readIntType()
{
	T incoming = 0;
	for (int i = 0; i < _currentByteSize; i++)
	{
		T nextByte = (T) Serial.read();
		incoming |=  nextByte << (i * 8);
	}
	return incoming;
}

float ArduinoSerialIn::readFloatType()
{
	typedef union
	{
		float floatVal;
		uint8_t asBytes[4];
	} binaryFloat;
	binaryFloat floatWithBytes;
	for (int i = 0; i < 4; i++)
	{
		floatWithBytes.asBytes[i] = Serial.read();
	}
	return floatWithBytes.floatVal;
}

void ArduinoSerialIn::readAndPrintType(uint8_t type, bool putOnNewLine)
{
	switch (type)
	{
		case SerialTypes::BOOL:
			if (putOnNewLine)
			 	Serial.println(readIntType<bool>() ? "true" : "false");
			else
				Serial.print(readIntType<bool>()  ? "true" : "false");
			break;
		case SerialTypes::CHAR:
			if (putOnNewLine)
			 	Serial.println(readIntType<char>());
			else
				Serial.print(readIntType<char>());
			break;
		case SerialTypes::INT8:
			if (putOnNewLine)
			 	Serial.println(readIntType<int8_t>());
			else
				Serial.print(readIntType<int8_t>());
			break;
		case SerialTypes::UINT8:
			if (putOnNewLine)
			 	Serial.println(readIntType<uint8_t>());
			else
				Serial.print(readIntType<uint8_t>());
			break;
		case SerialTypes::INT16:
			if (putOnNewLine)
			 	Serial.println(readIntType<int16_t>());
			else
				Serial.print(readIntType<int16_t>());
			break;
		case SerialTypes::UINT16:
			if (putOnNewLine)
			 	Serial.println(readIntType<uint16_t>());
			else
				Serial.print(readIntType<uint16_t>());
			break;
		case SerialTypes::INT32:
			if (putOnNewLine)
			 	Serial.println(readIntType<int32_t>());
			else
				Serial.print(readIntType<int32_t>());
			break;
		case SerialTypes::UINT32:
			if (putOnNewLine)
			 	Serial.println(readIntType<uint32_t>());
			else
				Serial.print(readIntType<uint32_t>());
			break;
		case SerialTypes::FLOAT:
			if (putOnNewLine)
			 	Serial.println(readFloatType());
			else
				Serial.print(readFloatType());
			break;
		default:
			readIfArray(type);
			break;
	}
}
