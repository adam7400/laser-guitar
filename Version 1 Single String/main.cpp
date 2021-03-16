#include <wiringPi.h>
#include <mcp3004.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// SPI setup
#define SPI_CHAN 0
#define MY_PIN 12345

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
	if (x < 500) { 
	  cout<<"\nDigital signal: "<<x<<endl;  
	
	// Use aplay function that is built into raspbain for audio
	  wget https://github.com/adam7400/space-harp/tree/main/Version%201%20Single%20String/Sound%20Libary%20(WAV%20files)/samples_a.wav
	  aplay a.wav 

	} else {
	  cout<<"\nDigital signal: "<<x<<endl;
	}
	
	cout<<"\nDigital signal: "<<x<<endl;	// Print the value of digital signal
					
	cout<<"Voltage:  "<<k*(float)(x)<<"V"<<endl; // Print voltage
	
	delay(200); // Delay required to print signal
}
	return 0;

