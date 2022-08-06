#pragma once

class Window
{
public:
	Window();

	void setWinsowSize();
	int getWindowX();
	int getWindowY();
	int getWindowHeight();
	int getWindowWidth();
	void moveWindow();
	void showWindowInfo() const;
private:
	int mWindowX;
	int mWindowY;
	int mWindowHeight;
	int mWindowWidth;
};