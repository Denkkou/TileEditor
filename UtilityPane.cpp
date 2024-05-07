#include "UtilityPane.h"

UtilityPane::UtilityPane(int x, int y, int w, int h, Tool* currTool)
{
	originX = x;
	originY = y;
	paneWidth = w;
	paneHeight = h;
	currentTool = currTool;
}

UtilityPane::~UtilityPane()
{
}

void UtilityPane::Update()
{
	if (MouseWithinPaneBounds() && clicked) {
		SDL_Log("Click occured within UtilityPane");

		// Calculate which button clicked in etc
		// ...

		// Set currentTool to the object data relevant to each button
		// ...
	}
}

void UtilityPane::Render(SDL_Renderer* renderer)
{
	// Default drawing
	SDL_Rect paneBG = { originX, originY, paneWidth, paneHeight };
	SDL_SetRenderDrawColor(renderer, defaultDrawColour.r, defaultDrawColour.g, defaultDrawColour.b, defaultDrawColour.a);
	SDL_RenderFillRect(renderer, &paneBG);
}
