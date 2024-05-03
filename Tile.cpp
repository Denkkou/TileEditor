#include "Tile.h"

Tile::Tile()
{
	tileCoord[0, 0];
	height = 0;
	collision = false;
	type = terrain_type::empty;
	canWarpCorners = true;

	topLeft[0, 0, 0];
	topRight[1, 0, 0];
	botLeft[0, 1, 0];
	botRight[1, 1, 0];
}

Tile::Tile(int x, int y, int h, bool col, int t, bool warp)
{
	tileCoord[x, y];
	height = h;
	collision = col;
	type = t;
	canWarpCorners = warp;

	// Set corner coordinates relative to top left, default z = height
	topLeft[x, y, h];
	topRight[x += 1, y, h];
	botLeft[x, y += 1, h];
	botRight[x += 1, y += 1, h];
}
