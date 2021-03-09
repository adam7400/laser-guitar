#include <iostream>
#include <thread>
#include <chrono>
#include <wiringPi.h>
#include <mcp3004.h>
#include "SoundThread.h"




// SPI definitions
#define SPI_CHAN 0
#define MY_PIN 12345


void SoundThread::run() {

// If the laser beam is broken and digital signal falls below threshold, then play the sound

	if (DS < threshold)
		std::cout << "PLAY SOUND!" << std::endl;
	}






int main (int argc, const char* argv[])
{
	int x1;	 		// input from ADC channel 1
	int x2;
	int th1;		// digital signal threshold
	int th2;

// Arbitrary threshold values. These will be based on chosen resistors in the phototransistor circuit.
th1 = 300;
th2 = 500;

while (1)
{

// User input for digital signal - should be replaced by ADC readings
std::cin >> x1;
std::cin >> x2;

SoundThread string1(th1, x1);
SoundThread string2(th2, x2);
string1.start();
string2.start();
string1.join();
string2.join();

}




// SPI setup
/*  	wiringPiSetup() ;
  	mcp3004Setup (MY_PIN, SPI_CHAN); // 3004 and 3008 are the same 4/8 channels
*/
// Read the digitalvalue from the ADC pin
//	x = analogRead (MY_PIN);
// Write the value on the screen
//	std::cout << "Digital signal:" << x << std::endl;






return 0;
}
