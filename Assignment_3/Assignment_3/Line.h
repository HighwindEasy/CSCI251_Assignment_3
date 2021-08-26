#ifndef LINE_H_
#define LINE_H_

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

class Point2D
{
//Protected values of class Point2D
protected:
	//Values of Point2D (Common values)
	int x, y;
	double distFrOrigin;

//Protected functions of class Point2D
protected:
	//Functions of Point2D (Common methods)
	void setDistFrOrigin();

//All Public methods of Point2D will be placed here
public:
	Point2D() {}
	//Constructor of Point2D
	Point2D(int X_setter, int Y_setter)
	{
		x = X_setter;
		y = Y_setter;
		this->setDistFrOrigin();
	}
	//Destructor of Point2D
	~Point2D()
	{

	}

	//Getters of Point2D / Point3D (Common methods)
	int getX() { return x; }
	int getY() { return y; }
	double getScalarValue() { return distFrOrigin; }

	//Setters of Point2D / Point 3D (Common methods)
	void setX(int x_Setter) { x = x_Setter; }
	void setY(int y_Setter) { y = y_Setter; }
	friend ostream& operator<<(ostream& os,  Point2D &p2d);
};

class Point3D : public Point2D
{
//Protected values of Point3D
protected:
	//Unique values to Point3D
	int z;

//Protected functions of Point3D
protected:
	//Unique methods to Point3D
	void setDistFrOrigin();

//Public Functions of Point3D
public:
	Point3D()
	{

	}
	Point3D(int X_setter, int Y_setter, int Z_setter)
	{
		x = X_setter;
		y = Y_setter;
		z = Z_setter;
		this->setDistFrOrigin();
	}
	//Getters of Point3D (Unique methods)
	int getZ() { return z; }

	//Setters of Point3D (Unique methods)
	void setZ(int z_Setter) { z = z_Setter; }

	friend ostream& operator<<(ostream& os, Point3D& p3d);
};

class Line2D
{
private:
	Point2D pt1;
	Point2D pt2;
protected:
	double length;

protected:
	void setLength();

public:
	Line2D()
	{
		
	}
	Line2D(Point2D Pt1, Point2D Pt2)
	{
		pt1 = Pt1;
		pt2 = Pt2;
		setLength();
	}
	~Line2D()
	{

	}

	Point2D getPt1() { return pt1; }
	Point2D getPt2() { return pt2; }
	double getScalarValue() { return length; }

	void setPt1(Point2D PT1) { pt1 = PT1; }
	void setPt2(Point2D PT2) { pt2 = PT2; }

	friend ostream& operator<<(ostream& os, Line2D& l2d);
};



class Line3D : public Line2D
{
private:
	Point3D pt1;
	Point3D pt2;
protected:
	double length;

protected:
	void setLength();

public:
	Line3D()
	{

	}
	Line3D(Point3D Pt1, Point3D Pt2)
	{
		pt1 = Pt1;
		pt2 = Pt2;
		setLength();
	}
	~Line3D()
	{

	}

	Point3D getPt1() { return pt1; }
	Point3D getPt2() { return pt2; }
	double getScalarValue() { return length; }

	void setPt1(Point3D PT1) { pt1 = PT1; }
	void setPt2(Point3D PT2) { pt2 = PT2; }
	friend ostream& operator<<(ostream& os, Line3D& l3d);
};



/*ostream& operator<<(ostream& os, Point3D& p3d)
{

}*/




#endif // !LINE_H_

