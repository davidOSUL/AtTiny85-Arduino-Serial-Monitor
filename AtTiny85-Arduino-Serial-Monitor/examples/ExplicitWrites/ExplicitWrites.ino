/*
 * Example of using the explictly named functions (writeInt8, writeFloat, etc.) 
 * to write values out. 
 * By: David O'Sullivan
 * https://github.com/davidOSUL/AtTiny85-Arduino-Serial-Monitor
 * 
 * Note that "physical pin" is used here to refer to the numbers of the hardware pins themselves (that is 1-4 going down on the left side of the tiny, 5-8 going up on the right)
 * Connect the Tiny's Pin D4 (physical pin 3) to the Arduino's RX pin with a 330 Ohm resistor in series.
 * Connect the Tiny's Voltage pin (physical pin 8) to the Arduino's 5V pin.
 * Connect the Tiny's GND Pin (physical pin 4) to the Arduino's GND pin
 * 
 * Optionally connect an LED to pin D0 (physical pin 5) with a resistor in series. This will light up when the 
 * AtTiny turns on so you know its working
 * 
 * Upload this code to the ATTiny. 
 * Make sure you have selected the correct processor and clock (Internal 8 MHZ most likely)
 */
#include <TinySerialOut.h>
#include <SerialTypes.h>
#define TX 4 //This is output pin to send serial data over: D4 (physical pin 3 on ATTiny85)
#define LED_PIN 0 //connect an LED to make sure the tiny is turning on. This is pin D0 (physical pin 5 on ATTiny85)

TinySerialOut SerialOut(TX); //create the serial to be used on this tiny. To get arduino style coloring, name this "Serial" 
void setup() {
   pinMode(LED_PIN, OUTPUT); 
   digitalWrite(LED_PIN, HIGH); //turn on the LED attached to D0. 
   
   pinMode(TX, OUTPUT); //needed to allow tiny to send out data
   SerialOut.begin(9600); //must be called before any writes to set up the serial on the tiny
}

void loop() {
  /*
   * Outputs a written character. To Output the numerical value instead,
   * use writeInt8. 
   */
  char letter = 't';
  SerialOut.writeChar(letter); 

  /*
   * Outputs a string. Note that the second input to 
   * writeString is the length of the char array.
   * sizeof works fine  because characters are 1 byte each.
   */
  char message[] = "Hello, world!";
  SerialOut.writeString(message, sizeof(message));

  /*
   *Writes an array of ints with formatting. Will be outputted as:
   *"[1,2,3,4,5]"
   *Note that the syntax is:
   *(array, the type of elements of the array, the length of the array, whether or not to include formatting)
   *Note that length == # of elements, *not* the total number of bytes
   *
   *(Without formatting this would be output as: "12345")
   */
  int16_t ints[] = {1,2,3,4,5};
  SerialOut.writeArray(ints, SerialTypes::INT16, 5, true);

  /*
   * Outputs a signed 32 bit integer. 
   * Similarly named functions exist for signed 8 and 16 bit integers
   */
  int32_t int32Max = 2147483647;
  SerialOut.writeInt32(int32Max);

  /*
   * Outputs an unsigned 8 bit integer.
   * Similarly named functions exist for 16 and 32 bit integers.
   */
  uint8_t meaningOfLife = 42;
  SerialOut.writeUnsignedInt8(meaningOfLife);

 /*
  * Outputs a bool as "true". 
  * To output a "1" instead, use writeUnsignedInt8
  */
  bool kaleIsHealthy = true;
  SerialOut.writeBool(kaleIsHealthy);

  /*
   * Outputs a floating point value.
   */
  float floatVal = -123.45;
  SerialOut.writeFloat(floatVal);
  

}
