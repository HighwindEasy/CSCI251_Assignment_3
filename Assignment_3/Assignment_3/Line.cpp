#include "Line.h"


void Point2D::setDistFrOrigin()
{
	this->distFrOrigin = sqrt(((x - 0) * (x - 0)) + (y - 0) * (y - 0));
}

void Point3D::setDistFrOrigin()
{
	this->distFrOrigin = sqrt(((x - 0) * (x - 0)) + (y - 0) * (y - 0) + (z - 0) * (z - 0));
}

void Line2D::setLength()
{
	this->length = sqrt(((pt1.getX() - pt2.getX()) * (pt1.getX() - pt2.getX())) + ((pt1.getY() - pt2.getY()) * (pt1.getY() - pt2.getY())));
}

void Line3D::setLength()
{
	this->length = sqrt(((pt1.getX() - pt2.getX()) * (pt1.getX() - pt2.getX())) + ((pt1.getY() - pt2.getY()) * (pt1.getY() - pt2.getY())) + ((pt1.getZ() - pt2.getZ()) * (pt1.getZ() - pt2.getZ())));
}

ostream& operator<<(ostream& os, Point2D& p2d)
{
	os << "[" << p2d.getX() << ", " << p2d.getY() << "] ";
	os << p2d.getScalarValue();
	return os;
}

ostream& operator<<(ostream& os, Point3D& p3d)
{
	os << "[" << p3d.getX() << ", " << p3d.getY() << ", "  << p3d.getZ()<< "] ";
	os << p3d.getScalarValue();
	return os;
}

ostream& operator<<(ostream& os, Line2D& l2d)
{
	os << "Point 1: [" << l2d.getPt1().getX() << ", " << l2d.getPt1().getY() << "] ";
	os << "Point 2: [" << l2d.getPt2().getX() << ", " << l2d.getPt2().getY() << "] ";
	os << "Length: " << l2d.getScalarValue();
	return os;
}

ostream& operator<<(ostream& os, Line3D& l3d)
{
	os << "Point 1: [" << l3d.getPt1().getX() << ", " << l3d.getPt1().getY() << ", " << l3d.getPt1().getZ() << "] ";
	os << "Point 2: [" << l3d.getPt2().getX() << ", " << l3d.getPt2().getY() << ", " << l3d.getPt2().getZ() << "] ";
	os << "Length: " << l3d.getScalarValue();
	return os;
}

bool operator==(Point2D a, Point2D b)
{
	return a.getX() == b.getX() && a.getY() == b.getY();
}

bool operator==(Point3D a, Point3D b)
{
	return a.getX() == b.getX()
		&& a.getY() == b.getY()
		&& a.getZ() == b.getZ();
}

bool operator==(Line2D a, Line2D b)
{
	return a.getPt1() == b.getPt1()
		&& a.getPt2() == b.getPt2();
}