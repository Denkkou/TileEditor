#pragma once

#include <SDL.h>
#include <vector>

#include "Tool.h"
#include "TileGridPane.h"
#include "TilePalettePane.h"
#include "UtilityPane.h"
#include "Timer.h"

#define MAX_KEYS int(256)

class Editor 
{
private:
	// Screen dimensions
	const int SCREENXRES = 1000;
	const int SCREENYRES = 660;

	// Timer and loop control
	Timer timer;
	const int DELTA_TIME = 60;
	bool done = false;

	// Keyboard input
	bool gKeys[MAX_KEYS];
	
	// Mouse input
	int mPosX, mPosY;
	bool clicked = false;

	Tool* currentTool = nullptr;
	std::vector<Pane*> panes;

public:
	Editor();
	~Editor();

	// SDL
	SDL_Window* window;
	SDL_Renderer* renderer;

	// Panes (xPos, yPos, width, height, tool ptr)
	TileGridPane tileGridPane{ 0, 0, 10, 10, currentTool };
	TilePalettePane tilePalettePane{ 50, 50, 10, 10, currentTool };
	UtilityPane utilityPane{ 100, 100, 10, 10, currentTool };

	// Member Functions
	void Init();
	void Run();

	void Input();
	void Update();
	void Render();

	void Quit();
};