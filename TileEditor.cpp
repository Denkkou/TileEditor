#include <SDL.h>

#include "Editor.h"

Editor editor;

int main(int argc, char* argv[])
{
    // Initialise SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return 1;
    else
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_Init failed!");

    // Start editor space
    editor.Init();
    editor.Run();

    SDL_Quit();
    return 0;
}