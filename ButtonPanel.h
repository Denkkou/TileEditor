#ifndef aButtonPanelFILE
#define aButtonPanelFILE

#include <SDL.h>
#include "Clickable.h"
#include "Button.h"
#include <vector>

#define PANELXSIZE int(340)
#define PANELYSIZE int(660)

// Container class for all of the GUI buttons to change tools etc
class ButtonPanel : public Clickable
{
private:
	// Array of each button
	std::vector<Button> buttonArray;
public:
	ButtonPanel();

	void Init();
	int Update(bool isClicked);
	void Render(SDL_Renderer* aRenderer);
};

#endif