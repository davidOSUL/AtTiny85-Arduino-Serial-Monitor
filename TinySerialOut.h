
#ifndef TinySerialOut
#define TinySerialOut
#include "Arduino.h"
#include <SoftwareSerial.h>
class TinySerialOut {
public:
	TinySerialOut(int RX, int TX);
	writeBool(bool out);

	writeChar(char out);

	writeByte(byte out);
	
	writeInt32(int32_t out);
	writeUnsignedInt32(uint32_t out);

	writeInt16(int16_t out);
	writeUnsignedInt16(uint16_t out);
	
	writeFloat(float out);
	
	writeDouble(double out);
	
	writeLong(long out);

	writeString(String out);
	writeCharArray(char[] out);
private:
	SoftwareSerial _mySerial;

}

#endif