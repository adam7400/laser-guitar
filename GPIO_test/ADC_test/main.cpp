#include <wiringPi.h>
#include <mcp3004.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// SPI setup
#define SPI_CHAN 0
#define MY_PIN 100

int main(void)
{
int x0,x1,x2,x3,x4,x5;	// Digital signal
float v;	// Voltage (V)
float k = 3.3/1024; //ADC resolution

// SPI setup
  wiringPiSetup() ;
  mcp3004Setup (MY_PIN, SPI_CHAN); // 3004 and 3008 are the same 4/8 channel

while(1){
	x0 = analogRead (MY_PIN); 	// Read value from CH0 on ADC
	x1 = analogRead (MY_PIN + 1);
	x2 = analogRead (MY_PIN + 2);
	x3 = analogRead (MY_PIN + 3);
	x4 = analogRead (MY_PIN + 4);
	x5 = analogRead (MY_PIN + 5);
	cout<<"\nCH0: "<<x0<<endl;	// Print the value of digital signal
	cout<<"CH1: "<<x1<<endl;	// Print the value of digital signal
	cout<<"CH2: "<<x2<<endl;	
	cout<<"CH3: "<<x3<<endl;
	cout<<"CH4: "<<x4<<endl;	
	cout<<"CH5: "<<x5<<endl;
	//cout<<"Voltage:  "<<k*(float)(x)<<"V"<<endl; // Print voltage
	
	delay(100);
}
	return 0;
}
