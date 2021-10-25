#include "../include/intersection.hpp"
#include <gtest/gtest.h>

const double x = 417.4132;
const double y = -631.321;
const double z = 123.632;

TEST(VectorTest, InitValue)
{
	geometry::Vector v(x, y, z);
	ASSERT_EQ(v.x_, x);
	ASSERT_EQ(v.y_, y);
	ASSERT_EQ(v.z_, z);
}

TEST(VectorTest, InitOther)
{
	geometry::Vector other(x, y, z);
	geometry::Vector v(other);
	ASSERT_EQ(other.x_, v.x_);
	ASSERT_EQ(other.y_, v.y_);
	ASSERT_EQ(other.z_, v.z_);
}

TEST(VectorTest, InitByTwoPoints)
{
	geometry::Point p1(x, y, z);
	geometry::Point p2(z, x, -y);
	geometry::Vector v(p1, p2);
	ASSERT_EQ(v.x_, p2.x_-p1.x_);
	ASSERT_EQ(v.y_, p2.y_-p1.y_);
	ASSERT_EQ(v.z_, p2.z_-p1.z_);
}

TEST(VectorTest, InitByOnePoint)
{
	geometry::Point p(x, y, z);
	geometry::Vector v(p);
	ASSERT_EQ(v.x_, p.x_);
	ASSERT_EQ(v.y_, p.y_);
	ASSERT_EQ(v.z_, p.z_);
}

TEST(VectorTest, OperatorPlus)
{
	geometry::Vector v1(x, y, z);
	geometry::Vector v2(2*x, -6.3*z, y);
	geometry::Vector res(x, y, 2.0);
	res = v1 + v2;
	ASSERT_EQ(res.x_, v1.x_ + v2.x_);
	ASSERT_EQ(res.y_, v1.y_ + v2.y_);
	ASSERT_EQ(res.z_, v1.z_ + v2.z_);
}

TEST(VectorTest, OperatorMin)
{
	geometry::Vector v1(x, y, z);
	geometry::Vector v2(2*x, -6.3*z, y);
	geometry::Vector res(x, y, 2.0);
	res = v1 - v2;
	ASSERT_EQ(res.x_, v1.x_ - v2.x_);
	ASSERT_EQ(res.y_, v1.y_ - v2.y_);
	ASSERT_EQ(res.z_, v1.z_ - v2.z_);
}

TEST(VectorTest, OperatorMult)
{
	geometry::Vector v1(x, y, z);
	const double num = 5.21;
	geometry::Vector res(x, y, -6.2);
	res = v1 * num;
	ASSERT_EQ(res.x_, v1.x_*num);
	ASSERT_EQ(res.y_, v1.y_*num);
	ASSERT_EQ(res.z_, v1.z_*num);
}

TEST(VectorTest, OperatorDiv)
{
	geometry::Vector v1(x, y, z);
	const double num = 5.21;
	geometry::Vector res(x, y, -6.2);
	res = v1 / num;
	ASSERT_EQ(res.x_, v1.x_/num);
	ASSERT_EQ(res.y_, v1.y_/num);
	ASSERT_EQ(res.z_, v1.z_/num);
}

TEST(VectorTest, OperatorEq)
{
	geometry::Vector other(x, y, z);
	geometry::Vector v(2.6, 6.2, 0.0);
	v = other;
	ASSERT_EQ(v.x_, other.x_);
	ASSERT_EQ(v.y_, other.y_);
	ASSERT_EQ(v.z_, other.z_);
}

TEST(VectorTest, OperatorPlusEq)
{
	geometry::Vector p(x, y, z);
	geometry::Vector other(-x*1.5, z, y*x);
	p += other;
	ASSERT_EQ(p.x_, x + other.x_);
	ASSERT_EQ(p.y_, y + other.y_);
	ASSERT_EQ(p.z_, z + other.z_);
}

TEST(VectorTest, OperatorMinEq)
{
	geometry::Vector p(x, y, z);
	geometry::Vector other(-x*1.5, z, y*x);
	p -= other;
	ASSERT_EQ(p.x_, x - other.x_);
	ASSERT_EQ(p.y_, y - other.y_);
	ASSERT_EQ(p.z_, z - other.z_);
}

TEST(VectorTest, OperatorMulEq)
{
	geometry::Vector p(x, y, z);
	const double num = 7.74;
	p *= num;
	ASSERT_EQ(p.x_, x*num);
	ASSERT_EQ(p.y_, y*num);
	ASSERT_EQ(p.z_, z*num);
}

TEST(VectorTest, OperatorDivEq)
{
	geometry::Vector p(x, y, z);
	const double num = 7.74;
	p /= num;
	ASSERT_EQ(p.x_, x/num);
	ASSERT_EQ(p.y_, y/num);
	ASSERT_EQ(p.z_, z/num);
}

TEST(VectorTest, ScalarMult)
{
	geometry::Vector v(x, y, z);
	geometry::Vector other(x, y, z);
	const double res = v.scalar_mult(other);
	ASSERT_EQ(res, v.x_*other.x_+v.y_*other.y_+v.z_*other.z_);
}

TEST(VectorTest, VectorMult)
{
	geometry::Vector v(x, y, z);
	geometry::Vector other(y, z, x);
	geometry::Vector res = v.vector_mult(other);
	ASSERT_EQ(res.x_, v.y_*other.z_-v.z_*other.y_);
	ASSERT_EQ(res.y_, v.z_*other.x_-v.x_*other.z_);
	ASSERT_EQ(res.z_, v.x_*other.y_-v.y_*other.x_);
}

TEST(VectorTest, VectorAbs)
{
	geometry::Vector v(x, y, z);
	const double res = v.abs();
	ASSERT_EQ(res, std::sqrt(v.x_*v.x_+v.y_*v.y_+v.z_*v.z_));
}

TEST(VectorTest, VectorNormalize)
{
	geometry::Vector v(x, y, z);
	const double abs = v.abs();
	geometry::Vector res = v.normalize();
	ASSERT_EQ(res.x_, v.x_/abs);
	ASSERT_EQ(res.y_, v.y_/abs);
	ASSERT_EQ(res.z_, v.z_/abs);
}
