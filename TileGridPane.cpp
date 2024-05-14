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
	if (MouseWithinPaneBounds() && clicked) {
		SDL_Log("Click occured within TileGridPane");

		// Catch empty tool
		if (currentTool == nullptr) {
			//SDL_Log("No tool currently selected!");
			return;
		}

		// Calculate which tile clicked in etc
		// ...

		// If currentTool.name == abc, apply abc to clicked tile, then return (prevent cascading down each if)
		// ...
	}
}

void TileGridPane::Render(SDL_Renderer* renderer)
{
	// Default drawing
	SDL_Rect paneBG = { originX, originY, paneWidth, paneHeight };
	SDL_SetRenderDrawColor(renderer, 64, 64, 64, defaultDrawColour.a);
	SDL_RenderFillRect(renderer, &paneBG);

	// Draw the grid based on width and height of pane divided by grid dimension
	// start at origin x y and draw from there.
	int cellW = paneWidth / gridDimension;
	int cellH = paneHeight / gridDimension;

	for (int i = 0; i <= gridDimension; i++) {
		for (int j = 0; j <= gridDimension; j++) {

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderDrawLine(renderer, originX + (cellW * i), originY, originX + (cellW * i), originX + paneHeight);	// Columns
			SDL_RenderDrawLine(renderer, originX, originY + (cellH * j), originY + paneWidth, originY + (cellH * j)); // Rows
		}
	}


}
