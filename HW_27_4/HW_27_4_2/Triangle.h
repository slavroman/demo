#pragma once
#include "BaseFigure.h"

class Triangle :
    public BaseFigure
{
public:
    Triangle(std::string, std::string, double);
    ~Triangle();
    
    void getSquare() override;
    std::unique_ptr<Rectangle> getBoundaryBox() override;

private:
    double mSideLength;
    double mBisectrix;
};