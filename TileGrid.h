#ifndef aTileGridFILE
#define aTileGridFILE

#include <vector>
#include <string>
#include <iostream>
#include <SDL.h>
#include "MY_ENUMS.h"
#include "Tile.h"
#include "Clickable.h"

#define GRIDXSIZE int(32)
#define GRIDYSIZE int(32)

class TileGrid : public Clickable
{
private:
	int currentTool;

	// 2D array of tile objects
	Tile grid[GRIDXSIZE][GRIDYSIZE];
public:
	TileGrid();

	void SetTool(int tool);
	std::string GetToolFromEnum(int tool);

	void applyToolToTile(int tool, int gridX, int gridY);

	// Unimplemented - Calculate where a tile's corner coordinates should move to
	// in order to have no vertical gaps in elevation. Each corner should be evaluated
	// with the three neighbouring corners of the adjacent tiles and set them to an average
	// of their original height value. Do not do this to tiles with doNotWarp = true.
	// Run this pass every frame.
	void CalcCornerCoords();

	void Init();
	void Update(bool isClicked, int margin, int regionSize);
	void Render(SDL_Renderer* aRenderer, int margin, int regionSize);
};


#endif