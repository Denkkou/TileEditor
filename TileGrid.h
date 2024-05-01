#ifndef aTileGridFILE
#define aTileGridFILE

#include <vector>
#include <string>
#include <iostream>
#include <SDL.h>
#include "MY_ENUMS.h"
#include "Tile.h"

#define GRIDXSIZE int(32)
#define GRIDYSIZE int(32)

// The Tile Grid is the region of the Editor Space that contains the tiles
// that can be clicked and edited. The "tool" mode is selected within the
// Editor Space and passed into here to be set as the current tool.

class TileGrid
{
private:
	int currentTool;
	int mPosX, mPosY;

	// 2D array of tile objects
	Tile grid[GRIDXSIZE][GRIDYSIZE];
public:
	TileGrid();

	void SetTool(int tool);
	std::string GetToolFromEnum(int tool);

	void SetMousePosition(int x, int y);

	void Init();
	void Update(bool isClicked, int margin, int regionSize);
	void Render(SDL_Renderer* aRenderer, int margin, int regionSize);
};


#endif