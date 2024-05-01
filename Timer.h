#ifndef aTimerFILE
#define aTimerFILE

#include <SDL.h>

class Timer
{
private:
	int startTicks;
public:
	Timer();

	void ResetTicks();
	int GetTicks();
};

#endif
