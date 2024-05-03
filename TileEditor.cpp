#include <iostream>
#include <string>
#include <SDL.h>

#include "EditorSpace.h"

EditorSpace editorSpace;

int main(int argc, char* argv[])
{
    // Initialise SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return 1;
    else
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_Init failed!");

    // Start editor space
    editorSpace.Init();
    editorSpace.Run();

    SDL_Quit();
    return 0;
}