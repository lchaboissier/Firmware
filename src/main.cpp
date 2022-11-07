// Include Libraries
#include "LED.h"
#include <Arduino.h>

// Pin Definitions
#define LEDB_PIN_VIN 15
#define LEDR_PIN_VIN 2

// Channel Definitions
#define LEDB_PIN_CHANNEL 0
#define LEDR_PIN_CHANNEL 3

// Global variables and defines

// object initialization
LED ledB(LEDB_PIN_VIN, LEDB_PIN_CHANNEL);
LED ledR(LEDR_PIN_VIN, LEDR_PIN_CHANNEL);

// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) LED - Basic Blue 5mm"));
    Serial.println(F("(2) LED - Basic Red 5mm"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("Now Testing LED - Basic Blue 5mm"));
    		else if(c == '2') 
    			Serial.println(F("Now Testing LED - Basic Red 5mm"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{

    if(menuOption == '1') {
    // LED - Basic Blue 5mm - Test Code
    // The LED will turn on and fade till it is off
    for(int i=255 ; i> 0 ; i -= 5)
    {
        ledB.dim(i);            // 1. Dim Led 
        delay(30);              // 2. waits 30 milliseconds. Change the value in the brackets for a longer or shorter delay in milliseconds.
    }                                          
    ledB.off();                 // 3. turns off
    }
    else if(menuOption == '2') {
    // LED - Basic Red 5mm - Test Code
    // The LED will turn on and fade till it is off
    for(int i=255 ; i> 0 ; i -= 5)
    {
    ledR.dim(i);                // 1. Dim Led 
    delay(30);                  // 2. waits 30 milliseconds. Change the value in the brackets for a longer or shorter delay in milliseconds.
    }                                          
    ledR.off();                 // 3. turns off
    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}

