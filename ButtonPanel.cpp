#include "ButtonPanel.h"

ButtonPanel::ButtonPanel()
{
	// Construct each button, give location, size, tool assignment, and add to array
	Button addCol(680, 30, 140, 25, tool_enum::addCollisionFlag);
	buttonArray.push_back(addCol);

	Button rmvCol(830, 30, 140, 25, tool_enum::rmvCollisionFlag);
	buttonArray.push_back(rmvCol);

	Button addWarp(680, 65, 140, 25, tool_enum::addWarpFlag);
	buttonArray.push_back(addWarp);

	Button rmvWarp(830, 65, 140, 25, tool_enum::rmvWarpFlag);
	buttonArray.push_back(rmvWarp);

	// Gap of 20 between blocks

	Button rasHeight(800, 110, 50, 50, tool_enum::raiseHeight);
	buttonArray.push_back(rasHeight);

	Button rstHeight(700, 165, 250, 35, tool_enum::resetHeight);
	buttonArray.push_back(rstHeight);

	Button lowHeight(800, 205, 50, 50, tool_enum::lowerHeight);
	buttonArray.push_back(lowHeight);

}

void ButtonPanel::Init()
{

}

// If a button is clicked, this Update() returns the tool to be used
int ButtonPanel::Update(bool isClicked) 
{
	if (isClicked) {
		int toolOfClicked = -1;

		// Iterate array of buttons, pass mouse coordinates
		for (int i = 0; i < buttonArray.size(); i++) {

			// If button detects being clicked, it'll return its tool value
			toolOfClicked = buttonArray[i].checkIfClicked(mPosX, mPosY);

			// If that tool value is valid (aka, a button was clicked at all)
			if (toolOfClicked != -1) {

				// Toggle off all buttons
				for (int j = 0; j < buttonArray.size(); j++) {
					buttonArray[j].isToggled = false;
				}

				// Toggle on the clicked button
				buttonArray[i].isToggled = true;

				// Return the tool to use
				return toolOfClicked;
			}
		}
	}

	return -1;
}

void ButtonPanel::Render(SDL_Renderer* aRenderer)
{
	// Magic numbers are just to add a margin to the panel
	SDL_Rect panelBG = { 660 , 0 + 9, PANELXSIZE - 10, PANELYSIZE - 18};
	SDL_SetRenderDrawColor(aRenderer, 150, 150, 150, 255);
	SDL_RenderFillRect(aRenderer, &panelBG);

	// Render each button
	for (Button b : buttonArray)
	{
		b.Render(aRenderer);
	}
}
