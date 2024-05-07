#pragma once

#include "Pane.h"

class UtilityPane : public Pane
{
private:
public:
	UtilityPane(int x, int y, int w, int h, Tool* currTool);
	~UtilityPane();

	void Input(int mPosX, int mPosY, bool clicked);
	void Update();
	void Render(SDL_Renderer* renderer);
};