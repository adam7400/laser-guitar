#include <wiringPi.h>
#include <mcp3004.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
using namespace std;

// SPI setup
#define SPI_CHAN 0
#define MY_PIN 100


// ADC_test function to be run in thread
void ADCtest(int pin){
	int x; // store value from ADC in x
	while(1){
		x = analogRead (MY_PIN+pin);
		cout<<"CH"<<pin<<": "<<x<<endl;
		delay(100);
	}
	
}

int main(void){
	// SPI setup
	wiringPiSetup();
	mcp3004Setup (MY_PIN, SPI_CHAN);
	// threads
	std::thread chan0(ADCtest,0);
	std::thread chan1(ADCtest,1);
	std::thread chan2(ADCtest,2);
	std::thread chan3(ADCtest,3);
	std::thread chan4(ADCtest,4);
	std::thread chan5(ADCtest,5);

	chan0.join();
	chan1.join();
	chan2.join();
	chan3.join();
	chan4.join();
	chan5.join();
	return 0;
}


