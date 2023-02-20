#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <iostream>
#include <memory>

void setColor(std::string&);

int main()
{
	std::cout << "Task 2.\n";
	
	std::string type = "";
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
			Circle circle(type, color, radius);
			circle.getSquare();
			circle.printFigure();
			auto ptrBoundaryRectangle = circle.getBoundaryBox();
			ptrBoundaryRectangle->printBoundaryFigure();
		}

		if (type == "square")
		{
			std::cout << "Please side of square:\n";
			double side;
			std::cin >> side;
			setColor(color);
			Rectangle square(type, color, side, side);
			square.getSquare();
			square.printFigure();
			auto ptrBoundaryRectangle = square.getBoundaryBox();
			ptrBoundaryRectangle->printBoundaryFigure();
		}

		if (type == "triangle")
		{
			std::cout << "Please side of triangle:\n";
			double side;
			std::cin >> side;
			setColor(color);
			Triangle triangle(type, color, side);
			triangle.getSquare();
			triangle.printFigure();
			auto ptrBoundaryRectangle = triangle.getBoundaryBox();
			ptrBoundaryRectangle->printBoundaryFigure();
		}

		if (type == "rectangle")
		{
			std::cout << "Please input height and width of rectangle:\n";
			double height, width;
			std::cin >> height >> width;
			setColor(color);
			Rectangle rectangle(type, color, height, width);
			rectangle.getSquare();
			rectangle.printFigure();
			auto ptrBoundaryRectangle = rectangle.getBoundaryBox();
			ptrBoundaryRectangle->printBoundaryFigure();
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