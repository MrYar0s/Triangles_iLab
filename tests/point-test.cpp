#include "../include/intersection.hpp"
#include <gtest/gtest.h>

const double x = 521.352;
const double y = -523.31;
const double z = 12052.32;

TEST(PointTest, Init)
{
	geometry::Point p(x, y, z);
	ASSERT_EQ(p.x_, x);
	ASSERT_EQ(p.y_, y);
	ASSERT_EQ(p.z_, z);
}

TEST(PointTest, InitOther)
{
	geometry::Point other(x, y, z);
	geometry::Point p(other);
	ASSERT_EQ(other.x_, p.x_);
	ASSERT_EQ(other.y_, p.y_);
	ASSERT_EQ(other.z_, p.z_);
}

TEST(PointTest, OperatorEq)
{
	geometry::Point other(x, y, z);
	geometry::Point p(y, 0, x);
	p = other;
	ASSERT_EQ(p.x_, other.x_);
	ASSERT_EQ(p.y_, other.y_);
	ASSERT_EQ(p.z_, other.z_);
}

TEST(PointTest, OperatorPlus)
{
	geometry::Point p;
	geometry::Point other1(x, y, z);
	geometry::Point other2(x, 2*y, z/3);
	p = other1 + other2;
	ASSERT_EQ(p.x_, other1.x_+other2.x_);
	ASSERT_EQ(p.y_, other1.y_+other2.y_);
	ASSERT_EQ(p.z_, other1.z_+other2.z_);
}

TEST(PointTest, OperatorMin)
{
	geometry::Point p;
	geometry::Point other1(x, y, z);
	geometry::Point other2(x, 2*y, z/3);
	p = other1 - other2;
	ASSERT_EQ(p.x_, other1.x_-other2.x_);
	ASSERT_EQ(p.y_, other1.y_-other2.y_);
	ASSERT_EQ(p.z_, other1.z_-other2.z_);
}

TEST(PointTest, OperatorPlusEq)
{
	geometry::Point p(x, y, z);
	geometry::Point other(x, 2*y, z/3);
        p += other;
        ASSERT_EQ(p.x_, other.x_+x);
        ASSERT_EQ(p.y_, other.y_+y);
        ASSERT_EQ(p.z_, other.z_+z);
}

TEST(PointTest, OperatorMinEq)
{
	geometry::Point p(x, y, z);
	geometry::Point other(x, 2*y, z/3);
	p -= other;
	ASSERT_EQ(p.x_, x-other.x_);
	ASSERT_EQ(p.y_, y-other.y_);
	ASSERT_EQ(p.z_, z-other.z_);
}
