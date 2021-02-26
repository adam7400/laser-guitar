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
	
	cout<<"\nDigital signal: "<<x<<endl;	// Print the value of digital signal
					
	cout<<"Voltage:  "<<k*(float)(x)<<"V"<<endl; // Print voltage
	
	delay(2000);
}
	return 0;
}
