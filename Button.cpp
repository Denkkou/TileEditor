#include "Button.h"

Button::Button()
{

}

Button::Button(int x, int y, int w, int h, int tool)
{
    topColour = 100;
    shadowColour = 50;

    xPos = x;
    yPos = y;
    width = w;
    height = h;
    assignedTool = tool;
}


// Return the ID of this button if it was clicked
int Button::checkIfClicked(int mPosX, int mPosY)
{
    // Check if mouse coords are within region
    if (mPosX >= xPos && mPosY >= yPos && mPosX < xPos+width && mPosY < yPos+height) {
        return assignedTool;
    }
    else {
        return -1;
    }
}


void Button::Render(SDL_Renderer* aRenderer)
{
    if (isToggled) {
        // Use Toggle-On sprite here
        shadowColour = 100;
        topColour = 50;
    }
    else {
        // Use Toggle-Off sprite here
        shadowColour = 50;
        topColour = 100;
    }

    SDL_Rect shadowRect = { xPos, yPos, width + 3, height + 3 };
    SDL_SetRenderDrawColor(aRenderer, shadowColour, shadowColour, shadowColour, 255);
    SDL_RenderFillRect(aRenderer, &shadowRect);

    SDL_Rect rect = { xPos, yPos, width, height };
    SDL_SetRenderDrawColor(aRenderer, topColour, topColour, topColour, 255);
    SDL_RenderFillRect(aRenderer, &rect);
}
