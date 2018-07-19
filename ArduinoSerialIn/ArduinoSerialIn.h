#ifndef ArduinoSerialIn_h
#define ArduinoSerialIn_h
#include "SerialTypes.h"
#include "Arduino.h"
class ArduinoSerialIn{
public:
	ArduinoSerialIn();
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