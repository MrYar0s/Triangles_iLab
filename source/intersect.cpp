#include "../include/triangle.hpp"

namespace geometry
{

int plane_and_triang_intersect(const Plane& pi, const Triangle& tr)
{
	double pi_to_tr_first = pi.distance_to_point(tr.v0_);
	double pi_to_tr_second = pi.distance_to_point(tr.v1_);
	double pi_to_tr_third = pi.distance_to_point(tr.v2_);
	if(pi_to_tr_first > 0 && pi_to_tr_second > 0 && pi_to_tr_third > 0)
		return 0; //do not intersect
	if(pi_to_tr_first < 0 && pi_to_tr_second < 0 && pi_to_tr_third < 0)
		return 0; //do not intersect
	if(pi_to_tr_first == 0 && pi_to_tr_second == 0 && pi_to_tr_third == 0)
		return 2; //co-planar (2d)
	return 1; //mb intersection in 3d
}

std::pair<Line, Line> get_lines(const Triangle& tr, const Plane& pi)
{
	Point A = tr.getV0();
	Point B = tr.getV1();
	Point C = tr.getV2();

	double distA = pi.distance_to_point(A);
	double distB = pi.distance_to_point(B);
	double distC = pi.distance_to_point(C);

	Line lhs;
	Line rhs;

	if((distA > 0 && distB > 0 && distC < 0) || (distA < 0 && distB < 0 && distC > 0))
	{
		lhs(A, C);
		rhs(B, C);
	} else if((distA > 0 && distB < 0 && distC > 0) || (distA < 0 && distB > 0 && distC < 0))
	{
		lhs(A, B);
		rhs(C, B);
	} else if((distA < 0 && distB > 0 && distC > 0) || (distA > 0 && distB < 0 && distC < 0))
	{
		lhs(C, A);
		rhs(B, A);
	}
	return lhs, rhs;
}

std::vector<double> get_intervals(const Line& inter, const Triangle& tr1, const Triangle& tr2)
{
	Plane pi1(tr1);
	Plane pi2(tr2);
	auto line_pairs = get_lines(tr1, pi2);
	Line line_lhs = line_pairs.first;
	Line line_rhs = line_pairs.second;



	//auto line_pairs2 = get_lines(tr2, pi1);
}

bool intersection(const Triangle& tr1, const Triangle& tr2)
{
	Plane pi1(tr1);
	Plane pi2(tr2);
	int st1 = plane_and_triang_intersect(pi1, tr2);
	int st2 = plane_and_triang_intersect(pi2, tr1);
	if(!st1 || !st2)
	{
		return false;
	}
	if(st1 == 2 || st2 == 2)
	{
		return intersection_2d(tr1, tr2);
	}
	Line instersect_line(pl1, pl2);
	std::vector<double> = get_intervals(instersect_line, tr1, tr2);
}

bool intersection_2d(const Triangle& tr1, const Triangle& tr2)
{

}

} //namespace geometry
