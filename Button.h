#ifndef aButtonFILE
#define aButtonFILE

#include "MY_ENUMS.h"
#include <SDL.h>

class Button
{
private:

	int assignedTool;
	int xPos;
	int yPos;
	int width;
	int height;
public:
	Button();
	Button(int x, int y, int w, int h, int tool);

	// Only in leu of sprites
	int topColour = 100;
	int shadowColour = 50;

	bool isToggled = false;

	int checkIfClicked(int mPosX, int mPosY);

	void Render(SDL_Renderer* aRenderer);
};

#endif