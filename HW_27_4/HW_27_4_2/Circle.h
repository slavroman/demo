#pragma once
#include "BaseFigure.h"

class Circle :
    public BaseFigure
{
public:
    Circle(double);
    ~Circle();

    void getSquare() override;

private:
    double mRadius;
};

