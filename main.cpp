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
		if (tone=='a'){ 
		system(a);
		}
		else if (tone=='b'){ 
		system(b);
		}
	}

class Chord{
public:

char E;
char B;
char G;
char D;
char A;
char e; 

}; 
	




int main (int argc, const char* argv[])
{
	int x1;	 		// input from ADC channel 1
	int th1;		// digital signal threshold
	int chord;
	
// Threshold value based on the resistor used
th1 = 900;


// SPI setup
  	wiringPiSetup() ;
  	mcp3004Setup (MY_PIN, SPI_CHAN); // 3004 and 3008 are the same 4/8 channels


// define chords
Chord Ami;
/* Ami.E = ;
Ami.B = ;
Ami.G = ;
Ami.D = ;
Ami.A = ; */
Ami.e = 'a';  // should be different tone, this is just for testing

Chord A;
/* A.E = ;
A.B = ;
A.G = ;
A.D = ;
A.A = ; */
A.e = 'b';

// define the object for the current chord
Chord current;



std::cout<<"Pick a chord (Ami - 1, A - 2): "<<std::endl;
std::cin>> chord;


if (chord == 1) { 
current = Ami;
} 

else if (chord == 2) { 
current = A;
} 


while (1)
{

// Read the digitalvalue from the ADC pin
	x1 = analogRead (MY_PIN);
	


	// Create a thread representing string 1 (high E string)
std::thread estring(play,x1,th1,current.e);
	//Create a thread representing string 2 (A string)
//std::thread Astring(play,x2,th2,current.A);


// Wait until thread terminates
estring.join();
//Astring.join();


}













return 0;
}
