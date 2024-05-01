#include "EditorSpace.h"

EditorSpace::EditorSpace()
{
	SDL_Log("EditorSpace constructed.");
}

void EditorSpace::Init()
{
	window = SDL_CreateWindow("Tile Editor v0.1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREENXRES, SCREENYRES, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	// Initialise TileGrid
	tileGrid.Init();

	SDL_Log("EditorSpace initialised.");
}

void EditorSpace::Run()
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

void EditorSpace::Input()
{
	while (SDL_PollEvent(&event)) {

		// End main loop if quitting
		if (event.type == SDL_QUIT) {
			done = true;
		}
		
		SDL_Keycode keyPressed = event.key.keysym.sym;

		// Set to true when key is pressed, do associated thing
		if (event.type == SDL_KEYDOWN && !event.key.repeat) {
			//SDL_Log("[KEY DOWN] time %d; code %d; char %s;", event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));

			switch (event.key.keysym.sym) {
			case SDLK_ESCAPE: { done = true; break; }
			case SDLK_1: { gKeys[SDLK_1] = true; tileGrid.SetTool(tool_enum::raiseHeight); break; }			// Raise Height
			case SDLK_2: { gKeys[SDLK_2] = true; tileGrid.SetTool(tool_enum::lowerHeight); break; }			// Lower Height
			case SDLK_3: { gKeys[SDLK_3] = true; tileGrid.SetTool(tool_enum::resetHeight); break; }			// Reset Height
			case SDLK_4: { gKeys[SDLK_4] = true; tileGrid.SetTool(tool_enum::addCollisionFlag); break; }	// Add Collision Flag
			case SDLK_5: { gKeys[SDLK_5] = true; tileGrid.SetTool(tool_enum::rmvCollisionFlag); break; }	// Remove Collision Flag
			case SDLK_q: { gKeys[SDLK_q] = true; tileGrid.SetTool(tool_enum::setEmpty); break; }			// Set tile type to Empty
			case SDLK_w: { gKeys[SDLK_w] = true; tileGrid.SetTool(tool_enum::setSoil); break; }				// Set tile type to Soil
			case SDLK_e: { gKeys[SDLK_e] = true; tileGrid.SetTool(tool_enum::setGrass); break; }			// Set tile type to Grass
			case SDLK_r: { gKeys[SDLK_r] = true; tileGrid.SetTool(tool_enum::setStone); break; }			// Set tile type to Stone
			case SDLK_t: { gKeys[SDLK_t] = true; tileGrid.SetTool(tool_enum::setPath); break; }				// Set tile type to Path
			}
		}

		// Set to false when key is released
		if (event.type == SDL_KEYUP) {
			//SDL_Log("[KEY UP]time %d; code %d; char %s;", event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));

			switch (event.key.keysym.sym) {
			case SDLK_1: { gKeys[SDLK_1] = false; break; }
			case SDLK_2: { gKeys[SDLK_2] = false; break; }
			case SDLK_3: { gKeys[SDLK_3] = false; break; }
			case SDLK_4: { gKeys[SDLK_4] = false; break; }
			case SDLK_5: { gKeys[SDLK_5] = false; break; }
			case SDLK_q: { gKeys[SDLK_q] = false; break; }
			case SDLK_w: { gKeys[SDLK_w] = false; break; }
			case SDLK_e: { gKeys[SDLK_e] = false; break; }
			case SDLK_r: { gKeys[SDLK_r] = false; break; }
			case SDLK_t: { gKeys[SDLK_t] = false; break; }
			}
		}

		// Mouse input
		if (SDL_GetMouseState(&mPosX, &mPosY)) {
			tileGrid.SetMousePosition(mPosX, mPosY);
		}

		switch (event.type) {
		case SDL_MOUSEBUTTONDOWN:
			isClicked = true;
			break;
		case SDL_MOUSEBUTTONUP:
			isClicked = false;
			break;
		}
	}
}

void EditorSpace::Update()
{
	// Done every frame
	tileGrid.Update(isClicked, MARGIN, REGIONSIZE);
}

void EditorSpace::Render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	// Container render functions
	tileGrid.Render(renderer, MARGIN, REGIONSIZE);

	SDL_RenderPresent(renderer);
}

void EditorSpace::Quit()
{
	SDL_Log("Quitting application.");
}