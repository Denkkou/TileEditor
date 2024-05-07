#pragma once

#include "Pane.h"

class TilePalettePane : public Pane
{
private:
	std::vector<Tool*> tileTools;
public:
	TilePalettePane(int x, int y, int w, int h, Tool* currTool);
	~TilePalettePane();

	void Input(int mPosX, int mPosY, bool clicked);
	void Update();
	void Render(SDL_Renderer* renderer);
};