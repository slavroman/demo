#pragma once
#include "BaseFigure.h"

class Triangle :
    public BaseFigure
{
public:
    Triangle(std::string, std::string, double);
    ~Triangle();

    double getBisectrix();
    void getSquare() override;

private:
    double mSideLength;
    double mBisectrix;
};

