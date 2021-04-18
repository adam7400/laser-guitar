#include <wiringPi.h>
#include <mcp3004.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
//#include <cstdlib>
#include <string.h>
//using namespace std;

// SPI/ADC setup
#define SPI_CHAN 0
#define MY_PIN 100

// Keyboard interrupt 
static volatile bool keep_going = true;
void userInput() {

	while(keep_going) { 
		if (std::cin.get() == 'c') {
		keep_going = false;
		} 
	} 
} 

// function that reads ADC and plays sound
void string(int pin, int threshold, char tone){
	int x; 				// store value from ADC in x
	int playing = 0; 	// is the string currently playing?

	char c[100];
	char E[100];
	char b[100];
	char g[100];
	char d[100];
	char a[100];
	char e[100];
	// Sound will play for 1 second and thread will terminate
	strcpy(E,"aplay -d 1 Ehi.wav");  
	strcpy(b,"aplay -d 1 B.wav");  	  
	strcpy(g,"aplay -d 1 G.wav");  
	strcpy(d,"aplay -d 1 D.wav");  
	strcpy(a,"aplay -d 1 A.wav"); 
	strcpy(e,"aplay -d 1 E.wav");  
	
	while(1){
		x = analogRead (MY_PIN+pin);
		if (x < threshold && playing==0){
			playing = 1;
			if (tone=='a'){ 
				system(a);
			}
			else if (tone=='b'){ 
				system(b);
			}
			else if (tone=='c'){ 
				system(c);
			}
			else if (tone=='d'){ 
				system(d);
			} 
			else if (tone=='e'){
				system(e);
			}
			else if (tone=='E'){ 
				system(E); 
			} 
			else if (tone=='g'){ 
				system(g);	
			} 
		}
		if (x > threshold && playing==1){
			playing = 0;
			// code to stop sound playback
		}
	}
}

class Chord{
public:

char E;
char b;
char g;
char d;
char a;
char e; 

}; 

int main(void){
	// Threshold value based on the resistor used
	int th = 800;
	// ADC setup
	wiringPiSetup();
	mcp3004Setup (MY_PIN, SPI_CHAN);
	// chord selection
	int chord;
	// define chords
	Chord free;
	free.E = 'E';
	free.b = 'b';
	free.g = 'g';
	free.d = 'd';
	free.a = 'a'; 
	free.e = 'e';
	// define the current chord
	Chord current;
	// main loop begins with user input to select chord
	while(1){
		std::cout<<"Enter the number to pick a chord: "<<std::endl;
		std::cout<<"1    Open strings"<<std::endl;
		std::cin>> chord;
		std::cout<<"Type 'c' and press ENTER to return to the chord selection menu"<<std::endl;
		if (chord == 1){ 
			current.E = free.E;
			current.b = free.b;
			current.g = free.g;
			current.d = free.d;
			current.a = free.a; 
			current.e = free.e;
		}
		// keyboard interrupt thread
		std::thread changeChord(userInput);
		while (keep_going){
			// threads
			std::thread string0(string,0,th,current.e);
			std::thread string1(string,1,th,current.a);
			std::thread string2(string,2,th,current.d);
			std::thread string3(string,3,th,current.g);
			std::thread string4(string,4,th,current.b);
			std::thread string5(string,5,th,current.E);

			string0.join();
			string1.join();
			string2.join();
			string3.join();
			string4.join();
			string5.join();
		}
		changeChord.join(); 
		keep_going = true;  
	}
	return 0;
}


