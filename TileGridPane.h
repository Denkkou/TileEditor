#pragma once

#include "Pane.h"

class TileGridPane : public Pane
{
private:
	int gridDimension = 32;	// Default 32
public:
	TileGridPane(int x, int y, int w, int h, Tool* currTool);
	~TileGridPane();

	void Input(int mPosX, int mPosY, bool clicked);
	void Update();
	void Render(SDL_Renderer* renderer);
};