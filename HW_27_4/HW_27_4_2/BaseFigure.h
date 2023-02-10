#pragma once

class BaseFigure
{
public:

	enum class Color
	{
		COLOR_NONE,
		COLOR_RED,
		COLOR_BLUE,
		COLOR_GREEN
	};

	BaseFigure();
	~BaseFigure();

private:
	double mCenter; // x,y
	size_t mColor;
};