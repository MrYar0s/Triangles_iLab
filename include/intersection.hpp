#include <vector>
#include <iostream>
#include <limits>
#include <cmath>

namespace geometry
{

struct Point;
struct Vector;
struct Segment;
class Line;
class Plane;
class Triangle;

struct Point
{
        double x_ = NAN;
        double y_ = NAN;
        double z_ = NAN;

        //ctors
	Point();
        Point(double x, double y, double z);
	Point(const Vector& other);
        Point(const Point& other);
        //operators
        Point operator+(const Point& other) const;
        Point operator-(const Point& other) const;
        Point& operator*(const double num) const;
        Point& operator/(const double num) const;
        //operators=
        Point& operator= (const Point& other);
        Point& operator+=(const Point& other);
        Point& operator-=(const Point& other);
        Point& operator*=(const double num);
        Point& operator/=(const double num);
        //get info about point
        void info() const;
};

struct Vector
{
        double x_;
        double y_;
        double z_;

        //ctors
	Vector();
        Vector(const double x, const double y, const double z);
        Vector(const Point& other);
        Vector(const Point& start, const Point& end);
        Vector(const Vector& other);
        //operators
        Vector operator+(const Vector& other) const;
        Vector operator-(const Vector& other) const;
        Vector operator*(const double num) const;
        Vector operator/(const double num) const;
        //operators=
        Vector& operator= (const Vector& other);
        Vector& operator+=(const Vector& other);
        Vector& operator-=(const Vector& other);
        Vector& operator*=(const double num);
        Vector& operator/=(const double num);
        //non standart operations
        double scalar_mult(const Vector& rhs);
        Vector vector_mult(const Vector& rhs);
        double abs() const;
        Vector normalize() const;
        //get info about Vector
        void info() const;
};

class Line
{
        Vector guide_;
public:
        //ctors
	Line();
        Line(const Vector& guide);
        Line(const Plane& lhs, const Plane& rhs);
        Line(const Line& other);

        Vector get_guide() const;
        void info() const;
};

class Plane
{
        double d_;
        Vector normal_;

public:
        //ctors
        Plane(const Triangle& triag);
        Plane(const double d, const Vector& normal);
        Plane(const Plane& other);
        //non standart operations
        double distance_to_point(const Point& p);
        Vector get_normal() const;
        double get_num() const;
        void info() const;
};

class Triangle
{
        Point v0_;
        Point v1_;
        Point v2_;

public:
        //ctors
        Triangle(const Point& v0, const Point& v1, const Point& v2);
	Point getV0() const;
	Point getV1() const;
	Point getV2() const;
};

}

//Triangle to Triangle intersection
//Check intersections between Segments of tr1 and plane from tr2
//If no intersection : false
//If there are intersections
//Intersections AB BC => 
