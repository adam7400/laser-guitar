#ifndef SOUND_THREAD_H
#define SOUND_THREAD_H

#include "CppThread.h"


class SoundThread : public CppThread {


public:
	SoundThread(int _threshold, int _DS, int _tone) {
		threshold = _threshold;
		DS = _DS;
		tone = _tone;
	}

private:
	void run();


private: 
	int threshold;
	int DS;
	int tone;
};


#endif		
	
