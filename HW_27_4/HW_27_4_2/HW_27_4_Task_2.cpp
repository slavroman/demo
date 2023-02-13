#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <iostream>
#include <memory>

// TODO: Need change main logic!!!

enum class Figure
{
	FIGURE_CIRCLE = 1,
	FIGURE_SQUARE,
	FIGURE_TRIANGLE,
	FIGURE_RECTANGLE
};

enum class Color
{
	COLOR_NONE,
	COLOR_RED,
	COLOR_BLUE,
	COLOR_GREEN
};

int main()
{
	std::cout << "Task 2.\n";

	int answer = 0;
	std::cout << "Please input figure type:\n"
			  << "1 - Circle\n"
			  << "2 - Square\n"
			  << "3 - Triangle\n"
			  << "4 - Rectangle\n";
	std::cin >> answer;

	while (answer < 1 && answer > 4)
	{
		std::cout << "Incorrect input please try again!\n";
		std::cin >> answer;
	}
		
	switch (answer)
	{
		case 1:
		{
			std::cout << "Please input radius of circle:\n";
			double radius;
			std::cin >> radius;
			auto ptrCircle = std::make_shared<Circle>(radius);
			break;
		}			
		case 2:
		{
			std::cout << "Please side of square:\n";
			double side;
			std::cin >> side;
			auto ptrSquare = std::make_shared<Rectangle>(side, side);
			break;
		}			
		case 3:
		{
			std::cout << "Please side of triangle:\n";
			double side;
			std::cin >> side;
			auto ptrTriangle = std::make_shared<Triangle>(side);
			break;
		}			
		case 4:
		{
			std::cout << "Please input height and width of rectangle:\n";
			double height = 0.0, width = 0.0;
			std::cin >> height >> width;
			auto ptrRectangle = std::make_shared<Rectangle>(height, width);
			break;
		}			
	}

		

	

	
	return 0;
}