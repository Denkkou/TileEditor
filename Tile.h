#ifndef aTileFILE
#define aTileFILE

#include "MY_ENUMS.h"

class Tile
{
public:
	Tile();
	Tile(int x, int y, int h, bool col, int t, bool warp);

	int tileCoord[2];
	int height;
	bool collision; // To be changed to edge collision rather than whole-tile
	int type;
	bool canWarpCorners;	// Allow corner moving

	// Coordinates for each corner
	int topLeft[3];
	int topRight[3];
	int botLeft[3];
	int botRight[3];
};

#endif