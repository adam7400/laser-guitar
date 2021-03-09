#ifndef SOUND_THREAD_H
#define SOUND_THREAD_H

#include "CppThread.h"


class SoundThread : public CppThread {


public:
	SoundThread(int _threshold, int _DS) {
		threshold = _threshold;
		DS = _DS;
	}

private:
	void run();


private: 
	int threshold;
	int DS;
};


#endif		
	
