#pragma once

#include <SDL.h>

#include "Tool.h"

class Button
{
private:
	Tool* assignedTool = nullptr;

	int xPos;
	int yPos;
	int width;
	int height;
public:
	Button();
	Button(int x, int y, int w, int h, Tool* toolToAssign);
	~Button();

	// Get pointer to assigned tool
	Tool* OnClick();

	void Render(SDL_Renderer* renderer);
};