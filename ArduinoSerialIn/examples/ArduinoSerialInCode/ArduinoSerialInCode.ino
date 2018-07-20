/*
 * Upload this code to your arduino to recieve input from
 * an AtTiny which is using the TinySerialOut Library.
 * By: David O'Sullivan 
 * https://github.com/davidOSUL/AtTiny85-Arduino-Serial-Monitor
 * 
 * 
 * The ATTiny Pin specified TX in the TinySerialOut instance should be connected to 
 * this Arduino's RX pin with a 330 ohm resistor in series. 
 */
#include <ArduinoSerialIn.h>
ArduinoSerialIn SerialIn; //Create a new instance of the serial reader. Be careful to not name this "Serial" as this library makes use of arduinos default Serial
void setup() {
  Serial.begin(9600); //Initialize Serial on the arduino
} 

void loop() {
  SerialIn.readIfShould(); //Constantly check for new inputs from ATTiny
  
}
