#include "TilePalettePane.h"

TilePalettePane::TilePalettePane(int x, int y, int w, int h, Tool* currTool)
{
	originX = x;
	originY = y;
	paneWidth = w;
	paneHeight = h;
	currentTool = currTool;
}

TilePalettePane::~TilePalettePane()
{
}

void TilePalettePane::Update()
{
	if (clicked) {
		// Calculate which palette button clicked
		// ...

		// Set currentTool to the object data relevant to each button
		// ...
	}
}

void TilePalettePane::Render(SDL_Renderer* renderer)
{
	// Default drawing
	SDL_Rect paneBG = { originX, originY, paneWidth, paneHeight };
	SDL_SetRenderDrawColor(renderer, defaultDrawColour.r, defaultDrawColour.g, defaultDrawColour.b, defaultDrawColour.a);
	SDL_RenderFillRect(renderer, &paneBG);
}
