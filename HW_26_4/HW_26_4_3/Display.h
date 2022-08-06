#pragma once
//#include <vector>
#include "Window.h"

class Display
{
public:
	static const int mDisplayWidth = 80;
	static const int mDisplayHeight = 50;

	Display();

	void showDisplay(Window& object);
private:	
	//std::vector<std::vector<int>> mDisplayMatrix;
};

