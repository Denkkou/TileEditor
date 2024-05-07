#pragma once

#include <SDL.h>
#include <vector>
#include <string>

#include "Tool.h"

class Pane
{
private:

public:
	Pane() {};
	~Pane() {};

	// Reference to current tool
	Tool* currentTool = nullptr;

	SDL_Colour defaultDrawColour = { 150, 150, 150, 255 };

	// Screenspace values
	int originX = 0;
	int originY = 0;
	int paneWidth = 0;
	int paneHeight = 0;

	// Mouse position & click
	int mPosX = 0;
	int mPosY = 0;
	bool clicked = false;

	void Input(int mX, int mY, bool clk) { mPosX = mX; mPosY = mY; clicked = clk; };

	virtual void Update() = 0;
	virtual void Render(SDL_Renderer* renderer) = 0;
};