#include <iostream>
//#include <vector>
#include "Display.h"
#include "Window.h"


Display::Display()
{    
    //mDisplayMatrix.resize(mHeight, std::vector<int>(mWidth, 0));
}

void Display::showDisplay(Window& object)
{
    size_t x = object.getWindowX();
    size_t y = object.getWindowY();
    size_t windowWidth = x + object.getWindowWidth();
    size_t windowHeight = y + object.getWindowHeight();

    std::cout << std::endl;

    for (size_t i = 0; i < mDisplayHeight; i++)
    {
        for (size_t j = 0; j < mDisplayWidth; j++)
        {
            if (i >= y && i < windowHeight &&
                j >= x && j < windowWidth)
            {
                //mDisplayMatrix[i][j] = 1;
                std::cout << 1 << " ";
            }
            else
            {
                std::cout << 0 << " ";
            }
            //std::cout << mDisplayMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}