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
	buttonPanel.Init();

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

			// Set to true when key is pressed
			switch (event.key.keysym.sym) {
			case SDLK_ESCAPE: 
				done = true; 
				break;
			case SDLK_1:
				gKeys[SDLK_1] = true; 
				tileGrid.SetTool(tool_enum::raiseHeight); 
				break;
			case SDLK_2: 
				gKeys[SDLK_2] = true; 
				tileGrid.SetTool(tool_enum::lowerHeight); 
				break;
			case SDLK_3: 
				gKeys[SDLK_3] = true; 
				tileGrid.SetTool(tool_enum::resetHeight); 
				break;
			case SDLK_4: 
				gKeys[SDLK_4] = true; 
				tileGrid.SetTool(tool_enum::addCollisionFlag); 
				break;
			case SDLK_5: 
				gKeys[SDLK_5] = true; 
				tileGrid.SetTool(tool_enum::rmvCollisionFlag); 
				break;
			case SDLK_a: 
				gKeys[SDLK_a] = true; 
				tileGrid.SetTool(tool_enum::addWarpFlag); 
				break;
			case SDLK_s: 
				gKeys[SDLK_s] = true; 
				tileGrid.SetTool(tool_enum::rmvWarpFlag); 
				break;
			case SDLK_q: 
				gKeys[SDLK_q] = true; 
				tileGrid.SetTool(tool_enum::setEmpty); 
				break;
			case SDLK_w: 
				gKeys[SDLK_w] = true; 
				tileGrid.SetTool(tool_enum::setSoil); 
				break;
			case SDLK_e: 
				gKeys[SDLK_e] = true; 
				tileGrid.SetTool(tool_enum::setGrass); 
				break;
			case SDLK_r: 
				gKeys[SDLK_r] = true; 
				tileGrid.SetTool(tool_enum::setStone); 
				break;
			case SDLK_t: 
				gKeys[SDLK_t] = true; 
				tileGrid.SetTool(tool_enum::setPath); 
				break;
			}
		}

		// Set to false when key is released
		if (event.type == SDL_KEYUP) {
			//SDL_Log("[KEY UP]time %d; code %d; char %s;", event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));

			switch (event.key.keysym.sym) {
			case SDLK_1:
				gKeys[SDLK_1] = false; 
				break;
			case SDLK_2:
				gKeys[SDLK_2] = false; 
				break;
			case SDLK_3:
				gKeys[SDLK_3] = false; 
				break;
			case SDLK_4:
				gKeys[SDLK_4] = false; 
				break;
			case SDLK_5:
				gKeys[SDLK_5] = false; 
				break;
			case SDLK_q:
				gKeys[SDLK_q] = false; 
				break;
			case SDLK_w:
				gKeys[SDLK_w] = false; 
				break;
			case SDLK_e:
				gKeys[SDLK_e] = false; 
				break;
			case SDLK_r:
				gKeys[SDLK_r] = false; 
				break;
			case SDLK_t:
				gKeys[SDLK_t] = false; 
				break;
			case SDLK_a:
				gKeys[SDLK_a] = false; 
				break;
			case SDLK_s:
				gKeys[SDLK_s] = false; 
				break;
			}
		}

		// Mouse input
		if (SDL_GetMouseState(&mPosX, &mPosY)) {
			tileGrid.SetMousePosition(mPosX, mPosY);
			buttonPanel.SetMousePosition(mPosX, mPosY);
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

	// If a button is clicked, receive the tool to use here, set it in tileGrid
	int toolToSet = buttonPanel.Update(isClicked);
	if (toolToSet != -1) {
		tileGrid.SetTool(toolToSet);
	}
}

void EditorSpace::Render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	// Container render functions
	tileGrid.Render(renderer, MARGIN, REGIONSIZE);
	buttonPanel.Render(renderer);

	SDL_RenderPresent(renderer);
}

void EditorSpace::Quit()
{
	SDL_Log("Quitting application.");
}
