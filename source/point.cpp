#include "../include/intersection.hpp"

namespace geometry
{
Point::Point() :
	x_(NAN), y_(NAN), z_(NAN) {}

Point::Point(double x, double y, double z) :
	x_(x), y_(y), z_(z) {}

Point::Point(const Vector& other) :
	x_(other.x_), y_(other.y_), z_(other.z_) {}

Point::Point(const Point& other) :
	x_(other.x_), y_(other.y_), z_(other.z_) {}

Point& Point::operator= (const Point& other)
{
	x_ = other.x_;
	y_ = other.y_;
	z_ = other.z_;
	return *this;
}

Point Point::operator+(const Point& other) const
{
	Point p = *this;
	p += other;
	return p;
}

Point Point::operator-(const Point& other) const
{
	Point p = *this;
	p -= other;
	return p;
}

Point& Point::operator+=(const Point& other)
{
	x_ += other.x_;
	y_ += other.y_;
	z_ += other.z_;
	return *this;
}

Point& Point::operator-=(const Point& other)
{
	x_ -= other.x_;
	y_ -= other.y_;
	z_ -= other.z_;
	return *this;
}

void Point::info() const
{
	std::cout << "X = " << x_ << std::endl;
	std::cout << "Y = " << y_ << std::endl;
	std::cout << "Z = " << z_ << std::endl;
}

} //namespace geometry
