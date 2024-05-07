#pragma once

#include <SDL.h>

class Timer
{
private:
	int startTicks;
public:
	Timer() { startTicks = 0; };

	void ResetTicks() { startTicks = SDL_GetTicks(); };
	int GetTicks() { return (SDL_GetTicks() - startTicks); };
};