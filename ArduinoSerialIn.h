#ifndef ArduinoSerialIn_h
#define ArduinoSerialIn_h
#include "SerialTypes.h"
#include "Arduino.h"
class ArduinoSerialIn{
public:
	ArduinoSerialIn(int rate);
	void readIfShould();
private:
	uint8_t _currentByteSize;
	uint8_t _currentType;
	void readIfArray(uint8_t currType);
};
#endif