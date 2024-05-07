#include "Editor.h"

Editor::Editor()
{
}

Editor::~Editor()
{
}

void Editor::Init()
{
	// Create SDL components
	window = SDL_CreateWindow("Tile Editor v0.2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREENXRES, SCREENYRES, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	// Add panes to vector
	panes.push_back(&tileGridPane);
	panes.push_back(&tilePalettePane);
	panes.push_back(&utilityPane);
}

void Editor::Run()
{
	while (!done) {
		timer.ResetTicks();

		Input();
		Update();
		Render();

		// Delay until frame completes
		if (timer.GetTicks() < DELTA_TIME) {
			SDL_Delay(DELTA_TIME - timer.GetTicks());
		}
	}

	Quit();
}

void Editor::Input()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {

		// End main loop if quitting
		if (event.type == SDL_QUIT) {
			done = true;
		}

		// Keyboard input
		// ...

		// Detect mouse click
		switch (event.type) {
		case SDL_MOUSEBUTTONDOWN:
			clicked = true;
			break;
		case SDL_MOUSEBUTTONUP:
			clicked = false;
			break;
		}

		// Get mouse position
		SDL_GetMouseState(&mPosX, &mPosY);

		// Pass position & click state to panes
		for (auto pane : panes) {
			pane->Input(mPosX, mPosY, clicked);
		}	
	}
}

void Editor::Update()
{
	// Pane updates
	for (auto pane : panes) {
		pane->Update();
	}
}

void Editor::Render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	// Pane renders
	for (auto pane : panes) {
		pane->Render(renderer);
	}

	SDL_RenderPresent(renderer);
}

void Editor::Quit()
{
	SDL_Log("Quitting application.");
}