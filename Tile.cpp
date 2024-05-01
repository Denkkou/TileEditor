#include "Tile.h"

Tile::Tile()
{
}

Tile::Tile(int x, int y, int h, bool col, int t)
{
	height = h;
	collision = col;
	type = t;
}
