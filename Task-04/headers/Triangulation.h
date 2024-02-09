#pragma once
#include<.\Triangle.h>
#include<.\Point3D.h>
#include<vector>
#include<map>
using namespace std;
class Triangulation
{
    public:
        Triangulation();
        ~Triangulation();
        vector<Triangle>& getTriangles();
        vector<Point3D>& getPoints();
    private:
        vector<Triangle> mTraingles;
        vector<Point3D> mUnique3DPoints;
};