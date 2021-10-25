#include "../include/intersection.hpp"

namespace geometry
{

Triangle::Triangle(const Point& v0, const Point& v1, const Point& v2) :
	v0_(v0), v1_(v1), v2_(v2) {}

Point Triangle::getV0() const
{
	return v0_;
}

Point Triangle::getV1() const
{
	return v1_;
}

Point Triangle::getV2() const
{
	return v2_;
}

} //namespace geometry
