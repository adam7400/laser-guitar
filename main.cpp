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
	int x0,x1,x2,x3,x4,x5;	 		// input from ADC channels 0-5
	int th0,th1,th2,th3,th4,th5;		// digital signal threshold
	int chord;
	
// Threshold value based on the resistor used
th0 = 900;


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


// User input for picking a chord
std::cout<<"Pick a chord (Ami - 1, A - 2): "<<std::endl;
std::cin>> chord;


if (chord == 1) { 

/* current.E = ;
current.B = ;
current.G = ;
current.D = ;
current.A = ; */
current.e = Ami.e;
} 

else if (chord == 2) { 
 
/* current.E = ;
current.B = ;
current.G = ;
current.D = ;
current.A = ; */
current.e = A.e;
} 

while (1)
{

// Read the digitalvalue from the ADC channels
	x0 = analogRead (MY_PIN);	
	/*x1 = analogRead (MY_PIN + 1);	
	x2 = analogRead (MY_PIN + 2);
	x3 = analogRead (MY_PIN + 3);
	x4 = analogRead (MY_PIN + 4);
	x5 = analogRead (MY_PIN + 5);*/


	// Create a thread representing string 1 (high E string)
std::thread estring(play,x0,th0,current.e);
	//Create a thread representing string 2 (A string)
//std::thread Astring(play,x1,th1,current.A);
	//Threads for other strings
//std::thread Dstring(play,x2,th2,current.D);
//std::thread Gstring(play,x3,th3,current.G);
//std::thread Bstring(play,x4,th4,current.B);
//std::thread Estring(play,x5,th5,current.E);

// Wait until thread terminates
estring.join();
//Astring.join();
//Dstring.join();
//Gstring.join();
//Bstring.join();
//Estring.join();

}













return 0;
}
