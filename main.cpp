#include <iostream>
#include <thread>
#include <chrono>
#include <wiringPi.h>
#include <mcp3004.h>
#include <cstdlib>
#include <string.h>




// SPI definitions
#define SPI_CHAN 0
#define MY_PIN 12345



void play(int DS, int threshold, char tone) { 

	char a[100];
	char b[100];
	strcpy(a,"aplay -d 1 samples_a.wav"); // Sound will play for 1 second and thread will terminate	
	strcpy(b,"aplay -d 1 samples_b.wav");  

	if (DS < threshold)
		if (tone == 'a'){
	system(a);}
		else if (tone == 'b'){
	system(b);}

	}
	




int main (int argc, const char* argv[])
{
	int x1;	 		// input from ADC channel 1
	int th1;		// digital signal threshold
	char tone;		// tone to be played
	
// Threshold value based on the resistor used
th1 = 900;


// SPI setup
  	wiringPiSetup() ;
  	mcp3004Setup (MY_PIN, SPI_CHAN); // 3004 and 3008 are the same 4/8 channels

std::cout<<"Type in the tone to be played (OPTIONS: a,b): "<< std::endl;
std::cin >> tone;


while (1)
{

// Read the digitalvalue from the ADC pin
	x1 = analogRead (MY_PIN);
	


// Create a thread representing string 1
std::thread string1(play,x1,th1,tone);

// Wait until thread terminates
string1.join();


}













return 0;
}
