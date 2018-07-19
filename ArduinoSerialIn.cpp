#include "ArduinoSerialIn.h"
#include "SerialTypes.h"
#include "Arduino.h"
	ArduinoSerialIn::ArduinoSerialIn(int rate) {
		Serial.begin(rate);
		_currentByteSize = -1;
	}
	void ArduinoSerialIn::readIfShould() {
		if (Serial.available() >= 1 && _currentByteSize == -1) {
			uint8_t type = (uint8_t )Serial.read();
			_currentByteSize = SerialTypes::getTypeNumBytes(type);
			_currentType = type;
		}
		else if (_currentByteSize != -1 && Serial.available() >= _currentByteSize) {
			switch(_currentType) {
				case SerialTypes::BOOL:
					Serial.println((bool) Serial.read());
					break;
				case SerialTypes::CHAR:
					Serial.println((char) Serial.read());
					break;
				case SerialTypes::INT8:
					Serial.println((char) Serial.read());
					break;
				case SerialTypes::UINT8:
					Serial.println((uint8_t) Serial.read());
					break;
				case SerialTypes::INT16:
				case SerialTypes::UINT16:
				case SerialTypes::INT32:
				case SerialTypes::UINT32:
				case SerialTypes::FLOAT:
					break;
				default:
					readIfArray(_currentType);
					break;
			}
			_currentByteSize = -1;
		}
	}
	void ArduinoSerialIn::readIfArray(uint8_t currType) {
		if (currType == SerialTypes::ARR_FORM) {

		}
		else if (currType == SerialTypes::ARR_NO_FORM) {

		}
	}