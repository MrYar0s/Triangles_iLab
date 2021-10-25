#include "../include/intersection.hpp"
#include <gtest/gtest.h>

const double x = 421.643;
const double y = -41.63;
const double z = -72.31;

TEST(LineTest, InitValue)
{
	Point o(x, y, z);
	Vector guide(2*x, y/4, -z);
	Line res(o, guide);
	res_o = res.get_point();
	res_v = res.get_guide();
	ASSERT_EQ(res_o.x_, o.x_);
	ASSERT_EQ(res_o.y_, o.y_);
	ASSERT_EQ(res_o.z_, o.z_);
	ASSERT_EQ(res_v.x_, guide.x_);
	ASSERT_EQ(res_v.y_, guide.y_);
	ASSERT_EQ(res_v.z_, guide.z_);
}
