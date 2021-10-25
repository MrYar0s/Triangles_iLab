#include "../include/intersection.hpp"

namespace geometry
{

Line::Line() :
	guide_(Vector{}) {}

Line::Line(const Vector& guide) :
	guide_(guide) {}

Line::Line(const Plane& lhs, const Plane& rhs)
{
        Vector n1(lhs.get_normal());
        Vector n2(rhs.get_normal());

        guide_ = n1.vector_mult(n2);
}

Line::Line(const Line& other) :
	guide_(other.get_guide()){}

Vector Line::get_guide() const
{
	return guide_;
}

void Line::info() const
{
	std::cout << "Guide vector " << std::endl;
	guide_.info();
}

}//namespace geometry
