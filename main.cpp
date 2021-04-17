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

static volatile bool keep_going = true;

 
void userInput() {

	while(keep_going) { 
		if (std::cin.get() == 'c') {

		keep_going = false;
		} 
	} 
} 





void play(int DS, int threshold, char tone) { 

	char a[100];
	char b[100];	
	char c[100];
	char d[100];
	char e[100];
	char x[100];
	char g[100];

// Sound will play for 1 second and thread will terminate

	strcpy(a,"aplay -d 1 A.wav"); 	
	strcpy(b,"aplay -d 1 B.wav");  	
	strcpy(c,"aplay -d 1 C.wav");  
	strcpy(d,"aplay -d 1 D.wav");  
	strcpy(e,"aplay -d 1 E.wav");  
	strcpy(x,"aplay -d 1 Ehi.wav");  
	strcpy(g,"aplay -d 1 G.wav");  

	if (DS < threshold)
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
		else if (tone=='x'){ 
		system(x); 
		} 
		else if (tone=='g'){ 
		system(g);	
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
th1 = 900;
th2 = 900;
th3 = 900;
th4 = 900;
th5 = 900;


// SPI setup
  	wiringPiSetup() ;
  	mcp3004Setup (MY_PIN, SPI_CHAN); // 3004 and 3008 are the same 4/8 channels


// define chords
Chord free;
free.E = 'e';
free.B = 'b';
free.G = 'g';
free.D = 'd';
free.A = 'a'; 
free.e = 'x';  // should be different tone, this is just for testing

Chord A;
 A.E = 'f';
A.B = 'a';
A.G = 'd';
A.D = 'g';
A.A ='b' ;
A.e = 'e';

// define the object for the current chord
Chord current;

while(1) { 
// User input for picking a chord
std::cout<<"Pick a chord (none - 1, A - 2): "<<std::endl;
std::cin>> chord;


if (chord == 1) { 

 current.E = free.E ;
current.B = free.B;
current.G = free.G;
current.D = free.D;
current.A = free.A; 
current.e = free.e;
} 

else if (chord == 2) { 
 
current.E = A.E ;
current.B = A.B;
current.G = A.G;
current.D = A.D;
current.A = A.A;
current.e = A.e;
} 


std::thread changeChord(userInput); 

while (keep_going)
{

// Read the digitalvalue from the ADC channels
	x0 = analogRead (MY_PIN);	
	x1 = analogRead (MY_PIN + 1);	
	x2 = analogRead (MY_PIN + 2);
	x3 = analogRead (MY_PIN + 3);
	x4 = analogRead (MY_PIN + 4);
	x5 = analogRead (MY_PIN + 5);


	// Create a thread representing string 1 (high E string)
std::thread Estring(play,x0,th0,current.E);
	//Create a thread representing string 2 (A string)
std::thread Bstring(play,x1,th1,current.B);
	//Threads for other strings
std::thread Gstring(play,x2,th2,current.G);
std::thread Dstring(play,x3,th3,current.D);
std::thread Astring(play,x4,th4,current.A);
std::thread estring(play,x5,th5,current.e);

// Wait until thread terminates
estring.join();
Astring.join();
Dstring.join();
Gstring.join();
Bstring.join();
Estring.join();

}

changeChord.join(); 
keep_going = 1;







} 



return 0;
}
