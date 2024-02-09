#include <..\headers\Point3D.h>
#include <iostream>
using namespace std;
Point3D::Point3D()
{
    this->mX = 0.0;
    this->mY = 0.0;
    this->mZ = 0.0;
}
Point3D::Point3D(double x, double y, double z)
{
    this->mX = x;
    this->mY = y;
    this->mZ = z;
}
Point3D::~Point3D()
{
}
void Point3D::setmX(double x)
{
    this->mX=x;
}
void Point3D::setmY(double y)
{
    this->mY=y;
}
void Point3D::setmZ(double z)
{
    this->mZ=z;
}
double Point3D::getMX()
{
    return this->mX;
}
double Point3D::getMY()
{
    return this->mY;
}
double Point3D::getMZ()
{
    return this->mZ;
}
