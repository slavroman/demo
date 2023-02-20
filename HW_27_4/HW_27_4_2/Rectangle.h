#pragma once
#include "BaseFigure.h"

class Rectangle :
    public BaseFigure
{
public:    
    Rectangle(std::string, std::string, double, double);
    ~Rectangle();
    
    void getSquare() override;
    std::unique_ptr<Rectangle> getBoundaryBox() override;
    void printBoundaryFigure();
};