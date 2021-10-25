#include "../include/intersection.hpp"

namespace geometry
{

Vector::Vector() :
	x_(NAN), y_(NAN), z_(NAN) {}

Vector::Vector(double x, double y, double z) :
	x_(x), y_(y), z_(z) {}

Vector::Vector(const Point& other) :
	x_(other.x_), y_(other.y_), z_(other.z_) {}

Vector::Vector(const Point& start, const Point& end) :
	x_(end.x_-start.x_), y_(end.y_-start.y_), z_(end.z_-start.z_) {}

Vector::Vector(const Vector& other) :
	x_(other.x_), y_(other.y_), z_(other.z_) {}

Vector Vector::operator+(const Vector& other) const
{
	Vector v = *this;
	v += other;
	return v;
}

Vector Vector::operator-(const Vector& other) const
{
	Vector v = *this;
	v -= other;
	return v;
}

Vector Vector::operator*(const double num) const
{
	Vector v = *this;
	v *= num;
	return v;
}

Vector Vector::operator/(const double num) const
{
	Vector v = *this;
	v /= num;
	return v;
}

Vector& Vector::operator= (const Vector& other)
{
	x_ = other.x_;
	y_ = other.y_;
	z_ = other.z_;
	return *this;
}

Vector& Vector::operator+=(const Vector& other)
{
	x_ += other.x_;
	y_ += other.y_;
	z_ += other.z_;
	return *this;
}

Vector& Vector::operator-=(const Vector& other)
{
	x_ -= other.x_;
	y_ -= other.y_;
	z_ -= other.z_;
	return *this;
}

Vector& Vector::operator*=(const double num)
{
	x_ *= num;
	y_ *= num;
	z_ *= num;
	return *this;
}

Vector& Vector::operator/=(const double num)
{
	x_ /= num;
	y_ /= num;
	z_ /= num;
	return *this;
}

double Vector::scalar_mult(const Vector& rhs)
{
	Vector lhs = *this;
	return (lhs.x_ * rhs.x_ + lhs.y_ * rhs.y_ + lhs.z_ * rhs.z_);
}

Vector Vector::vector_mult(const Vector& rhs)
{
	Vector lhs = *this;
	double x = lhs.y_ * rhs.z_ - lhs.z_ * rhs.y_;
	double y = lhs.z_ * rhs.x_ - lhs.x_ * rhs.z_;
	double z = lhs.x_ * rhs.y_ - lhs.y_ * rhs.x_;
	return Vector(x, y, z);
}

double Vector::abs() const
{
	return std::sqrt(x_*x_ + y_*y_ + z_*z_);
}

Vector Vector::normalize() const
{
	return (*this)/this->abs();
}

void Vector::info() const
{
	std::cout << "X = " << x_ << std::endl;
	std::cout << "Y = " << y_ << std::endl;
	std::cout << "Z = " << z_ << std::endl;
}

} //namespace geometry
