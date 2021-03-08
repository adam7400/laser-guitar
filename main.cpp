#include <iostream>
#include <thread>
#include <wiringPi.h>
#include <mcp3004.h>



// SPI definitions
#define SPI_CHAN 0
#define MY_PIN 12345






int main()
{
	int x;




// SPI setup
  	wiringPiSetup() ;
  	mcp3004Setup (MY_PIN, SPI_CHAN); // 3004 and 3008 are the same 4/8 channels

// Read the digitalvalue from the ADC pin
	x = analogRead (MY_PIN);
// Write the value on the screen
	std::cout << "Digital signal:" << x << std::endl;






return 0;
}
