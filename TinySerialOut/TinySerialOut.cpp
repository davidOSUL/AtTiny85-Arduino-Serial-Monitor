#include "Arduino.h"
#include "TinySerialOut.h"
#include "SerialTypes.h"
#include <SoftwareSerial.h>
//typedef SerialTypes Type;
	TinySerialOut::TinySerialOut(uint8_t RX, uint8_t TX) : _mySerial(SoftwareSerial(RX, TX)){
	}
	TinySerialOut::writeBool(bool out) {
		_mySerial.write((uint8_t)SerialTypes::BOOL);
		writeAllBytes(&out, SerialTypes::getTypeNumBytes(SerialTypes::BOOL));
	}

	TinySerialOut::writeCharAsCharacter(char out) {
		_mySerial.write((uint8_t)SerialTypes::CHAR);
		writeAllBytes(&out, SerialTypes::getTypeNumBytes(SerialTypes::CHAR));
	}

	
	TinySerialOut::writeInt32(int32_t out)  {
		_mySerial.write((uint8_t)SerialTypes::INT32);
		writeAllBytes(&out, SerialTypes::getTypeNumBytes(SerialTypes::INT32));
	}
	TinySerialOut::writeUnsignedInt32(uint32_t out) {
		_mySerial.write((uint8_t)SerialTypes::UINT32);
		writeAllBytes(&out, SerialTypes::getTypeNumBytes(SerialTypes::UINT32));
	}
	TinySerialOut::writeInt16(int16_t out) {
		_mySerial.write((uint8_t)SerialTypes::INT16);
		writeAllBytes(&out, SerialTypes::getTypeNumBytes(SerialTypes::INT16));
	}
	TinySerialOut::writeUnsignedInt16(uint16_t out)  {
		_mySerial.write((uint8_t)SerialTypes::UINT16);
		writeAllBytes(&out, SerialTypes::getTypeNumBytes(SerialTypes::UINT16));
	}
	TinySerialOut::writeInt8(int8_t out) {
		_mySerial.write((uint8_t)SerialTypes::INT8);
		writeAllBytes(&out, SerialTypes::getTypeNumBytes(SerialTypes::INT8));
	}
	TinySerialOut::writeUnsignedInt8(uint8_t out) {
		_mySerial.write((uint8_t)SerialTypes::UINT8);
		writeAllBytes(&out, SerialTypes::getTypeNumBytes(SerialTypes::UINT8));
	}
	
	TinySerialOut::writeFloat(float out)  {
		_mySerial.write((uint8_t)SerialTypes::FLOAT);
		writeAllBytes(&out, SerialTypes::getTypeNumBytes(SerialTypes::FLOAT));
	}
	TinySerialOut::writeArray(void * out, SerialTypes::Type type, uint32_t length, bool addFormatting)  {
		_mySerial.write(addFormatting ? SerialTypes::ARR_FORM : SerialTypes::ARR_NO_FORM);
		_mySerial.write((uint8_t) type);
		writeArrayLength(length);
		uint8_t * newOut = (uint8_t *) out;
		uint32_t totalSize = length*SerialTypes::getTypeNumBytes(type);
		for (int i = 0 ; i < totalSize; i++) {
			_mySerial.write(newOut[i]);
		}
		_mySerial.flush();
		#ifdef USE_DELAY
			delay(100);
		#endif
	}
	TinySerialOut::writeAllBytes(void * bytes, uint8_t numBytes) {
		uint8_t * newBytes = (uint8_t *) bytes;
		for (int i = 0; i < numBytes; i++) {
			_mySerial.write(newBytes[i]);
		}
		_mySerial.flush();
		#ifdef USE_DELAY
			delay(100);
		#endif
	}
	TinySerialOut::writeArrayLength(uint32_t size) {
		writeAllBytes(&size, SerialTypes::getTypeNumBytes(SerialTypes::UINT32));
	}
	TinySerialOut::begin(int rate) {
		_mySerial.begin(rate);
	}
