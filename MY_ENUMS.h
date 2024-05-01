#ifndef MY_ENUMS
#define MY_ENUMS

namespace tool_enum
{
	enum DrawTools {
		raiseHeight,
		lowerHeight,
		resetHeight,

		addCollisionFlag,
		rmvCollisionFlag,

		setEmpty,
		setSoil,
		setGrass,
		setStone,
		setPath
		// needs inputs assigning and also TileGrid::GetToolFromEnum() cases
	};
}

namespace terrain_type
{
	enum TerrainType {
		empty,
		soil,
		grass,
		stone,
		path
	};
}

#endif