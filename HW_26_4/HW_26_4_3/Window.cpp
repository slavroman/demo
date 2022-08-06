#include <iostream>
#include "Window.h"
#include "Display.h"

Window::Window()
	:mWindowX(0), mWindowY(0), mWindowHeight(0), mWindowWidth(0)
{
}

void Window::setWinsowSize()
{
	int width = 0;
	int height = 0;

	std::cout << "\nPlease input new window width and height:\n";
	std::cin >> width >> height;

	//width += getWindowX();
	//height += getWindowY();

	while (width < Display::mDisplayWidth && width > Display::mDisplayWidth &&
		   height < Display::mDisplayHeight && height > Display::mDisplayHeight)
	{
		std::cout << "\nThe window size cannot exceed the display size!\n";
		std::cout << "Please try again:\n";
		std::cin >> width >> height;
	}

	mWindowWidth = width;
	mWindowHeight = height;

	showWindowInfo();
}

int Window::getWindowX()
{
	return mWindowX;
}

int Window::getWindowY()
{
	return mWindowY;
}

int Window::getWindowHeight()
{
	return mWindowHeight;
}

int Window::getWindowWidth()
{
	return mWindowWidth;
}

void Window::moveWindow()
{
	int x = 0;
	int y = 0;

	std::cout << "\nPlease input new window x and y position:\n";
	std::cin >> x >> y;

	while (x < Display::mDisplayWidth && x > Display::mDisplayWidth &&
		   y < Display::mDisplayHeight && y > Display::mDisplayHeight)
	{
		std::cout << "\nWindow coordinates cannot be off screen!\n";
		std::cout << "Please try again:\n";
		std::cin >> x >> y;
	}	

	mWindowX = x;
	mWindowY = y;

	showWindowInfo();
}

void Window::showWindowInfo() const
{
	std::cout << "\nWindow size    : " << mWindowWidth << " x " << mWindowHeight << "\n";
	std::cout << "Window position: X = " << mWindowX << ", Y = " << mWindowY << "\n";
}
