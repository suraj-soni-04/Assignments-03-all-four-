#pragma once
#include<.\Point3D.h>
#include<.\Triangle.h>
#include<vector>
#include<string>
using namespace std;
class ObjWriter
{
    public:
        void fileWriter(string ,vector<Point3D>&, vector<Triangle> &);
};