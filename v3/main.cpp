#include <iostream>
#include <thread>
#include <chrono>
#include <wiringPi.h>
#include <mcp3004.h>
//#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



// SPI definitions
#define SPI_CHAN 0
#define MY_PIN 100

static volatile bool keep_going = true;

 
void userInput() {

	while(keep_going) { 
		if (std::cin.get() == 'c') {

		keep_going = false;
		} 
	} 
} 





void play(int pin, int threshold, char tone ) { 


	int y;
	int playing = 0;

	char a[100];
	char b[100];	
	char c[100];
	char d[100];
	char e[100];
	char x[100];
	char g[100];
	char i[100];
	char j[100];
	char k[100];
	char l[100];
	char n[100];
	char o[100];

// Sound will play for 1 second and thread will terminate

	strcpy(a,"aplay -q -d 1 A.wav"); 	
	strcpy(b,"aplay -q -d 1 B.wav");  	
	strcpy(c,"aplay -q -d 1 C.wav");  
	strcpy(d,"aplay -q -d 1 D.wav");  
	strcpy(e,"aplay -q -d 1 E.wav");  
	strcpy(x,"aplay -q -d 1 Ehi.wav");  	
	strcpy(g,"aplay -q -d 1 G.wav");
	strcpy(i,"aplay -q -d 1 C2.wav");
	strcpy(j,"aplay -q -d 1 G2.wav");  
	strcpy(k,"aplay -q -d 1 A#1.wav");  
	strcpy(l,"aplay -q -d 1 F2.wav");  
	strcpy(n,"aplay -q -d 1 C#3hi.wav");  
	strcpy(o,"aplay -q -d 1 C#3.wav");  


	while(keep_going){
	
	y = analogRead(MY_PIN+pin);
	if (y < threshold && playing==0){ 
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
		else if (tone=='x'){ 
		system(x); 
		} 
		else if (tone=='g'){ 
		system(g);	
		}
		
		else if (tone=='i'){ 
		system(i);	
		} 	

 	
		else if (tone=='j'){ 
		system(j);	
		} 	

		else if (tone=='k'){ 
		system(k);	
		} 	

		else if (tone=='l'){ 
		system(l);	
		} 	
		
		else if (tone=='n'){ 
		system(n);	
		} 	
		
		else if (tone=='o'){ 
		system(o);	
		} 	
	}
	if (y>threshold && playing==1){
		playing = 0;
		//code to stop sound playback
		}

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
	




int main (void)
{
	int th;		// digital signal threshold
	int chord;
	
// Threshold value based on the resistor used
th = 900;


// SPI setup
  	wiringPiSetup() ;
  	mcp3004Setup (MY_PIN, SPI_CHAN); // 3004 and 3008 are the same 4/8 channels


// define chords
Chord free;
free.e = 'x';
free.B = 'b';
free.G = 'g';
free.D = 'd';
free.A = 'a'; 
free.E = 'e';  // should be different tone, this is just for testing

Chord Emi;
Emi.e = 'x';
Emi.B = 'b';
Emi.G = 'g';
Emi.D = 'i' ;  //!!!
Emi.A ='j' ;	//!!!
Emi.E = 'e';

Chord Ami;
Ami.e = 'x';
Ami.B = 'k';		//!!!
Ami.G = 'l'; 		//!!!
Ami.D = 'i';		//!!!
Ami.A = 'a';		
Ami.E = 'm';		//!!! muted ,

Chord G; 
G.e = 'n'; 	 	//!!!
G.B = 'b';
G.G = 'g';
G.D = 'd';
G.A = 'j';		//!!!
G.E = 'o'; 	//!!!



// define the object for the current chord
Chord current;

while(1) { 
// User input for picking a chord
std::cout<<"Enter the number to pick a chord: "<<std::endl;
std::cout<<"1    Open strings"<<std::endl;
std::cout<<"2    E minor"<<std::endl;
std::cout<<"3    A minor"<<std::endl;
std::cout<<"4    G"<<std::endl;
std::cin>> chord;
std::cout<<"Type in 'c' and press ENTER to return to the changing chords menu"<<std::endl;

if (chord == 1) { 

current.e = free.e ;
current.B = free.B;
current.G = free.G;
current.D = free.D;
current.A = free.A; 
current.E = free.E;
} 

else if (chord == 2) { 
 
current.e = Emi.e ;
current.B = Emi.B;
current.G = Emi.G;
current.D = Emi.D;
current.A = Emi.A;
current.E = Emi.E;
} 

else if (chord == 3){ 
current = Ami;
}  


else if (chord == 4) { 
current = G;
} 


std::thread changeChord(userInput); 

while (keep_going)
{

//E is low E string
std::thread Estring(play,0,th,current.E);
	//Create a thread representing string 2 (A string)
std::thread Astring(play,1,th,current.A);
	//Threads for other strings
std::thread Dstring(play,2,th,current.D);
std::thread Gstring(play,3,th,current.G);
std::thread Bstring(play,4,th,current.B);
std::thread estring(play,5,th,current.e);
// Wait until thread terminates
estring.join();
Astring.join();
Dstring.join();
Gstring.join();
Bstring.join();
Estring.join();

}

changeChord.join(); 
keep_going = true;







} 



return 0;
}
