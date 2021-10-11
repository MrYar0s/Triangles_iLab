#include "../include/triangle.hpp"

namespace geometry
{
Point::Point(double x, double y, double z) :
	x_(x), y_(y), z_(z) {}

Point::Point(const Point& other) :
	x_(other.x_), y_(other.y_), z_(other.z_) {}

Point& Point::operator= (const Point& other)
{
	x_ = other.x_;
	y_ = other.y_;
	z_ = other.z_;
	return *this;
}

Point::Point operator+(const Point& other)
{
	Point p = *this;
	p += other;
	return p;
}

Point::Point operator-(const Point& other)
{
	Point p = *this;
	p -= other;
	return p;
}

Point::Point operator*(const double num)
{
	Point p = *this;
	p *= num;
	return p;
}

Point::Point operator/(const double num)
{
	Point p = *this;
	p /= num;
	return p;
}

Point::Point& operator+=(const Point& other)
{
	x_ += other.x_;
	y_ += other.y_;
	z_ += other.z_;
	return *this;
}

Point::Point& operator-=(const Point& other)
{
	x_ -= other.x_;
	y_ -= other.y_;
	z_ -= other.z_;
	return *this;
}

Point::Point& operator*=(const double num)
{
	x_ *= num;
	y_ *= num;
	z_ *= num;
	return *this;
}

Point::Point& operator/=(const double num)
{
	x_ /= num;
	y_ /= num;
	z_ /= num;
	return *this;
}

Vector::Vector(const Point& other) :
	end_(other) {}

Vector::Vector(const Point& start, const Point& end) :
	end_(end - start) {}

Vector::Vector(const Vector& other) :
	end_(other.guide_) {}

Vector::Vector operator+(const Vector& other)
{
	Vector v = *this;
	v += other;
	return v;
}

Vector::Vector operator-(const Vector& other)
{
	Vector v = *this;
	v -= other;
	return v;
}

Vector::Vector operator*(const double num)
{
	Vector v = *this;
	v *= num;
	return v;
}

Vector::Vector operator/(const double num)
{
	Vector v = *this;
	v /= num;
	return v;
}

Vector::Vector& operator= (const Vector& other)
{
	end_ = other.end_;
	return *this;
}

Vector::Vector& operator+=(const Vector& other)
{
	end_ += other.end_;
	return *this;
}

Vector::Vector& operator-=(const Vector& other)
{
	end_ -= other.end_;
	return *this;
}

Vector::Vector& operator*=(const double num)
{
	end_ *= num;
	return *this;
}

Vector::Vector& operator/=(const double num)
{
	end_ /= num;
	return *this;
}

double scalar_mult(const Vector& lhs, const Vector& rhs)
{
	return (lhs.end_.x_ * rhs.end_.x_ +
			lhs.end_.y_ * rhs.end_.y_ +
			lhs.end_.z_ * rhs.end_.z_);
}

Vector vector_mult(const Vector& lhs, const Vector& rhs)
{
	double x = lhs.end_.y_ * rhs.end_.z_ - lhs.end_.z_ * rhs.end_.y_;
	double y = lhs.end_.z_ * rhs.end_.x_ - lhs.end_.x_ * rhs.end_.z_;
	double z = lhs.end_.x_ * rhs.end_.y_ - lhs.end_.y_ * rhs.end_.x_;
	return Vector(x, y, z);
}

Plane::Plane(const Triangle& triag)
{
	Vector normal_{vector_mult((triag.v0_,triag.v1_), (triag.v0_,triag.v2_))};
	Point d_{-scalar_mult(normal, triag.v0_)};
}

Plane::Plane(const Point& start, const Vector& normal) :
	d_(d), normal_(normal) {}

Plane::Plane(const Plane& other) :
	d_(other.d_), normal_(other.normal_) {}

double Plane::distance_to_point(const Point& p)
{
	return (scalar_mult(normal_, Vector(p)) + d_)
}

Line::Line(const Point& o, const Vector& guide) :
	o_(o), guide_(guide) {}

Line::Line(const Plane& lhs, const Plane& rhs)
{
	Vector n1(lhs.normal_);
	Vector n2(rhs.normal_);

	guide_ = vector_mult(n1, n2);
	
}

Triangle::Triangle(const Point& v0, const Point& v1, const Point& v2) :
	v0_(v0), v1_(v1), v2_(v2) {}

int plane_and_triang_intersect(const Plane& pi, const Triangle& tr)
{
	double pi_to_tr_first = pi.distance_to_point(tr.v0_);
	double pi_to_tr_second = pi.distance_to_point(tr.v1_);
	double pi_to_tr_third = pi.distance_to_point(tr.v2_);
	if(pi_to_tr_first > 0 && pi_to_tr_second > 0 && pi_to_tr_third > 0)
		return 0;
	if(pi_to_tr_first < 0 && pi_to_tr_second < 0 && pi_to_tr_third < 0)
		return 0;
	if(pi_to_tr_first == 0 && pi_to_tr_second == 0 && pi_to_tr_third == 0)
		return 2; //co-planar (2d)
	return 1; //mb intersection in 3d
}

bool choose_intersect_case(const Triangle& tr1, const Triangle& tr2)
{
	int st1 = plane_and_triang_intersect(Plane pi1(tr1), tr2);
	int st2 = plane_and_triang_intersect(Plane pi2(tr2), tr1);
	if(!st1 || !st2)
	{
		return false;
	} else if(st1 == 2 && st2 == 2)
	{
		intersection_2d(tr1, tr2);
	} else
	{
		intersection_3d(tr1, tr2);
	}
}

bool intersection_2d(const Triangle& tr1, const Triangle& tr2)
{

}

bool intersection_3d(const Triangle& tr1, const Triangle& tr2)
{
	
}

} //namespace geometry