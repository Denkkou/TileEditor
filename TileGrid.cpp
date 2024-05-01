#include "TileGrid.h"

TileGrid::TileGrid()
{
	SDL_Log("Tile Grid Constructed.");
}

void TileGrid::SetTool(int tool)
{
	currentTool = tool;
	SDL_Log("Current tool set to: %s", GetToolFromEnum(tool).c_str());
}

std::string TileGrid::GetToolFromEnum(int tool)
{
	// Match with DrawingTools enum, bit of a lazy workaround
	switch (tool) {
	case tool_enum::raiseHeight:		return std::string("Raise Terrain Height");				break;
	case tool_enum::lowerHeight:		return std::string("Lower Terrain Height");				break;
	case tool_enum::resetHeight:		return std::string("Reset Terrain Height");				break;
	case tool_enum::addCollisionFlag:	return std::string("Add Collision Flag");				break;
	case tool_enum::rmvCollisionFlag:	return std::string("Remove Collision Flag");			break;
	case tool_enum::setEmpty:			return std::string("Set tile to Empty type");			break;
	case tool_enum::setSoil:			return std::string("Set tile to Soil type");			break;
	case tool_enum::setGrass:			return std::string("Set tile to Grass type");			break;
	case tool_enum::setStone:			return std::string("Set tile to Stone type");			break;
	case tool_enum::setPath:			return std::string("Set tile to Path type");			break;
	default:
		return std::string("Unknown Tool");
	}
}

void TileGrid::SetMousePosition(int x, int y)
{
	mPosX = x;
	mPosY = y;
}

void TileGrid::Init()
{
	// Fill grid with tile objects
	for (int i = 0; i < GRIDXSIZE; i++) {
		for (int j = 0; j < GRIDYSIZE; j++) {
			Tile t(i, j, 0, false, terrain_type::empty);		// X, Y, Height, Collision flag, Terrain Type
			grid[i][j] = t;
		}
	}
}

void TileGrid::Update(bool isClicked, int margin, int regionSize)
{
	if (isClicked) {
		// Ensure mouse click is within confines of editor area
		// 10,10 to 650, 650
		if (mPosX >= margin && mPosY >= margin && mPosX <= regionSize + margin && mPosY <= regionSize + margin) {
			SDL_Log("Clicked within grid. X: %i Y: %i", mPosX, mPosY);

			// Work out which tile square clicked and express as coordinates for use in grid[][]
			int gridX = ((mPosX + margin) / 20) - 1;
			int gridY = ((mPosY + margin) / 20) - 1;

			SDL_Log("Cell clicked (%i, %i)", gridX, gridY);

			// Depending on tool currently selected, implement that effect on the clicked tile
			switch (currentTool) {
			case tool_enum::raiseHeight:		grid[gridX][gridY].height += 1;					break;
			case tool_enum::lowerHeight:		grid[gridX][gridY].height -= 1;					break;
			case tool_enum::resetHeight:		grid[gridX][gridY].height = 0;					break;
			case tool_enum::addCollisionFlag:	grid[gridX][gridY].collision = true;			break;
			case tool_enum::rmvCollisionFlag:	grid[gridX][gridY].collision = false;			break;
			case tool_enum::setEmpty:			grid[gridX][gridY].type = terrain_type::empty;	break;
			case tool_enum::setSoil:			grid[gridX][gridY].type = terrain_type::soil;	break;
			case tool_enum::setGrass:			grid[gridX][gridY].type = terrain_type::grass;	break;
			case tool_enum::setStone:			grid[gridX][gridY].type = terrain_type::stone;	break;
			case tool_enum::setPath:			grid[gridX][gridY].type = terrain_type::path;	break;
			}
		}
	}
}

void TileGrid::Render(SDL_Renderer* aRenderer, int margin, int regionSize)
{
	// Draw the grid (Iterates one more time to cap the ends)
	for (int i = 0; i <= GRIDXSIZE; i++) {
		for (int j = 0; j <= GRIDYSIZE; j++) {
			// Width and Height of each cell by increments of i and j
			int w = (i * (regionSize / GRIDXSIZE));
			int h = (j * (regionSize / GRIDYSIZE));

			// Prevent drawing extra row / column due to extra iteration
			if (i != GRIDXSIZE && j != GRIDYSIZE) {

				// Set up switch for tile's type (and therefore colour to display)
				int tileType = grid[i][j].type;
				SDL_Rect rect = { w + margin, h + margin, regionSize / GRIDXSIZE, regionSize / GRIDYSIZE };

				switch (tileType) {
				case terrain_type::empty:
					SDL_SetRenderDrawColor(aRenderer, 0, 0, 0, 255);		// Black
					SDL_RenderFillRect(aRenderer, &rect);
					break;
				case terrain_type::soil:
					SDL_SetRenderDrawColor(aRenderer, 100, 80, 40, 255);	// Brown
					SDL_RenderFillRect(aRenderer, &rect);
					break;
				case terrain_type::grass:
					SDL_SetRenderDrawColor(aRenderer, 80, 150, 70, 255);	// Green
					SDL_RenderFillRect(aRenderer, &rect);
					break;
				case terrain_type::stone:
					SDL_SetRenderDrawColor(aRenderer, 150, 150, 150, 255);	// Light Grey
					SDL_RenderFillRect(aRenderer, &rect);
					break;
				case terrain_type::path:
					SDL_SetRenderDrawColor(aRenderer, 190, 180, 90, 255);	// Yellowy-Brown
					SDL_RenderFillRect(aRenderer, &rect);
					break;
				}

				// Visual indicators for other attributes
				// Red border? for collision
				// Number drawn for height value
			}

			// Grid depends on screen dimensions being a multiple of GRIDSIZE
			SDL_SetRenderDrawColor(aRenderer, 255, 255, 255, 255);
			SDL_RenderDrawLine(aRenderer, w + margin, margin, w + margin, regionSize + margin);
			SDL_RenderDrawLine(aRenderer, margin, h + margin, regionSize + margin, h + margin);
		}
	}
}

