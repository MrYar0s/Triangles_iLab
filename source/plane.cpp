#include "../include/intersection.hpp"

namespace geometry
{

Plane::Plane(const Triangle& triag)
{
	Vector a(triag.getV0(), triag.getV1());
	Vector b(triag.getV0(), triag.getV2());
        normal_ = (a.vector_mult(b));
	d_ = (-normal_.scalar_mult(triag.getV0()));
}

Plane::Plane(const double d, const Vector& normal) :
        d_(d), normal_(normal) {}

Plane::Plane(const Plane& other) :
        d_(other.get_num()), normal_(other.get_normal()) {}

double Plane::distance_to_point(const Point& p)
{
	Vector h(p);
        return normal_.scalar_mult(h) + d_;
}

Vector Plane::get_normal() const
{
	return normal_;
}

double Plane::get_num() const
{
	return d_;
}

void Plane::info() const
{
	std::cout << "Normal vector " << std::endl;
	normal_.info();
	std::cout << "Num " << d_ << std::endl;
}

}//namespace geometry
