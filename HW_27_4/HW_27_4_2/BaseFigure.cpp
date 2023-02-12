#include "BaseFigure.h"

BaseFigure::BaseFigure()
	:mName("Unknown"), mColor(0), mCenter(0.0)
{
}

BaseFigure::~BaseFigure()
{
}

void BaseFigure::setName(const std::string name)
{
	mName = name;
}

void BaseFigure::setColor(const size_t color)
{
	mColor = color;
}
