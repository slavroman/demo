#include <iostream>
#include <string>
#include <cmath>

#define PI 3.14

struct BoundingBoxDimensions
{
	double width{};
	double height{};
};

class Shape // interface
{
public:	

	virtual double                square() = 0; // returns square of a particular figure
	virtual BoundingBoxDimensions dimensions() = 0; // dimensions of the box rectangle
	virtual std::string           type() = 0;

protected:
	BoundingBoxDimensions m_Data;
};

class Circle :
	public Shape
{
public:
	Circle(double);
	~Circle();

	double				  square();
	BoundingBoxDimensions dimensions();
	std::string			  type();

private:
	double m_radius;
};

Circle::Circle(double radius)
	: m_radius(radius)
{
}

Circle::~Circle()
{
}

double Circle::square()
{
	return PI * m_radius * m_radius;
}

BoundingBoxDimensions Circle::dimensions()
{
	m_Data.width = m_Data.height = m_radius + m_radius;

	return m_Data;
}

std::string Circle::type()
{
	return "Circle";
}

class Triangle :
	public Shape
{
public:
	Triangle(double, double, double);
	~Triangle();

	double				  square();
	BoundingBoxDimensions dimensions();
	std::string			  type();

private:
	double m_side1;
	double m_side2;
	double m_side3;
	double m_triangleSemiPerimeter;
};

Triangle::Triangle(double side1, double side2, double side3)
	: m_side1(side1), m_side2(side2), m_side3(side3),
	  m_triangleSemiPerimeter((m_side1 + m_side2 + m_side3) / 2)
{
}

Triangle::~Triangle()
{
}

double Triangle::square()
{	
	double triangleSquare = sqrt(m_triangleSemiPerimeter *
								(m_triangleSemiPerimeter - m_side1) *
								(m_triangleSemiPerimeter - m_side2) *
								(m_triangleSemiPerimeter - m_side3));

	return triangleSquare;
}

BoundingBoxDimensions Triangle::dimensions()
{
	double triangleCircleRadius = m_side1 * m_side2 * m_side3 / (4 * sqrt(m_triangleSemiPerimeter *
																		 (m_triangleSemiPerimeter - m_side1) *
																		 (m_triangleSemiPerimeter - m_side2) *
																		 (m_triangleSemiPerimeter - m_side3)));
	m_Data.width = m_Data.height = triangleCircleRadius * 2;

	return m_Data;
}

std::string Triangle::type()
{
	return "Triangle";
}

class Rectangle :
	public Shape
{
public:
	Rectangle(double, double);
	~Rectangle();

	double				  square();
	BoundingBoxDimensions dimensions();
	std::string			  type();

private:
	double m_side1;
	double m_side2;
};

Rectangle::Rectangle(double side1, double side2)
	: m_side1(side1), m_side2(side2)
{
}

Rectangle::~Rectangle()
{
}

double Rectangle::square()
{
	return m_side1 * m_side2;
}

BoundingBoxDimensions Rectangle::dimensions()
{
	m_Data.width = m_side1;
	m_Data.height = m_side2;

	return m_Data;
}

std::string Rectangle::type()
{
	return "Rectangle";
}
	

void printParams(Shape* shape) // here you can transfer any shapes
{
	std::cout << std::endl;
	std::cout << "  Type: " << shape->type() << std::endl;
	std::cout << "Square: " << shape->square() << std::endl;
	std::cout << " Width: " << shape->dimensions().width << std::endl;
	std::cout << "Height: " << shape->dimensions().height << std::endl;
	std::cout << std::endl;
}

int main()
{
	std::cout << "Task 2.\n";

	Circle circle(5);
	printParams(&circle);

	Triangle triangle(3, 4, 5);
	printParams(&triangle);

	Rectangle rectangle(4, 9);
	printParams(&rectangle);

	std::cout << "\tEND OF PROGRAMM !!!\n";

	return 0;
}