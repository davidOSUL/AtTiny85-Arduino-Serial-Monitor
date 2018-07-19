
#ifndef TinySerialOut_h
#define TinySerialOut_h
#include "Arduino.h"
#include <SoftwareSerial.h>
#include "SerialTypes.h"
#define USE_DELAY
class TinySerialOut {
public:
	TinySerialOut(uint8_t RX, uint8_t  TX);
	writeBool(bool out);

	writeCharAsCharacter(char out);

	writeInt8(int8_t out);
	writeUnsignedInt8(uint8_t out);

	writeInt16(int16_t out);
	writeUnsignedInt16(uint16_t out);
		
	writeInt32(int32_t out);
	writeUnsignedInt32(uint32_t out);

	writeFloat(float out);
	
	writeArray(void * out, SerialTypes::Type type, uint32_t length, bool addFormatting);
	begin(int rate);
private:
	SoftwareSerial _mySerial;
	writeAllBytes(void  * bytes, uint8_t numBytes);
	writeArrayLength(uint32_t size);

};
#endif