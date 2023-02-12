#pragma once
#include "BaseFigure.h"

class Circle :
    public BaseFigure
{
public:
    Circle(double);
    ~Circle();

    double getSquare() override;
    void printFigure() override;

private:
    double mRadius;

};

