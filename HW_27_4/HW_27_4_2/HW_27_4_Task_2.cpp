#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <iostream>
#include <memory>

void setColor(std::string&);

int main()
{
	std::cout << "Task 2.\n";

	const auto factor = 0.5;
	std::string type = "";
	std::string outerRectangle = "outer rectangle";
	std::string color = "";

	do
	{
		std::cout << "\nPlease input command (circle, square, triangle or rectangle) "
		          << "or exit for end program:\n";
		std::cin >> type;

		while (type != "circle" && type != "square"
			&& type != "triangle" && type != "rectangle"
			&& type != "exit")
		{
			std::cout << "Incorrect input please try again!\n";
			std::cin >> type;
		}

		if (type == "circle")
		{
			std::cout << "Please input radius of circle:\n";
			double radius;
			std::cin >> radius;
			setColor(color);
			auto ptrCircle = std::make_shared<Circle>(type, color, radius);
			ptrCircle->getSquare();
			ptrCircle->printFigure();

			auto ptrOuterRectangle = std::make_shared<Rectangle>(outerRectangle, "", radius + factor, radius + factor);
			ptrOuterRectangle->printFigure();			
		}

		if (type == "square")
		{
			std::cout << "Please side of square:\n";
			double side;
			std::cin >> side;
			setColor(color);
			auto ptrSquare = std::make_shared<Rectangle>(type, color, side, side);
			ptrSquare->getSquare();
			ptrSquare->printFigure();			
			
			auto ptrOuterRectangle = std::make_shared<Rectangle>(outerRectangle, "", side + factor, side + factor);
			ptrOuterRectangle->printFigure();			
		}

		if (type == "triangle")
		{
			std::cout << "Please side of triangle:\n";
			double side;
			std::cin >> side;
			setColor(color);
			auto ptrTriangle = std::make_shared<Triangle>(type, color, side);
			ptrTriangle->getSquare();
			ptrTriangle->printFigure();			

			double bisectrix = ptrTriangle->getBisectrix();
			auto ptrOuterRectangle = std::make_shared<Rectangle>(outerRectangle, "", bisectrix + factor, side + factor);
			ptrOuterRectangle->printFigure();			
		}

		if (type == "rectangle")
		{
			std::cout << "Please input height and width of rectangle:\n";
			double height, width;
			std::cin >> height >> width;
			setColor(color);
			auto ptrRectangle = std::make_shared<Rectangle>(type, color, height, width);
			ptrRectangle->getSquare();
			ptrRectangle->printFigure();			
			
			auto ptrOuterRectangle = std::make_shared<Rectangle>(outerRectangle, "", height + factor, width + factor);
			ptrOuterRectangle->printFigure();			
		}

	} while (type != "exit");
	
	return 0;
}

void setColor(std::string& str)
{
	std::cout << "Please figure color (red, blue or green):\n";
	std::cin >> str;

	while (str != "red" && str != "blue" && str != "green")
	{
		std::cout << "Incorrect input please try again!\n";
		std::cin >> str;
	}	
}