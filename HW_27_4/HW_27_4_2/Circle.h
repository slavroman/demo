#pragma once
#include "BaseFigure.h"

class Circle :
    public BaseFigure
{
public:
    Circle(std::string, std::string, double);
    ~Circle();

    void getSquare() override;    

private:
    double mRadius;
};

