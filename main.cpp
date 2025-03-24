// import the library
#include "mbed.h"
#include "arm_book_lib.h"

// define the input  pins 

DigitalIn weighDetector(D2);
DigitalIn servochange(D3);
DigitalIn Lcdchange(D4);

// define the output pins
DigitalOut weighLed(LED1);
DigitalOut servoLed(LED2);
DigitalOut LcdLED(LED3);

// defining the variables 
bool weighLedState = false;
bool lcdLedState = false;


// the main loop 
int main()
{
    weighDetector.mode(PullDown);
    servochange.mode(PullDown);
    Lcdchange.mode(PullDown);

    weighLed = OFF;
    servoLed = OFF;
    LcdLED = OFF;

    while (true) {
       // check the button for the weight sensor 
        if (weighDetector.read()) {
            while (weighDetector.read());
            weighLedState = !weighLedState;
            weighLed = weighLedState;
        }
     // check the button for lcd input 
        if (Lcdchange.read()) {
            while (Lcdchange.read());
            lcdLedState = !lcdLedState;
            LcdLED = lcdLedState;
        }
// check for the servo input, and flash the led 3 tines. to show that the dog feeding 3 times 
        if (servochange.read()) {
           while (servochange.read());
            for (int i = 0; i < 3; i++) {
                servoLed = ON;
                thread_sleep_for(500); 
                servoLed = OFF;
                thread_sleep_for(1000); 
            }
        }
    }
}
