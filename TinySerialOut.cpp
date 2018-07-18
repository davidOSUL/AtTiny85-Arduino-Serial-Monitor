#include "Arduino.h"
#include "Morse.h"
#include <SoftwareSerial.h>
class TinySerialOut{
	TinySerialOut::TinySerialOut(int RX, int TX) {
		_mySerial = SoftwareSerial(RX, TX);
	}
	TinySerialOut::writeBool(bool out) {

	}

	TinySerialOut::writeChar(char out) {

	}

	TinySerialOut::writeByte(byte out)  {

	}
	
	TinySerialOut::writeInt32(int32_t out)  {

	}
	TinySerialOut::writeUnsignedInt32(uint32_t out) {

	}

	TinySerialOut::writeInt16(int16_t out) {

	}
	TinySerialOut::writeUnsignedInt16(uint16_t out)  {

	}
	
	TinySerialOut::writeFloat(float out)  {

	}
	
	TinySerialOut::writeDouble(double out)  {

	}
	
	TinySerialOut::writeLong(long out) {

	}

	TinySerialOut::writeString(char[] out)  {

	}
	TinySerialOut::writeArray(void * out, Type type, uint32_t length, bool addFormatting)  {
		switch(type) {
		case BOOL:

		case CHAR:
		case INT32:
		case UINT32:
		case INT16:
		case UINT16:
		case FLOAT:
		}
	}

}