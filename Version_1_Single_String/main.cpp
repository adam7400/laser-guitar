#include <wiringPi.h>
#include <mcp3004.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// SPI setup
#define SPI_CHAN 0
#define MY_PIN 12345


// *** Potentially have to call all required sound files at the start of main using wget so that all files are available when digital signal is interrupted***
// Then use aplay when required further down the main.cpp (Sampling Rates using aplay ~r 48000 Hz a.wav will need to be looked at so audio can be played from audio jack)

int main(void)
{
int x,i;	// Digital signal
float v;	// Voltage (V)
float k = 3.3/1024; //ADC resolution


// SPI setup
  wiringPiSetup() ;
  mcp3004Setup (MY_PIN, SPI_CHAN); // 3004 and 3008 are the same 4/8 channels

while(1){
	x = analogRead (MY_PIN); 	// Read value from CH0 on ADC

// if statement to monitor digital signal 	
	if (x < 500) {  				// 500 value may change depending on final resistor selected, currently 30k resistor
	  cout<<"\nDigital signal: "<<x<<endl;  
	
	system("aplay samples_a.wav");

	} else {
	  cout<<"\nDigital signal: "<<x<<endl;
	}
	
	cout<<"\nDigital signal: "<<x<<endl;	// Print the value of digital signal
					
	cout<<"Voltage:  "<<k*(float)(x)<<"V"<<endl; // Print voltage
	
	// Delay removed so that response of digital signal is essentially the response of the photoresistor
}
	return 0;
} 
