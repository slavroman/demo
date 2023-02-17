#pragma once
#include "BaseFigure.h"

class Rectangle :
    public BaseFigure
{
public:    
    Rectangle(std::string, std::string, double, double);
    ~Rectangle();
    
    void getSquare() override;
    void getBoundaryBox(const double) override;

private:
    double mHeight;
    double mWidth;
};

