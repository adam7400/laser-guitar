#include  "wiringPi.h"
#include "stdio.h"
#include <iostream>
using namespace std;
int LED = 26;			/* GPIO26 as per wiringPi, GPIO12 as per BCM, pin no.32 */
int main(){
	wiringPiSetup();	/* initialize wiringPi setup */
	pinMode(LED,OUTPUT);	/* set GPIO as output */
	
	while (1){
		digitalWrite(LED,HIGH);		/* write high on GPIO */
		cout<<"1"<<endl;
		delay(1000);
		digitalWrite(LED, LOW);		/* write low on GPIO */
		delay(1000);
		}
}
