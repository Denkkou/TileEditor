#ifndef aClickableFILE
#define aClickableFILE

class Clickable
{
public:
	int mPosX, mPosY;
	void SetMousePosition(int x, int y) { mPosX = x; mPosY = y; };
};

#endif