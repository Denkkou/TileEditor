#include "TileGridPane.h"

TileGridPane::TileGridPane(int x, int y, int w, int h, Tool* currTool)
{
	originX = x;
	originY = y;
	paneWidth = w;
	paneHeight = h;
	currentTool = currTool;
}

TileGridPane::~TileGridPane()
{
}

void TileGridPane::Update()
{
	if (clicked) {
		// Calculate which tile clicked in etc
		// ...

		// Catch empty tool
		if (currentTool == nullptr) {
			SDL_Log("No tool currently selected!");
			return;
		}

		// If currentTool.name == abc, apply abc to clicked tile, then return (prevent cascading down each if)
		// ...
	}
}

void TileGridPane::Render(SDL_Renderer* renderer)
{
	// Default drawing
	SDL_Rect paneBG = { originX, originY, paneWidth, paneHeight };
	SDL_SetRenderDrawColor(renderer, defaultDrawColour.r, defaultDrawColour.g, defaultDrawColour.b, defaultDrawColour.a);
	SDL_RenderFillRect(renderer, &paneBG);
}
