#pragma once
#include "BaseFigure.h"

class Circle :
    public BaseFigure
{
public:
    Circle(std::string, std::string, double);
    ~Circle();

    void getSquare() override;
    std::unique_ptr<Rectangle> getBoundaryBox() override;

private:
    double mRadius;
};

