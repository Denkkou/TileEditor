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
	const int SCREENXRES = 1600;
	const int SCREENYRES = 900;

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

	/*	Currently, pane sizes and positions are arbitrary for the sake of basic implementation. This is because several panes
	*	have no implemented / required size. Once these sizes are established, the process of designing the UI layout can start.
	*	Note: The tileGridPane will overdraw by 1px and also must be divisible by the grid's desired dimension.
	*/

	// Panes (xPos, yPos, width, height, tool ptr)
	TileGridPane tileGridPane{ 10, 10, 768, 768, currentTool };
	TilePalettePane tilePalettePane{ 1000, 1, 320, 320, currentTool };
	UtilityPane utilityPane{ 1000, 500, 320, 320, currentTool };

	// Member Functions
	void Init();
	void Run();

	void Input();
	void Update();
	void Render();

	void Quit();
};