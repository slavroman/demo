#pragma once
#include "BaseFigure.h"

class Triangle :
    public BaseFigure
{
public:
    Triangle(double);
    ~Triangle();

    void getSquare() override;

private:
    double mSideLength;
    double mBisectrix;
};

