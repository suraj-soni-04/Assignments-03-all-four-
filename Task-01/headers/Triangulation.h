#pragma once
#include<.\Triangle.h>
#include<.\Point3D.h>
#include<vector>
#include<map>
using namespace std;
class Triangulation
{
    public:
        vector<Triangle> getTriangles();
        vector<Point3D> getPoints();
        static Triangulation * getInstance();
        
    private:
        vector<Triangle> mTraingles;
        vector<Point3D> mUnique3DPoints;
        static Triangulation *triangulation;

        Triangulation();

        Triangulation(const Triangulation&other)=delete; //cc
        Triangulation& operator=(const Triangulation&other)=delete;
};
