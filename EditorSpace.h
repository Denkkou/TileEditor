#ifndef anEditorSpaceFILE
#define anEditorSpaceFILE

#include <iostream>
#include <SDL.h>
#include "Timer.h"
#include "TileGrid.h"
#include "MY_ENUMS.h"

#define MAX_KEYS int(256)

class EditorSpace
{
private:
	// Screen dimensions
	const int SCREENXRES = 1000;
	const int SCREENYRES = 660;

	// Tile grid region size and margin from screen edge
	const int MARGIN = 10;
	const int REGIONSIZE = 640;

	// Timer and loop control
	Timer timer;
	const int DELTA_TIME = 60;
	bool done = false;

	// Array of keys
	bool gKeys[MAX_KEYS];

	// Mouse input
	int mPosX, mPosY;
	bool isClicked;

public:
	EditorSpace();

	// SDL
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;

	// Tile Grid
	TileGrid tileGrid;

	void Init();
	void Run();

	void Input();
	void Update();
	void Render();

	void Quit();
};

#endif