#ifndef INCLUDE_TRIANGLE_HPP
#define INCLUDE_TRIANGLE_HPP

namespace geometry
{

class Point
{
	double x_ = NAN;
	double y_ = NAN;
	double z_ = NAN;

public:
	//ctors
	Point(double x, double y, double z);
	Point(const Point& other);
	//operators
	Point operator+(const Point& other);
	Point operator-(const Point& other);
	Point& operator*(const double num);
	Point& operator/(const double num);
	//operators=
	Point& operator= (const Point& other);
	Point& operator+=(const Point& other);
	Point& operator-=(const Point& other);
	Point& operator*=(const double num);
	Point& operator/=(const double num);
};

class Vector
{
	Point end_;

public:
	//ctors
	Vector(const Point& other);
	Vector(const Point& start, const Point& end);
	Vector(const Vector& other);
	//operators
	Vector operator+(const Vector& other);
	Vector operator-(const Vector& other);
	Vector operator*(const double num);
	Vector operator/(const double num);
	//operators=
	Vector& operator= (const Vector& other);
	Vector& operator+=(const Vector& other);
	Vector& operator-=(const Vector& other);
	Vector& operator*=(const double num);
	Vector& operator/=(const double num);
	//non standart operations
	double scalar_mult(const Vector& lhs, const Vector& rhs);
	Vector vector_mult(const Vector& lhs, const Vector& rhs);
};

class Plane
{
	double d_;
	Vector normal_;

public:
	//ctors
	Plane(const Triangle& triag);
	Plane(const Point& d, const Vector& normal);
	Plane(const Plane& other);
	//non standart operations
	double distance_to_point(const Point& p);
};

class Line
{
	Point o_;
	Vector guide_;
public:
	//ctors
	Line(const Point& o, const Vector& guide);
	Line(const Plane& lhs, const Plane& rhs);
	Line(const Line& other);
};

class Triangle
{
	Point v0_;
	Point v1_;
	Point v2_;

public:
	//ctors
	Triangle(const Point& v0, const Point& v1, const Point& v2);
};

int plane_and_triang_intersect(const Plane& pi, const Triangle& tr);
bool choose_intersect_case(const Triangle& tr1, const Triangle& tr2);
bool intersection_2d(const Triangle& tr1, const Triangle& tr2);

} //namespace geometry

#endif //INCLUDE_TRIANGLE_HPP