/*
* Library Uploaded to AtTiny to Write to arduino
* By: David O'Sullivan
* https://github.com/davidOSUL/AtTiny85-Arduino-Serial-Monitor
*/
#include "Arduino.h"
#include "TinySerialOut.h"
#include "SerialTypes.h"
#include <SoftwareSerial.h>
	TinySerialOut::TinySerialOut(uint8_t TX) : _mySerial(SoftwareSerial(-1, TX)){
	}
	#ifdef USE_BOOL
		TinySerialOut::writeBool(bool out) {
			_mySerial.write((uint8_t)SerialTypes::BOOL);
			writeAllBytes(&out, SerialTypes::getTypeNumBytes(SerialTypes::BOOL));
		}
	#endif 

	#ifdef USE_CHAR
		TinySerialOut::writeChar(char out) {
			_mySerial.write((uint8_t)SerialTypes::CHAR);
			writeAllBytes(&out, SerialTypes::getTypeNumBytes(SerialTypes::CHAR));
		}
	#endif

	#ifdef USE_INT8
		TinySerialOut::writeInt8(int8_t out) {
			_mySerial.write((uint8_t)SerialTypes::INT8);
			writeAllBytes(&out, SerialTypes::getTypeNumBytes(SerialTypes::INT8));
		}
	#endif

	#ifdef USE_UINT8
		TinySerialOut::writeUnsignedInt8(uint8_t out) {
			_mySerial.write((uint8_t)SerialTypes::UINT8);
			writeAllBytes(&out, SerialTypes::getTypeNumBytes(SerialTypes::UINT8));
		}
	#endif

	#ifdef USE_INT16
		TinySerialOut::writeInt16(int16_t out) {
			_mySerial.write((uint8_t)SerialTypes::INT16);
			writeAllBytes(&out, SerialTypes::getTypeNumBytes(SerialTypes::INT16));
		}
	#endif

	#ifdef USE_UINT16
		TinySerialOut::writeUnsignedInt16(uint16_t out)  {
			_mySerial.write((uint8_t)SerialTypes::UINT16);
			writeAllBytes(&out, SerialTypes::getTypeNumBytes(SerialTypes::UINT16));
		}
	#endif

	#ifdef USE_INT32
		TinySerialOut::writeInt32(int32_t out)  {
			_mySerial.write((uint8_t)SerialTypes::INT32);
			writeAllBytes(&out, SerialTypes::getTypeNumBytes(SerialTypes::INT32));
		}
	#endif

	#ifdef USE_UINT32
		TinySerialOut::writeUnsignedInt32(uint32_t out) {
			_mySerial.write((uint8_t)SerialTypes::UINT32);
			writeAllBytes(&out, SerialTypes::getTypeNumBytes(SerialTypes::UINT32));
		}
	#endif
	
	#ifdef USE_FLOAT
		TinySerialOut::writeFloat(float out)  {
			_mySerial.write((uint8_t)SerialTypes::FLOAT);
			writeAllBytes(&out, SerialTypes::getTypeNumBytes(SerialTypes::FLOAT));
		}
	#endif

	#ifdef USE_ARRAY
		TinySerialOut::writeArray(void * out, SerialTypes::Type type, uint32_t length, bool addFormatting)  {
			_mySerial.write(addFormatting ? SerialTypes::ARR_FORM : SerialTypes::ARR_NO_FORM); //whether or not we format
			_mySerial.write((uint8_t) type); //then send type of array
			writeArrayLength(length); //followed by length
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
		TinySerialOut::writeString(char * out, uint32_t length) {
			writeArray(out, SerialTypes::CHAR, length, false);
		}
	#endif

	TinySerialOut::writeAllBytesNoFlush(void * bytes, uint8_t numBytes) {
		uint8_t * newBytes = (uint8_t *) bytes;
		for (int i = 0; i < numBytes; i++) {
			_mySerial.write(newBytes[i]);
		}
	}

	TinySerialOut::writeAllBytes(void * bytes, uint8_t numBytes) {
		writeAllBytesNoFlush(bytes, numBytes);
		_mySerial.flush();
		#ifdef USE_DELAY
			delay(100);
		#endif
	}

	#ifdef USE_ARRAY
		TinySerialOut::writeArrayLength(uint32_t size) {
			writeAllBytesNoFlush(&size, SerialTypes::getTypeNumBytes(SerialTypes::UINT32));
		}
	#endif

	TinySerialOut::begin(int rate) {
		_mySerial.begin(rate);
	}

#ifdef USE_SHORTHAND_FUNCTIONS
	#ifdef USE_INT16
		TinySerialOut::write(int16_t out) {
			writeInt16(out);
		}
	#endif
	
	#ifdef USE_INT32
		TinySerialOut::write(int32_t out) {
			writeInt32(out);
		}
	#endif
	
	#ifdef USE_ARRAY
		TinySerialOut::write(char * out, uint32_t length) {
			writeString(out, length);
		}
	#endif

	#ifdef USE_BOOL
		TinySerialOut::write(bool out) {
			writeBool(out);
		}
	#endif

	#ifdef USE_CHAR
		TinySerialOut::write(char out) {
			writeChar(out);
		}
	#endif
	
	#ifdef USE_FLOAT
		TinySerialOut::write(float out) {
			writeFloat(out);
		}

		TinySerialOut::write(double out) {
			writeFloat(out);
		}
	#endif
#endif
