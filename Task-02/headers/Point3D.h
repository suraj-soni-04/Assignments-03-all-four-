#pragma once
class Point3D
{
public:
    Point3D();
    Point3D(double x, double y, double z);
    ~Point3D();

    void setmX(double);
    void setmY(double);
    void setmZ(double);

    double getMX();
    double getMY();
    double getMZ();

private:
    double mX;
    double mY;
    double mZ;
};