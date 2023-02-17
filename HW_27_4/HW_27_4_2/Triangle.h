#pragma once
#include "BaseFigure.h"

class Triangle :
    public BaseFigure
{
public:
    Triangle(std::string, std::string, double);
    ~Triangle();
    
    void getSquare() override;
    void getBoundaryBox(const double) override;

private:
    double mSideLength;
    double mBisectrix;
};