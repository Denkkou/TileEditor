#ifndef aTileFILE
#define aTileFILE

#include "MY_ENUMS.h"

class Tile
{
public:
	Tile();
	Tile(int x, int y, int h, bool col, int t);
	int tileX;
	int tileY;
	int height;
	bool collision;
	int type;
};

#endif