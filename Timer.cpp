#include "Timer.h"

Timer::Timer()
{
	startTicks = 0;
}

void Timer::ResetTicks()
{
	startTicks = SDL_GetTicks();
}

int Timer::GetTicks()
{
	return (SDL_GetTicks() - startTicks);
}