/*
 * Example of using the implicit "write" function to write different types of data.
 * Note that this function is provided for convenience but does not introduce any additional functionality. 
 * 
 * Values that can be written out using write(...) are: 
 * int16_t (Arduino's "int"), int32_t (Arduino's "long"), char arrays, bool, char, float
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

#define STRING_WRITE(str) (SerialOut.write(str, sizeof(str))) //macro to make writing strings easier

TinySerialOut SerialOut(TX); //create the serial to be used on this tiny. To get arduino style coloring, name this "Serial" 
void setup() {
   pinMode(LED_PIN, OUTPUT); 
   digitalWrite(LED_PIN, HIGH); //turn on the LED attached to D0. 
   
   pinMode(TX, OUTPUT); //needed to allow tiny to send out data
   SerialOut.begin(9600); //must be called before any writes to set up the serial on the tiny
}

void loop() {
  /*
   * Outputs a written character. 
   */
  char letter = 't';
  SerialOut.write(letter); 

  /*
   * Outputs a string. Note that the second input to 
   * write when using a char array is the length of the char array.
   * sizeof works fine because characters are 1 byte each.
   */
  char message[] = "Hello, world!";
  SerialOut.write(message, sizeof(message));

  /*
   * Using the macro STRING_WRITE defined above, we could also do:
   */
  STRING_WRITE("Good day, planet!");
  
  /*
   * Outputs an int (a signed 16 bit integer).
   */
  int intMax = 32767;
  SerialOut.write(intMax);
  
  /*
   * Outputs a long (a signed 32 bit integer).
   */
   long longMax = 2147483647;
   SerialOut.write(longMax);
 
 /*
  * Outputs a bool as "false". 
  */
  bool candyIsHealthy = false;
  SerialOut.write(candyIsHealthy);

  /*
   * Outputs a floating point value.
   */
  float floatVal = -123.45;
  SerialOut.write(floatVal);
  

}
